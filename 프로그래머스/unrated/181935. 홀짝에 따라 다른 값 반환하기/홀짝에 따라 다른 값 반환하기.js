function solution(n) {
    let res = 0;
    if(n % 2) { 
        for(let i = 1; i < n + 1; i++) {
            if(i % 2) res += i;
        }
    } else {
        for(let i = 1; i < n + 1; i++) {
            if(!(i % 2)) res += i ** 2;
        }
    }
    return res;
}