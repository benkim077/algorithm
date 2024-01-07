function solution(num_list, n) {
    return num_list.filter((el, idx) => {
        if(idx % n === 0) return true;
        return false;
    })
}