const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [n, nums, x] = input.toString().split("\n");
nums = nums.split(" ").map(Number);
x = Number(x);

// console.log(solution(n, m, aArr, bArr));
console.log(solution(n, nums, x));
function solution(n, nums, x) {
  let res = 0;
  nums.sort((a, b) => a - b);

  let s = 0;
  let e = nums.length - 1;

  while (s < e) {
    // console.log();
    const temp = nums[s] + nums[e];
    // console.log(s, e, temp);
    if (temp === x) {
      res++;
      e--;
    } else if (temp < x) s++;
    else e--;
  }

  return res;
}
