function solution(numlist, n) {    
    return numlist.sort((a, b) => {
        const distanceGap = Math.abs(a - n) - Math.abs(b - n)
        if (distanceGap === 0) {
            return b - a;
        }
        return distanceGap;
    })
}