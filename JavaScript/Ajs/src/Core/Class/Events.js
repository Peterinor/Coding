/*
---

name: Events

description: Events Class, Use for costom Event.

requires: [Class]

provides: [Events]

...
*/

var removeOn = function(string) {
    return string.replace(/^on([A-Z])/, function(full, first) {
        return first.toLowerCase();
    });
};

var Events = this.Events = new Class({

    $events: {},

    addEvent: function(type, fn, internal) {
        type = removeOn(type);

        this.$events[type] = (this.$events[type] || []).include(fn);
        if (internal) fn.internal = true;
        return this;
    },

    addEvents: function(events) {
        for (var type in events) this.addEvent(type, events[type]);
        return this;
    },

    fireEvent: function(type, args, delay) {
        type = removeOn(type);
        var events = this.$events[type];
        if (!events) return this;
        args = Array.from(args);
        events.each(function(fn) {
            if (delay) fn.delay(delay, this, args);
            else fn.apply(this, args);
        }, this);
        return this;
    },

    removeEvent: function(type, fn) {
        type = removeOn(type);
        var events = this.$events[type];
        if (events && !fn.internal) {
            var index = events.indexOf(fn);
            if (index != -1) delete events[index];
        }
        return this;
    },

    removeEvents: function(events) {
        var type;
        if (typeOf(events) == 'object') {
            for (type in events) this.removeEvent(type, events[type]);
            return this;
        }
        if (events) events = removeOn(events);
        for (type in this.$events) {
            if (events && events != type) continue;
            var fns = this.$events[type];
            for (var i = fns.length; i--;)
                if (i in fns) {
                    this.removeEvent(type, fns[i]);
                }
        }
        return this;
    }

});


Events.implement({
    on: function(type, fn) {
        return this.addEvent(type, fn);
    }.overloadSetter(),

    off: function(type, fn) {
        type = removeOn(type);
        var events = this.$events[type];
        if (!fn) {
            events.empty();
            delete this.$events[type];
            return this;
        }
        if (events && !fn.internal) {
            var index = events.indexOf(fn);
            if (index != -1) events.remove(index);
        }
        return this;
    }.overloadSetter(),

    one: function(type, fn) {
        var self = this;
        var et = function() {
            self.off(type, et);
            fn.apply(this, Array.prototype.slice(arguments));
        }
        return this.on(type, et);
    },

    trigger: function(type, data, delay) {
        return this.fireEvent(type, data, delay);
    }
});
