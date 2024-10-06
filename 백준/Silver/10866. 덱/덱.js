const fs = require("fs");
// let input = fs.readFileSync("./input.txt");
let input = fs.readFileSync("/dev/stdin");

let [n, ...commands] = input.toString().split("\n");
n = Number(n);

const MAX_N = 10000;
class Deque {
  constructor() {
    this.arr = Array(MAX_N * 2 + 1).fill(null);
    this.head = MAX_N;
    this.tail = MAX_N;
  }

  pushFront(num) {
    this.arr[--this.head] = num;
  }

  pushBack(num) {
    this.arr[this.tail++] = num;
  }

  popFront() {
    if (this.head === this.tail) return -1;
    return this.arr[this.head++];
  }

  popBack() {
    if (this.head === this.tail) return -1;
    this.tail--;
    return this.arr[this.tail];
  }

  size() {
    return this.tail - this.head;
  }

  empty() {
    return this.size() === 0 ? 1 : 0;
  }

  front() {
    if (this.head === this.tail) return -1;
    return this.arr[this.head];
  }

  back() {
    if (this.head === this.tail) return -1;
    return this.arr[this.tail - 1];
  }
}

console.log(solution(n, commands));

function getCommand(command) {
  const [main, detail] = command.split(" ");
  return [main, Number(detail)];
}

function solution(n, commands) {
  let res = [];
  const dq = new Deque();
  for (let i = 0; i < commands.length; i++) {
    const [command, detail] = getCommand(commands[i]);
    let temp;
    switch (command) {
      case "push_front":
        temp = dq.pushFront(detail);
        break;
      case "push_back":
        temp = dq.pushBack(detail);
        break;
      case "pop_front":
        temp = dq.popFront();
        break;
      case "pop_back":
        temp = dq.popBack();
        break;
      case "size":
        temp = dq.size();
        break;
      case "empty":
        temp = dq.empty();
        break;
      case "front":
        temp = dq.front();
        break;
      case "back":
        temp = dq.back();
        break;
      default:
        break;
    }
    if (temp !== undefined) {
      res.push(temp);
    }
  }
  return res.join("\n");
}
