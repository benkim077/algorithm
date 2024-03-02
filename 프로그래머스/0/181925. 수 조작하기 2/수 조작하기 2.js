function solution(numLog) {
    let res = "";
    for(let i = 0; i < numLog.length - 1; i++) {
        const input = numLog[i + 1] - numLog[i];
        switch(input) {
            case 1: 
                res += 'w';
                break;
            case -1:
                res += 's';
                break;
            case 10:
                res += 'd';
                break;
            case -10:
                res += 'a';
                break;
        }
    }
    return res;
}