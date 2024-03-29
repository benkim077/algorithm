function solution(q, r, code) {
    let res = "";
    Array.from(code).forEach((_, idx) => {
        if(idx % q === r) res += code.at(idx);
    })
    return res;
}