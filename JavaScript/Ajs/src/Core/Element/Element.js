/*
---

name: Element

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

license: MIT-style license.

requires: [Window, Document, Array, String, Function, Object, Number, Slick.Parser, Slick.Finder]

provides: [Element, Elements, $, $$, IFrame, Selectors]

...
*/

var Element = this.Element = function(tag, props) {
	var _Element = function() {};
	// var el = jQuery(tag).attr(props || {});
	if (typeOf(tag) == 'element') return tag;
	var el = Sizzle(tag)[0];
	_Element.prototype = el;
	var _el = new _Element();
	return el;
};


if (Browser.Element) {
	Element.prototype = Browser.Element.prototype;
	// IE8 and IE9 require the wrapping.
	Element.prototype._fireEvent = (function(fireEvent) {
		return function(type, event) {
			return fireEvent.call(this, type, event);
		};
	})(Element.prototype.fireEvent);
}

new Type('Element', Element).mirror(function(name) {
	if (Array.prototype[name]) return;

	var obj = {};
	obj[name] = function() {
		var results = [],
			args = arguments,
			elements = true;
		for (var i = 0, l = this.length; i < l; i++) {
			var element = this[i],
				result = results[i] = element[name].apply(element, args);
			elements = (elements && typeOf(result) == 'element');
		}
		return (elements) ? new Elements(results) : results;
	};

	// Elements.implement(obj);
});

if (!Browser.Element) {
	Element.parent = Object;

	Element.Prototype = {
		'$constructor': Element,
		'$family': Function.from('element').hide()
	};

	Element.mirror(function(name, method) {
		Element.Prototype[name] = method;
	});
}

Element.Constructors = {};


// var Element = this.Element = jQuery;


var IFrame = new Type('IFrame', function() {
	var params = Array.link(arguments, {
		properties: Type.isObject,
		iframe: function(obj) {
			return (obj != null);
		}
	});

	var props = params.properties || {}, iframe;
	if (params.iframe) iframe = document.id(params.iframe);
	var onload = props.onload || function() {};
	delete props.onload;
	props.id = props.name = [props.id, props.name, iframe ? (iframe.id || iframe.name) : 'IFrame_' + String.uniqueID()].pick();
	iframe = new Element(iframe || 'iframe', props);

	var onLoad = function() {
		onload.call(iframe.contentWindow);
	};

	if (window.frames[props.id]) onLoad();
	else iframe.addListener('load', onLoad);
	return iframe;
});



var Elements = this.Elements = function(nodes) {
	var ns = Sizzle(nodes);
	for (var i = 0; i < ns.length; i++) {
		this.push(ns[i]);
	};
};

Elements.prototype = {
	length: 0
};
Elements.parent = Array;

new Type('Elements', Elements).implement({

	filter: function(filter, bind) {
		if (!filter) return this;
		return new Elements(Array.filter(this, (typeOf(filter) == 'string') ? function(item) {
			return item.match(filter);
		} : filter, bind));
	}.protect(),

	push: function() {
		var length = this.length;
		for (var i = 0, l = arguments.length; i < l; i++) {
			var item = arguments[i];
			if (item) this[length++] = item;
		}
		return (this.length = length);
	}.protect(),

	unshift: function() {
		var items = [];
		for (var i = 0, l = arguments.length; i < l; i++) {
			var item = arguments[i];
			if (item) items.push(item);
		}
		return Array.prototype.unshift.apply(this, items);
	}.protect(),

	concat: function() {
		var newElements = new Elements(this);
		for (var i = 0, l = arguments.length; i < l; i++) {
			var item = arguments[i];
			if (Type.isEnumerable(item)) newElements.append(item);
			else newElements.push(item);
		}
		return newElements;
	}.protect(),

	append: function(collection) {
		for (var i = 0, l = collection.length; i < l; i++) this.push(collection[i]);
		return this;
	}.protect(),

	empty: function() {
		while (this.length) delete this[--this.length];
		return this;
	}.protect()

});

//<1.2compat>

Elements.alias('extend', 'append');

//</1.2compat>

(function() {

	// FF, IE
	var splice = Array.prototype.splice,
		object = {
			'0': 0,
			'1': 1,
			length: 2
		};

	splice.call(object, 1, 1);
	if (object[1] == 1) Elements.implement('splice', function() {
		var length = this.length;
		var result = splice.apply(this, arguments);
		while (length >= this.length) delete this[length--];
		return result;
	}.protect());

	Array.forEachMethod(function(method, name) {
		Elements.implement(name, method);
	});

	Array.mirror(Elements);

	/*<ltIE8>*/
	var createElementAcceptsHTML;
	try {
		createElementAcceptsHTML = (document.createElement('<input name=x>').name == 'x');
	} catch (e) {}

	var escapeQuotes = function(html) {
		return ('' + html).replace(/&/g, '&amp;').replace(/"/g, '&quot;');
	};
	/*</ltIE8>*/

	Document.implement({

		newElement: function(tag, props) {
			if (props && props.checked != null) props.defaultChecked = props.checked;
			/*<ltIE8>*/ // Fix for readonly name and type properties in IE < 8
			if (createElementAcceptsHTML && props) {
				tag = '<' + tag;
				if (props.name) tag += ' name="' + escapeQuotes(props.name) + '"';
				if (props.type) tag += ' type="' + escapeQuotes(props.type) + '"';
				tag += '>';
				delete props.name;
				delete props.type;
			}
			/*</ltIE8>*/
			return this.id(this.createElement(tag)).set(props);
		}

	});


	Document.implement({

		newTextNode: function(text) {
			return this.createTextNode(text);
		},

		getDocument: function() {
			return this;
		},

		getWindow: function() {
			return this.window;
		},

		id: function(el) {
			if (typeOf(el) == 'string') {
				if (el.indexOf('#') == -1) {
					el = '#' + el;
				}
			}
			return Sizzle(el)[0];
		}
	});

})();


var inserters = {

	before: function(context, element) {
		$(context).insertBefore(element);
	},

	after: function(context, element) {
		$(context).insertAfter(element);
	},

	bottom: function(context, element) {
		$(element).append(context);
	},

	top: function(context, element) {
		$(element).insertBefore($(":first-child", context));
	}

};

inserters.inside = inserters.bottom;

Element.implement({
	toDom: function() {
		return this[0] || null;
	},

	setProperty: function(name, value) {
		return this.attr(name, value);
	},

	setProperties: function(attributes) {
		return this.attr(attributes);
	},

	getProperty: function(name) {
		return this.attr(name);
	},

	getProperties: function() {
		var args = Array.from(arguments);
		return args.map(this.getProperty, this).associate(args);
	},

	removeProperty: function(name) {
		return this.setProperty(name, null);
	},

	removeProperties: function() {
		Array.each(arguments, this.removeProperty, this);
		return this;
	},

	removeData: function(prop) {
		$(this).removeData(prop);
	},

	data: function(prop, value) {
		if (value) {
			return $(this).data(prop, value);
		}
		return $(this).data(prop);
	},

	set: function(prop, value) {
		var property = Element.Properties[prop];
		(property && property.set) ? property.set.call(this, value) : this.setProperty(prop, value);
	}.overloadSetter(),

	get: function(prop) {
		var property = Element.Properties[prop];
		return (property && property.get) ? property.get.apply(this) : this.getProperty(prop);
	}.overloadGetter(),

	erase: function(prop) {
		var property = Element.Properties[prop];
		(property && property.erase) ? property.erase.apply(this) : this.removeProperty(prop);
		return this;
	},

	adopt: function() {
		var parent = this.toDom(),
			fragment, elements = Array.flatten(arguments),
			length = elements.length;
		if (length > 1) parent = fragment = document.createDocumentFragment();

		for (var i = 0; i < length; i++) {
			var element = $(elements[i], true);
			if (element) parent.appendChild(element);
		}

		if (fragment) this.appendChild(fragment);

		return this;
	},

	// appendText: function(text, where) {
	// 	return this.grab(Element(text), where);
	// },

	// grab: function(el, where) {
	// 	inserters[where || 'bottom']($(el).toDom(), this);
	// 	return this;
	// },

	inject: function(el, where) {
		inserters[where || 'bottom'](this, $(el).toDom());
		return this;
	},

	replaces: function(el) {
		el = $(el).toDom();
		el.parentNode.replaceChild(this, el);
		return this;
	},

	// wraps: function(el, where) {
	// 	el = $(el).toDom();
	// 	return this.replaces(el).grab(el, where);
	// },

	getSelected: function() {
		this.toDom().selectedIndex; // Safari 3.2.1
		return new Elements(Array.from(this.options).filter(function(option) {
			return option.selected;
		}));
	},

	toQueryString: function() {
		var queryString = [];
		$('input, select, textarea', this).each(function(_el) {
			var el = _el.toDom();
			var type = el.type;
			if (!el.name || el.disabled || type == 'submit' || type == 'reset' || type == 'file' || type == 'image') return;

			var value = (el.get('tag') == 'select') ? el.getSelected().map(function(opt) {
				// IE
				return $(opt).get('value');
			}) : ((type == 'radio' || type == 'checkbox') && !el.checked) ? null : el.get('value');

			Array.from(value).each(function(val) {
				if (typeof val != 'undefined') queryString.push(encodeURIComponent(el.name) + '=' + encodeURIComponent(val));
			});
		});
		return queryString.join('&');
	}
});