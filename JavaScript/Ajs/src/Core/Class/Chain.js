/*
---

name: Chain

description: the Chain Class

requires: [Class]

provides: [Chain]

...
*/

var Chain = this.Chain = new Class({

    $chain: [],

    chain: function() {
        this.$chain.append(Array.flatten(arguments));
        return this;
    },

    callChain: function() {
        return (this.$chain.length) ? this.$chain.shift().apply(this, arguments) : false;
    },

    clearChain: function() {
        this.$chain.empty();
        return this;
    }

});
