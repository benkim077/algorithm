class Queue {
    constructor(arr) {
        this.data = arr;
    }
    enqueue(el) {
        this.data.push(el);
    }
    dequeue(el) {
        return this.data.shift(el);
    }
}

const fs = require('fs');

// const filePath = 'input.txt';
const filePath = '/dev/stdin';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

const [n, k] = input[0].split(' ').map(el => parseInt(el));

const arr = Array.from({length: n}).map((_, idx) => idx + 1);

const q = new Queue(arr);

const solution = (q) => {
    const answer = [];
    let count = 1;
    
    while (q.data.length > 0) {
        if (count === k) {
            answer.push(q.dequeue());
            count = 1;
        } else {
            q.enqueue(q.dequeue());
            count += 1;
        }
    }
    return '<' + answer.join(', ') + '>';
}

console.log(solution(q));
