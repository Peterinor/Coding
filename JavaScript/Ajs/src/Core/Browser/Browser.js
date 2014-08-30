/*
---

name: Browser

description: The Browser Object. Contains Browser initialization, Window and Document, and the Browser Hash.

requires: [Array, Function, Number, String]

provides: [Browser, Window, Document]

...
*/


var parse = function(ua, platform){
    ua = ua.toLowerCase();
    platform = (platform ? platform.toLowerCase() : '');

    var UA = ua.match(/(opera|ie|firefox|chrome|trident|crios|version)[\s\/:]([\w\d\.]+)?.*?(safari|(?:rv[\s\/:]|version[\s\/:])([\w\d\.]+)|$)/) || [null, 'unknown', 0];

    if (UA[1] == 'trident'){
        UA[1] = 'ie';
        if (UA[4]) UA[2] = UA[4];
    } else if (UA[1] == 'crios') {
        UA[1] = 'chrome';
    }

    var platform = ua.match(/ip(?:ad|od|hone)/) ? 'ios' : (ua.match(/(?:webos|android)/) || platform.match(/mac|win|linux/) || ['other'])[0];
    if (platform == 'win') platform = 'windows';

    return {
        extend: Function.prototype.extend,
        name: (UA[1] == 'version') ? UA[3] : UA[1],
        version: parseFloat((UA[1] == 'opera' && UA[4]) ? UA[4] : UA[2]),
        platform: platform
    };
};

var Browser = this.Browser = parse(navigator.userAgent, navigator.platform);

if (Browser.ie){
    Browser.version = document.documentMode;
}

Browser.extend({
    Features: {
        xpath: !!(document.evaluate),
        air: !!(window.runtime),
        query: !!(document.querySelector),
        json: !!(window.JSON)
    },
    parseUA: parse
});


// Request

Browser.Request = (function(){

    var XMLHTTP = function(){
        return new XMLHttpRequest();
    };

    var MSXML2 = function(){
        return new ActiveXObject('MSXML2.XMLHTTP');
    };

    var MSXML = function(){
        return new ActiveXObject('Microsoft.XMLHTTP');
    };

    return Function.attempt(function(){
        XMLHTTP();
        return XMLHTTP;
    }, function(){
        MSXML2();
        return MSXML2;
    }, function(){
        MSXML();
        return MSXML;
    });

})();

Browser.Features.xhr = !!(Browser.Request);

// String scripts

Browser.exec = function(text){
    if (!text) return text;
    if (window.execScript){
        window.execScript(text);
    } else {
        var script = document.createElement('script');
        script.setAttribute('type', 'text/javascript');
        script.text = text;
        document.head.appendChild(script);
        document.head.removeChild(script);
    }
    return text;
};

String.implement('stripScripts', function(exec){
    var scripts = '';
    var text = this.replace(/<script[^>]*>([\s\S]*?)<\/script>/gi, function(all, code){
        scripts += code + '\n';
        return '';
    });
    if (exec === true) Browser.exec(scripts);
    else if (typeOf(exec) == 'function') exec(scripts, text);
    return text;
});

// Window, Document

Browser.extend({
    Document: window.Document,
    Window: window.Window,
    Element: window.Element,
    Event: window.Event
});

var superWin = function(){};
// superWin.prototype = window.Window;
var Window = window.Window = this.Window = window.$constructor = new Type('Window', superWin);

window.$family = Function.from('window').hide().protect();

Window.mirror(function(name, method){
    window[name] = method;
});

var superDoc = function(){};
// superDoc.prototype = window.Document;
var Document = window.Document = this.Document = document.$constructor = new Type('Document', superDoc);

document.$family = Function.from('document').hide().protect();

Document.mirror(function(name, method){
    document[name] = method;
});

document.window = window;

document.html = document.documentElement;
if (!document.head) document.head = document.getElementsByTagName('head')[0];

if (document.execCommand) try {
    document.execCommand("BackgroundImageCache", false, true);
} catch (e){}

// /*<ltIE9>*/
// if (window.attachEvent && !window.addEventListener){
//     var unloadEvent = function(){
//         window.detachEvent('onunload', unloadEvent);
//         document.head = document.html = document.window = null;
//     };
//     window.attachEvent('onunload', unloadEvent);
// }

