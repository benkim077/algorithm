function solution(a, b) {
    if(isOddNumber(a) && isOddNumber(b)) return a ** 2 + b ** 2;
    if(!isOddNumber(a) && !isOddNumber(b)) return Math.abs(a - b);
    else return 2 * (a + b);
}

function isOddNumber(x) {
    return x & 1 ? true : false;
}