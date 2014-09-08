/*
---

name: Element.Event

description: Contains Element methods for dealing with events. This file also includes mouseenter and mouseleave custom Element Events, if necessary.

requires: [Element, DOMEvent]

provides: [Element.Event]

...
*/


[Element, Window, Document].invoke('implement', {

    addEvent: function(type, fn, data) {
        var events = this.retrieve('events', {});
        if (!events[type]) events[type] = {
            keys: [],
            values: []
        };
        if (events[type].keys.contains(fn)) return this;
        events[type].keys.push(fn);
        var realType = type,
            custom = Element.Events[type],
            condition = fn,
            self = this;
        if (custom) {
            if (custom.onAdd) custom.onAdd.call(this, fn, type);
            if (custom.condition) {
                condition = function(event) {
                    if (custom.condition.call(this, event, type)) return fn.call(this, event);
                    return true;
                };
            }
            if (custom.base) realType = Function.from(custom.base).call(this, type);
        }
        var defn = function() {
            return fn.call(self);
        };
        var nativeEvent = Element.NativeEvents[realType];
        if (nativeEvent) {
            if (nativeEvent == 2) {
                defn = function(event) {
                    event = new DOMEvent(event, self.getWindow(), data);
                    if (condition.call(self, event) === false) event.stop();
                };
            }
            this.addListener(realType, defn, arguments[3]);
        }
        events[type].values.push(defn);
        return this;
    },

    removeEvent: function(type, fn) {
        var events = this.retrieve('events');
        if (!events || !events[type]) return this;
        var list = events[type];
        var index = list.keys.indexOf(fn);
        if (index == -1) return this;
        var value = list.values[index];
        delete list.keys[index];
        delete list.values[index];
        var custom = Element.Events[type];
        if (custom) {
            if (custom.onRemove) custom.onRemove.call(this, fn, type);
            if (custom.base) type = Function.from(custom.base).call(this, type);
        }
        return (Element.NativeEvents[type]) ? this.removeListener(type, value, arguments[2]) : this;
    },

    addEvents: function(events) {
        for (var event in events) this.addEvent(event, events[event]);
        return this;
    },

    removeEvents: function(events) {
        var type;
        if (typeOf(events) == 'object') {
            for (type in events) this.removeEvent(type, events[type]);
            return this;
        }
        var attached = this.retrieve('events');
        if (!attached) return this;
        if (!events) {
            for (type in attached) this.removeEvents(type);
            this.eliminate('events');
        } else if (attached[events]) {
            attached[events].keys.each(function(fn) {
                this.removeEvent(events, fn);
            }, this);
            delete attached[events];
        }
        return this;
    },

    fireEvent: function(type, args, delay) {
        var events = this.retrieve('events');
        if (!events || !events[type]) return this;
        args = Array.from(args);

        events[type].keys.each(function(fn) {
            if (delay) fn.delay(delay, this, args);
            else fn.apply(this, args);
        }, this);
        return this;
    },

    cloneEvents: function(from, type) {
        from = document.id(from);
        var events = from.retrieve('events');
        if (!events) return this;
        if (!type) {
            for (var eventType in events) this.cloneEvents(from, eventType);
        } else if (events[type]) {
            events[type].keys.each(function(fn) {
                this.addEvent(type, fn);
            }, this);
        }
        return this;
    }

});


Element.NativeEvents = {
    click: 2,
    dblclick: 2,
    mouseup: 2,
    mousedown: 2,
    contextmenu: 2, //mouse buttons
    mousewheel: 2,
    DOMMouseScroll: 2, //mouse wheel
    mouseover: 2,
    mouseout: 2,
    mousemove: 2,
    selectstart: 2,
    selectend: 2, //mouse movement
    keydown: 2,
    keypress: 2,
    keyup: 2, //keyboard
    orientationchange: 2, // mobile
    touchstart: 2,
    touchmove: 2,
    touchend: 2,
    touchcancel: 2, // touch
    gesturestart: 2,
    gesturechange: 2,
    gestureend: 2, // gesture
    focus: 2,
    blur: 2,
    change: 2,
    reset: 2,
    select: 2,
    submit: 2,
    paste: 2,
    input: 2, //form elements
    load: 2,
    unload: 1,
    beforeunload: 2,
    resize: 1,
    move: 1,
    DOMContentLoaded: 1,
    readystatechange: 1, //window
    hashchange: 1,
    popstate: 2, // history
    error: 1,
    abort: 1,
    scroll: 1 //misc
};

Element.Events = {
    mousewheel: {
        base: 'onwheel' in document ? 'wheel' : 'onmousewheel' in document ? 'mousewheel' : 'DOMMouseScroll'
    }
};

var check = function(event) {
    var related = event.relatedTarget;
    if (related == null) return true;
    if (!related) return false;
    return (related != this && related.prefix != 'xul' && typeOf(this) != 'document' && !this.contains(related));
};

if ('onmouseenter' in document.documentElement) {
    Element.NativeEvents.mouseenter = Element.NativeEvents.mouseleave = 2;
    Element.MouseenterCheck = check;
} else {
    Element.Events.mouseenter = {
        base: 'mouseover',
        condition: check
    };

    Element.Events.mouseleave = {
        base: 'mouseout',
        condition: check
    };
}

/*<ltIE9>*/
if (!window.addEventListener) {
    Element.NativeEvents.propertychange = 2;
    Element.Events.change = {
        base: function() {
            var type = this.type;
            return (this.get('tag') == 'input' && (type == 'radio' || type == 'checkbox')) ? 'propertychange' : 'change';
        },
        condition: function(event) {
            return event.type != 'propertychange' || event.event.propertyName == 'checked';
        }
    };
}
/*</ltIE9>*/


(function() {

    [Element, Document, Window].invoke('implement', {

        on: function(types, selector, data, fn, /*INTERNAL*/ one) {
            var origFn, type;

            // Types can be a map of types/handlers
            if (typeof types === "object") {
                // ( types-Object, selector, data )
                if (typeof selector !== "string") {
                    // ( types-Object, data )
                    data = data || selector;
                    selector = undefined;
                }
                for (type in types) {
                    this.on(type, selector, data, types[type], one);
                }
                return this;
            }

            if (data == null && fn == null) {
                // ( types, fn )
                fn = selector;
                data = selector = undefined;
            } else if (fn == null) {
                if (typeof selector === "string") {
                    // ( types, selector, fn )
                    fn = data;
                    data = undefined;
                } else {
                    // ( types, data, fn )
                    fn = data;
                    data = selector;
                    selector = undefined;
                }
            }
            if (fn === false) {
                fn = Function.returnFalse;
            } else if (!fn) {
                return this;
            }

            if (selector) {
                var _fn = function(event) {
                    event.delegateTarget = this;
                    var target = event.target;
                    event.handleObj = {
                        selector: selector,
                        handler: fn
                    };
                    if (Sizzle.matches(selector, [target]).length) {
                        if (one == 1) {
                            this.off(event);
                        }
                        fn.apply(this, arguments);
                    }
                }
                var de = this.retrieve('delegate_events') || (this.store('delegate_events', {})).retrieve('delegate_events');
                de[selector] = (de[selector] || (de[selector] = []));
                de[selector].push({
                    e: _fn,
                    oe: fn
                });
                return this.addEvent(types, _fn, data);
            }

            if (one === 1) {
                origFn = fn;
                fn = function(event) {
                    event.handleObj = {
                        selector: selector,
                        handler: fn
                    };
                    // Can use an empty set, since event contains the info
                    this.off(event);
                    return origFn.apply(this, arguments);
                };
            }
            return this.addEvent(types, fn, data);
        },

        off: function(types, selector, fn) {
            if (typeOf(types) == 'domevent') {
                handleObj = types.handleObj;
                types = types.type;
                if (handleObj) {
                    selector = handleObj.selector;
                    fn = handleObj.handler;
                }
            }

            if (typeof types === "object") {
                // ( types-object [, selector] )
                for (var type in types) {
                    this.off(type, selector, types[type]);
                }
                return this;
            }
            if (selector === false || typeof selector === "function") {
                // ( types [, fn] )
                fn = selector;
                selector = undefined;
            }
            if (fn === false) {
                fn = Function.returnFalse;
            }
            if (selector) {
                var de = this.retrieve('delegate_events');
                var hhs = de[selector];
                if (!hhs) {
                    return this;
                }
                if ( !! fn) {
                    hhs = hhs.filter(function(v, i) {
                        return v.oe === fn;
                    });
                }

                hhs.each(function(v, i) {
                    this.removeEvent(types, v.e);
                }, this);
                return this;
            }
            if (!fn) {
                return this.removeEvents(types);
            }
            return this.removeEvent(types, fn);
        },

        trigger: function(event, args) {
            return this.fireEvent(event, args);
        }

    });

    // /*<ltIE9>*/
    // if (window.attachEvent && !window.addEventListener) {
    //     var gc = function() {
    //         Object.each(collected, clean);
    //         if (window.CollectGarbage) CollectGarbage();
    //         window.removeListener('unload', gc);
    //     }
    //     window.addListener('unload', gc);
    // }
    // /*</ltIE9>*/

})();