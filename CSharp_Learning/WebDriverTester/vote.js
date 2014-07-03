
window.totalticket = 0;

window.vote1736 = function (code) {

    team_id = 1736;
    vote_code = code;

    voteOpt = {
        type: "POST",
        url: "/www/cydx/vote",
        cache: false,
        dataType: "json",
        data: { 'team_id': team_id, 'vote_code': vote_code },
        success: function (result) {
            if (result['status'] > 0) {
                window.totalticket = result['data'][0];
            } else {
                alert(result['info']);
            }
        }
    };
    //开始AJAX请求
    $.ajax(voteOpt);
}

window.getCount = function () {
    return window.totalticket;
}