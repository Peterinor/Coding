// test("$ Compactable API", function() {
//     ok($, "$");
//     ok($ == $);
//     ok($ == Ajs.$);
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


test("$.merge()", function() {
    expect(8);

    deepEqual( $.merge([],[]), [], "Empty arrays" );

    deepEqual( $.merge([ 1 ],[ 2 ]), [ 1, 2 ], "Basic" );
    deepEqual( $.merge([ 1, 2 ], [ 3, 4 ]), [ 1, 2, 3, 4 ], "Basic" );

    deepEqual( $.merge([ 1, 2 ],[]), [ 1, 2 ], "Second empty" );
    deepEqual( $.merge([],[ 1, 2 ]), [ 1, 2 ], "First empty" );

    // Fixed at [5998], #3641
    deepEqual( $.merge([ -2, -1 ], [ 0, 1, 2 ]), [ -2, -1 , 0, 1, 2 ],
        "Second array including a zero (falsy)");

    // After fixing #5527
    deepEqual( $.merge([], [ null, undefined ]), [ null, undefined ],
        "Second array including null and undefined values");
    deepEqual( $.merge({ length: 0 }, [ 1, 2 ] ), { length: 2, 0: 1, 1: 2},
        "First array like");
});


test("$.extend(Object, Object)", function() {
    expect(28);

    var settings = {
        "xnumber1": 5,
        "xnumber2": 7,
        "xstring1": "peter",
        "xstring2": "pan"
    },
        options = {
            "xnumber2": 1,
            "xstring2": "x",
            "xxx": "newstring"
        },
        optionsCopy = {
            "xnumber2": 1,
            "xstring2": "x",
            "xxx": "newstring"
        },
        merged = {
            "xnumber1": 5,
            "xnumber2": 1,
            "xstring1": "peter",
            "xstring2": "x",
            "xxx": "newstring"
        },
        deep1 = {
            "foo": {
                "bar": true
            }
        },
        deep1copy = {
            "foo": {
                "bar": true
            }
        },
        deep2 = {
            "foo": {
                "baz": true
            },
            "foo2": document
        },
        deep2copy = {
            "foo": {
                "baz": true
            },
            "foo2": document
        },
        deepmerged = {
            "foo": {
                "bar": true,
                "baz": true
            },
            "foo2": document
        },
        arr = [1, 2, 3],
        nestedarray = {
            "arr": arr
        };

    $.extend(settings, options);
    deepEqual(settings, merged, "Check if extended: settings must be extended");
    deepEqual(options, optionsCopy, "Check if not modified: options must not be modified");

    $.extend(settings, null, options);
    deepEqual(settings, merged, "Check if extended: settings must be extended");
    deepEqual(options, optionsCopy, "Check if not modified: options must not be modified");

    $.extend(true, deep1, deep2);
    deepEqual(deep1["foo"], deepmerged["foo"], "Check if foo: settings must be extended");
    deepEqual(deep2["foo"], deep2copy["foo"], "Check if not deep2: options must not be modified");
    equal(deep1["foo2"], document, "Make sure that a deep clone was not attempted on the document");

    ok($.extend(true, {}, nestedarray)["arr"] !== arr, "Deep extend of object must clone child array");

    // #5991
    ok($.isArray($.extend(true, {
        "arr": {}
    }, nestedarray)["arr"]), "Cloned array heve to be an Array");
    ok($.isPlainObject($.extend(true, {
        "arr": arr
    }, {
        "arr": {}
    })["arr"]), "Cloned object heve to be an plain object");

    var empty = {};
    var optionsWithLength = {
        "foo": {
            "length": -1
        }
    };
    $.extend(true, empty, optionsWithLength);
    deepEqual(empty["foo"], optionsWithLength["foo"], "The length property must copy correctly");

    empty = {};
    var optionsWithDate = {
        "foo": {
            "date": new Date()
        }
    };
    $.extend(true, empty, optionsWithDate);
    deepEqual(empty["foo"], optionsWithDate["foo"], "Dates copy correctly");

    /** @constructor */
    var myKlass = function() {};
    var customObject = new myKlass();
    var optionsWithCustomObject = {
        "foo": {
            "date": customObject
        }
    };
    empty = {};
    $.extend(true, empty, optionsWithCustomObject);
    ok(empty["foo"] && empty["foo"]["date"] === customObject, "Custom objects copy correctly (no methods)");

    // Makes the class a little more realistic
    myKlass.prototype = {
        "someMethod": function() {}
    };
    empty = {};
    $.extend(true, empty, optionsWithCustomObject);
    ok(empty["foo"] && empty["foo"]["date"] === customObject, "Custom objects copy correctly");

    var MyNumber = Number;
    var ret = $.extend(true, {
        "foo": 4
    }, {
        "foo": new MyNumber(5)
    });
    ok(ret.foo == 5, "Wrapped numbers copy correctly");

    var nullUndef;
    nullUndef = $.extend({}, options, {
        "xnumber2": null
    });
    ok(nullUndef["xnumber2"] === null, "Check to make sure null values are copied");

    nullUndef = $.extend({}, options, {
        "xnumber2": undefined
    });
    ok(nullUndef["xnumber2"] === options["xnumber2"], "Check to make sure undefined values are not copied");

    nullUndef = $.extend({}, options, {
        "xnumber0": null
    });
    ok(nullUndef["xnumber0"] === null, "Check to make sure null values are inserted");

    var target = {};
    var recursive = {
        foo: target,
        bar: 5
    };
    $.extend(true, target, recursive);
    deepEqual(target, {
        bar: 5
    }, "Check to make sure a recursive obj doesn't go never-ending loop by not copying it over");

    ret = $.extend(true, {
        foo: []
    }, {
        foo: [0]
    }); // 1907
    equal(ret.foo.length, 1, "Check to make sure a value with coersion 'false' copies over when necessary to fix #1907");

    ret = $.extend(true, {
        foo: "1,2,3"
    }, {
        foo: [1, 2, 3]
    });
    ok(typeof ret.foo != "string", "Check to make sure values equal with coersion (but not actually equal) overwrite correctly");

    ret = $.extend(true, {
        foo: "bar"
    }, {
        foo: null
    });
    ok(typeof ret.foo !== "undefined", "Make sure a null value doesn't crash with deep extend, for #1908");

    var obj = {
        foo: null
    };
    $.extend(true, obj, {
        foo: "notnull"
    });
    equal(obj.foo, "notnull", "Make sure a null value can be overwritten");

    function func() {}
    $.extend(func, {
        key: "value"
    });
    equal(func.key, "value", "Verify a function can be extended");

    var defaults = {
        xnumber1: 5,
        xnumber2: 7,
        xstring1: "peter",
        xstring2: "pan"
    },
        defaultsCopy = {
            xnumber1: 5,
            xnumber2: 7,
            xstring1: "peter",
            xstring2: "pan"
        },
        options1 = {
            xnumber2: 1,
            xstring2: "x"
        },
        options1Copy = {
            xnumber2: 1,
            xstring2: "x"
        },
        options2 = {
            xstring2: "xx",
            xxx: "newstringx"
        },
        options2Copy = {
            xstring2: "xx",
            xxx: "newstringx"
        },
        merged2 = {
            xnumber1: 5,
            xnumber2: 1,
            xstring1: "peter",
            xstring2: "xx",
            xxx: "newstringx"
        };

    settings = $.extend({}, defaults, options1, options2);
    deepEqual(settings, merged2, "Check if extended: settings must be extended");
    deepEqual(defaults, defaultsCopy, "Check if not modified: options1 must not be modified");
    deepEqual(options1, options1Copy, "Check if not modified: options1 must not be modified");
    deepEqual(options2, options2Copy, "Check if not modified: options2 must not be modified");
});

test("$.each(Object,Function)", function() {
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

    var stylesheet_count = 0;
    $.each(document.styleSheets, function(i) {
        stylesheet_count++;
    });
    equal(stylesheet_count, 2, "should not throw an error in IE while looping over document.styleSheets and return proper amount");

});


test("$.inArray", function() {
    expect(3);

    equal($.inArray(0, false), -1, "Search in 'false' as array returns -1 and doesn't throw exception");

    equal($.inArray(0, null), -1, "Search in 'null' as array returns -1 and doesn't throw exception");

    equal($.inArray(0, undefined), -1, "Search in 'undefined' as array returns -1 and doesn't throw exception");
});

test("$.isEmptyObject", function() {
    expect(2);

    equal(true, $.isEmptyObject({}), "isEmptyObject on empty object literal");
    equal(false, $.isEmptyObject({
        a: 1
    }), "isEmptyObject on non-empty object literal");

    // What about this ?
    // equal(true, $.isEmptyObject(null), "isEmptyObject on null" );
});

test("$.proxy", function() {
    expect(7);

    var test = function() {
        equal(this, thisObject, "Make sure that scope is set properly.");
    };
    var thisObject = {
        foo: "bar",
        method: test
    };

    // Make sure normal works
    test.call(thisObject);

    // Basic scoping
    $.proxy(test, thisObject)();

    // Another take on it
    $.proxy(thisObject, "method")();

    // Make sure it doesn't freak out
    equal($.proxy(null, thisObject), undefined, "Make sure no function was returned.");

    // Partial application
    var test2 = function(a) {
        equal(a, "pre-applied", "Ensure arguments can be pre-applied.");
    };
    $.proxy(test2, null, "pre-applied")();

    // Partial application w/ normal arguments
    var test3 = function(a, b) {
        equal(b, "normal", "Ensure arguments can be pre-applied and passed as usual.");
    };
    $.proxy(test3, null, "pre-applied")("normal");

    // Test old syntax
    var test4 = {
        "meth": function(a) {
            equal(a, "boom", "Ensure old syntax works.");
        }
    };
    $.proxy(test4, "meth")("boom");
});



test('$.noConflict', function() {

    var $$ = $.noConflict();

    equal($$, Ajs.$, "noConflict returned the $ object");
    equal(Ajs.$, $$, "Make sure jQuery wasn't touched.");

    jQuery = $ = $$;

    equal(jQuery.noConflict(true), $$, "noConflict returned the jQuery object");
    ok($$("#qunit-fixture").html("test"), "Make sure that jQuery still works.");

    window.$ = window.jQuery = $$;
});

test("trim", function() {
    expect(13);

    var nbsp = String.fromCharCode(160);

    equal($.trim("hello  "), "hello", "trailing space");
    equal($.trim("  hello"), "hello", "leading space");
    equal($.trim("  hello   "), "hello", "space on both sides");
    equal($.trim("  " + nbsp + "hello  " + nbsp + " "), "hello", "&nbsp;");

    equal($.trim(), "", "Nothing in.");
    equal($.trim(undefined), "", "Undefined");
    equal($.trim(null), "", "Null");
    equal($.trim(5), "5", "Number");
    equal($.trim(false), "false", "Boolean");

    equal($.trim(" "), "", "space should be trimmed");
    equal($.trim("ipad\xA0"), "ipad", "nbsp should be trimmed");
    equal($.trim("\uFEFF"), "", "zwsp should be trimmed");
    equal($.trim("\uFEFF \xA0! | \uFEFF"), "! |", "leading/trailing should be trimmed");
});

test("type", function() {
    expect(28);

    equal($.type(null), "null", "null");
    equal($.type(undefined), "undefined", "undefined");
    equal($.type(true), "boolean", "Boolean");
    equal($.type(false), "boolean", "Boolean");
    equal($.type(Boolean(true)), "boolean", "Boolean");
    equal($.type(0), "number", "Number");
    equal($.type(1), "number", "Number");
    equal($.type(Number(1)), "number", "Number");
    equal($.type(""), "string", "String");
    equal($.type("a"), "string", "String");
    equal($.type(String("a")), "string", "String");
    equal($.type({}), "object", "Object");
    equal($.type(/foo/), "regexp", "RegExp");
    equal($.type(new RegExp("asdf")), "regexp", "RegExp");
    equal($.type([1]), "array", "Array");
    equal($.type(new Date()), "date", "Date");
    equal($.type(new Function("return;")), "function", "Function");
    equal($.type(function() {}), "function", "Function");
    equal($.type(new Error()), "error", "Error");
    equal($.type(window), "window", "Window");
    equal($.type(document), "document", "Document");
    equal($.type(document.body), "element", "Element");
    equal($.type(document.createTextNode("foo")), "textnode", "TextNode");
    equal($.type(document.getElementsByTagName("*")), "collection", "NodeList");

    // Avoid Lint complaints
    var MyString = String;
    var MyNumber = Number;
    var MyBoolean = Boolean;
    var MyObject = Object;
    equal($.type(new MyBoolean(true)), "boolean", "Boolean");
    equal($.type(new MyNumber(1)), "number", "Number");
    equal($.type(new MyString("a")), "string", "String");
    equal($.type(new MyObject()), "object", "Object");
});

asyncTest("isPlainObject", function() {
    expect(15);

    var pass, iframe, doc,
        fn = function() {};

    // The use case that we want to match
    ok($.isPlainObject({}), "{}");

    // Not objects shouldn't be matched
    ok(!$.isPlainObject(""), "string");
    ok(!$.isPlainObject(0) && !$.isPlainObject(1), "number");
    ok(!$.isPlainObject(true) && !$.isPlainObject(false), "boolean");
    ok(!$.isPlainObject(null), "null");
    ok(!$.isPlainObject(undefined), "undefined");

    // Arrays shouldn't be matched
    ok(!$.isPlainObject([]), "array");

    // Instantiated objects shouldn't be matched
    ok(!$.isPlainObject(new Date()), "new Date");

    // Functions shouldn't be matched
    ok(!$.isPlainObject(fn), "fn");

    // Again, instantiated objects shouldn't be matched
    ok(!$.isPlainObject(new fn()), "new fn (no methods)");

    // Makes the function a little more realistic
    // (and harder to detect, incidentally)
    fn.prototype["someMethod"] = function() {};

    // Again, instantiated objects shouldn't be matched
    ok(!$.isPlainObject(new fn()), "new fn");

    // DOM Element
    ok(!$.isPlainObject(document.createElement("div")), "DOM Element");

    // Window
    ok(!$.isPlainObject(window), "window");

    pass = false;
    try {
        $.isPlainObject(window.location);
        pass = true;
    } catch (e) {}
    ok(pass, "Does not throw exceptions on host objects");

    // Objects from other windows should be matched
    window.iframeCallback = function(otherObject, detail) {
        window.iframeCallback = undefined;
        iframe.parentNode.removeChild(iframe);
        ok($.isPlainObject(new otherObject()), "new otherObject" + (detail ? " - " + detail : ""));
        start();
    };

    try {
        iframe = $("#qunit-fixture")[0].appendChild(document.createElement("iframe"));
        doc = iframe.contentDocument || iframe.contentWindow.document;
        doc.open();
        doc.write("<body onload='window.parent.iframeCallback(Object);'>");
        doc.close();
    } catch (e) {
        window.iframeDone(Object, "iframes not supported");
    }
});


test("isFunction", function() {
    expect(19);

    // Make sure that false values return false
    ok(!$.isFunction(), "No Value");
    ok(!$.isFunction(null), "null Value");
    ok(!$.isFunction(undefined), "undefined Value");
    ok(!$.isFunction(""), "Empty String Value");
    ok(!$.isFunction(0), "0 Value");

    // Check built-ins
    // Safari uses "(Internal Function)"
    ok($.isFunction(String), "String Function(" + String + ")");
    ok($.isFunction(Array), "Array Function(" + Array + ")");
    ok($.isFunction(Object), "Object Function(" + Object + ")");
    ok($.isFunction(Function), "Function Function(" + Function + ")");

    // When stringified, this could be misinterpreted
    var mystr = "function";
    ok(!$.isFunction(mystr), "Function String");

    // When stringified, this could be misinterpreted
    var myarr = ["function"];
    ok(!$.isFunction(myarr), "Function Array");

    // When stringified, this could be misinterpreted
    var myfunction = {
        "function": "test"
    };
    ok(!$.isFunction(myfunction), "Function Object");

    // Make sure normal functions still work
    var fn = function() {};
    ok($.isFunction(fn), "Normal Function");

    var obj = document.createElement("object");

    // Firefox says this is a function
    ok(!$.isFunction(obj), "Object Element");

    // IE says this is an object
    // Since 1.3, this isn't supported (#2968)
    //ok( $.isFunction(obj.getAttribute), "getAttribute Function" );

    var nodes = document.body.childNodes;

    // Safari says this is a function
    ok(!$.isFunction(nodes), "childNodes Property");

    var first = document.body.firstChild;

    // Normal elements are reported ok everywhere
    ok(!$.isFunction(first), "A normal DOM Element");

    var input = document.createElement("input");
    input.type = "text";
    document.body.appendChild(input);

    // IE says this is an object
    // Since 1.3, this isn't supported (#2968)
    //ok( $.isFunction(input.focus), "A default function property" );

    document.body.removeChild(input);

    var a = document.createElement("a");
    a.href = "some-function";
    document.body.appendChild(a);

    // This serializes with the word 'function' in it
    ok(!$.isFunction(a), "Anchor Element");

    document.body.removeChild(a);

    // Recursive function calls have lengths and array-like properties

    function callme(callback) {
        function fn(response) {
            callback(response);
        }

        ok($.isFunction(fn), "Recursive Function Call");

        fn({
            some: "data"
        });
    }

    callme(function() {
        callme(function() {});
    });
});

test("isNumeric", function() {
    expect(36);

    var t = $.isNumeric,
        Traditionalists = /** @constructor */ function(n) {
            this.value = n;
            this.toString = function() {
                return String(this.value);
            };
        },
        answer = new Traditionalists("42"),
        rong = new Traditionalists("Devo");

    ok(t("-10"), "Negative integer string");
    ok(t("0"), "Zero string");
    ok(t("5"), "Positive integer string");
    ok(t(-16), "Negative integer number");
    ok(t(0), "Zero integer number");
    ok(t(32), "Positive integer number");
    ok(t("040"), "Octal integer literal string");
    // OctalIntegerLiteral has been deprecated since ES3/1999
    // It doesn't pass lint, so disabling until a solution can be found
    //ok( t(0144), "Octal integer literal");
    ok(t("0xFF"), "Hexadecimal integer literal string");
    ok(t(0xFFF), "Hexadecimal integer literal");
    ok(t("-1.6"), "Negative floating point string");
    ok(t("4.536"), "Positive floating point string");
    ok(t(-2.6), "Negative floating point number");
    ok(t(3.1415), "Positive floating point number");
    ok(t(8e5), "Exponential notation");
    ok(t("123e-2"), "Exponential notation string");
    ok(t(answer), "Custom .toString returning number");
    equal(t(""), false, "Empty string");
    equal(t("        "), false, "Whitespace characters string");
    equal(t("\t\t"), false, "Tab characters string");
    equal(t("abcdefghijklm1234567890"), false, "Alphanumeric character string");
    equal(t("xabcdefx"), false, "Non-numeric character string");
    equal(t(true), false, "Boolean true literal");
    equal(t(false), false, "Boolean false literal");
    equal(t("bcfed5.2"), false, "Number with preceding non-numeric characters");
    equal(t("7.2acdgs"), false, "Number with trailling non-numeric characters");
    equal(t(undefined), false, "Undefined value");
    equal(t(null), false, "Null value");
    equal(t(NaN), false, "NaN value");
    equal(t(Infinity), false, "Infinity primitive");
    equal(t(Number.POSITIVE_INFINITY), false, "Positive Infinity");
    equal(t(Number.NEGATIVE_INFINITY), false, "Negative Infinity");
    equal(t(rong), false, "Custom .toString returning non-number");
    equal(t({}), false, "Empty object");
    equal(t(function() {}), false, "Instance of a function");
    equal(t(new Date()), false, "Instance of a Date");
    equal(t(function() {}), false, "Instance of a function");
});

test("isWindow", function() {
    expect(14);

    ok($.isWindow(window), "window");
    ok($.isWindow(document.getElementsByTagName("iframe")[0].contentWindow), "iframe.contentWindow");
    ok(!$.isWindow(), "empty");
    ok(!$.isWindow(null), "null");
    ok(!$.isWindow(undefined), "undefined");
    ok(!$.isWindow(document), "document");
    ok(!$.isWindow(document.documentElement), "documentElement");
    ok(!$.isWindow(""), "string");
    ok(!$.isWindow(1), "number");
    ok(!$.isWindow(true), "boolean");
    ok(!$.isWindow({}), "object");
    ok(!$.isWindow({
        setInterval: function() {}
    }), "fake window");
    ok(!$.isWindow(/window/), "regexp");
    ok(!$.isWindow(function() {}), "function");
});



test("Traversing", function() {
    ok($('div.find-test').find('p').length == 3, '$().find');

});