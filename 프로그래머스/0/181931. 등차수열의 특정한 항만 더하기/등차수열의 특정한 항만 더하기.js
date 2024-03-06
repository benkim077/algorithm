function solution(a, d, included) {
    return included.map((el, idx) => a + d * idx).reduce((acc, elem, idx) => {
        if(included[idx]) return acc + elem;
        else return acc;
    }, 0)
}