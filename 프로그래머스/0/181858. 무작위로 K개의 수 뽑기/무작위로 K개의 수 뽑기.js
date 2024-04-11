function solution(arr, k) {
    const set = new Set();
    for (let i = 0; i < arr.length; i++) {
        if (set.size >= k) break;
        set.add(arr[i]);
    }
    
    const res = Array.from(set);
    if (res.length < k) {
        for (let i = res.length; i < k; i++) {
            res.push(-1);
        }
    }
    
    return res;
}