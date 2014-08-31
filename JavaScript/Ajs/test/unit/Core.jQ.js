// test("jQuery Compactable API", function() {
//     ok(jQuery, "jQuery");
//     ok(jQuery == $);
//     ok(jQuery == Ajs.$);
// });

test("Utilities", function() {
    var func = function() {};
    ok($.type("string") == 'string', '$.type("string")');

    ok($.type(func) == 'function', '$.type(func)');
    ok($.isFunction(func), '$.isFunction(func)');

    ok($.type([]) == 'array', '$.type([])');
    ok($.isArray([]), '$.isArray([])');
    ok(!$.isArray({}), '$.isArray({}})');

    ok($.isNumeric(2), '$.isNumeric(2)');
    ok($.isNumeric("2"), '$.isNumeric("2")');
    ok(!$.isNumeric("A2"), '$.isNumeric("A2")');

    ok($.isWindow(window), '$.isWindow(window)');
    ok(!$.isWindow(document), '$.isWindow(document)');

    ok($.isEmptyObject({}), '$.isEmptyObject({})');
    ok(!$.isEmptyObject({
        a: 1
    }), '$.isEmptyObject({a : 1})');

    ok($.isPlainObject({
        a: 1
    }), '$.isPlainObject({a : 1})');
    ok($.isPlainObject(new Object({
        a: 1
    })), '$.isPlainObject(new Object({a : 1}))');
    ok(!$.isPlainObject(document), '$.isPlainObject(document)');

});


test("Utilities/$.each(Object,Function)", function() {
    // expect(14);
    $.each([0, 1, 2], function(i, n) {
        equal(i, n, "Check array iteration");
    });

    $.each([5, 6, 7], function(i, n) {
        equal(i, n - 5, "Check array iteration");
    });

    $.each({
        name: "name",
        lang: "lang"
    }, function(i, n) {
        equal(i, n, "Check object iteration");
    });

    var total = 0;
    $.each([1, 2, 3], function(i, v) {
        total += v;
    });
    equal(total, 6, "Looping over an array");
    total = 0;
    $.each([1, 2, 3], function(i, v) {
        total += v;
        if (i == 1) {
            return false;
        }
    });
    equal(total, 3, "Looping over an array, with break");
    total = 0;
    $.each({
        "a": 1,
        "b": 2,
        "c": 3
    }, function(i, v) {
        total += v;
    });
    equal(total, 6, "Looping over an object");
    total = 0;
    $.each({
        "a": 3,
        "b": 3,
        "c": 3
    }, function(i, v) {
        total += v;
        return false;
    });
    equal(total, 3, "Looping over an object, with break");

    var f = function() {};
    f.foo = "bar";
    $.each(f, function(i) {
        f[i] = "baz";
    });
    equal("baz", f.foo, "Loop over a function");

    // var stylesheet_count = 0;
    // $.each(document.styleSheets, function(i) {
    //     stylesheet_count++;
    // });
    // equal(stylesheet_count, 2, "should not throw an error in IE while looping over document.styleSheets and return proper amount");
});


test("Traversing", function() {
    ok($('div.find-test').find('p').length == 3, '$().find');

});

// test('$.noConflict', function() {

//     var $ = Ajs.$.noConflict();

//     ok($ != Ajs.$, 'Ajs.$/jQuery .noConflict()');

// });