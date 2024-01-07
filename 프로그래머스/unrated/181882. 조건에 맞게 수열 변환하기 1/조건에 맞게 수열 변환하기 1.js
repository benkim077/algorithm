function solution(arr) {
    return arr.map(fn);
}

const fn = (e) => {
    if(e >= 50 && !(e % 2)) return e / 2;
    if(e < 50 && e % 2) return e * 2;
    return e;
}