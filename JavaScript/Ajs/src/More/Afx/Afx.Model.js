/*
---

name: Afx.Model

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Afx.ObjectObservable]
provides: [Afx.Model]

...
*/

var Model = Afx.Model = new Class({
    Extends: ObjectObservable
});


Afx.User = new Class({
    Extends: Model,

    initialize: function(name, age) {
        this.set({
            name: name,
            age: age
        });
    }
});