function solution(myString, pat) {
    let res = "";
    for(let i = 0; i < myString.length; i++) {
        myString[i] === "A" ? res += "B" : res += "A";
    }
    return res.includes(pat) ? 1 : 0;
}