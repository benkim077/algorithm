const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [n] = input.toString().split("\n");
n = Number(n);

// console.log(solution(n, m, aArr, bArr));
console.log(solution(n));

function solution(n) {
  const q = Array(n)
    .fill(0)
    .map((el, idx) => idx + 1);
  let head = 0;

  while (true) {
    if (head === q.length - 1) {
      break;
    } else {
      head++;
    }

    if (head === q.length - 1) {
      break;
    } else {
      q.push(q[head]);
      head++;
    }
  }
  return q[head];
}