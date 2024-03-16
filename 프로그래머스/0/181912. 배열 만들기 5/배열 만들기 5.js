function solution(intStrs, k, s, l) {
    const res = [];
    for(let i = 0; i < intStrs.length; i++) {
        const slicedNumber = Number(intStrs[i].slice(s, s + l));
        if(slicedNumber > k) res.push(slicedNumber);
    }
    return res;
}