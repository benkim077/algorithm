function solution(my_strings, parts) {
    let res = "";
    for(let i = 0; i < my_strings.length; i++) {
        let [s, e] = parts[i]; e++
        res += my_strings[i].slice(s, e);
    }
    return res;
}