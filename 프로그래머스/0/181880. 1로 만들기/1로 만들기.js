function solution(num_list) {
    let res = 0;
    num_list.forEach((num) => {
        while(num !== 1) {
            num = num & 1 ? (num - 1) / 2 : num / 2;
            res++;
        }
    })
    
    return res;
}