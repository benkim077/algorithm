function solution(citations) {
    let mx = 0;
    citations.sort((a, b) => a - b);
    for(let i = 0; i <= citations[citations.length - 1]; i++) {
        const s = citations.findIndex(el => el >= i);
        if(citations.length - s + 1 > i) mx = i;
        else break;
    }
    return mx;
}