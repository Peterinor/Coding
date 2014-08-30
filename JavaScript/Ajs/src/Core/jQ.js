/*
---

name: jQ

description: jQuery compatible API

requires: [Element, Element.Attribute, Element.Style, Element.Event]
provides: [jQuery]

...
*/

//For jQuery API compact
Element.implement({

    removeData: function(prop) {
        return this.eliminate(prop);
    },

    data: function(prop, value) {
        return value ? this.store(prop, value) : this.retrieve(prop);
    }
});

//For jQuery API compact
Element.implement({
    css: function(property, value) {
        switch (typeOf(property)) {
            case 'object':
                this.setStyles(property);
                break;
            case 'string':
                if (value) this.setStyle(property, value)
                else return this.getStyle(property);
        }
        return this;
    }
});

// Save a reference to some core methods
core_push = Array.prototype.push,
core_slice = Array.prototype.slice,
core_indexOf = Array.prototype.indexOf,
core_toString = Object.prototype.toString,
core_hasOwn = Object.prototype.hasOwnProperty,
core_trim = String.prototype.trim;


var $ = this.$;

// Map over the $ in case of overwrite
var _$$ = window.jQuery;
var _$ = window.$;

window.$ = $;

this.$.extend({
    noConflict: function(deep) {
        if (window.$ === this.$) {
            window.$ = _$;
        }

        if (deep && window.jQuery === $) {
            window.jQuery = _$$;
        }

        return $;
    },

    each: function() {

    },

    isFunction: function(obj) {
        return $.type(obj) === "function";
    },

    isArray: Array.isArray || function(obj) {
        return $.type(obj) === "array";
    },

    isWindow: function(obj) {
        return obj != null && obj == obj.window;
    },

    isNumeric: function(obj) {
        return !isNaN(parseFloat(obj)) && isFinite(obj);
    },

    type: function(obj) {
        return Ajs.typeOf(obj);
    },

    isEmptyObject: function(obj) {
        var name;
        for (name in obj) {
            return false;
        }
        return true;
    },

    error: function(msg) {
        throw new Error(msg);
    },
    trim: function(v) {
        return String(v).trim();
    }
});


this.$.implement({
    // The number of elements contained in the matched element set
    size: function() {
        return this.length;
    },

    toArray: function() {
        // return Array.from(this);
    },

    // Get the Nth element in the matched element set OR
    // Get the whole matched element set as a clean array
    get: function(num) {
        return num == null ?
            this.toArray() :
            (num < 0 ? this[this.length + num] : this[num]);
    },

    // // Take an array of elements and push it onto the stack
    // // (returning the new matched element set)
    // pushStack: function(elems, name, selector) {

    //     // Build a new jQuery matched element set
    //     var ret = jQuery.merge(this.constructor(), elems);

    //     // Add the old object onto the stack (as a reference)
    //     ret.prevObject = this;

    //     ret.context = this.context;

    //     if (name === "find") {
    //         ret.selector = this.selector + (this.selector ? " " : "") + selector;
    //     } else if (name) {
    //         ret.selector = this.selector + "." + name + "(" + selector + ")";
    //     }

    //     // Return the newly-formed element set
    //     return ret;
    // },

    // // Execute a callback for every element in the matched set.
    // // (You can seed the arguments with an array of args, but this is
    // // only used internally.)
    // each: function(callback, args) {
    //     return jQuery.each(this, callback, args);
    // },

    // ready: function(fn) {
    //     // Add the callback
    //     jQuery.ready.promise().done(fn);

    //     return this;
    // },

    eq: function(i) {
        return $(this.get(i));
    },

    first: function() {
        return this.eq(0);
    },

    last: function() {
        return this.eq(-1);
    }

    // map: function(callback) {
    //     return this.pushStack(jQuery.map(this, function(elem, i) {
    //         return callback.call(elem, i, elem);
    //     }));
    // },

    // end: function() {
    //     return this.prevObject || this.constructor(null);
    // },   
    // // // For internal use only.
    // // // Behaves like an Array's method, not like a jQuery method.
    // // push: core_push,
    // // sort: [].sort,
    // // splice: [].splice
});


$.implement({
    find: function(selector, util) {
        var t = $();
        t.selector = this.selector + ' ' + selector;
        for (var i = 0, l = this.length; i < l; i++) {
            // console.log(Array.from($(selector, this[i])));
            // t.push.apply(t, Array.from($(selector, this[i])));
            // t.push(Array.from($(selector, this[i])));
            Array.prototype.push.apply(t, Array.from($(selector, this[i])));
            // t.__push($(selector, this[i]));
        };
        return t;
    }
})

//Event
$.implement({
    on: function(type, fn) {
        return this.addEvent(type, fn);
    }.overloadSetter(),

    off: function(type, fn) {
        return this.removeEvent(type, fn);
    }.overloadSetter()
})