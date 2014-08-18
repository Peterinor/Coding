
//port for using

jQuery.fn.extend({
    getStyle : function (prop) {
        return this.css(prop);
    },
    setStyle : function(prop, value){
        return this.css(prop, value);
    },
    getStyles : function(props){
        return this.css(props);
    },
    setStyles : function(css){
        return this.css(css);
    }
});


jQuery.fn.extend({

    addEvent: function(type, fn){
        this.on(type, fn);
    },

    removeEvent: function(type, fn){
        this.off(type, fn);
    },

    addEvents: function(events){
        this.on(events);
    },

    removeEvents: function(events){
        this.off(events);
    },

    fireEvent: function(type, args, delay){
        this.trigger(type);
    },

    // cloneEvents: function(from, type){
    //     from = document.id(from);
    //     var events = from.retrieve('events');
    //     if (!events) return this;
    //     if (!type){
    //         for (var eventType in events) this.cloneEvents(from, eventType);
    //     } else if (events[type]){
    //         events[type].keys.each(function(fn){
    //             this.addEvent(type, fn);
    //         }, this);
    //     }
    //     return this;
    // }

});