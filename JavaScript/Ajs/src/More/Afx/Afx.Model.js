/*
---

name: Afx.Model

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Array, Function, Number, String, Object, Number]
provides: [Afx.Model]

...
*/


Afx.Model = new Class({
    initialize: function(o) {
        console.log('model' + o);
    }
});


Afx.User = new Class({

    Extends: Afx.Model,

    initialize: function(o) {
        console.log('user' + o);
        this._super(o);
    }
})