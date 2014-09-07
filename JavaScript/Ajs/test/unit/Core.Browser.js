
module('Core.Browser');

test("Core.Browser", function(){
    ok(Ajs.Browser, "Browser Object");
    ok(Ajs.Browser.name, "Browser name");
    ok(Ajs.version, "Browser version");
    ok(Ajs.Browser.platform, "Browser platform");

    ok(Ajs.Browser.Request, "Xhr Request");
    var xhr = Ajs.Browser.Request();
    ok(xhr, "Xhr Request Object");
    ok(xhr.send, "Xhr send");
});