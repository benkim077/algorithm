function solution(num_list) {
    let oddSum = 0, evenSum = 0;
    for(let i = 0; i < num_list.length; i++) {
        i & 1 ? evenSum += num_list[i] : oddSum += num_list[i];
    }
    return Math.max(oddSum, evenSum);
}