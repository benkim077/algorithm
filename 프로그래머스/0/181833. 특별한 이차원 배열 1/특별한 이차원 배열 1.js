function solution(n) {
    const answer = [];
    
    for(let i = 0; i < n; i++) {
        const list = [];
        for(let j = 0; j < n; j++) {
            if(i === j) list.push(1);
            else list.push(0);
        }
        answer.push(list);
    }
    
    return answer;
}