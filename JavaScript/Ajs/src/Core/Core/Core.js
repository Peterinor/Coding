/*
---

name: Core

description: The heart of Ajs.

inspiration:
  - Class implementation inspired by [Base.js](http://dean.edwards.name/weblog/2006/03/base/) Copyright (c) 2006 Dean Edwards, [GNU Lesser General Public License](http://opensource.org/licenses/lgpl-license.php)
  - Some functionality inspired by [Prototype.js](http://prototypejs.org) Copyright (c) 2005-2007 Sam Stephenson, [MIT License](http://opensource.org/licenses/mit-license.php)

provides: [Core, Type, typeOf, instanceOf, Native]

...
*/

// typeOf, instanceOf

var typeOf = this.typeOf = function(item) {
    if (item == null) return String(item);
    if (item.$family != null) return item.$family();

    if (item.nodeName) {
        if (item.nodeType == 1) return 'element';
        if (item.nodeType == 3) return (/\S/).test(item.nodeValue) ? 'textnode' : 'whitespace';
    } else if (typeof item.length == 'number') {
        if ('callee' in item) return 'arguments';
        if ('item' in item) return 'collection';
    }

    var tp = Object.prototype.toString.call(item);
    return tp.replace(/\[|\]|object|\s/g, '').toLowerCase();
    // return typeof item;
};

var instanceOf = this.instanceOf = function(item, object){
    if (item == null) return false;
    var constructor = item.$constructor || item.constructor;
    while (constructor){
        if (constructor === object) return true;
        constructor = constructor.parent;
    }
    /*<ltIE8>*/
    if (!item.hasOwnProperty) return false;
    /*</ltIE8>*/
    return item instanceof object;
};


var enumerables = true;
for (var i in {toString: 1}) enumerables = null;
if (enumerables) enumerables = ['hasOwnProperty', 'valueOf', 'isPrototypeOf', 'propertyIsEnumerable', 'toLocaleString', 'toString', 'constructor'];

Function.prototype.overloadSetter = function(usePlural) {
    var self = this;
    return function(a, b) {
        var __args = arguments;
        if (a == null) return this;
        if (usePlural || typeof a != 'string') {
            __args = [1, 2].concat(Array.prototype.slice.call(arguments, 1));
            for (var k in a) {
                __args[0] = k;
                __args[1] = a[k];
                self.apply(this, __args);
            }
            if (enumerables)
                for (var i = enumerables.length; i--;) {
                    k = enumerables[i];
                    if (a.hasOwnProperty(k)) self.call(this, k, a[k]);
                }
        } else {
            self.apply(this, __args);
        }
        return this;
    };
};
// Function.prototype.overloadSetter = function(usePlural) {
//     var self = this;
//     return function(a, b) {
//         var args = arguments;
//         if (a == null) return this;
//         if (usePlural || typeof a != 'string') {
//             for (var k in a) {
//                 args[0] = k;
//                 args[1] = a[k];
//                 self.apply(this, args);
//             }
//             if (enumerables)
//                 for (var i = enumerables.length; i--;) {
//                     k = enumerables[i];
//                     if (a.hasOwnProperty(k)) {
//                         args[0] = k;
//                         args[1] = a[k];
//                         self.apply(this, args);
//                     }
//                 }
//         } else {
//             self.apply(this, args);
//         }
//         return this;
//     };
// };

Function.prototype.overloadGetter = function(usePlural){
    var self = this;
    return function(a){
        var args, result;
        if (typeof a != 'string') args = a;
        else if (arguments.length > 1) args = arguments;
        else if (usePlural) args = [a];
        if (args){
            result = {};
            for (var i = 0; i < args.length; i++) result[args[i]] = self.call(this, args[i]);
        } else {
            result = self.call(this, a);
        }
        return result;
    };
};

Function.prototype.iteratorDecorator = function(){
    var self = this;
    return function(){
        var result = [];
        for (var i = 0; i < this.length; i++) {
            var _this = this[i];
            result.push(self.apply(_this, Array.from(arguments)));
        };
        return result;
    };
};

Function.prototype.extend = function(key, value){
    this[key] = value;
}.overloadSetter();

Function.prototype.implement = function(key, value){
    this.prototype[key] = value;
}.overloadSetter();

// From

var slice = Array.prototype.slice;

Function.from = function(item){
    return (typeOf(item) == 'function') ? item : function(){
        return item;
    };
};

//直接使用slice在ie8,7,6..版本中出错
Array.from = function(item){
    if (item == null) return [];
    // if(typeOf(item) == 'array') return item;
    if(Type.isEnumerable(item) && typeof item != 'string'){
        var l = item.length;
        var ret = [];
        for (var i = 0; i < l; i++) {
            ret.push(item[i]);
        }
        return ret;
    }
    return [item];
}

Number.from = function(item){
    var number = parseFloat(item);
    return isFinite(number) ? number : null;
};

String.from = function(item){
    return item + '';
};

// hide, protect

Function.implement({

    hide: function(){
        this.$hidden = true;
        return this;
    },

    protect: function(){
        this.$protected = true;
        return this;
    }

});

// Type

var Type = this.Type = function(name, object){
    if (name){
        var lower = name.toLowerCase();
        var typeCheck = function(item){
            return (typeOf(item) == lower);
        };

        Type['is' + name] = typeCheck;
        if (object != null){
            object.prototype.$family = (function(){
                return lower;
            }).hide();
        }
    }

    if (object == null) return null;
    object.extend(this);
    object.$constructor = Type;
    object.prototype.$constructor = object;

    return object;
};

var toString = Object.prototype.toString;

Type.isEnumerable = function(item){
    return (item != null && typeof item.length == 'number' && toString.call(item) != '[object Function]' );
};

var hooks = {};

var hooksOf = function(object){
    var type = typeOf(object.prototype);
    return hooks[type] || (hooks[type] = []);
};

var implement = function(name, method){
    if (method && method.$hidden) return;

    var hooks = hooksOf(this);

    for (var i = 0; i < hooks.length; i++){
        var hook = hooks[i];
        if (typeOf(hook) == 'type') implement.call(hook, name, method);
        else hook.call(this, name, method);
    }

    var previous = this.prototype[name];
    if (previous == null || !previous.$protected) this.prototype[name] = method;

    if (this[name] == null && typeOf(method) == 'function') extend.call(this, name, function(item){
        return method.apply(item, slice.call(arguments, 1));
    });
};

var extend = function(name, method){
    if (method && method.$hidden) return;
    var previous = this[name];
    if (previous == null || !previous.$protected) this[name] = method;
};

Type.implement({

    implement: implement.overloadSetter(),

    extend: extend.overloadSetter(),

    alias: function(name, existing){
        implement.call(this, name, this.prototype[existing]);
    }.overloadSetter(),

    mirror: function(hook){
        hooksOf(this).push(hook);
        return this;
    }

});

new Type('Type', Type);

// Default Types

var force = function(name, object, methods){
    var isType = (object != Object),
        prototype = object.prototype;

    if (isType) object = new Type(name, object);

    delete object.$family;

    for (var i = 0, l = methods.length; i < l; i++){
        var key = methods[i],
            generic = object[key],
            proto = prototype[key];

        if (generic) generic.protect();
        if (isType && proto) object.implement(key, proto.protect());
    }

    if (isType){
        var methodsEnumerable = prototype.propertyIsEnumerable(methods[0]);
        object.forEachMethod = function(fn){
            if (!methodsEnumerable) for (var i = 0, l = methods.length; i < l; i++){
                fn.call(prototype, prototype[methods[i]], methods[i]);
            }
            for (var key in prototype) fn.call(prototype, prototype[key], key);
        };
    }

    return force;
};

force('String', String, [
    'charAt', 'charCodeAt', 'concat', 'contains', 'indexOf', 'lastIndexOf', 'match', 'quote', 'replace', 'search',
    'slice', 'split', 'substr', 'substring', 'trim', 'toLowerCase', 'toUpperCase'
])('Array', Array, [
    'pop', 'push', 'reverse', 'shift', 'sort', 'splice', 'unshift', 'concat', 'join', 'slice',
    'indexOf', 'lastIndexOf', 'filter', 'forEach', 'every', 'map', 'some', 'reduce', 'reduceRight'
])('Number', Number, [
    'toExponential', 'toFixed', 'toLocaleString', 'toPrecision'
])('Function', Function, [
    'apply', 'call', 'bind'
])('RegExp', RegExp, [
    'exec', 'test'
])('Object', Object, [
    'create', 'defineProperty', 'defineProperties', 'keys',
    'getPrototypeOf', 'getOwnPropertyDescriptor', 'getOwnPropertyNames',
    'preventExtensions', 'isExtensible', 'seal', 'isSealed', 'freeze', 'isFrozen'
])('Date', Date, ['now'])('Boolean', Boolean, []);

Object.extend = extend.overloadSetter();

Date.extend('now', function(){
    return +(new Date);
});


// fixes NaN returning as Number
Number.prototype.$family = function(){
    return isFinite(this) ? 'number' : 'null';
}.hide();

// Number.random

Number.extend('random', function(min, max){
    return Math.floor(Math.random() * (max - min + 1) + min);
});

// forEach, each
var hasOwnProperty = Object.prototype.hasOwnProperty;
Object.extend('forEach', function(object, fn, bind){
    for (var key in object){
        if (hasOwnProperty.call(object, key)) fn.call(bind, object[key], key, object);
    }
});

Object.each = Object.forEach;

Type.extend({

    isNumeric: function(obj) {
        return !isNaN(parseFloat(obj)) && isFinite(obj);
    },

    isPlainObject: function(obj) {
        // Must be an Object.
        // Because of IE, we also have to check the presence of the constructor property.
        // Make sure that DOM nodes and window objects don't pass through, as well
        if (!obj || typeOf(obj) !== "object" || obj.nodeType || this.isWindow(obj)) {
            return false;
        }

        try {
            // Not own constructor property must be Object
            if (obj.constructor && !hasOwnProperty.call(obj, "constructor") && !hasOwnProperty.call(obj.constructor.prototype, "isPrototypeOf")) {
                return false;
            }
        } catch (e) {
            // IE8,9 Will throw exceptions on certain host objects #9897
            return false;
        }
        // Own properties are enumerated firstly, so to speed up,
        // if last one is own, then all properties are own.
        var key;
        for (key in obj) {}

        return key === undefined || hasOwnProperty.call(obj, key);
    },

    isEmptyObject: function(obj) {
        var name;
        for (name in obj) {
            return false;
        }
        return true;
    }
});

//compact with jQuery.extend
Ajs.each = function(obj, callback) {
    var name,
        i = 0,
        length = obj.length,
        isObj = length === undefined || Type.isFunction(obj);
    if (isObj) {
        for (name in obj) {
            if (callback.call(obj[name], name, obj[name]) === false) {
                break;
            }
        }
    } else {
        for (; i < length;) {
            if (callback.call(obj[i], i, obj[i++]) === false) {
                break;
            }
        }
    }
    return obj;
};

//compact with jQuery.extend
Ajs.extend = function( /*at least one argument, extend into Ajs itself*/ ) {
    var length = arguments.length;
    var deep = false;
    var start = 1;
    var target = arguments[0] || {};

    if (Type.isBoolean(target)) {
        deep = arguments[0];
        target = arguments[1] || {};
        start = 2;
    }

    if (typeof target !== "object" && !Type.isFunction(target)) {
        target = {};
    }
    if (length === start) {
        target = this;
        start--;
    }

    var options, name, src, copy, copyIsArray, clone;

    for (var i = start; i < length; i++) {
        // Only deal with non-null/undefined values
        if ((options = arguments[i]) != null) {
            // Extend the base object
            for (name in options) {
                src = target[name];
                copy = options[name];

                // Prevent never-ending loop
                if (target === copy) {
                    continue;
                }

                // Recurse if we're merging plain objects or arrays
                if (deep && copy && (Type.isPlainObject(copy) || (copyIsArray = Type.isArray(copy)))) {
                    if (copyIsArray) {
                        copyIsArray = false;
                        clone = src && Type.isArray(src) ? src : [];

                    } else {
                        clone = src && Type.isPlainObject(src) ? src : {};
                    }

                    // Never move original objects, clone them
                    target[name] = Ajs.extend(deep, clone, copy);

                    // Don't bring in undefined values
                } else if (copy !== undefined) {
                    target[name] = copy;
                }
            }
        }
    }
    return target;
};

Array.implement({

    /*<!ES5>*/
    forEach: function(fn, bind){
        for (var i = 0, l = this.length; i < l; i++){
            if (i in this) fn.call(bind, this[i], i, this);
        }
    },
    /*</!ES5>*/

    each: function(fn, bind){
        Array.forEach(this, fn, bind);
        return this;
    }

});

// Array & Object cloning, Object merging and appending

var cloneOf = function(item){
    switch (typeOf(item)){
        case 'array': return item.clone();
        case 'object': return Object.clone(item);
        default: return item;
    }
};

Array.implement('clone', function(){
    var i = this.length, clone = new Array(i);
    while (i--) clone[i] = cloneOf(this[i]);
    return clone;
});

var mergeOne = function(source, key, current){
    switch (typeOf(current)){
        case 'object':
            if (typeOf(source[key]) == 'object') Object.merge(source[key], current);
            else source[key] = Object.clone(current);
        break;
        case 'array': source[key] = current.clone(); break;
        default: source[key] = current;
    }
    return source;
};

Object.extend({

    merge: function(source, k, v){
        if (typeOf(k) == 'string') return mergeOne(source, k, v);
        for (var i = 1, l = arguments.length; i < l; i++){
            var object = arguments[i];
            for (var key in object) mergeOne(source, key, object[key]);
        }
        return source;
    },

    clone: function(object){
        var clone = {};
        for (var key in object) clone[key] = cloneOf(object[key]);
        return clone;
    },

    append: function(original){
        for (var i = 1, l = arguments.length; i < l; i++){
            var extended = arguments[i] || {};
            for (var key in extended) original[key] = extended[key];
        }
        return original;
    }

});

// Object-less types

['Object', 'WhiteSpace', 'TextNode', 'Collection', 'Arguments'].each(function(name){
    new Type(name);
});


// Unique ID
(function() {
    var uid = 0;
    Ajs.simpleUID = function(prefix) {
        return prefix ? prefix + uid++ : uid++;
    };

    var idCount = Date.now();
    Ajs.uniqueID = function(prefix) {
        var id = (idCount++).toString(36);
        return prefix ? prefix + id : id;
    };

})();


String.extend('uniqueID', Ajs.uniqueID);


(function(Ajs) {

    /*
     RequireJS 2.1.11 Copyright (c) 2010-2014, The Dojo Foundation All Rights Reserved.
     Available via the MIT or new BSD license.
     see: http://github.com/jrburke/requirejs for details
    */
	var requirejs,require,define;
	(function(ca){function G(b){return"[object Function]"===M.call(b)}function H(b){return"[object Array]"===M.call(b)}function v(b,c){if(b){var d;for(d=0;d<b.length&&(!b[d]||!c(b[d],d,b));d+=1);}}function U(b,c){if(b){var d;for(d=b.length-1;-1<d&&(!b[d]||!c(b[d],d,b));d-=1);}}function s(b,c){return ga.call(b,c)}function j(b,c){return s(b,c)&&b[c]}function B(b,c){for(var d in b)if(s(b,d)&&c(b[d],d))break}function V(b,c,d,g){c&&B(c,function(c,h){if(d||!s(b,h))g&&"object"===typeof c&&c&&!H(c)&&!G(c)&&!(c instanceof
	RegExp)?(b[h]||(b[h]={}),V(b[h],c,d,g)):b[h]=c});return b}function t(b,c){return function(){return c.apply(b,arguments)}}function da(b){throw b;}function ea(b){if(!b)return b;var c=ca;v(b.split("."),function(b){c=c[b]});return c}function C(b,c,d,g){c=Error(c+"\nhttp://requirejs.org/docs/errors.html#"+b);c.requireType=b;c.requireModules=g;d&&(c.originalError=d);return c}function ha(b){function c(a,e,b){var f,n,c,d,g,h,i,I=e&&e.split("/");n=I;var m=l.map,k=m&&m["*"];if(a&&"."===a.charAt(0))if(e){n=
	I.slice(0,I.length-1);a=a.split("/");e=a.length-1;l.nodeIdCompat&&R.test(a[e])&&(a[e]=a[e].replace(R,""));n=a=n.concat(a);d=n.length;for(e=0;e<d;e++)if(c=n[e],"."===c)n.splice(e,1),e-=1;else if(".."===c)if(1===e&&(".."===n[2]||".."===n[0]))break;else 0<e&&(n.splice(e-1,2),e-=2);a=a.join("/")}else 0===a.indexOf("./")&&(a=a.substring(2));if(b&&m&&(I||k)){n=a.split("/");e=n.length;a:for(;0<e;e-=1){d=n.slice(0,e).join("/");if(I)for(c=I.length;0<c;c-=1)if(b=j(m,I.slice(0,c).join("/")))if(b=j(b,d)){f=b;
	g=e;break a}!h&&(k&&j(k,d))&&(h=j(k,d),i=e)}!f&&h&&(f=h,g=i);f&&(n.splice(0,g,f),a=n.join("/"))}return(f=j(l.pkgs,a))?f:a}function d(a){z&&v(document.getElementsByTagName("script"),function(e){if(e.getAttribute("data-requiremodule")===a&&e.getAttribute("data-requirecontext")===i.contextName)return e.parentNode.removeChild(e),!0})}function g(a){var e=j(l.paths,a);if(e&&H(e)&&1<e.length)return e.shift(),i.require.undef(a),i.require([a]),!0}function u(a){var e,b=a?a.indexOf("!"):-1;-1<b&&(e=a.substring(0,
	b),a=a.substring(b+1,a.length));return[e,a]}function m(a,e,b,f){var n,d,g=null,h=e?e.name:null,l=a,m=!0,k="";a||(m=!1,a="_@r"+(M+=1));a=u(a);g=a[0];a=a[1];g&&(g=c(g,h,f),d=j(p,g));a&&(g?k=d&&d.normalize?d.normalize(a,function(a){return c(a,h,f)}):c(a,h,f):(k=c(a,h,f),a=u(k),g=a[0],k=a[1],b=!0,n=i.nameToUrl(k)));b=g&&!d&&!b?"_unnormalized"+(Q+=1):"";return{prefix:g,name:k,parentMap:e,unnormalized:!!b,url:n,originalName:l,isDefine:m,id:(g?g+"!"+k:k)+b}}function q(a){var e=a.id,b=j(k,e);b||(b=k[e]=new i.Module(a));
	return b}function r(a,e,b){var f=a.id,n=j(k,f);if(s(p,f)&&(!n||n.defineEmitComplete))"defined"===e&&b(p[f]);else if(n=q(a),n.error&&"error"===e)b(n.error);else n.on(e,b)}function w(a,e){var b=a.requireModules,f=!1;if(e)e(a);else if(v(b,function(e){if(e=j(k,e))e.error=a,e.events.error&&(f=!0,e.emit("error",a))}),!f)h.onError(a)}function x(){S.length&&(ia.apply(A,[A.length,0].concat(S)),S=[])}function y(a){delete k[a];delete W[a]}function F(a,e,b){var f=a.map.id;a.error?a.emit("error",a.error):(e[f]=
	!0,v(a.depMaps,function(f,c){var d=f.id,g=j(k,d);g&&(!a.depMatched[c]&&!b[d])&&(j(e,d)?(a.defineDep(c,p[d]),a.check()):F(g,e,b))}),b[f]=!0)}function D(){var a,e,b=(a=1E3*l.waitSeconds)&&i.startTime+a<(new Date).getTime(),f=[],c=[],h=!1,k=!0;if(!X){X=!0;B(W,function(a){var i=a.map,m=i.id;if(a.enabled&&(i.isDefine||c.push(a),!a.error))if(!a.inited&&b)g(m)?h=e=!0:(f.push(m),d(m));else if(!a.inited&&(a.fetched&&i.isDefine)&&(h=!0,!i.prefix))return k=!1});if(b&&f.length)return a=C("timeout","Load timeout for modules: "+
	f,null,f),a.contextName=i.contextName,w(a);k&&v(c,function(a){F(a,{},{})});if((!b||e)&&h)if((z||fa)&&!Y)Y=setTimeout(function(){Y=0;D()},50);X=!1}}function E(a){s(p,a[0])||q(m(a[0],null,!0)).init(a[1],a[2])}function K(a){var a=a.currentTarget||a.srcElement,e=i.onScriptLoad;a.detachEvent&&!Z?a.detachEvent("onreadystatechange",e):a.removeEventListener("load",e,!1);e=i.onScriptError;(!a.detachEvent||Z)&&a.removeEventListener("error",e,!1);return{node:a,id:a&&a.getAttribute("data-requiremodule")}}function L(){var a;
	for(x();A.length;){a=A.shift();if(null===a[0])return w(C("mismatch","Mismatched anonymous define() module: "+a[a.length-1]));E(a)}}var X,$,i,N,Y,l={waitSeconds:7,baseUrl:"./",paths:{},bundles:{},pkgs:{},shim:{},config:{}},k={},W={},aa={},A=[],p={},T={},ba={},M=1,Q=1;N={require:function(a){return a.require?a.require:a.require=i.makeRequire(a.map)},exports:function(a){a.usingExports=!0;if(a.map.isDefine)return a.exports?p[a.map.id]=a.exports:a.exports=p[a.map.id]={}},module:function(a){return a.module?
	a.module:a.module={id:a.map.id,uri:a.map.url,config:function(){return j(l.config,a.map.id)||{}},exports:a.exports||(a.exports={})}}};$=function(a){this.events=j(aa,a.id)||{};this.map=a;this.shim=j(l.shim,a.id);this.depExports=[];this.depMaps=[];this.depMatched=[];this.pluginMaps={};this.depCount=0};$.prototype={init:function(a,e,b,f){f=f||{};if(!this.inited){this.factory=e;if(b)this.on("error",b);else this.events.error&&(b=t(this,function(a){this.emit("error",a)}));this.depMaps=a&&a.slice(0);this.errback=
	b;this.inited=!0;this.ignore=f.ignore;f.enabled||this.enabled?this.enable():this.check()}},defineDep:function(a,e){this.depMatched[a]||(this.depMatched[a]=!0,this.depCount-=1,this.depExports[a]=e)},fetch:function(){if(!this.fetched){this.fetched=!0;i.startTime=(new Date).getTime();var a=this.map;if(this.shim)i.makeRequire(this.map,{enableBuildCallback:!0})(this.shim.deps||[],t(this,function(){return a.prefix?this.callPlugin():this.load()}));else return a.prefix?this.callPlugin():this.load()}},load:function(){var a=
	this.map.url;T[a]||(T[a]=!0,i.load(this.map.id,a))},check:function(){if(this.enabled&&!this.enabling){var a,e,b=this.map.id;e=this.depExports;var f=this.exports,c=this.factory;if(this.inited)if(this.error)this.emit("error",this.error);else{if(!this.defining){this.defining=!0;if(1>this.depCount&&!this.defined){if(G(c)){if(this.events.error&&this.map.isDefine||h.onError!==da)try{f=i.execCb(b,c,e,f)}catch(d){a=d}else f=i.execCb(b,c,e,f);this.map.isDefine&&void 0===f&&((e=this.module)?f=e.exports:this.usingExports&&
	(f=this.exports));if(a)return a.requireMap=this.map,a.requireModules=this.map.isDefine?[this.map.id]:null,a.requireType=this.map.isDefine?"define":"require",w(this.error=a)}else f=c;this.exports=f;if(this.map.isDefine&&!this.ignore&&(p[b]=f,h.onResourceLoad))h.onResourceLoad(i,this.map,this.depMaps);y(b);this.defined=!0}this.defining=!1;this.defined&&!this.defineEmitted&&(this.defineEmitted=!0,this.emit("defined",this.exports),this.defineEmitComplete=!0)}}else this.fetch()}},callPlugin:function(){var a=
	this.map,b=a.id,d=m(a.prefix);this.depMaps.push(d);r(d,"defined",t(this,function(f){var d,g;g=j(ba,this.map.id);var J=this.map.name,u=this.map.parentMap?this.map.parentMap.name:null,p=i.makeRequire(a.parentMap,{enableBuildCallback:!0});if(this.map.unnormalized){if(f.normalize&&(J=f.normalize(J,function(a){return c(a,u,!0)})||""),f=m(a.prefix+"!"+J,this.map.parentMap),r(f,"defined",t(this,function(a){this.init([],function(){return a},null,{enabled:!0,ignore:!0})})),g=j(k,f.id)){this.depMaps.push(f);
	if(this.events.error)g.on("error",t(this,function(a){this.emit("error",a)}));g.enable()}}else g?(this.map.url=i.nameToUrl(g),this.load()):(d=t(this,function(a){this.init([],function(){return a},null,{enabled:!0})}),d.error=t(this,function(a){this.inited=!0;this.error=a;a.requireModules=[b];B(k,function(a){0===a.map.id.indexOf(b+"_unnormalized")&&y(a.map.id)});w(a)}),d.fromText=t(this,function(f,c){var g=a.name,J=m(g),k=O;c&&(f=c);k&&(O=!1);q(J);s(l.config,b)&&(l.config[g]=l.config[b]);try{h.exec(f)}catch(j){return w(C("fromtexteval",
	"fromText eval for "+b+" failed: "+j,j,[b]))}k&&(O=!0);this.depMaps.push(J);i.completeLoad(g);p([g],d)}),f.load(a.name,p,d,l))}));i.enable(d,this);this.pluginMaps[d.id]=d},enable:function(){W[this.map.id]=this;this.enabling=this.enabled=!0;v(this.depMaps,t(this,function(a,b){var c,f;if("string"===typeof a){a=m(a,this.map.isDefine?this.map:this.map.parentMap,!1,!this.skipMap);this.depMaps[b]=a;if(c=j(N,a.id)){this.depExports[b]=c(this);return}this.depCount+=1;r(a,"defined",t(this,function(a){this.defineDep(b,
	a);this.check()}));this.errback&&r(a,"error",t(this,this.errback))}c=a.id;f=k[c];!s(N,c)&&(f&&!f.enabled)&&i.enable(a,this)}));B(this.pluginMaps,t(this,function(a){var b=j(k,a.id);b&&!b.enabled&&i.enable(a,this)}));this.enabling=!1;this.check()},on:function(a,b){var c=this.events[a];c||(c=this.events[a]=[]);c.push(b)},emit:function(a,b){v(this.events[a],function(a){a(b)});"error"===a&&delete this.events[a]}};i={config:l,contextName:b,registry:k,defined:p,urlFetched:T,defQueue:A,Module:$,makeModuleMap:m,
	nextTick:h.nextTick,onError:w,configure:function(a){a.baseUrl&&"/"!==a.baseUrl.charAt(a.baseUrl.length-1)&&(a.baseUrl+="/");var b=l.shim,c={paths:!0,bundles:!0,config:!0,map:!0};B(a,function(a,b){c[b]?(l[b]||(l[b]={}),V(l[b],a,!0,!0)):l[b]=a});a.bundles&&B(a.bundles,function(a,b){v(a,function(a){a!==b&&(ba[a]=b)})});a.shim&&(B(a.shim,function(a,c){H(a)&&(a={deps:a});if((a.exports||a.init)&&!a.exportsFn)a.exportsFn=i.makeShimExports(a);b[c]=a}),l.shim=b);a.packages&&v(a.packages,function(a){var b,
	a="string"===typeof a?{name:a}:a;b=a.name;a.location&&(l.paths[b]=a.location);l.pkgs[b]=a.name+"/"+(a.main||"main").replace(ja,"").replace(R,"")});B(k,function(a,b){!a.inited&&!a.map.unnormalized&&(a.map=m(b))});if(a.deps||a.callback)i.require(a.deps||[],a.callback)},makeShimExports:function(a){return function(){var b;a.init&&(b=a.init.apply(ca,arguments));return b||a.exports&&ea(a.exports)}},makeRequire:function(a,e){function g(f,c,d){var j,l;e.enableBuildCallback&&(c&&G(c))&&(c.__requireJsBuild=
	!0);if("string"===typeof f){if(G(c))return w(C("requireargs","Invalid require call"),d);if(a&&s(N,f))return N[f](k[a.id]);if(h.get)return h.get(i,f,a,g);j=m(f,a,!1,!0);j=j.id;return!s(p,j)?w(C("notloaded",'Module name "'+j+'" has not been loaded yet for context: '+b+(a?"":". Use require([])"))):p[j]}L();i.nextTick(function(){L();l=q(m(null,a));l.skipMap=e.skipMap;l.init(f,c,d,{enabled:!0});D()});return g}e=e||{};V(g,{isBrowser:z,toUrl:function(b){var e,d=b.lastIndexOf("."),g=b.split("/")[0];if(-1!==
	d&&(!("."===g||".."===g)||1<d))e=b.substring(d,b.length),b=b.substring(0,d);return i.nameToUrl(c(b,a&&a.id,!0),e,!0)},defined:function(b){return s(p,m(b,a,!1,!0).id)},specified:function(b){b=m(b,a,!1,!0).id;return s(p,b)||s(k,b)}});a||(g.undef=function(b){x();var c=m(b,a,!0),e=j(k,b);d(b);delete p[b];delete T[c.url];delete aa[b];U(A,function(a,c){a[0]===b&&A.splice(c,1)});e&&(e.events.defined&&(aa[b]=e.events),y(b))});return g},enable:function(a){j(k,a.id)&&q(a).enable()},completeLoad:function(a){var b,
	c,f=j(l.shim,a)||{},d=f.exports;for(x();A.length;){c=A.shift();if(null===c[0]){c[0]=a;if(b)break;b=!0}else c[0]===a&&(b=!0);E(c)}c=j(k,a);if(!b&&!s(p,a)&&c&&!c.inited){if(l.enforceDefine&&(!d||!ea(d)))return g(a)?void 0:w(C("nodefine","No define call for "+a,null,[a]));E([a,f.deps||[],f.exportsFn])}D()},nameToUrl:function(a,b,c){var f,d,g;(f=j(l.pkgs,a))&&(a=f);if(f=j(ba,a))return i.nameToUrl(f,b,c);if(h.jsExtRegExp.test(a))f=a+(b||"");else{f=l.paths;a=a.split("/");for(d=a.length;0<d;d-=1)if(g=a.slice(0,
	d).join("/"),g=j(f,g)){H(g)&&(g=g[0]);a.splice(0,d,g);break}f=a.join("/");f+=b||(/^data\:|\?/.test(f)||c?"":".js");f=("/"===f.charAt(0)||f.match(/^[\w\+\.\-]+:/)?"":l.baseUrl)+f}return l.urlArgs?f+((-1===f.indexOf("?")?"?":"&")+l.urlArgs):f},load:function(a,b){h.load(i,a,b)},execCb:function(a,b,c,d){return b.apply(d,c)},onScriptLoad:function(a){if("load"===a.type||ka.test((a.currentTarget||a.srcElement).readyState))P=null,a=K(a),i.completeLoad(a.id)},onScriptError:function(a){var b=K(a);if(!g(b.id))return w(C("scripterror",
	"Script error for: "+b.id,a,[b.id]))}};i.require=i.makeRequire();return i}var h,x,y,D,K,E,P,L,q,Q,la=/(\/\*([\s\S]*?)\*\/|([^:]|^)\/\/(.*)$)/mg,ma=/[^.]\s*require\s*\(\s*["']([^'"\s]+)["']\s*\)/g,R=/\.js$/,ja=/^\.\//;x=Object.prototype;var M=x.toString,ga=x.hasOwnProperty,ia=Array.prototype.splice,z=!!("undefined"!==typeof window&&"undefined"!==typeof navigator&&window.document),fa=!z&&"undefined"!==typeof importScripts,ka=z&&"PLAYSTATION 3"===navigator.platform?/^complete$/:/^(complete|loaded)$/,
	Z="undefined"!==typeof opera&&"[object Opera]"===opera.toString(),F={},r={},S=[],O=!1;if("undefined"===typeof define){if("undefined"!==typeof requirejs){if(G(requirejs))return;r=requirejs;requirejs=void 0}"undefined"!==typeof require&&!G(require)&&(r=require,require=void 0);h=requirejs=function(b,c,d,g){var u,m="_";!H(b)&&"string"!==typeof b&&(u=b,H(c)?(b=c,c=d,d=g):b=[]);u&&u.context&&(m=u.context);(g=j(F,m))||(g=F[m]=h.s.newContext(m));u&&g.configure(u);return g.require(b,c,d)};h.config=function(b){return h(b)};
	h.nextTick="undefined"!==typeof setTimeout?function(b){setTimeout(b,4)}:function(b){b()};require||(require=h);h.version="2.1.11";h.jsExtRegExp=/^\/|:|\?|\.js$/;h.isBrowser=z;x=h.s={contexts:F,newContext:ha};h({});v(["toUrl","undef","defined","specified"],function(b){h[b]=function(){var c=F._;return c.require[b].apply(c,arguments)}});if(z&&(y=x.head=document.getElementsByTagName("head")[0],D=document.getElementsByTagName("base")[0]))y=x.head=D.parentNode;h.onError=da;h.createNode=function(b){var c=
	b.xhtml?document.createElementNS("http://www.w3.org/1999/xhtml","html:script"):document.createElement("script");c.type=b.scriptType||"text/javascript";c.charset="utf-8";c.async=!0;return c};h.load=function(b,c,d){var g=b&&b.config||{};if(z)return g=h.createNode(g,c,d),g.setAttribute("data-requirecontext",b.contextName),g.setAttribute("data-requiremodule",c),g.attachEvent&&!(g.attachEvent.toString&&0>g.attachEvent.toString().indexOf("[native code"))&&!Z?(O=!0,g.attachEvent("onreadystatechange",b.onScriptLoad)):
	(g.addEventListener("load",b.onScriptLoad,!1),g.addEventListener("error",b.onScriptError,!1)),g.src=d,L=g,D?y.insertBefore(g,D):y.appendChild(g),L=null,g;if(fa)try{importScripts(d),b.completeLoad(c)}catch(j){b.onError(C("importscripts","importScripts failed for "+c+" at "+d,j,[c]))}};z&&!r.skipDataMain&&U(document.getElementsByTagName("script"),function(b){y||(y=b.parentNode);if(K=b.getAttribute("data-main"))return q=K,r.baseUrl||(E=q.split("/"),q=E.pop(),Q=E.length?E.join("/")+"/":"./",r.baseUrl=
	Q),q=q.replace(R,""),h.jsExtRegExp.test(q)&&(q=K),r.deps=r.deps?r.deps.concat(q):[q],!0});define=function(b,c,d){var g,h;"string"!==typeof b&&(d=c,c=b,b=null);H(c)||(d=c,c=null);!c&&G(d)&&(c=[],d.length&&(d.toString().replace(la,"").replace(ma,function(b,d){c.push(d)}),c=(1===d.length?["require"]:["require","exports","module"]).concat(c)));if(O){if(!(g=L))P&&"interactive"===P.readyState||U(document.getElementsByTagName("script"),function(b){if("interactive"===b.readyState)return P=b}),g=P;g&&(b||
	(b=g.getAttribute("data-requiremodule")),h=F[g.getAttribute("data-requirecontext")])}(h?h.defQueue:S).push([b,c,d])};define.amd={jQuery:!0};h.exec=function(b){return eval(b)};h(r)}})(this);

    function namespace(ns) {
        if (!ns || !ns.length) {
            return null;
        }
        var levels = ns.split(".");
        var nsobj = Ajs;

        for (var i = (levels[0] == "Ajs") ? 1 : 0; i < levels.length; ++i) {
            nsobj[levels[i]] = nsobj[levels[i]] || {};
            nsobj = nsobj[levels[i]];
        }
        return nsobj;
    }

    Ajs.namespace = namespace;

    var require = Ajs.requires = Ajs.require = requirejs;
    var define = Ajs.defines = Ajs.define = define;


    var ajs_path_r = /ajs\.(min.){0,1}js/;
    var ajs_file = '';
    var ajs_path = '';

    var scripts = document.getElementsByTagName('script');
    for (var i = 0; i < scripts.length; i++) {
        var s = scripts[i];
        // window.s = s;
        // console.log(s);
        var data_main = s.attributes['data-main'];
        var data_ajs = s.attributes['data-ajs'];
        var src = s.src;
        if (ajs_path_r.test(src) || data_main || data_ajs) {
            ajs_file = src;
            ajs_path = src.substr(0, src.lastIndexOf('/')) + '/';
            break;
        }

    };

    var ajs_libs = {
        'Core.Browser': 'Core/Browser/Browser',

        'Core.Class': 'Core/Class/Class',
        'Core.Class.Extras': 'Core/Class/Class.Extras',
        'Core.Class.Callback': 'Core/Class/Callback',
        'Core.Class.Deferred': 'Core/Class/Deferred',

        'third-party.Sizzle': 'third-party/Sizzle',
        // 'third-party.jQuery': 'third-party/jQuery',

        'Core.Element': 'Core/Element/Element',
        'Core.Element.Attributes': 'Core/Element/Element.Attributes',
        'Core.Element.Event': 'Core/Element/Element.Event',
        'Core.Element.Style': 'Core/Element/Element.Style',

        'Core.Fx': 'Core/Fx/Fx',
        'Core.Fx.CSS': 'Core/Fx/Fx.CSS',
        'Core.Fx.Transition': 'Core/Fx/Fx.Transition',
        'Core.Fx.Tween': 'Core/Fx/Fx.Tween',
        'Core.Fx.Morph': 'Core/Fx/Fx.Morph',

        'Core.Request': 'Core/Request/Request',
        'Core.Request.HTML': 'Core/Request/Request.HTML',
        'Core.Request.JSON': 'Core/Request/Request.JSON',

        'Core.Types.Array': 'Core/Types/Array',
        'Core.Types.Function': 'Core/Types/Function',
        'Core.Types.Number': 'Core/Types/Number',
        'Core.Types.Object': 'Core/Types/Object',
        'Core.Types.String': 'Core/Types/String',
        'Core.Types.DOMEvent': 'Core/Types/DOMEvent',

        'Core.Utilities.Cookie': 'Core/Utilities/Cookie',
        'Core.Utilities.JSON': 'Core/Utilities/JSON',
        'Core.Utilities.DOMReady': 'Core/Utilities/DOMReady',

        'Core.jQ': 'Core/jQ'
    }
    var ajs_libs_config = {};

    for (var lib in ajs_libs) {
        if(lib.indexOf('third-party') == -1){
            ajs_libs_config['Ajs.' + lib] = ajs_path + ajs_libs[lib];
        }else{
            ajs_libs_config[lib] = ajs_path + ajs_libs[lib];
        }
    }
    console.log(ajs_libs_config);
    // ajs_libs_config['Ajs.Core.Core.Core'] = ajs_file.substr(0, ajs_file.lastIndexOf('.js'));

    Ajs.config = function(config) {
        config = config || {
            urlArgs: "bust=" + Date.now(),
            baseUrl: "./",
            paths: {},
            shim: {
            }
        };

        Object.merge(config.paths, ajs_libs_config);
        // console.log(config);
        require.config(config);
        //...
        //TODO:        
    }
    Ajs.config();

    var Dependence = function(name) {
        Object.merge(this, {
            name: name,
            _requires: [],
            loaded: false,
            body: []
        });
    }

    Dependence.implement({
        requires: function() {
            this._requires = Array.prototype.slice.call(arguments);
            return this;
        },
        defines: function(m) {
            this.body.push(m);
            var nsobj = Ajs.namespace(this.name);
            if (typeof m == 'object') {
                if (nsobj) {
                    Object.merge(nsobj, m);
                }
                return this;
            }
            if (typeof m == 'function') {
                Ajs.define(this._requires, function() {
                    var _m = m.apply(Ajs, Array.prototype.slice.call(arguments));
                    if (nsobj) {
                        Object.merge(nsobj, _m);
                    }
                });
            }
            return this;
        }
    })

    Ajs.module = function(name) {
        var d = new Dependence(name);
        return d;
    };

})(Ajs);