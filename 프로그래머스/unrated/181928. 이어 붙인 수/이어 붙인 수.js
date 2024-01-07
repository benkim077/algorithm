function solution(num_list) {
    let odd = 0, even = 0;
    num_list.map(el => String(el)).forEach(el => {
        if(el % 2) {
            odd += el;
        } else {
            even += el;
        }
    });
    return Number(odd) + Number(even);
}