const fs = require("fs");
let input = fs.readFileSync("/dev/stdin").toString();
input = input.split(" ").map(Number);

let output = "";
input.sort((a, b) => a - b);
for (let i = 0; i < input.length; i++) output += input[i] + " ";

console.log(output);
