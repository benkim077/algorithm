function solution(a, b) {
    let res = '';
    if (a.length >= b.length) {
        b = b.padStart(a.length, '0');
    } else {
        a = a.padStart(b.length, '0');
    }
    
    let temp = 0;
    for(let i = a.length - 1; i >= 0; i--) {
        if (Number(a[i]) + Number(b[i]) + temp >= 10) {
            res = String(Number(a[i]) + Number(b[i]) + temp - 10) + res;
            temp = 1;
        } else {
            res = String(Number(a[i]) + Number(b[i]) + temp) + res;
            temp = 0;
        }
    }
    
    if (temp) res = String(temp) + res;
    return res;
}