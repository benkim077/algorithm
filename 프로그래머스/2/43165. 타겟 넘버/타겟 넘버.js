let count = 0;

function solution(numbers, target) {
    bfs(numbers, 0, 0);
    function bfs(numbers, i, acc) {
        if (i >= numbers.length) {
            if (acc === target) count += 1;
        } else {
            bfs(numbers, i + 1, acc + numbers[i]);
            bfs(numbers, i + 1, acc - numbers[i]);    
        }
    }
    
    return count;
}
