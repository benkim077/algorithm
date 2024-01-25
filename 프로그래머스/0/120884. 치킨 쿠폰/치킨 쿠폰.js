function solution(chicken) {
    let coupon = chicken, res = 0;
    while(coupon >= 10) {
        res += Math.floor(coupon / 10);
        coupon = Math.floor(coupon / 10) + coupon % 10;
    }
    return res;
}