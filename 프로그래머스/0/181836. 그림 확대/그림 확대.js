function solution(picture, k) {
    const res = [];
    for (let i = 0; i < picture.length; i++) {
        const inner = [];
        for (let j = 0; j < picture[0].length; j++) {
            for (let n = 0; n < k; n++) {
                inner.push(picture[i][j]);    
            }
        }
        for (let n = 0; n < k; n++) {
            res.push(inner.join(''));    
        }
    }
    return res;
}