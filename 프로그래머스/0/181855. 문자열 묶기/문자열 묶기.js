function solution(strArr) {
    const countArr = Array.from({length: 100004}).map(el => 0);
    strArr.forEach(str => {
        countArr[str.length]++;
    })
    
    return Math.max(...countArr);
}