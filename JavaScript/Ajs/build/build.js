var fs = require("fs"),
    child = require("child_process"),
    path = require("path");

var config_str = fs.readFileSync('./config.json', 'utf-8');

var config = JSON.parse(config_str);

var modules = config.modules;


//生成依赖关系
var deps = {};
var req_r = /requires:.*?\[(.*?)\]/;
var pro_r = /provides:.*?\[(.*?)\]/;
for (var i = 0; i < modules.length; i++) {
    var m = modules[i];
    var src_file = config.root + m + '.js';
    var src = fs.readFileSync(src_file, 'utf-8');

    var provs = pro_r.exec(src);
    if (provs) {
        var ps = provs[1].replace(/[\[\]]/g, '').replace(/\s/g, '').split(',');
        for (var j = 0; j < ps.length; j++) {
            var p = ps[j];
            var _m = 'Ajs.' + m.replace(/[\/\\]/g, '.');
            deps[p] || (deps[p] = []);
            if (_m == 'Ajs.Core.Core.Core') {
                deps;
            } else {
                var _ms = _m.split('.');
                //去掉重复
                var msObj = '';
                for (var k = 0; k < _ms.length; k++) {
                    var __m = _ms[k];
                    if(msObj.indexOf(__m + '.') == -1){
                        msObj += __m + '.';
                    }
                };
                deps[p].push(msObj.substr(0, msObj.length -1));
            }
            // deps[p] ? deps[p].push(_m) : (deps[p] = [], deps[p].push(_m));
        };
    }
}
console.log(deps);

var campat_r = /<(.*compat)>+[\d\D]*?<\/\1>/g; //采用[\d\D]或[\w\W]或[\s\S]来解决不能换行问题

var ECMAScript5 = /<(!ES5.*?)>+[\d\D]*?<\/\1>/g;
var ltIE9_r = /<(ltIE[6789].*?)>+[\d\D]*?<\/\1>/g;


var ajsFile = '../dist/ajs.js';
var template = fs.readFileSync('./js.temp.js', 'utf-8');

if (fs.existsSync(ajsFile)) {
    fs.unlinkSync(ajsFile);
}
var fd = fs.openSync(ajsFile, 'a');
for (var i = 0; i < modules.length; i++) {
    var m = modules[i];
    var src_file = config.root + m + '.js';
    var src = fs.readFileSync(src_file, 'utf-8');

    //分析依赖
    var requires = [];
    // var requires_val = '';
    var reqs = req_r.exec(src);
    if (reqs) {
        var rs = reqs[1].replace(/[\[\]]/g, '').replace(/\s/g, '').split(',');
        for (var k = 0; k < rs.length; k++) {
            var r = rs[k];
            // requires_val += 'var ' + r + ' = this.' + r + ';';
            if (deps[r]) {
                requires = requires.concat(deps[r]);
            }
        }
    }
    // console.log(m, requires);

    src = src.replace(campat_r, '');

    if (!config.ES5) {
        src = src.replace(ECMAScript5, '');
    }
    if (!config.ltIE9) {
        src = src.replace(ltIE9_r, '');
    }
    var buf = new Buffer(src);
    // fs.appendFileSync(ajsFile, src.replace(r, ''));
    fs.writeSync(fd, buf, 0, buf.length, null);

    var sig = '../dist/' + m + '.js';
    if (fs.existsSync(sig)) {
        fs.unlinkSync(sig);
    }
    checkdir(sig, true);

    fs.appendFileSync(sig,
        template
        .replace('{{requires}}', '"' + requires.join('","') + '"')
        // .replace('{{requires_val}}', requires_val)
        .replace('{{defines}}', src));
};

fs.closeSync(fd);
// console.log(config);

function checkdir(path, isfile) {
    var _path = path.substr(0, path.lastIndexOf('/') || path.lastIndexOf('\\'));
    var ps = _path.split(/[\/\\]{1}/g);
    var p = ps[0];
    for (var i = 1; i < ps.length; i++) {
        var p = p + '/' + ps[i];
        if (!fs.existsSync(p)) {
            fs.mkdirSync(p);
        }
    };
}