function solution(start_num, end_num) {
    return Array.from({length: end_num - start_num + 1}, (_, idx) => start_num + idx);
    // return Array(end_num - start_num + 1).fill(0).map((_, idx) => start_num + idx);
    // for(let i = start_num; i < end_num + 1; i++) {
    //     answer.push(i);
    // }
    // return answer;
}