const fs = require('fs');

// const filePath = 'input.txt';
const filePath = '/dev/stdin';

const input = fs.readFileSync(filePath).toString().trim().split('\n');

const V = parseInt(input[0]);
const E = parseInt(input[1]);
const edges = [...input].slice(2).map(str => str.split(' ').map(num => parseInt(num)));

function solution(V, E, edges) {    
    const graph = Array.from({length: V + 1}, () => Array.from({length: V + 1}, () => 0));
    const checkList = Array.from({length: V+1}, () => 0)
    
    edges.forEach(se => {
        const s = se[0];
        const e = se[1];
        graph[s][e] = 1;
        graph[e][s] = 1;
    })
    
    function bfs(graph, sV, checkList) {
        const q = [];
        q.push(sV); // enqueue
        checkList[sV] = 1;
        while (q.length !== 0) {
            currentV = q.shift();
            graph[currentV].forEach((flag, idx) => {
                if (flag === 1 && checkList[idx] === 0) {
                    q.push(idx);
                    checkList[idx] = 1;
                }
            })
        }
        return checkList.reduce((acc, cur) => acc + cur, 0) - 1;
    }

    console.log(bfs(graph, 1, checkList));
}

solution(V, E, edges);