function solution(N, arr) {
    let avg = arr.reduce((acc, cur) => acc + cur, 0) / N;
    let cnt = 0;
    arr.forEach((e) => {
        if(e > avg) cnt++;
    })

    console.log((cnt / N * 100).toFixed(3) + '%'); 
}

const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();
input = input.split('\n');

const tc = +input[0]; // 형 변환
for(let i = 1; i < tc + 1; i++) {
    const arr = input[i].split(' ').map(item => +item);

    solution(arr[0], arr.slice(1));   
}