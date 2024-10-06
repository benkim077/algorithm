const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [s] = input.toString().split("\n");

// console.log(solution(n, m, aArr, bArr));
console.log(solution(s));
function solution(s) {
  const res = Array(26).fill(0);
  for (let i = 0; i < s.length; i++) {
    res[s.charCodeAt(i) - 97]++;
  }
  return res.join(" ");
}
