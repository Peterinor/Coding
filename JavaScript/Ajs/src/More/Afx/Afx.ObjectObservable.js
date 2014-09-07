/*
---

name: Afx.ObjectObservable

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Afx.Observable]
provides: [Afx.ObjectObservable]

...
*/

var _ObjectObservable = function(attr, options) {
    this.cid = Ajs.simpleUID('m');
    this.attributes = {};

    this.set(attr, options);
}

_ObjectObservable.implement({

    toJSON: function() {
        return Object.clone(this.attributes);
    },

    has: function(attr) {
        return this.get(attr) != null;
    },

    get: function(attr) {
        return this.attributes[attr];
    },

    set: function(key, value, options) {
        this.attributes[key] = value;
    }.overloadSetter()

});

var ObjectObservable = Afx.ObjectObservable = new Class({
    Implements: Observable,
    Extends: _ObjectObservable
});
