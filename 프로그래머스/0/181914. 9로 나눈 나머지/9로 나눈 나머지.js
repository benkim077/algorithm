function solution(number) {
    let sum = 0;
    const str = String(number);
    for(let i = 0; i < str.length; i++) {
        sum += Number(str[i]);
    }
    return sum % 9;
}