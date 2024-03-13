function solution(arr, flag) {
    let res = [];
    
    arr.forEach((num, idx) => {
        if(flag[idx]) {
            for(let i = 0; i < 2 * num; i++) {
                res.push(num);    
            }
        } else {
            for(let i = 0; i < num; i++) {
                res.pop();
            }
        }
    });
    
    return res;
}