
test("jQuery API", function(){

    ok($('div.find-test').find('p').length == 3, '$().find');

});