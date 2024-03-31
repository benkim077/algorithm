function solution(my_string) {
    const length = 'z'.charCodeAt() - 'a'.charCodeAt() + 1;
    const res = Array.from({length: length * 2}).map(el => 0);
    
    for(let i = 0; i < my_string.length; i++) {
        if(my_string.charCodeAt(i) >= 'a'.charCodeAt()) {
            res[my_string.charCodeAt(i) - 'a'.charCodeAt() + length]++;
        } else {
            res[my_string.charCodeAt(i) - 'A'.charCodeAt()]++;
        }
    }    
    
    return res;
}