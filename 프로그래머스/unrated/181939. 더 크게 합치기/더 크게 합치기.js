function solution(_a, _b) {
    const a = String(_a);
    const b = String(_b);
    return a + b > b + a ? Number(a + b) : Number(b + a);
}