const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let sentences = input.toString().split("\n");

console.log(solution(sentences));
function solution(sentences) {
  const res = [];

  for (let i = 0; i < sentences.length; i++) {
    const sentence = sentences[i];
    if (sentence === ".") break;
    res.push(go(sentence));
    function go(sentence) {
      const stk = [];
      for (let j = 0; j < sentence.length; j++) {
        const char = sentence[j];
        if (char === "(" || char === "[") {
          stk.push(char);
        } else if (char === ")") {
          const top = stk[stk.length - 1];
          if (top === undefined) return "no";
          if (top !== "(") return "no";
          else stk.pop();
        } else if (char === "]") {
          const top = stk[stk.length - 1];
          if (top === undefined) return "no";
          if (top !== "[") return "no";
          else stk.pop();
        } else continue;
      }

      if (stk.length > 0) return "no";
      return "yes";
    }
  }

  return res.join("\n");
}
