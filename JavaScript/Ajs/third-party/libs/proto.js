Function.prototype.overloadSetter = function(usePlural) {
    var self = this;
    return function(a, b) {
        if (a == null) return this;
        if (usePlural || typeof a != 'string') {
            for (var k in a) self.call(this, k, a[k]);
        } else {
            self.call(this, a, b);
        }
        return this;
    };
};

Function.prototype.overloadGetter = function(usePlural) {
    var self = this;
    return function(a) {
        var args, result;
        if (typeof a != 'string') args = a;
        else if (arguments.length > 1) args = arguments;
        else if (usePlural) args = [a];
        if (args) {
            result = {};
            for (var i = 0; i < args.length; i++) result[args[i]] = self.call(this, args[i]);
        } else {
            result = self.call(this, a);
        }
        return result;
    };
};

Function.prototype.extend = function(key, value) {
    this[key] = value;
}.overloadSetter();

Function.prototype.implement = function(key, value) {
    this.prototype[key] = value;
}.overloadSetter();



Function.implement({

    attempt: function(args, bind){
        try {
            return this.apply(bind, Array.from(args));
        } catch (e){}

        return null;
    },

    /*<!ES5-bind>*/
    bind: function(that){
        var self = this,
            args = arguments.length > 1 ? Array.slice(arguments, 1) : null,
            F = function(){};

        var bound = function(){
            var context = that, length = arguments.length;
            if (this instanceof bound){
                F.prototype = self.prototype;
                context = new F;
            }
            var result = (!args && !length)
                ? self.call(context)
                : self.apply(context, args && length ? args.concat(Array.slice(arguments)) : args || arguments);
            return context == that ? result : context;
        };
        return bound;
    },
    /*</!ES5-bind>*/

    pass: function(args, bind){
        var self = this;
        if (args != null) args = Array.from(args);
        return function(){
            return self.apply(bind, args || arguments);
        };
    },

    delay: function(delay, bind, args){
        return setTimeout(this.pass((args == null ? [] : args), bind), delay);
    },

    periodical: function(periodical, bind, args){
        return setInterval(this.pass((args == null ? [] : args), bind), periodical);
    }

});

Array.prototype.remove = function(from, to) {
    var rest = this.slice((to || from) + 1 || this.length);
    this.length = from < 0 ? this.length + from : from;
    return this.push.apply(this, rest);
};

Date.prototype.format = function(format) {
    if (isNaN(this.getDay())) { //Invalid Date
        return "";
    }
    var o = {
        "M+": this.getMonth() + 1, //month
        "d+": this.getDate(), //day
        "h+": this.getHours() % 12, //hour
        "H+": this.getHours(), //hour
        "AP": this.getHours() > 12 ? 'PM' : 'AM', //AM/PM
        "m+": this.getMinutes(), //minute
        "s+": this.getSeconds(), //second
        "q+": Math.floor((this.getMonth() + 3) / 3), //quarter
        "S": this.getMilliseconds() //millisecond
    }
    if (/(y+)/.test(format)) {
        format = format.replace(RegExp.$1, (this.getFullYear() + "").substr(4 - RegExp.$1.length));
    }
    for (var k in o) {
        if (new RegExp("(" + k + ")").test(format)) {
            format = format.replace(RegExp.$1, RegExp.$1.length == 1 ? o[k] : ("00" + o[k]).substr(("" + o[k]).length));
        }
    }
    return format;
};
Date.fromString = function(dt) {
    var dtStr = dt.replace(/-/g, "/");

    var dateTime = new Date(Date.parse(dtStr));

    return dateTime;
};
Date.prototype._toString = Date.prototype.toString;
Date.prototype.toString = function(format) {
    if ( !! format) {
        return this.format(format);
    }
    return this._toString();
}