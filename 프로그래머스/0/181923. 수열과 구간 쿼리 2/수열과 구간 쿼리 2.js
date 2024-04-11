function solution(arr, queries) {
    const res = [];
    
    queries.forEach(([s, e, k]) => {
        let temp = -1;
        for (let i = s; i <= e; i++) {
            if (temp === -1 && arr[i] > k) temp = arr[i];
            if (arr[i] > k && arr[i] < temp) temp = arr[i];
        }
        res.push(temp);
    })
    
    return res;
}