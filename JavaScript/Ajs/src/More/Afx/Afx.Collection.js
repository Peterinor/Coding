/*
---

name: Afx.Collection

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Afx]
provides: [Afx.Collection]

...
*/

var Collection = function() {}

Collection.implement({

    length: 0,

    model: Model,

    initialize: function() {}

});

//make Collection looks like an Array
Array.forEachMethod(function(method, name) {
    Collection.implement(name, method);
});

Array.mirror(Collection);

var Collection = Afx.Collection = new Class({
    Implements: Events,
    Extends: Collection
});


Collection.implement({

});