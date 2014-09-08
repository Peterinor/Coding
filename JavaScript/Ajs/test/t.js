var ss = 'ss';
var sss = 'sssssssss';

for (var k = 1; k < 7; k++) {
    var len = 1000 * Math.pow(10, k);

    var dt1 = new Date();
    for (var i = 0; i < len; i++) {
        if (ss < '') {

        }
    };
    var dt2 = new Date();
    console.log(dt2 - dt1);

    for (var i = 0; i < len; i++) {
        if (sss < 'sssss') {

        }
    };
    var dt3 = new Date();

    console.log(dt3 - dt2);

    for (var i = 0; i < len; i++) {
        if (i < 100) {

        }
    };
    var dt4 = new Date();


    console.log(dt4 - dt3);
    console.log('------');
};