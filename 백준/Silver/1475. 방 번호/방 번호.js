const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [num] = input.toString().split("\n");

// console.log(solution(n, m, aArr, bArr));
console.log(solution(num));
function solution(num) {
  const counts = Array(10).fill(0);
  for (let i = 0; i < num.length; i++) {
    counts[num[i]]++;
  }

  let max69 = 0;
  let maxOthers = 0;
  for (let i = 0; i < counts.length; i++) {
    if (i === 6 || i === 9) {
      max69 += counts[i];
    } else {
      maxOthers = Math.max(maxOthers, counts[i]);
    }
  }

  // console.log(max69, maxOthers);
  return Math.max(Math.ceil(max69 / 2), maxOthers);
}
