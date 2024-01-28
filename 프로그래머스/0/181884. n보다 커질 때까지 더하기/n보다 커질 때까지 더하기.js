function solution(numbers, n) {
    let res = 0;
    for(let i = 0; i < numbers.length; i++) {
        if(res > n) break;
        res += numbers[i];
    }
    return res;
}