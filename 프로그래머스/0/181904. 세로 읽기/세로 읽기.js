function solution(my_string, m, c) {
    let res = "";
    for(let idx = 0; idx < my_string.length; idx++) {
        if(idx % m + 1 === c) res += my_string[idx];
    }
    return res;
}