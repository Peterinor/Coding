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
var eventType = function(type) {
    return type.split('.');
}

var Events = this.Events = new Class({

    $events: {},

    addEvent: function(type, fn, context) {
        var _type = eventType(removeOn(type));
        type = _type[0];
        var namespace = _type[1];
        if (context) {
            fn = function(args) {
                fn.apply(context, Array.from(args));
            }
        }
        if (namespace) {
            fn.namespace = namespace;
        }
        this.$events[type] = (this.$events[type] || []).include(fn);
        return this;
    },

    addEvents: function(events) {
        for (var type in events) this.addEvent(type, events[type]);
        return this;
    },

    fireEvent: function(type, args, delay) {
        var _type = eventType(removeOn(type));
        type = _type[0];
        var namespace = _type[1];

        var events = this.$events[type];
        if (!events) return this;
        args = Array.from(args);
        if (namespace) {
            events.each(function(fn) {
                if (fn.namespace == namespace) {
                    if (delay) fn.delay(delay, this, args);
                    else fn.apply(this, args);
                }
            }, this);
        } else {
            events.each(function(fn) {
                if (delay) fn.delay(delay, this, args);
                else fn.apply(this, args);
            }, this);
        }
        return this;
    },

    removeEvent: function(type, fn) {
        return this.off(type, fn);
    },

    removeEvents: function(events) {
        return this.off(events);
    }

});


Events.implement({
    on: function(type, fn, context) {
        return this.addEvent(type, fn, context);
    }.overloadSetter(),

    off: function(type, fn) {
        var _type = eventType(removeOn(type));
        type = _type[0];
        var namespace = _type[1];

        var events = this.$events[type];
        if (namespace) {
            if (!fn) {
                events.each(function(fn, ind) {
                    if (fn.namespace == namespace && !fn.internal) {
                        delete events[ind];
                    }
                });
                return this;
            }
        } else {
            if (!fn) {
                events.each(function(fn, ind) {
                    if (!fn.internal) {
                        delete events[ind];
                    }
                });
                return this;
            }
            if (events && !fn.internal) {
                var index = events.indexOf(fn);
                if (index != -1) events.remove(index);
            }
        }
        return this;
    }.overloadSetter(),

    one: function(type, fn, context) {
        var self = this;
        var et = function() {
            self.off(type, et);
            fn.apply(this, Array.prototype.slice(arguments));
        }
        return this.on(type, et, context);
    },

    trigger: function(type, data, delay) {
        return this.fireEvent(type, data, delay);
    }
});

var listenMethods = {
    listenTo: 'on',
    listenToOnce: 'one'
};

Object.each(listenMethods, function(attach, listenTo) {
    Events.implement(listenTo, function(obj, type, fn) {
        obj[attach](type, fn, this);
    });
});