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
	var el = jQuery(tag).attr(props);
	return el;
};

var Element = this.Element = jQuery;


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

	set: function(prop, value) {
		var property = Element.Properties[prop];
		(property && property.set) ? property.set.call(this, value) : this.setProperty(prop, value);
	}.overloadSetter(),

	get: function(prop) {
		if (typeOf(prop) == 'number') {
			return this[0];
		}
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


//Element.Style
var html = document.html,
	el;


Element.Properties = {};


Element.Properties.style = {

	set: function(style) {
		this.toDom().style.cssText = style;
	},

	get: function() {
		return this.toDom().style.cssText;
	},

	erase: function() {
		this.toDom().style.cssText = '';
	}

};

Element.Properties.tag = {

	get: function() {
		return this.toDom().tagName.toLowerCase();
	}

};

Element.Properties.html = {

	set: function(html) {
		if (html == null) html = '';
		else if (typeOf(html) == 'array') html = html.join('');
		this.toDom().innerHTML = html;
	},

	erase: function() {
		this.toDom().innerHTML = '';
	}

};

var floatName = (html.style.cssFloat == null) ? 'styleFloat' : 'cssFloat',
	namedPositions = {
		left: '0%',
		top: '0%',
		center: '50%',
		right: '100%',
		bottom: '100%'
	},
	hasBackgroundPositionXY = (html.style.backgroundPositionX != null);


Element.Styles = {
	left: '@px',
	top: '@px',
	bottom: '@px',
	right: '@px',
	width: '@px',
	height: '@px',
	maxWidth: '@px',
	maxHeight: '@px',
	minWidth: '@px',
	minHeight: '@px',
	backgroundColor: 'rgb(@, @, @)',
	backgroundSize: '@px',
	backgroundPosition: '@px @px',
	color: 'rgb(@, @, @)',
	fontSize: '@px',
	letterSpacing: '@px',
	lineHeight: '@px',
	clip: 'rect(@px @px @px @px)',
	margin: '@px @px @px @px',
	padding: '@px @px @px @px',
	border: '@px @ rgb(@, @, @) @px @ rgb(@, @, @) @px @ rgb(@, @, @)',
	borderWidth: '@px @px @px @px',
	borderStyle: '@ @ @ @',
	borderColor: 'rgb(@, @, @) rgb(@, @, @) rgb(@, @, @) rgb(@, @, @)',
	zIndex: '@',
	'zoom': '@',
	fontWeight: '@',
	textIndent: '@px',
	opacity: '@'
};

Element.ShortStyles = {
	margin: {},
	padding: {},
	border: {},
	borderWidth: {},
	borderStyle: {},
	borderColor: {}
};

['Top', 'Right', 'Bottom', 'Left'].each(function(direction) {
	var Short = Element.ShortStyles;
	var All = Element.Styles;
	['margin', 'padding'].each(function(style) {
		var sd = style + direction;
		Short[style][sd] = All[sd] = '@px';
	});
	var bd = 'border' + direction;
	Short.border[bd] = All[bd] = '@px @ rgb(@, @, @)';
	var bdw = bd + 'Width',
		bds = bd + 'Style',
		bdc = bd + 'Color';
	Short[bd] = {};
	Short.borderWidth[bdw] = Short[bd][bdw] = All[bdw] = '@px';
	Short.borderStyle[bds] = Short[bd][bds] = All[bds] = '@';
	Short.borderColor[bdc] = Short[bd][bdc] = All[bdc] = 'rgb(@, @, @)';
});

if (hasBackgroundPositionXY) Element.ShortStyles.backgroundPosition = {
	backgroundPositionX: '@',
	backgroundPositionY: '@'
};