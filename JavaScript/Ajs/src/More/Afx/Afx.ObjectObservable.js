/*
---

name: Afx.ObjectObservable

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Options, Afx.Observable]
provides: [Afx.ObjectObservable]

...
*/

var ObjectObservable = Afx.ObjectObservable = new Class({

    Implements: [Observable, Options],

    initialize: function(obj, options) {
        this.cid = Ajs.simpleUID('m');
        this.attributes = {};

        this.setOptions(options);

        this.set(obj, options);
    },

    toJSON: function() {
        return Object.clone(this.attributes);
    },

    has: function(attr) {
        return this.get(attr) != null;
    },

    get: function(attr) {
        return this.attributes[attr];
    },

    //options.silent
    set: function(key, value, options) {
        var attrs;
        if (!key) return this;
        if (Type.isObject(key)) {
            attrs = key;
            options = value;
        } else {
            (attrs = {})[key] = value;
        }
        options || (options = {});

        this._set(attrs, options);
    },

    _set: function(attrs, options) {
        var silent = options.silent;
        var current = this.toJSON();
        var changes = [];
        for (var key in attrs) {
            var v = attrs[key];
            if (current[key] != v) {
                this.attributes[key] = v;
                changes.push(key);
            }
        }
        if (!silent) {
            for (var i = 0, l = changes.length; i < l; i++) {
                var key = changes[i];
                this.trigger('change:' + key, {
                    from: current[key],
                    to: this.get(key)
                });
            };

            this.trigger('changes', attrs);
        }
    }

});