/*
---

name: jQ

description: jQuery compatible API

requires: [Element, Element.Attribute, Element.Style, Element.Event, DOMReady]
provides: [jQuery]

attributes, callback, core, css, data, deferred, deprecated, dimensions, effect, event
export, manipulation, offset, queue, serialize, support, traversing, ajax
...
*/

/*****   jQuery Export  *****/
var _$$ = window.jQuery;
var _$ = window.$;
window.jQuery = window.$ = this.$;

this.$.extend({
    noConflict: function(deep) {
        if (window.$ === this.$) {
            window.$ = _$;
        }

        if (deep && window.jQuery === this.$) {
            window.jQuery = _$$;
        }

        return Ajs.$;
    }
});


(function($) {

    $.extend({

        Callbacks: Ajs.Callbacks,

        Deferred: Ajs.Deferred,

        when: Ajs.when,

        extend: Ajs.extend,

        proxy: function(fn, ctx) {
            if ($.type(ctx) == 'string') {
                var tmp = fn;
                fn = fn[ctx];
                arguments[1] = ctx = tmp;
            }
            if (!this.isFunction(fn)) {
                return undefined;
            }
            return Function.prototype.bind.apply(fn, Array.from(arguments).slice(1));
        },

        each: Ajs.each,

        isFunction: Ajs.Type.isFunction,

        isArray: Ajs.Type.isArray,

        isWindow: function(obj) {
            return obj != null && obj == obj.window;
        },

        isNumeric: Ajs.Type.isNumeric,

        type: Ajs.typeOf,

        isPlainObject: Ajs.Type.isPlainObject,

        isEmptyObject: Ajs.Type.isEmptyObject,

        inArray: function(val, arr, from) {
            if (this.isArray(arr)) {
                return arr.indexOf(val, from);
            }
            return -1;
        },

        error: function(msg) {
            throw new Error(msg);
        },

        trim: function(v) {
            if (v === null || v === undefined) {
                return "";
            }
            return String(v).trim();
        },

        merge: function(first, second) {
            if (this.isArray(first)) {
                var ret = Array.from(first);
                ret.append(second);
                return ret;
            }
            //just array like
            var i = first.length;
            var j = 0;
            while (second[j] !== undefined) {
                first[i++] = second[j++];
            }
            first.length = i;
            return first;
        },

        grep: function(elems, callback, inv) {
            var retVal,
                ret = [],
                i = 0,
                length = elems.length;
            inv = !! inv;

            // Go through the array, only saving the items
            // that pass the validator function
            for (; i < length; i++) {
                retVal = !! callback(elems[i], i);
                if (inv !== retVal) {
                    ret.push(elems[i]);
                }
            }

            return ret;
        },

        // arg is for internal usage only
        map: function(elems, callback, arg) {

        }
    });


    $.implement({
        // The number of elements contained in the matched element set
        size: function() {
            return this.length;
        },

        toArray: function() {
            return Array.from(this);
        },

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
})(this.$);


/*****   EVENTS   *****/
(function($) {

    // DOM Load
    $.implement('ready', function(fn) {
        window.addEvent('domready', fn);
        return this;
    });

    $.implement({

        bind: function(type, fn) {
            type.split(' ').each(function(event) { // accepts multiple event types!
                this.on(event, fn);
            }, this);
            return this;
        },

        unbind: function(type, fn) {
            return this.off(type, fn);
        },

        one: function(type, fn) {
            // TODO: Make this cleaner. Looks like a hack now.
            var removeOne = function() {
                this.off(type, fn).off(type, removeOne);
            }
            return this.on(type, fn).on(type, removeOne);
        },

        triggerHandler: function() {

        },

        delegate: function() {

        },

        undelegate: function() {

        }
    });

    (function(types) {
        var methods = {};
        types.each(function(name) {

            methods[name] = function(data, fn) {
                if (fn == null) {
                    fn = data;
                    data = null;
                }

                return arguments.length > 0 ?
                    this.on(name, fn) :
                    this.trigger(name);
            };
        });

        $.implement(methods);

    })(("blur focus focusin focusout resize click dblclick load scroll unload " +
        "mousedown mouseup mousemove mouseover mouseout mouseenter mouseleave " +
        "change select submit keydown keypress keyup error contextmenu").split(" "));

    [Element, Document, Window].invoke('implement', {
        hover: function(fnOver, fnOut) {
            return this.addEvents({
                'mouseenter': fnOver,
                'mouseleave': fnOut
            });
        }
    });
})(Ajs.$);


/*****   Data   *****/
(function(Ajs) {
    Ajs.Element.implement({

        removeData: function(prop) {
            return this.eliminate(prop);
        },

        data: function(prop, value) {
            return value ? this.store(prop, value) : this.retrieve(prop);
        }
    });

})(Ajs);

/*****   ATTR   *****/
(function(Ajs) {
    Ajs.Element.implement({
        // ATTR
        attr: function(prop, value) {
            switch ($type(prop)) {
                case 'object':
                    this.set(prop);
                    break;
                case 'string':
                    if (value) {
                        // Note: first attempt() arg is supposed to be index of elements array, but can't be done in Mootools
                        if ($type(value) == 'function') value = value.attempt(this, this);
                        this.set(prop, value)
                    } else return this.get(prop);
            }
            return this;
        },

        // HTML
        html: function(value) {
            return value ? this.setter('html', value) : this.getter('html');
        },

        // Text
        text: function(text) {
            return text ? this.setter('text', text) : this.getter('text');
        },

        // Value
        val: function(value) {
            // Note: Array type value not implemented
            return value ? this.setter('value', value) : this.getter('value');
        }
    });
})(Ajs);

/*****   CSS   *****/
(function(Ajs) {
    Ajs.Element.implement({
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
})(Ajs);


(function($) {
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
    });
})($);



/*****   AJAX   *****/
// Ajax Request

$.extend({

    ajax: function(options) {
        var request;
        options.method = options.type || options.method || 'get'; // default is 'get' for jQuery
        if (options.complete) options.onComplete = options.complete;
        if (options.error) options.onFailure = options.error;
        if (options.success) options.onSuccess = options.success;
        if (options.dataType && options.dataType == 'html' && Request.HTML) request = new Request.HTML(options);
        else if (options.dataType && options.dataType == 'json' && Request.JSON) request = new Request.JSON(options);
        else request = new Request(options);
        if (options.timeout) request.cancel.delay(options.timeout);
        return request.send();
    },

    get: function(url, data, fn, type) {
        if (typeOf(data) == 'function') {
            fn = data;
            data = null;
        }
        var request;
        var options = {
            url: url,
            data: data,
            onSuccess: fn,
            dataType: type
        };
        return this.ajax(options);
    },

    getJSON: function(url, data, fn) {
        return this.get(url, data, fn, 'json');
    },

    post: function(url, data, fn, type) {
        if (typeOf(data) == 'function') {
            fn = data;
            data = null;
        }
        var request;
        var options = {
            method: 'post',
            url: url,
            data: data,
            onSuccess: fn,
            dataType: type
        };
        return this.ajax(options);
    }

});