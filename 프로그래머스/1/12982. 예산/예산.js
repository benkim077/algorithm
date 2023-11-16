function solution(d, budget) {
    d.sort((a, b) => a - b);
    let _sum = 0, ret = 0;
    for(let i = 0; i < d.length; i++) {
        _sum += d[i];
        if(_sum > budget) break;
        ret++;
        
    }
    
    return ret;
}