const fs = require('fs');

// const filePath = 'input.txt';
const filePath = '/dev/stdin';

const [NM, _A, _B] = fs.readFileSync(filePath).toString().trim().split('\n');
const [N, M] = NM.split(' ').map(str => parseInt(str));
const A = _A.split(' ').map(str => parseInt(str));
const B = _B.split(' ').map(str => parseInt(str));

let i = 0;
let j = 0;
let answer = [];

while (true) {
    if (i < N && j < M) {
        if (A[i] >= B[j]) {
            answer.push(B[j]);
            j += 1;
        } else {
            answer.push(A[i]);
            i += 1;
        }
    } else if (i < N && j >= M) {
        answer = answer.concat(A.slice(i));
        i += N - i;
    } else if (i >= N && j < M) {
        answer = answer.concat(B.slice(j));
        j += M - j;
    } else {
        break;
    }
}

console.log(answer.join(' '));