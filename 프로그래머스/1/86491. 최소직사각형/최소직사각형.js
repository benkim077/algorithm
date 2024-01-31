function solution(sizes) {
    let wMax = -1, hMax = -1;
    sizes
        .map(([w, h]) => {
            if(w < h) return [h, w];
            else return [w, h];
        })
        .forEach(([w, h]) => {
            wMax = Math.max(wMax, w);
            hMax = Math.max(hMax, h);
        })
    return wMax * hMax;
}