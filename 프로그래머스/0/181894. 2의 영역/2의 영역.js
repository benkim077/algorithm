function solution(arr) {
    let s = -1, e = -1;
    for(let i = 0; i < arr.length; i++) {
        if(arr[i] === 2) {
            if(s === -1) s = e = i;
            else e = i;
        } 
    }

    if(s === -1 && e === -1) return [-1];
    return arr.slice(s, e + 1);
}