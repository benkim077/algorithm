function solution(ranks, attendance) {
    const tuples = ranks.map((r, idx) => {
        return [r, attendance[idx], idx];
    });
    
    tuples.sort((a, b) => {
        return a[0] - b[0];
    })
    
    let num = 3;
    return tuples.reduce((acc, [rank, isAttendance, idx]) => {
        if (num > 0 && isAttendance) {
            num--;
            return acc + (idx * (10 ** (num * 2)));
        }
        return acc;
    }, 0);
}