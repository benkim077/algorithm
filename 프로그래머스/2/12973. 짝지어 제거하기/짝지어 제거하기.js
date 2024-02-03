function solution(s) {
    const stk = [];
    for(let i = 0; i < s.length; i++) {
        if(stk.length && stk.at(-1) === s[i]) stk.pop();
        else stk.push(s[i]);
    }
    return stk.length ? 0 : 1;
}