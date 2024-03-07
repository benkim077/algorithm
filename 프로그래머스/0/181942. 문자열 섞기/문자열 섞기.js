function solution(str1, str2) {
    let res = "";
    for(let i = 0; i < str1.length; i++) {
        res += str1[i] + str2[i];
    }
    return res;
}