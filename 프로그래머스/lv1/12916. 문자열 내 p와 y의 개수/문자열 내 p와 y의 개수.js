function solution(s){
    var answer = true;

    let cnt_p = 0
    let cnt_y = 0
    
    // 문자열은 이터러블인가? OK
    for (const char of s) {
        if (char === 'p' || char === 'P') {
            cnt_p += 1
        } else if (char === 'y' || char === 'Y') {
            cnt_y += 1
        }
    }
    
    console.log(cnt_p, cnt_y)
    if (cnt_p === cnt_y) {
        answer = true
    } else {
        answer = false
    }

    return answer;
}