function solution(arr) {
    const res = [];
    arr.forEach(num => {
        for(let i = 0; i < num; i++) {
            res.push(num);
        }
    });
    return res;
}