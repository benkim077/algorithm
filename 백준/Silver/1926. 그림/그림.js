const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [first, ...boardLines] = input.toString().split("\n");
const [height, width] = first.split(" ").map(Number);

const board = [];
for (let i = 0; i < boardLines.length; i++) {
  const boardElements = boardLines[i].split(" ");
  board.push(boardElements.map(Number));
}

console.log(solution(board));

function solution(board) {
  const dy = [-1, 0, 1, 0];
  const dx = [0, 1, 0, -1];
  let count = 0;
  let max_area = 0;
  const vsted = Array(board.length)
    .fill()
    .map((el) => Array(board[0].length).fill(false));

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      const area = bfs(i, j);
      if (area === 0) continue;
      count++;
      max_area = Math.max(max_area, area);
    }
  }

  return [count, max_area].join("\n");

  function bfs(y, x) {
    const q = [];
    let area = 0;
    if (board[y][x] === 1 && !vsted[y][x]) {
      vsted[y][x] = true;
      q.push([y, x]);
    } else {
      return area;
    }
    while (q.length > 0) {
      [y, x] = q.pop();
      area++;

      for (let i = 0; i < 4; i++) {
        const ny = y + dy[i];
        const nx = x + dx[i];

        if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
        if (board[ny][nx] === 0) continue;
        if (vsted[ny][nx]) continue;

        vsted[ny][nx] = true;
        q.push([ny, nx]);
      }
    }

    return area;
  }
}
