/*
---

name: XML

description: JSON encoder and decoder.

requires: [Array, String, Number, Function]

provides: [XML]

...
*/

(function() {

    if (!window.DOMParser) {
        var DOMParser = window.DOMParser = function() {};

        DOMParser.implement({
            parseFromString: function(data, mime) {
                if (!mime) {
                    throw "Unsupported mime-type specified";
                }
                var xml = new ActiveXObject("Microsoft.XMLDOM");
                xml.async = "false";
                xml.loadXML(data);

                return xml;
            }
        });
    }
})();