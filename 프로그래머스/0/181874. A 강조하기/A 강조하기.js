function solution(myString) {
    let res = '';
    for(let i = 0; i < myString.length; i++) {
        const ascii = myString.charCodeAt(i);
        if(ascii === 97) res += 'A';
        else if(ascii < 97 && ascii !== 65) res += myString[i].toLowerCase();
        else res += myString[i];
    }
    return res;
}