function solution(myString) {
    let res = "";
    const L_ASCII = 'l'.charCodeAt();
    for(let idx = 0; idx < myString.length; idx++) {
        if(myString[idx].charCodeAt() < L_ASCII) res += 'l';
        else res += myString[idx];
    }
    return res;
}