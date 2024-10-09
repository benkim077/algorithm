const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [first, second] = input.toString().split("\n");
let [n, m] = first.split(" ");
n = Number(n);
m = Number(m);
const list = second.split(" ").map(Number);

console.log(solution(n, m, list));
function solution(n, m, list) {
  let res = 0;
  const dq = Array(n)
    .fill(0)
    .map((_, idx) => idx + 1);

  // console.log(n, m, list);
  list.forEach((item) => {
    const idx = dq.findIndex((el) => el === item);
    // console.log(dq, item, idx);
    if (idx === 0) {
      dq.shift();
    } else {
      if (idx < dq.length - idx) {
        // console.log(`2번 연산 ${idx}번`);
        for (let i = 0; i < idx; i++) {
          // 2번 연산 필요한 만큼 반복
          const front = dq.shift();
          dq.push(front);
          res++;
        }
      } else {
        // console.log(`3번 연산 ${dq.length - idx}번`);
        for (let i = 0; i < dq.length - idx; i++) {
          // 3번 연산
          const back = dq.pop();
          dq.unshift(back);
          res++;
        }
      }
      dq.shift();
    }
    // console.log(res);
  });

  return res;
}
