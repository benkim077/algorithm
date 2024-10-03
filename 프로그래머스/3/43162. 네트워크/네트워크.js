function solution(n, adj) {
    let res = 0;
    const vsted = Array(n).fill(false);
    
    for (let i = 0; i < n; i++) {
        if (!vsted[i]) {
            dfs(i);
            res += 1;
        }
    }
    
    return res;
    
    function dfs(here) {
        vsted[here] = true;
        adj[here].forEach((_, there) => {
            if (adj[here][there] === 1 && !vsted[there]) {
                dfs(there);
            }
        })
    }
}