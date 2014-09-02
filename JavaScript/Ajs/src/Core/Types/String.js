/*
---

name: String

description: Contains String Prototypes like camelCase, capitalize, test, and toInt.

requires: [Type, Array]

provides: [String]

...
*/
var core_trim = String.prototype.trim;
var rtrim = /^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g;

String.implement({

	//<!ES6>
	contains: function(string, index) {
		return (index ? String(this).slice(index) : String(this)).indexOf(string) > -1;
	},
	//</!ES6>

	test: function(regex, params) {
		return ((typeOf(regex) == 'regexp') ? regex : new RegExp('' + regex, params)).test(this);
	},

	trim: core_trim && !core_trim.call("\uFEFF\xA0") ? function() {
		String(this).trim();
	} : function() {
		return String(this).replace(rtrim, '');
	},

	clean: function() {
		return String(this).replace(/\s+/g, ' ').trim();
	},

	camelCase: function() {
		return String(this).replace(/-\D/g, function(match) {
			return match.charAt(1).toUpperCase();
		});
	},

	hyphenate: function() {
		return String(this).replace(/[A-Z]/g, function(match) {
			return ('-' + match.charAt(0).toLowerCase());
		});
	},

	capitalize: function() {
		return String(this).replace(/\b[a-z]/g, function(match) {
			return match.toUpperCase();
		});
	},

	escapeRegExp: function() {
		return String(this).replace(/([-.*+?^${}()|[\]\/\\])/g, '\\$1');
	},

	toInt: function(base) {
		return parseInt(this, base || 10);
	},

	toFloat: function() {
		return parseFloat(this);
	},

	hexToRgb: function(array) {
		var hex = String(this).match(/^#?(\w{1,2})(\w{1,2})(\w{1,2})$/);
		return (hex) ? hex.slice(1).hexToRgb(array) : null;
	},

	rgbToHex: function(array) {
		var rgb = String(this).match(/\d{1,3}/g);
		return (rgb) ? rgb.rgbToHex(array) : null;
	},

	substitute: function(object, regexp) {
		return String(this).replace(regexp || (/\\?\{([^{}]+)\}/g), function(match, name) {
			if (match.charAt(0) == '\\') return match.slice(1);
			return (object[name] != null) ? object[name] : '';
		});
	}

});