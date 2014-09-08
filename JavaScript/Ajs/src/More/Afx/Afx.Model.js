/*
---

name: Afx.Model

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Afx.ObjectObservable]
provides: [Afx.Model]

...
*/

var Model = Afx.Model = new Class({

    Extends: ObjectObservable,

    initialize: function(attr, options) {
        this._super(attr, options);
    },

    //override set method of ObjectObservable
    //options.validate, options.silent, options.unset
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

        if (!this._validate(attrs, options)) return false;
        this._set(attrs, options);
    },

    _validate: function(attrs, options) {
        if (!options.validate) return true;
        attrs = Ajs.extend(this.toJSON(), attrs);
        if (this.validate) {
            var error = this.validationError = this.validate(attrs, options) || null;
            // if (!error) return true;
            if (error) {
                this.trigger('invalid', error);
                return false;
            }
        }
        for (var key in attrs) {
            var __validates = this.__validates[key];
            if (__validates) {
                for (var i = 0, l = __validates.length; i < l; i++) {
                    var v = __validates[i];
                    var error = this.validationError = v(attrs[key], key);
                    if (error) {
                        this.trigger('invalid', error);
                        return false;
                    }
                };
            }
        }
        return true;
    },

    __validates: {},

    //validate = function(attrs)    --  !!deprecated
    //prop = name, validate = function(val, key)
    addValidates: function(prop, validates) {
        if (Type.isFunction(prop)) {
            this.validate = prop;
            return this;
        }
        (function(prop, validates) {
            var vs = this.__validates[prop] || (this.__validates[prop] = []);
            vs.push(validates);
        }.overloadSetter()).apply(this, [prop, validates]);
    },

    removeValidates: function(prop, validate) {
        //remove all validates
        if (!prop) {
            delete this.validate;
            delete this.__validates;
            this.__validates = {};
            return this;
        }
        //remove all validates for prop
        if (!validate) {
            delete this.__validates[prop];
            return this;
        }
        var validates = this.__validates[prop];
        if (validates) {
            var ind = validates.indexOf(validate);
            ind == -1 || validates.remove(ind);
        }
        return this;
    }

});