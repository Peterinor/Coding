/*
---

name: Element

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Browser, Array, Function, Number, String, Object, Number, Sizzle]
provides: [Element, Elements, $]

...
*/

var Element = this.Element = function(tag, props) {
    if (typeOf(tag) == 'window' ||
        typeOf(tag) == 'document')
        return tag;
    var el;
    if (typeOf(tag) == 'element') el = tag;
    else el = Sizzle(tag)[0];
    //for ie6,7
    if (el) {
        if (!Browser.Element) {
            var fireEvent = el.fireEvent;
            el._fireEvent = function(type, event) {
                return fireEvent(type, event);
            };
            Object.append(el, Element.Prototype);
        }
    }

    return el;
};


(function() {

    [Element, Window, Document].invoke('implement', {

        addListener: function(type, fn) {
            if (this.addEventListener) this.addEventListener(type, fn, !! arguments[2]);
            else this.attachEvent('on' + type, fn);
            return this;
        },

        removeListener: function(type, fn) {
            if (this.removeEventListener) this.removeEventListener(type, fn, !! arguments[2]);
            else this.detachEvent('on' + type, fn);
            return this;
        }

    });

    Document.implement({
        id: function(el) {
            if (typeOf(el) == 'string') {
                if (el.indexOf('#') == -1) {
                    el = '#' + el;
                }
            }
            var el = Sizzle(el)[0];
            return el;
        },
        getDocument: function() {
            return this;
        },
        getWindow: function() {
            return this.window;
        }
    });

    Window.implement({
        getDocument: function() {
            return this.document;
        },
        getWindow: function() {
            return this;
        }
    });
})();

if (Browser.Element) {
    Element.prototype = Browser.Element.prototype;
    // IE8 and IE9 require the wrapping.
    Element.prototype._fireEvent = (function(fireEvent) {
        return function(type, event) {
            return fireEvent.call(this, type, event);
        };
    })(Element.prototype.fireEvent);
}

new Type('Element', Element).mirror(function(name) {
    var obj = {};
    obj[name] = function() {
        var results = [],
            args = arguments,
            elements = true;
        for (var i = 0, l = this.length; i < l; i++) {
            var element = new Element(this[i]),
                result = results[i] = element[name].apply(element, args);
            elements = (elements && typeOf(result) == 'element');
        }
        // return (elements) ? $(results) : results;
        return (elements) ? $(results) : results[0]; //jquery return the first element's value
    };
    $.implement(obj);
});

if (!Browser.Element) {
    Element.parent = Object;

    Element.Prototype = {
        '$constructor': Element,
        '$family': Function.from('element').hide()
    };

    Element.mirror(function(name, method) {
        Element.Prototype[name] = method;
    });
}

//------

// Define a local copy of $
var $ = function(selector, context) {
    return new $.fn.init(selector, context);
}

$.prototype = {
    length: 0
};

$.fn = $.prototype;
$.implement({
    constructor: $,
    length: 0,
    // Start with an empty selector
    selector: "",

    init: function(selector, context) {

        if (null == selector) {
            this.length = 0;
            return this;
        }

        // A simple way to check for HTML strings
        // Prioritize #id over <tag> to avoid XSS via location.hash (#9521)
        // Strict HTML recognition (#11290: must start with <)
        var rquickExpr = /^(?:(<[\w\W]+>)[^>]*|#([\w-]*))$/;
        // Match a standalone tag
        var rsingleTag = /^<(\w+)\s*\/?>(?:<\/\1>|)$/;
        // Handle HTML strings
        if (typeof selector === "string") {
            if (selector.charAt(0) === "<" && selector.charAt(selector.length - 1) === ">" && selector.length >= 3) {
                // Assume that strings that start and end with <> are HTML and skip the regex check
                match = [null, selector, null];

                // HANDLE: $(html) -> $(array)
                if (match[1]) {
                    context = context instanceof $ ? context[0] : context;

                    // scripts is true for back-compat
                    $.merge(this, $.parseHTML(
                        match[1],
                        context && context.nodeType ? context.ownerDocument || context : document,
                        true
                    ));

                    // HANDLE: $(html, props)
                    if (rsingleTag.test(match[1]) && $.isPlainObject(context)) {
                        for (match in context) {
                            // Properties of context are called as methods if possible
                            if ($.isFunction(this[match])) {
                                this[match](context[match]);

                                // ...and otherwise set as attributes
                            } else {
                                this.attr(match, context[match]);
                            }
                        }
                    }
                    return this;
                }
            } else if (!context || context instanceof $) {
                // HANDLE: $(expr, $(...))
                return $(Sizzle(selector, context));
            } else {
                // HANDLE: $(expr, context)
                // (which is just equivalent to: $(context).find(expr)
                return $(context).find(selector);
            }
        }

        // Handle $(DOMElement)
        if (selector.nodeType || window == selector) {
            this.context = this[0] = selector;
            this.length = 1;
            return this;
        }

        if (Type.isFunction(selector)) {
            var s = $(document);
            return s.ready ? s.ready(selector) : s;
        }

        var elems = [];
        if (typeOf(selector) === 'array') {
            //selector is a array itself
            elems = selector;
        } else {
            this.selector = selector;
            elems = Sizzle(selector, context);
        }
        // elems.__proto__ = $.fn;
        // return elems;

        for (var i = 0; i < elems.length; i++) {
            this.push(new Element(elems[i]));
        };
    }
});


//make $ looks like an Array
Array.makeArrayLike($);

$.fn.init.prototype = $.fn;

this.$ = $;

(function() {

    var collected = {},
        storage = {};
    var UIDX = 0;
    var get = function(uid) {
        return (storage[uid] || (storage[uid] = {}));
    };
    var uidOf = function(el) {
        return el.uniqueNumber || (el.uniqueNumber = UIDX++);
    };

    [Element, Window, Document].invoke('implement', {
        retrieve: function(property, dflt) {
            var _storage = get(uidOf(this)),
                prop = _storage[property];
            if (dflt != null && prop == null) prop = _storage[property] = dflt;
            return prop != null ? prop : null;
        },

        store: function(property, value) {
            var _storage = get(uidOf(this));
            _storage[property] = value;
            return this;
        },

        eliminate: function(property) {
            var _storage = get(uidOf(this));
            delete _storage[property];
            return this;
        }

    });
})();

(function() {
    Element.implement({
        getWindow: function() {
            return this.ownerDocument.window;
        },
        getDocument: function() {
            return this.ownerDocument;
        }
    });
})();