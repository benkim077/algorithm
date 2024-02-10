function solution(n) {
    const cache = {};
    return dp(n);
    
    function dp(n) {
        if(n === 1) return 1;
        if(n === 2) return 2;
        if(cache[n]) return cache[n];
        return cache[n] = (dp(n - 1) + dp(n - 2)) % 1234567;
    }
}

