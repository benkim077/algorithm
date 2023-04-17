function solution(dots) {    
    const [sx, sy] = dots[0];
    
    for (let i = 1; i < dots.length; i += 1) {
        if (dots[i][0] !== sx && dots[i][1] !== sy) {
            return Math.abs(dots[i][0] - sx) * Math.abs(dots[i][1] - sy);
        }
    }
}