/*
---

name: Element

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Browser, Array, Function, Number, String, Object, Number, Sizzle]
provides: [Element, Elements, $]

...
*/

var Element = this.Element = function(tag, props) {
    // var _Element = function() {};
    // var el = jQuery(tag).attr(props || {});
    if (typeOf(tag) == 'element') return tag;
    var el = Sizzle(tag)[0];
    // _Element.prototype = el;
    // var _el = new _Element();
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
            var element = this[i],
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
// Save a reference to some core methods
core_push = Array.prototype.push,
core_slice = Array.prototype.slice,
core_indexOf = Array.prototype.indexOf,
core_toString = Object.prototype.toString,
core_hasOwn = Object.prototype.hasOwnProperty,
core_trim = String.prototype.trim;

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
            this.__push(elems[i]);
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
    var uidName = 'Ajs-data-uid';
    var get = function(uid) {
        return (storage[uid] || (storage[uid] = {}));
    };
    var uidOf = function(el) {
        var id = el.getAttribute(uidName);
        if (!id) {
            var uid = UIDX++;
            el.setAttribute(uidName, uid);
            return uid;
        }
        return id;
    }

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

})();


(function() {

    Document.implement({
        id: function(el) {
            if (typeOf(el) == 'string') {
                if (el.indexOf('#') == -1) {
                    el = '#' + el;
                }
            }
            return Sizzle(el)[0];
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