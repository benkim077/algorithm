function solution(arr, idx) {
    let res = -1;
    for(let i = idx; i < arr.length; i++) {
        if(arr[i] === 1) {
            res = i;
            break;
        }
    }
    return res;
}