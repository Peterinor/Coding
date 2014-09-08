/*
---

name: Event

description: Contains the Event Type, to make the event object cross-browser.

requires: [Window, Document, Array, Function, String, Object]

provides: [DOMEvent]

...
*/

(function() {

	var _keys = {};

	var DOMEvent = this.DOMEvent = new Type('DOMEvent', function(event, win, data) {
		if (!win) win = window;
		event = event || win.event;
		if (event.$extended) return event;
		this.event = this.originalEvent = event;
		this.$extended = true;
		this.shift = this.shiftKey = event.shiftKey;
		this.control = this.ctrlKey = event.ctrlKey;
		this.alt = this.altKey = event.altKey;
		this.meta = this.metaKey = event.metaKey;
		var type = this.type = event.type;
		var target = event.target || event.srcElement;
		while (target && target.nodeType == 3) target = target.parentNode;
		this.target = new Element(target);
		this.relatedTarget = event.relatedTarget;
		this.currentTarget = this.delegateTarget = this.target;
		this.data = data;

		if (type.indexOf('key') == 0) {
			var code = this.which = this.code = (event.which || event.keyCode);
			this.key = _keys[code];
			if (type == 'keydown' || type == 'keyup') {
				if (code > 111 && code < 124) this.key = 'f' + (code - 111);
				else if (code > 95 && code < 106) this.key = code - 96;
			}
			if (this.key == null) this.key = String.fromCharCode(code).toLowerCase();
		} else if (type == 'click' || type == 'dblclick' || type == 'contextmenu' || type == 'DOMMouseScroll' || type.indexOf('mouse') == 0) {
			var doc = win.document;
			doc = (!doc.compatMode || doc.compatMode == 'CSS1Compat') ? doc.html : doc.body;
			this.page = {
				x: (event.pageX != null) ? event.pageX : event.clientX + doc.scrollLeft,
				y: (event.pageY != null) ? event.pageY : event.clientY + doc.scrollTop
			};
			this.client = {
				x: (event.pageX != null) ? event.pageX - win.pageXOffset : event.clientX,
				y: (event.pageY != null) ? event.pageY - win.pageYOffset : event.clientY
			};
			if (type == 'DOMMouseScroll' || type == 'mousewheel')
				this.wheel = (event.wheelDelta) ? event.wheelDelta / 120 : -(event.detail || 0) / 3;

			// Add which for click: 1 === left; 2 === middle; 3 === right
			this.which = event.which;
			var button = event.button;
			if (!this.which && button !== undefined) {
				this.which = (button & 1 ? 1 : (button & 2 ? 3 : (button & 4 ? 2 : 0)));
			}

			this.rightClick = (this.which == 3);
			if (type == 'mouseover' || type == 'mouseout') {
				var related = event.relatedTarget || event[(type == 'mouseover' ? 'from' : 'to') + 'Element'];
				while (related && related.nodeType == 3) related = related.parentNode;
				this.relatedTarget = new Element(target);
			}
		} else if (type.indexOf('touch') == 0 || type.indexOf('gesture') == 0) {
			this.rotation = event.rotation;
			this.scale = event.scale;
			this.targetTouches = event.targetTouches;
			this.changedTouches = event.changedTouches;
			var touches = this.touches = event.touches;
			if (touches && touches[0]) {
				var touch = touches[0];
				this.page = {
					x: touch.pageX,
					y: touch.pageY
				};
				this.client = {
					x: touch.clientX,
					y: touch.clientY
				};
			}
		}

		if (!this.client) this.client = {};
		if (!this.page) this.page = {};

		this.timeStamp = Date.now();
		this.isImmediatePropagationStopped = this.isDefaultPrevented = this.isPropagationStopped = Function.returnFalse;
	});

	DOMEvent.implement({

		stop: function() {
			return this.preventDefault().stopPropagation();
		},

		stopImmediatePropagation: function() {
			this.stopPropagation();
			this.isImmediatePropagationStopped = Function.returnTrue;
			return this;
		},

		stopPropagation: function() {
			if (this.event.stopPropagation) this.event.stopPropagation();
			else this.event.cancelBubble = true;
			this.isPropagationStopped = Function.returnTrue;
			return this;
		},

		preventDefault: function() {
			if (this.event.preventDefault) this.event.preventDefault();
			else this.event.returnValue = false;
			this.isDefaultPrevented = Function.returnTrue;
			return this;
		}

	});

	DOMEvent.defineKey = function(code, key) {
		_keys[code] = key;
		return this;
	};

	DOMEvent.defineKeys = DOMEvent.defineKey.overloadSetter(true);

	DOMEvent.defineKeys({
		'38': 'up',
		'40': 'down',
		'37': 'left',
		'39': 'right',
		'27': 'esc',
		'32': 'space',
		'8': 'backspace',
		'9': 'tab',
		'46': 'delete',
		'13': 'enter'
	});

})();