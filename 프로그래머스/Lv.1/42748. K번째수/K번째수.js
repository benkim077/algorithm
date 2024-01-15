function solution(array, commands) {
    return commands.map(sol)
    
    function sol(command) {
        const [i, j, k] = command;
        const a = array.slice(i - 1, j);
        a.sort((a, b) => a - b);
        return a[k - 1];
    }
}

