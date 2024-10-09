const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [first, ...lines] = input.toString().split("\n");
const [n, m] = first.split(" ").map(Number);
const board = [];
lines.forEach((line) => {
  board.push(line.split("").map(Number));
});
// console.log(board);

console.log(solution(n, m, board));
function solution(n, m, board) {
  const vsted = Array(n)
    .fill()
    .map((el) => Array(m).fill(0));
  bfs(0, 0);
  // console.log(vsted);
  return vsted[n - 1][m - 1];

  function bfs(y, x) {
    const dy = [-1, 0, 1, 0];
    const dx = [0, 1, 0, -1];
    const q = [];
    if (board[y][x] === 1 && vsted[y][x] === 0) {
      vsted[y][x] = 1;
      q.push([y, x]);
    }

    while (q.length > 0) {
      const [cy, cx] = q.shift();
      // console.log(`[${cy}][${cx}] 에서`);
      for (let i = 0; i < 4; i++) {
        const ny = cy + dy[i];
        const nx = cx + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] === 0) continue;
        if (vsted[ny][nx] !== 0) continue;
        // console.log(`[${ny}][${nx}] 으로 `);
        vsted[ny][nx] = vsted[cy][cx] + 1;
        q.push([ny, nx]);
      }
    }
  }
}
