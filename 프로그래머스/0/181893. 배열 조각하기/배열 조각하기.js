function solution(arr, query) {
    for (let i = 0; i < query.length; i++) {
        if (i & 1) {
            arr = arr.slice(query[i]);
        } else {
            arr = arr.slice(0, query[i] + 1);
        }
    }
    return arr;
}