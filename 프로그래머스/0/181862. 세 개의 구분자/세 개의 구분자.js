function solution(myStr) {
    let res = [];
    
    const targetStr = "abc";
    let temp = "";
    for(let i = 0; i < myStr.length; i++) {
        if(targetStr.includes(myStr[i])) {
            if(temp.length !== 0) {
                res.push(temp);
                temp = "";
            }
        } else {
            temp += myStr[i];
        }
    }
    if(temp.length !== 0) res.push(temp);
    
    
    if(res.length === 0) res = ['EMPTY'];
    return res;
}