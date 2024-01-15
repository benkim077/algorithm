function solution(a, b, n) {
    if(a > n) return 0;
    console.log(Math.floor(n / a) * b);
    return Math.floor(n / a) * b + solution(a, b, Math.floor(n / a) * b + n % a);
}
