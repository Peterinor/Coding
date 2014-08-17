var fs = require("fs"),
    child = require("child_process"),
    path = require("path");

var config_str = fs.readFileSync('./config.json', 'utf-8');

var config = JSON.parse(config_str);

var modules = config.modules;


var ajsFile = './ajs.js';
if (fs.existsSync(ajsFile)) {
    fs.unlinkSync(ajsFile);
}
var r = /<(.*compat)>+[\d\D]*?<\/\1>/g; //采用[\d\D]或[\w\W]或[\s\S]来解决不能换行问题

for (var i = 0; i < modules.length; i++) {
    var m = modules[i];
    var src_file = config.root + m + '.js';
    var src = fs.readFileSync(src_file, 'utf-8');

    fs.appendFileSync(ajsFile, src.replace(r, ''));
};

console.log(config);