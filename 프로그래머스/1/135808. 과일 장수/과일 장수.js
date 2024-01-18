function solution(k, m, score) {
    score.sort((a, b) => -(a - b));
    console.log(score);
    let temp = [];
    return score.reduce((acc, e, i) => {
        temp.push(e)
        if(i % m === m - 1) {
            acc += Math.min(...temp) * m;
            temp = [];
        }
        return acc;
    }, 0);
    
}