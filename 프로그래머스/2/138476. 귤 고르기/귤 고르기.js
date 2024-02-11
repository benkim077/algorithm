function solution(k, tangerine) {
    let sum = 0, res = 0;
    const cntArray = Array(10_000_004).fill(0);
    tangerine.forEach(size => {
        cntArray[size]++;
    });
    cntArray.sort((a, b) => -(a - b));
    
    for(let i = 0; i < cntArray.length; i++) {
        sum += cntArray[i];
        res++;
        if(sum >= k) break;
    }
    return res;
}