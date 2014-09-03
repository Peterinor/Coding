/*
---

name: JSON

description: JSON encoder and decoder.

requires: [Array, String, Number, Function]

provides: [JSON]

...
*/

;(function() {

	if (typeof JSON == 'undefined') window.JSON = {};

	var special = {
		'\b': '\\b',
		'\t': '\\t',
		'\n': '\\n',
		'\f': '\\f',
		'\r': '\\r',
		'"': '\\"',
		'\\': '\\\\'
	};

	var escape = function(chr) {
		return special[chr] || '\\u' + ('0000' + chr.charCodeAt(0).toString(16)).slice(-4);
	};

	var g_indent = 1;
	if (typeof JSON.stringify !== 'function') {

		JSON.stringify = function(obj, replacer, space) {
			var indent = '';
			var newline = '';

			if (typeof space === 'number') {
				for (i = 0; i < space; i += 1) {
					indent += ' ';
				}
			} else if (typeof space === 'string') {
				indent = space;
			}
			if ( !! indent) {
				newline = '\n';
			}
			var gen_indent = function(t) {
				t = t || g_indent;
				return (new Array(t)).join(indent);
			}

			if (obj && obj.toJSON) obj = obj.toJSON();

			switch (typeOf(obj)) {
				case 'string':
					return '"' + obj.replace(/[\x00-\x1f\\"]/g, escape) + '"';
				case 'array':
					g_indent++;
					var _indent = gen_indent(g_indent);
					var _indent_1 = gen_indent(g_indent - 1);
					var _join = ',' + newline + _indent;
					var ret = '[' + newline + _indent + obj.map(function(el, i) {
						return JSON.stringify(el, replacer, indent);
					}).clean().join(_join) + newline + _indent_1 + ']';
					g_indent--;
					return ret;
				case 'object':
				case 'hash':
					g_indent++;
					var string = [];
					var _indent = gen_indent(g_indent);
					var _indent_1 = gen_indent(g_indent - 1);
					var _join = ',' + newline + _indent;
					Object.each(obj, function(value, key) {
						var json = JSON.stringify(value, replacer, indent);
						if (json) string.push(JSON.stringify(key, replacer, indent) + ':' + json);
					});
					g_indent--;
					return '{' + newline + _indent + string.join(_join) + newline + _indent_1 + '}';
				case 'number':
				case 'boolean':
					return '' + obj;
				case 'null':
					return 'null';
			}

			return null;
		};

	}

	// JSON RegExp
	var rvalidchars = /^[\],:{}\s]*$/,
		rvalidbraces = /(?:^|:|,)(?:\s*\[)+/g,
		rvalidescape = /\\(?:["\\\/bfnrt]|u[\da-fA-F]{4})/g,
		rvalidtokens = /"[^"\\\r\n]*"|true|false|null|-?(?:\d+\.|)\d+(?:[eE][+-]?\d+|)/g;

	//JSON.parse 
	if (typeof JSON.parse !== 'function') {
		cx = /[\u0000\u00ad\u0600-\u0604\u070f\u17b4\u17b5\u200c-\u200f\u2028-\u202f\u2060-\u206f\ufeff\ufff0-\uffff]/g;
		JSON.parse = function(text, reviver) {

			var j;

			function walk(holder, key) {

				var k, v, value = holder[key];
				if (value && typeof value === 'object') {
					for (k in value) {
						if (Object.prototype.hasOwnProperty.call(value, k)) {
							v = walk(value, k);
							if (v !== undefined) {
								value[k] = v;
							} else {
								delete value[k];
							}
						}
					}
				}
				return reviver.call(holder, key, value);
			}

			text = String(text);
			cx.lastIndex = 0;
			if (cx.test(text)) {
				text = text.replace(cx, function(a) {
					return '\\u' +
						('0000' + a.charCodeAt(0).toString(16)).slice(-4);
				});
			}

			if (rvalidchars.test(text.replace(rvalidescape, '@')
				.replace(rvalidtokens, ']')
				.replace(rvalidbraces, ''))) {

				j = eval('(' + text + ')');

				return typeof reviver === 'function' ? walk({
					'': j
				}, '') : j;
			}

			throw new SyntaxError('JSON.parse');
		};
	}
})();