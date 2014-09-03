/*
---

name: Element

description: One of the most important items in MooTools. Contains the dollar function, the dollars function, and an handful of cross-browser, time-saver methods to let you easily work with HTML Elements.

requires: [Element]
provides: [Element.Attribute]

...
*/

// getProperty / setProperty

var propertyGetters = {}, propertySetters = {};

// properties

var properties = {};
Array.forEach([
	'type', 'value', 'defaultValue', 'accessKey', 'cellPadding', 'cellSpacing', 'colSpan',
	'frameBorder', 'rowSpan', 'tabIndex', 'useMap'
], function(property) {
	properties[property.toLowerCase()] = property;
});

properties.html = 'innerHTML';
properties.text = (document.createElement('div').textContent == null) ? 'innerText' : 'textContent';

Object.forEach(properties, function(real, key) {
	propertySetters[key] = function(node, value) {
		node[real] = value;
	};
	propertyGetters[key] = function(node) {
		return node[real];
	};
});

// Booleans

var bools = [
	'compact', 'nowrap', 'ismap', 'declare', 'noshade', 'checked',
	'disabled', 'readOnly', 'multiple', 'selected', 'noresize',
	'defer', 'defaultChecked', 'autofocus', 'controls', 'autoplay',
	'loop'
];

var booleans = {};
Array.forEach(bools, function(bool) {
	var lower = bool.toLowerCase();
	booleans[lower] = bool;
	propertySetters[lower] = function(node, value) {
		node[bool] = !! value;
	};
	propertyGetters[lower] = function(node) {
		return !!node[bool];
	};
});

// Special cases

Object.append(propertySetters, {

	'class': function(node, value) {
		('className' in node) ? node.className = (value || '') : node.setAttribute('class', value);
	},

	'for': function(node, value) {
		('htmlFor' in node) ? node.htmlFor = value : node.setAttribute('for', value);
	},

	'style': function(node, value) {
		(node.style) ? node.style.cssText = value : node.setAttribute('style', value);
	},

	'value': function(node, value) {
		node.value = (value != null) ? value : '';
	}

});

propertyGetters['class'] = function(node) {
	return ('className' in node) ? node.className || null : node.getAttribute('class');
};

/* <webkit> */
var el = document.createElement('button');
// IE sets type as readonly and throws
try {
	el.type = 'button';
} catch (e) {}
if (el.type != 'button') propertySetters.type = function(node, value) {
	node.setAttribute('type', value);
};
el = null;
/* </webkit> */

/*<IE>*/
var input = document.createElement('input');
input.value = 't';
input.type = 'submit';
if (input.value != 't') propertySetters.type = function(node, type) {
	var value = node.value;
	node.type = type;
	node.value = value;
};
input = null;
/*</IE>*/

/* getProperty, setProperty */

/* <ltIE9> */
var pollutesGetAttribute = (function(div) {
	div.random = 'attribute';
	return (div.getAttribute('random') == 'attribute');
})(document.createElement('div'));

var hasCloneBug = (function(test) {
	test.innerHTML = '<object><param name="should_fix" value="the unknown"></object>';
	return test.cloneNode(true).firstChild.childNodes.length != 1;
})(document.createElement('div'));
/* </ltIE9> */

var hasAttribute = function(elem, attr) {
	if (elem.hasAttribute) {
		return elem.hasAttribute(attr);
	}
	return null != elem.getAttribute(attr);
};

Element.implement({

	setProperty: function(name, value) {
		var setter = propertySetters[name.toLowerCase()];
		if (setter) {
			setter(this, value);
		} else {
			/* <ltIE9> */
			var attributeWhiteList;
			if (pollutesGetAttribute) attributeWhiteList = this.retrieve('$attributeWhiteList', {});
			/* </ltIE9> */

			if (value == null) {
				this.removeAttribute(name);
				/* <ltIE9> */
				if (pollutesGetAttribute) delete attributeWhiteList[name];
				/* </ltIE9> */
			} else {
				this.setAttribute(name, '' + value);
				/* <ltIE9> */
				if (pollutesGetAttribute) attributeWhiteList[name] = true;
				/* </ltIE9> */
			}
		}
		return this;
	},

	setProperties: function(attributes) {
		for (var attribute in attributes) this.setProperty(attribute, attributes[attribute]);
		return this;
	},

	getProperty: function(name) {
		var getter = propertyGetters[name.toLowerCase()];
		if (getter) return getter(this);
		/* <ltIE9> */
		if (pollutesGetAttribute) {
			var attr = this.getAttributeNode(name),
				attributeWhiteList = this.retrieve('$attributeWhiteList', {});
			if (!attr) return null;
			if (attr.expando && !attributeWhiteList[name]) {
				var outer = this.outerHTML;
				// segment by the opening tag and find mention of attribute name
				if (outer.substr(0, outer.search(/\/?['"]?>(?![^<]*<['"])/)).indexOf(name) < 0) return null;
				attributeWhiteList[name] = true;
			}
		}
		/* </ltIE9> */
		var result = this.getAttribute(name);
		return (!result && !hasAttribute(this, name)) ? null : result;
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

	setter: function(prop, value) {
		var property = Element.Properties[prop];
		(property && property.setter) ? property.setter.call(this, value) : this.setProperty(prop, value);
	}.overloadSetter(),

	getter: function(prop) {
		var property = Element.Properties[prop];
		return (property && property.getter) ? property.getter.apply(this) : this.getProperty(prop);
	}.overloadGetter(),

	erase: function(prop) {
		var property = Element.Properties[prop];
		(property && property.erase) ? property.erase.apply(this) : this.removeProperty(prop);
		return this;
	},

	adopt: function() {
		var parent = this,
			fragment, elements = Array.flatten(arguments),
			length = elements.length;
		if (length > 1) parent = fragment = document.createDocumentFragment();

		for (var i = 0; i < length; i++) {
			var element = document.id(elements[i], true);
			if (element) parent.appendChild(element);
		}

		if (fragment) this.appendChild(fragment);

		return this;
	},

	appendText: function(text, where) {
		return this.grab(this.getDocument().newTextNode(text), where);
	},

	grab: function(el, where) {
		inserters[where || 'bottom'](document.id(el, true), this);
		return this;
	},

	inject: function(el, where) {
		inserters[where || 'bottom'](this, document.id(el, true));
		return this;
	},

	replaces: function(el) {
		el = document.id(el, true);
		el.parentNode.replaceChild(this, el);
		return this;
	},

	wraps: function(el, where) {
		el = document.id(el, true);
		return this.replaces(el).grab(el, where);
	},

	getSelected: function() {
		this.selectedIndex; // Safari 3.2.1
		return new Elements(Array.from(this.options).filter(function(option) {
			return option.selected;
		}));
	},

	toQueryString: function() {
		var queryString = [];
		$('input, select, textarea', this).each(function(el) {
			var type = el.type;
			if (!el.name || el.disabled || type == 'submit' || type == 'reset' || type == 'file' || type == 'image') return;

			var value = (el.getter('tag') == 'select') ? el.getSelected().map(function(opt) {
				// IE
				return document.id(opt).getter('value');
			}) : ((type == 'radio' || type == 'checkbox') && !el.checked) ? null : el.getter('value');

			Array.from(value).each(function(val) {
				if (typeof val != 'undefined') queryString.push(encodeURIComponent(el.name) + '=' + encodeURIComponent(val));
			});
		});
		return queryString.join('&');
	}

});



//Class

var hasClassList = !! document.createElement('div').classList;

var classes = function(className) {
	var classNames = (className || '').clean().split(" "),
		uniques = {};
	return classNames.filter(function(className) {
		if (className !== "" && !uniques[className]) return uniques[className] = className;
	});
};

var addToClassList = function(name) {
	this.classList.add(name);
};

var removeFromClassList = function(name) {
	this.classList.remove(name);
};

//For jQuery API compact
Element.implement({

	hasClass: hasClassList ? function(className) {
		return this.classList.contains(className);
	} : function(className) {
		return this.className.clean().contains(className, ' ');
	},

	addClass: hasClassList ? function(className) {
		classes(className).forEach(addToClassList, this);
		return this;
	} : function(className) {
		this.className = classes(className + ' ' + this.className).join(' ');
		return this;
	},

	removeClass: hasClassList ? function(className) {
		classes(className).forEach(removeFromClassList, this);
		return this;
	} : function(className) {
		var classNames = classes(this.className);
		classes(className).forEach(classNames.erase, classNames);
		this.className = classNames.join(' ');
		return this;
	},

	toggleClass: function(className, force) {
		if (force == null) force = !this.hasClass(className);
		return (force) ? this.addClass(className) : this.removeClass(className);
	}
});


// appendHTML

var appendInserters = {
	before: 'beforeBegin',
	after: 'afterEnd',
	bottom: 'beforeEnd',
	top: 'afterBegin',
	inside: 'beforeEnd'
};

Element.implement('appendHTML', ('insertAdjacentHTML' in document.createElement('div')) ? function(html, where) {
	this.insertAdjacentHTML(appendInserters[where || 'bottom'], html);
	return this;
} : function(html, where) {
	var temp = new Element('div', {
		html: html
	}),
		children = temp.childNodes,
		fragment = temp.firstChild;

	if (!fragment) return this;
	if (children.length > 1) {
		fragment = document.createDocumentFragment();
		for (var i = 0, l = children.length; i < l; i++) {
			fragment.appendChild(children[i]);
		}
	}

	inserters[where || 'bottom'](fragment, this);
	return this;
});

var formProps = {
	input: 'checked',
	option: 'selected',
	textarea: 'value'
};

Element.implement({

	destroy: function() {
		var children = clean(this).getElementsByTagName('*');
		Array.each(children, clean);
		Element.dispose(this);
		return null;
	},

	empty: function() {
		Array.from(this.childNodes).each(Element.dispose);
		return this;
	},

	dispose: function() {
		return (this.parentNode) ? this.parentNode.removeChild(this) : this;
	},

	clone: function(contents, keepid) {
		contents = contents !== false;
		var clone = this.cloneNode(contents),
			ce = [clone],
			te = [this],
			i;

		if (contents) {
			ce.append(Array.from(clone.getElementsByTagName('*')));
			te.append(Array.from(this.getElementsByTagName('*')));
		}

		for (i = ce.length; i--;) {
			var node = ce[i],
				element = te[i];
			if (!keepid) node.removeAttribute('id');
			/*<ltIE9>*/
			if (node.clearAttributes) {
				node.clearAttributes();
				node.mergeAttributes(element);
				node.removeAttribute('uniqueNumber');
				if (node.options) {
					var no = node.options,
						eo = element.options;
					for (var j = no.length; j--;) no[j].selected = eo[j].selected;
				}
			}
			/*</ltIE9>*/
			var prop = formProps[element.tagName.toLowerCase()];
			if (prop && element[prop]) node[prop] = element[prop];
		}

		/*<ltIE9>*/
		if (hasCloneBug) {
			var co = clone.getElementsByTagName('object'),
				to = this.getElementsByTagName('object');
			for (i = co.length; i--;) co[i].outerHTML = to[i].outerHTML;
		}
		/*</ltIE9>*/
		return document.id(clone);
	}

});


Element.Properties = {};

Element.Properties.style = {

	setter: function(style) {
		this.style.cssText = style;
	},

	getter: function() {
		return this.style.cssText;
	},

	erase: function() {
		this.style.cssText = '';
	}

};

Element.Properties.tag = {

	getter: function() {
		return this.tagName.toLowerCase();
	}

};

Element.Properties.html = {

	setter: function(html) {
		if (html == null) html = '';
		else if (typeOf(html) == 'array') html = html.join('');
		this.innerHTML = html;
	},

	erase: function() {
		this.innerHTML = '';
	}

};



var supportsHTML5Elements = true,
	supportsTableInnerHTML = true,
	supportsTRInnerHTML = true;

/*<ltIE9>*/
// technique by jdbarlett - http://jdbartlett.com/innershiv/
var div = document.createElement('div');
div.innerHTML = '<nav></nav>';
supportsHTML5Elements = (div.childNodes.length == 1);
if (!supportsHTML5Elements) {
	var tags = 'abbr article aside audio canvas datalist details figcaption figure footer header hgroup mark meter nav output progress section summary time video'.split(' '),
		fragment = document.createDocumentFragment(),
		l = tags.length;
	while (l--) fragment.createElement(tags[l]);
}
div = null;
/*</ltIE9>*/

/*<IE>*/
supportsTableInnerHTML = Function.attempt(function() {
	var table = document.createElement('table');
	table.innerHTML = '<tr><td></td></tr>';
	return true;
});

/*<ltFF4>*/
var tr = document.createElement('tr'),
	html = '<td></td>';
tr.innerHTML = html;
supportsTRInnerHTML = (tr.innerHTML == html);
tr = null;
/*</ltFF4>*/

if (!supportsTableInnerHTML || !supportsTRInnerHTML || !supportsHTML5Elements) {

	Element.Properties.html.setter = (function(setter) {

		var translations = {
			table: [1, '<table>', '</table>'],
			select: [1, '<select>', '</select>'],
			tbody: [2, '<table><tbody>', '</tbody></table>'],
			tr: [3, '<table><tbody><tr>', '</tr></tbody></table>']
		};

		translations.thead = translations.tfoot = translations.tbody;

		return function(html) {
			var wrap = translations[this.getter('tag')];
			if (!wrap && !supportsHTML5Elements) wrap = [0, '', ''];
			if (!wrap) return setter.call(this, html);

			var level = wrap[0],
				wrapper = document.createElement('div'),
				target = wrapper;
			if (!supportsHTML5Elements) fragment.appendChild(wrapper);
			wrapper.innerHTML = [wrap[1], html, wrap[2]].flatten().join('');
			while (level--) target = target.firstChild;
			this.empty().adopt(target.childNodes);
			if (!supportsHTML5Elements) fragment.removeChild(wrapper);
			wrapper = null;
		};

	})(Element.Properties.html.setter);
}
/*</IE>*/

/*<ltIE9>*/
var testForm = document.createElement('form');
testForm.innerHTML = '<select><option>s</option></select>';

if (testForm.firstChild.value != 's') Element.Properties.value = {

	setter: function(value) {
		var tag = this.getter('tag');
		if (tag != 'select') return this.setProperty('value', value);
		var options = this.getElements('option');
		value = String(value);
		for (var i = 0; i < options.length; i++) {
			var option = options[i],
				attr = option.getAttributeNode('value'),
				optionValue = (attr && attr.specified) ? option.value : option.getter('text');
			if (optionValue === value) return option.selected = true;
		}
	},

	getter: function() {
		var option = this,
			tag = option.getter('tag');

		if (tag != 'select' && tag != 'option') return this.getProperty('value');

		if (tag == 'select' && !(option = option.getSelected()[0])) return '';

		var attr = option.getAttributeNode('value');
		return (attr && attr.specified) ? option.value : option.getter('text');
	}

};
testForm = null;
/*</ltIE9>*/

/*<IE>*/
if (document.createElement('div').getAttributeNode('id')) Element.Properties.id = {
	setter: function(id) {
		this.id = this.getAttributeNode('id').value = id;
	},
	getter: function() {
		return this.id || null;
	},
	erase: function() {
		this.id = this.getAttributeNode('id').value = '';
	}
};
/*</IE>*/