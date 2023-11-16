function solution(n) {
    let s = 0, e = 0, ret = 0;
    while(s <= e && e <= n) {
        const _sum = (e - s + 1) * (s + e) / 2;
        if(_sum == n) {ret++; e++}
        else if(_sum > n) {s++;}
        else {e++;}
    }
    return ret;
}