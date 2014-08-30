test("Basic requirements", function() {
	expect(9);
	
	ok(Array.prototype.push, "Array.push()");
	ok(Function.prototype.apply, "Function.apply()");
	ok(document.getElementById, "getElementById");
	ok(document.getElementsByTagName, "getElementsByTagName");
	ok(RegExp, "RegExp");

	var _Class = function(){};
	var a = new _Class;
	ok(a instanceof _Class, 'instanceof');

	var __Class = function(){
		return this;
	};
	var _a = new __Class;
	ok(_a instanceof __Class, 'instanceof');

	ok(Ajs.$, "Ajs.$");
	ok($, "$");
});

test("typeOf()", function() {
	expect(15);

	ok(typeOf == Ajs.typeOf, 'Ajs.typeOf');

	ok(typeOf(2) == 'number', '2');
	ok(typeOf(new Number(2)) == 'number', 'new Number(2)');
	ok(typeOf(Number(2)) == 'number', 'Number(2)');

	ok(typeOf("string") == 'string', 'string');
	ok(typeOf(String("string")) == 'string', 'String("string")');
	ok(typeOf(new String("string")) == 'string', 'new String("string")');

	ok(typeOf({}) == 'object', '{}');
	ok(typeOf(new Object()) == 'object', 'new Object()');

	ok(typeOf([]) == 'array', '[]');
	ok(typeOf(Array()) == 'array', 'Array()');
	ok(typeOf(new Array()) == 'array', 'new Array()');

	ok(typeOf(document.body) == 'element', 'document.body');

	var _type = {};
	_type.$family = function() {
		return "_type";
	}
	ok(typeOf(_type) == '_type', '$family()');
	(function() {
		ok(typeOf(arguments) == 'arguments', 'arguments');
	})();

});

test('instanceOf()', function() {
	expect(10);

	ok(instanceOf == Ajs.instanceOf, 'Ajs.instanceOf');

	ok(instanceOf(2, Number), '2 is a Number');
	ok(!instanceOf("2", Number), '"2" is not a Number');

	ok(instanceOf("string", String), '"string" is a String');
	ok(instanceOf(new String("string"), String), 'new String("string") is a String');

	ok(instanceOf([], Array), '[] is an Array');
	ok(instanceOf({}, Object), '{} is an Object');

	ok(instanceOf(function() {}, Function), 'function(){} is a Function');

	function _inst() {}
	var _ins = new _inst();
	ok(instanceOf(_ins, _inst), 'new _inst() is instanceof function _inst(){}');

	var proto = function(){};
	function AClass(){};
	AClass.prototype = new proto;
	var a = new AClass();
	ok(instanceOf(a, proto), 'instanceof prototype');
});