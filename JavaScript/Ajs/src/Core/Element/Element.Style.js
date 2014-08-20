/*
---

name: Element.Style

description: Contains methods for interacting with the styles of Elements in a fashionable way.

license: MIT-style license.

requires: Element

provides: Element.Style

...
*/


//Element.Style
var html = document.html;

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

var hasGetComputedStyle = !!window.getComputedStyle;

Element.implement({
	getComputedStyle: function(property) {
		var _this = this;
		if (!hasGetComputedStyle && _this.currentStyle) return _this.currentStyle[property.camelCase()];
		var defaultView = document.defaultView,
			computed = defaultView ? defaultView.getComputedStyle(_this, null) : null;
		return (computed) ? computed.getPropertyValue((property == floatName) ? 'float' : property.hyphenate()) : '';
	},
	getStyle: function(prop) {
		return $(this).css(prop);
	},
	setStyle: function(prop, value) {
		$(this).css(prop, value);
		return this;
	},
	getStyles: function(props) {
		return $(this).css(props);
	},
	setStyles: function(css) {
		$(this).css(css);
		return this;
	}
});

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