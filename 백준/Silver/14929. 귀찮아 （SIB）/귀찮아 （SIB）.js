const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

const N = input[0]
let lst = input[1].split(' ')
lst = lst.map(x => Number(x))


let prefix_sum = 0
let ans = 0
for (i = N - 1; i > 0; i -= 1) {
    prefix_sum += lst[i]
    ans += lst[i - 1] * prefix_sum
}

console.log(ans)