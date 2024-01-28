function solution(my_string, is_suffix) {
    for(let i = 0; i < is_suffix.length; i++) {
        if(my_string.at(-1 - i) !== is_suffix.at(-1 - i)) return 0;
    }
    return 1;
}