function solution(names) {
    const res = [];
    for(let i = 0; i < names.length; i = i + 5) {
        res.push(names[i]);
    }
    return res;
}