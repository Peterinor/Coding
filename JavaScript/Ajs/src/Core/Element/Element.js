/*
---

name: Element

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Browser, Array, Function, Number, String, Object, Number, Sizzle]
provides: [Element, Elements, $]

...
*/

var Element = this.Element = function(tag, props) {
    var el;
    if (typeOf(tag) == 'element') el = tag;
    else el = Sizzle(tag)[0];
    //for ie7
    if (Browser.name == 'ie' && Browser.version == '7') {
        var fireEvent = el.fireEvent;
        el._fireEvent = function(type, event) {
            return fireEvent(type, event);
        };
        Object.append(el, Element.Prototype);
    }
    return el;
};


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

$.fn = $.prototype = {
    constructor: $,
    length: 0,
    // Start with an empty selector
    selector: "",

    init: function(selector, context) {

        // Handle $(DOMElement)
        if (selector.nodeType) {
            this.context = this[0] = selector;
            this.length = 1;
            return this;
        }

        var elems = [];
        if (typeOf(selector) === 'array') {
            //selector is a array itself
            elems = selector;
        } else {
            this.selector = selector;
            elems = Sizzle(selector, context);
        }

        for (var i = 0; i < elems.length; i++) {
            this.__push(new Element(elems[i]));
        };
    },

    __push: function() {
        var length = this.length;
        for (var i = 0, l = arguments.length; i < l; i++) {
            var item = arguments[i];
            if (item) this[length++] = item;
        }
        return (this.length = length);
    }.protect()
};

$.fn.init.prototype = $.fn;

this.$ = $;

(function() {

    var collected = {}, storage = {};
    var UIDX = 0;
    // var uidName = 'Ajs-data-uid';
    var get = function(uid) {
        return (storage[uid] || (storage[uid] = {}));
    };
    var uidOf = function(el) {
        // var id = el.getAttribute(uidName);
        // if (!id) {
        //     var uid = UIDX++;
        //     el.setAttribute(uidName, uid);
        //     return uid;
        // }
        // return id;
        return el.uniqueNumber || (el.uniqueNumber = UIDX++);
    }

    // var clean = function(item) {
    //     var uid = item.uniqueNumber;
    //     if (item.removeEvents) item.removeEvents();
    //     if (item.clearAttributes) item.clearAttributes();
    //     if (uid != null) {
    //         delete collected[uid];
    //         delete storage[uid];
    //     }
    //     return item;
    // };

    Element.implement({

        retrieve: function(property, dflt) {
            var storage = get(uidOf(this)),
                prop = storage[property];
            if (dflt != null && prop == null) prop = storage[property] = dflt;
            return prop != null ? prop : null;
        },

        store: function(property, value) {
            var storage = get(uidOf(this));
            storage[property] = value;
            return this;
        },

        eliminate: function(property) {
            var storage = get(uidOf(this));
            delete storage[property];
            return this;
        }
    });

    [Element, Window, Document].invoke('implement', {

        addListener: function(type, fn) {
            if (window.attachEvent && !window.addEventListener) {
                collected[uidOf(this)] = this;
            }
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

    // /*<ltIE9>*/
    // if (window.attachEvent && !window.addEventListener) {
    //     var gc = function() {
    //         Object.each(collected, clean);
    //         if (window.CollectGarbage) CollectGarbage();
    //         window.removeListener('unload', gc);
    //     }
    //     window.addListener('unload', gc);
    // }
    // /*</ltIE9>*/

})();


(function() {

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

    Element.implement({
        getWindow: function() {
            return this.ownerDocument.window;
        },
        getDocument: function() {
            return this.ownerDocument;
        }
    })
})();