function solution(myString, pat) {
    let idx = -1;
    for(let i = 0; i < myString.length - pat.length + 1; i++) {
        let flag = true;
        for(let j = 0; j < pat.length; j++) {
            if(myString[i + j] !== pat[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            idx = i;
        }
    }
    console.log(idx)
    if(idx === -1) return "";
    else return myString.slice(0, idx + pat.length);
}