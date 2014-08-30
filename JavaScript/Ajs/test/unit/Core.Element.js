
test("Core.Element", function(){

    var body = document.body;
    ok(new Ajs.Element("body") == body, 'new Ajs.Element("body")');
    ok($("body").get(0) == body, 'Selector: body');

    ok($('div#test').length == 1, 'Selector: #test');

    ok(document.id('test'), 'document.id("id")');
    ok(document.id('#test'), 'document.id("#id")');
    ok(document.id('test') == document.id('#test'), 'id("id") == id("id")');
    ok(document.id('#test') == new Ajs.Element('#test'), 'document.id() == new Ajs.Element("#id")');
    ok(Ajs.Element('#test') == new Ajs.Element('#test'), 'Ajs.Element("") == new Ajs.Element("")');

    var el = new Ajs.Element('#test');
    ok(el, 'el is ok');

    [el, window, document].each(function(e, ind){
        e.store('test', 'testData');
    }).each(function(e, ind){
        ok(el.retrieve('test') == 'testData', typeOf(e) + '.store()/.retrieve()');
    });

    [window, document, body].each(function(el){
        ok(el == Ajs.Element(el), 'dom == Ajs.Element(dom)');
    });

    ok(document.getDocument() == window.getDocument(), 'getDocument()')
    ok(document.getDocument() == document.body.getDocument(), 'getDocument()')
    ok(document.getWindow() == window.getWindow(), 'getWindow()')
    ok(document.getWindow() == document.body.getWindow(), 'getWindow()')
 });