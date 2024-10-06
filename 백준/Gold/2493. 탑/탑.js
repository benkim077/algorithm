const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [n, nums] = input.toString().split("\n");
n = Number(n);
nums = nums.split(" ").map(Number);

// console.log(solution(n, m, aArr, bArr));
console.log(solution(n, nums));
function solution(n, nums) {
  const res = Array(n).fill(-1);
  const stk = [];

  for (let i = nums.length - 1; i >= 0; i--) {
    // console.log("idx: ", i);
    const tempStk = [];
    while (stk.length > 0) {
      const top = nums[stk[stk.length - 1]];
      // console.log(i, top);
      if (nums[i] >= top) {
        const idx = stk.pop();
        res[idx] = i + 1;
      } else {
        break;
      }
    }
    stk.push(i);
  }

  while (stk.length > 0) {
    res[stk.pop()] = 0;
  }

  return res.join(" ");
}
