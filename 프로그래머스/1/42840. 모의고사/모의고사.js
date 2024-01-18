function solution(answers) {
    const a = [1, 2, 3, 4, 5];
    const b = [2, 1, 2, 3, 2, 4, 2, 5];
    const c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    const res = answers.reduce((acc, answer, idx) => {
        if(a[idx % a.length] === answer) acc[0]++;
        if(b[idx % b.length] === answer) acc[1]++;
        if(c[idx % c.length] === answer) acc[2]++;
        return acc;
    }, [0, 0, 0]);
    
    const mx = Math.max(...res);
    return res.reduce((acc, cnt, idx) => {
        if(cnt === mx) return [...acc, idx + 1];
        else return acc
    }, []);    
}