function solution(s, n) {
    s = Array.from(s);
    console.log(s);
    return s.reduce((acc, c) => {
        if(c === ' ') return acc + ' ';
        const ascii = c.charCodeAt();
        if(ascii < 97) { // 대문자
            if(ascii + n > 'Z'.charCodeAt()) {
                return acc + String.fromCharCode(ascii + n - 1 - 'Z'.charCodeAt() + 'A'.charCodeAt());
            }
            return acc + String.fromCharCode(ascii + n);
        } else { // 소문자
            if(ascii + n > 'z'.charCodeAt()) {
                return acc + String.fromCharCode(ascii + n - 1 - 'z'.charCodeAt() + 'a'.charCodeAt());
            }
            return acc + String.fromCharCode(ascii + n);
        }
    }, "");
}