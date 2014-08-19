
//port for using

// var hasGetComputedStyle = !!window.getComputedStyle;

// //Element.Style
// jQuery.fn.extend({
//     getComputedStyle : function(property){
//         var _this = this[0];
//         if (!hasGetComputedStyle && _this.currentStyle) return _this.currentStyle[property.camelCase()];
//         var defaultView = document.defaultView,
//             computed = defaultView ? defaultView.getComputedStyle(_this, null) : null;
//         return (computed) ? computed.getPropertyValue((property == floatName) ? 'float' : property.hyphenate()) : '';
//     },
//     getStyle : function (prop) {
//         return this.css(prop);
//     },
//     setStyle : function(prop, value){
//         return this.css(prop, value);
//     },
//     getStyles : function(props){
//         return this.css(props);
//     },
//     setStyles : function(css){
//         return this.css(css);
//     }
// });


// //Element.Event
// jQuery.fn.extend({

//     addEvent: function(type, fn){
//         return this.on(type, fn);
//     },

//     removeEvent: function(type, fn){
//         return this.off(type, fn);
//     },

//     addEvents: function(events){
//         return this.on(events);
//     },

//     removeEvents: function(events){
//         return this.off(events);
//     },

//     fireEvent: function(type, args, delay){
//         return this.trigger(type);
//     }
// });