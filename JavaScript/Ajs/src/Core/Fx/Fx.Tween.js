/*
---

name: Fx.Tween

description: Formerly Fx.Style, effect to transition any CSS property for an element.

license: MIT-style license.

requires: [Fx.CSS]

provides: [Fx.Tween, Element.fade, Element.highlight]

...
*/

Fx.Tween = new Class({

	Extends: Fx.CSS,

	initialize: function(element, options){
		this.element = this.subject = new Element(element);
		this.parent(options);
	},

	set: function(property, now){
		if (arguments.length == 1){
			now = property;
			property = this.property || this.options.property;
		}
		this.render(this.element, property, now, this.options.unit);
		return this;
	},

	start: function(property, from, to){
		if (!this.check(property, from, to)) return this;
		var args = Array.flatten(arguments);
		this.property = this.options.property || args.shift();
		var parsed = this.prepare(this.element, this.property, args);
		return this.parent(parsed.from, parsed.to);
	}

});

Element.Properties.tween = {

	setter: function(options){
		this.getter('tween').cancel().setOptions(options);
		return this;
	},

	getter: function(){
		var tween = this.data('tween');
		if (!tween){
			tween = new Fx.Tween(this, {link: 'cancel'});
			this.data('tween', tween);
		}
		return tween;
	}

};

Element.implement({

	tween: function(property, from, to){
		this.getter('tween').start(property, from, to);
		return this;
	},

	fade: function(how){
		var fade = this.getter('tween'), method, args = ['opacity'].append(arguments), toggle;
		if (args[1] == null) args[1] = 'toggle';
		switch (args[1]){
			case 'in': method = 'start'; args[1] = 1; break;
			case 'out': method = 'start'; args[1] = 0; break;
			case 'show': method = 'set'; args[1] = 1; break;
			case 'hide': method = 'set'; args[1] = 0; break;
			case 'toggle':
				var flag = this.data('fade:flag', this.getStyle('opacity') == 1);
				method = 'start';
				args[1] = flag ? 0 : 1;
				this.data('fade:flag', !flag);
				toggle = true;
			break;
			default: method = 'start';
		}
		if (!toggle) this.removeData('fade:flag');
		fade[method].apply(fade, args);
		var to = args[args.length - 1];
		if (method == 'set' || to != 0) this.setStyle('visibility', to == 0 ? 'hidden' : 'visible');
		else fade.chain(function(){
			this.element.setStyle('visibility', 'hidden');
			this.callChain();
		});
		return this;
	},

	highlight: function(start, end){
		if (!end){
			end = this.data('highlight:original', this.getStyle('background-color'));
			end = (end == 'transparent') ? '#fff' : end;
		}
		var tween = this.getter('tween');
		tween.start('background-color', start || '#ffff88', end).chain(function(){
			this.setStyle('background-color', this.data('highlight:original'));
			tween.callChain();
		}.bind(this));
		return this;
	}

});
