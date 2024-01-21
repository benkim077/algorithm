function solution(X, Y) {
    const cntA = Array.from({length: 10}, () => 0), 
          cntB = Array.from({length: 10}, () => 0), 
          cnt = Array.from({length: 10}, () => 0);
    let res = "";
    
    for(let i = 0; i < X.length; i++) {
        cntA[X[i]]++;
    }
    for(let j = 0; j < Y.length; j++) {
        cntB[Y[j]]++
    }
    for(let k = 0; k < 10; k++) {
        cnt[k] = Math.min(cntA[k], cntB[k]);
    }
    
    for(let idx = 9; idx >= 0; idx--) {
        if(idx === 0 && res.length === 0 && cnt[idx] > 0) res = "0";
        else res += String(idx).repeat(cnt[idx]);
    }
    if(res.length === 0) res = "-1";
    return res;
}