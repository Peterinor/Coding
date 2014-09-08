module('More.Afx');

test('More.Afx.Observable/Model', function() {

    var User = new Class({

        Extends: Ajs.Afx.Model,

        initialize: function(name, age) {
            this._super({
                name: name,
                age: age
            });
        }
    });

    var u = new User('ty', 25);
    u.addValidates(function(attr) {
        // return 'xxx';
    });

    strictEqual(u.get('name'), 'ty', 'get');
    strictEqual(u.get('age'), 25, 'get');

    var name = 'ty';
    u.on('change:name', function(data) {
        name = data.to;
    });

    u.set('name', 'TY');

    strictEqual(u.get('name'), 'TY', 'set&change:name event');
    strictEqual(name, 'TY', 'set&change:name event');

    u.set('name', 'ty', {
        silent: true
    })
    strictEqual(u.get('name'), 'ty', 'set with silent options');
    strictEqual(name, 'TY', 'set with silent options');

    u.addValidates('age', function(v, k) {
        if (typeOf(v) != 'number') return 'age must be a numberic value';
    });

    var invalidCount = 0;
    u.on('invalid', function(err) {
        console.log(err);
        strictEqual(err, 'age must be a numberic value', 'model validate');
        invalidCount++;
    });

    u.set('age', '20', {
        validate: true
    });

    strictEqual(invalidCount, 1);

    var ageCount = 0;
    u.on('change:age', function(data) {
        console.log(data);
        ageCount++;
    });

    u.set('age', 20);
    strictEqual(ageCount, 1, 'set/same data is not set to model');
    u.set('age', 20);
    u.set('age', 20);
    u.set('age', 20);
    strictEqual(ageCount, 1, 'same data is not set to model');

    u.removeValidates('age');

    u.set('age', '20', {
        validate: true
    });

    strictEqual(invalidCount, 1, 'removeValidates');

    var u2 = new User('TTY', 26);
    console.log(u.cid, u2.cid);
    notEqual(u.cid, u2.cid, 'cid');

});