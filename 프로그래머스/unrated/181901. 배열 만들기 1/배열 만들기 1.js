function solution(n, k) {
    return Array.from({length: n}, (e, i) => i + 1).filter(e => e % k ? false : true);
    // const res = [];
    // for(let i = 1; i < n + 1; i++) {
    //     if(!(i % k)) res.push(i); 
    // }
    // return res;
}