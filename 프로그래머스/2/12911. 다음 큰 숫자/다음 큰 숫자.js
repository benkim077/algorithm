function _count(n) {
    let _ret = 0;
    while(n > 1) {
        if(n % 2 == 1) _ret++;
        n = Math.floor(n / 2);
    }
    _ret++;
    return _ret;
}

function solution(n) {
    const cnt = _count(n);
    let ret = n;
    while(true) {
        if(cnt == _count(++ret)) break;
    }
    return ret;
}