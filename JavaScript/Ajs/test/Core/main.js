Ajs.module(
    'afx'
).requires(
    'js/rq.js'
).defines(function(t){
    // console.log(t);
    return {
        name : 'TY' + t.name,
        age: 100 + t.age
    };
}).defines({
    addr: 'XM,CHN'
})

setTimeout(function(){
    console.log(Ajs.afx);
}, 100);
