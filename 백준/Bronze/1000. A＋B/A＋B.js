const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

let lst = input[0].split(' ')
lst = lst.map(x => Number(x))

console.log(lst[0] + lst[1])