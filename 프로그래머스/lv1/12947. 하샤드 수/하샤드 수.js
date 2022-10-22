function solution(x) {
    var answer = true;
    const X = x
    
    let check = 0
    while (x > 0) {
        check += x % 10
        x = Math.floor(x / 10)
    }
    
    console.log(check)
    
    if (X % check === 0) {
        answer = true
    } else {
        answer = false
    }
    
    return answer;
}