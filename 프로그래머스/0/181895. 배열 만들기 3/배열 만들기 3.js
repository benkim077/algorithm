function solution(arr, intervals) {
    const [[a1, b1], [a2, b2]] = intervals;
    const front = arr.slice(a1, b1 + 1);
    const back = arr.slice(a2, b2 + 1);
    return front.concat(back);
}