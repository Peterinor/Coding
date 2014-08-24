
/*
---

name: Element.Event

description: Contains Element methods for dealing with events. This file also includes mouseenter and mouseleave custom Element Events, if necessary.

license: MIT-style license.

requires: [Element, Event]

provides: [Element.Event]

...
*/


Element.Properties.events = {set: function(events){
    this.addEvents(events);
}};

[Element, Window, Document].invoke('implement', {

    addEvent: function(type, fn){
        $(this).on(type, fn);
        return this;
    },

    removeEvent: function(type, fn){
        $(this).off(type,fn);
        return this;
    },

    addEvents: function(events){
        $(this).on(events);
        return this;
    },

    removeEvents: function(events){
        $(this).off(events);
        return this;
    },

    fireEvent: function(type, args, delay){
        if(delay){
            $(this).delay(delay).trigger(type, args);
        }else{
            $(this).trigger(type, args)
        }
        return this;
    }
});

// Element.NativeEvents = {
//     click: 2, dblclick: 2, mouseup: 2, mousedown: 2, contextmenu: 2, //mouse buttons
//     mousewheel: 2, DOMMouseScroll: 2, //mouse wheel
//     mouseover: 2, mouseout: 2, mousemove: 2, selectstart: 2, selectend: 2, //mouse movement
//     keydown: 2, keypress: 2, keyup: 2, //keyboard
//     orientationchange: 2, // mobile
//     touchstart: 2, touchmove: 2, touchend: 2, touchcancel: 2, // touch
//     gesturestart: 2, gesturechange: 2, gestureend: 2, // gesture
//     focus: 2, blur: 2, change: 2, reset: 2, select: 2, submit: 2, paste: 2, input: 2, //form elements
//     load: 2, unload: 1, beforeunload: 2, resize: 1, move: 1, DOMContentLoaded: 1, readystatechange: 1, //window
//     hashchange: 1, popstate: 2, // history
//     error: 1, abort: 1, scroll: 1 //misc
// };

// Element.Events = {
//     mousewheel: {
//         base: 'onwheel' in document ? 'wheel' : 'onmousewheel' in document ? 'mousewheel' : 'DOMMouseScroll'
//     }
// };

// var check = function(event){
//     var related = event.relatedTarget;
//     if (related == null) return true;
//     if (!related) return false;
//     return (related != this && related.prefix != 'xul' && typeOf(this) != 'document' && !this.contains(related));
// };

// if ('onmouseenter' in document.documentElement){
//     Element.NativeEvents.mouseenter = Element.NativeEvents.mouseleave = 2;
//     Element.MouseenterCheck = check;
// } else {
//     Element.Events.mouseenter = {
//         base: 'mouseover',
//         condition: check
//     };

//     Element.Events.mouseleave = {
//         base: 'mouseout',
//         condition: check
//     };
// }

// /*<ltIE9>*/
// if (!window.addEventListener){
//     Element.NativeEvents.propertychange = 2;
//     Element.Events.change = {
//         base: function(){
//             var type = this.type;
//             return (this.get('tag') == 'input' && (type == 'radio' || type == 'checkbox')) ? 'propertychange' : 'change';
//         },
//         condition: function(event){
//             return event.type != 'propertychange' || event.event.propertyName == 'checked';
//         }
//     };
// }
// /*</ltIE9>*/
