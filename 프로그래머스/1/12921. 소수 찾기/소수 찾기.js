function solution(max_n) {
    let res = 0;
    const che = Array.from({ length: max_n + 1 }, e => true);
    for(let n = 2; n <= max_n; n++) {
        if(che[n]) {
            for(let i = 2; n * i <= max_n; i++) che[n * i] = false;
        }
    }
    for(let n = 2; n <= max_n; n++) {
        if(che[n]) res++;
    }
    return res;
}
