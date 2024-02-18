function solution(str_list, ex) {
    return str_list
        .reduce((res, str) => str.includes(ex) ? res : res + str , "");
}