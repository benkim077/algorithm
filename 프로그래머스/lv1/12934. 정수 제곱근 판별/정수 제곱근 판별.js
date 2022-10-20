function solution(n) {
    var answer = 0;
    
    const root = n ** (1 / 2)
    const root_floor = Math.floor(root)
    
    if (root === root_floor) {
        answer = (root + 1) ** 2
    } else {
        answer = -1
    }
    
    return answer;
}