function solution(num_str) {
    let answer = 0;
    for (let i = 0; i < num_str.length; i += 1) {
        answer += parseInt(num_str.charAt(i));
    }
    return answer;
}