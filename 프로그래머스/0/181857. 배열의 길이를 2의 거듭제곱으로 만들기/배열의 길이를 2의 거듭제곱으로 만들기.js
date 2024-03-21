function solution(arr) {
    let n = 0;
    
    while(2 ** n < arr.length) {
        n++;
    }
    
    const targetLength = 2 ** n;
    const pushCount = targetLength - arr.length;
    for(let i = 0; i < pushCount; i++) {
        arr.push(0);
    }
    
    return arr;
}