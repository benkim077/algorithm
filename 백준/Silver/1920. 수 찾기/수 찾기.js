const binary_search = function (x, list) {
    let s = 0
    let e = N - 1
    let m
    while (s <= e) {
        m = Math.floor((s + e) / 2)
        
        if (list[m] > x) {
            e = m - 1
        } else if (list[m] < x) {
            s = m + 1
        } else {
            return 1
        }
    }
    return 0
}


const fs = require('fs');
let input = fs.readFileSync('./dev/stdin').toString().trim().split('\n');

const N = Number(input[0])
const A_LIST = input[1].split(' ').map(x => Number(x)).sort((a, b) => a - b)
const M = Number(input[2])
const M_LIST = input[3].split(' ').map(x => Number(x))

const result = M_LIST.map(x => binary_search(x, A_LIST))
console.log(result.join('\n'))