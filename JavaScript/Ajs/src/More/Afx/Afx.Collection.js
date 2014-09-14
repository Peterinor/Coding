/*
---

name: Afx.Collection

description: Afx.Collection

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
Array.makeArrayLike(Collection);

var Collection = Afx.Collection = new Class({
    Implements: Events,
    Extends: Collection
});

Collection.implement({
    toJSON: function(){
        return this.map(function(m, ind){
            return m.toJSON();
        })
    }
});