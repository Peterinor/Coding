/*
---

name: Afx.View

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Options, Afx.Observable]
provides: [Afx.View]

...
*/
var delegateEventSplitter = /^(\S+)\s*(.*)$/;
// var viewOptions = ['model', 'collection', 'el', 'id', 'attributes', 'className', 'tagName', 'events'];

var View = Afx.View = new Class({

    Implements: Options,

    tagName: 'div',

    // initialization logic.
    initialize: function(options) {
        this.cid = Ajs.simpleUID('v');

        // Object.subset
    },

    render: function() {
        return this;
    },

    remove: function() {
        this.$el.remove();
        this.stopListening();
        return this;
    },

    $: function(selector) {
        return this.$el.find(selector);
    },

    delegateEvents: function(events) {},
    undelegateEvents: function() {
        this.$el.off('.delegateEvents' + this.cid);
        return this;
    },
});