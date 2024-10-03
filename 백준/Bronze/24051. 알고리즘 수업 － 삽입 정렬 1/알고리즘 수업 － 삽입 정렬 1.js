const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

const [nk, a] = input.toString().split("\n");

const [n, k] = nk.split(" ").map(Number);
const arr = a.split(" ").map(Number);

console.log(solution(n, k, arr));
function solution(n, k, arr) {
  // let kArr = [];
  let kCount = 0;

  let i = 1;
  while (i < n) {
    const current = arr[i];

    let j = i - 1;
    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      // kArr.push(arr[j]);
      kCount += 1;
      if (kCount === k) return arr[j];
      j -= 1;
    }
    arr[j + 1] = current;
    if (j !== i - 1) {
      // kArr.push(current);
      kCount += 1;
      if (kCount === k) return current;
    }

    i += 1;
  }

  return -1;
  // if (kArr.length < k) {
  //   return -1;
  // } else {
  //   return kArr[k - 1];
  // }
}
