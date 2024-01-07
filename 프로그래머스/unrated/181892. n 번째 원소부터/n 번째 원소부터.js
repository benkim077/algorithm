function solution(num_list, n) {
    return num_list.filter((e, i) => {
        if(i + 1 >= n) return e;
    })
}