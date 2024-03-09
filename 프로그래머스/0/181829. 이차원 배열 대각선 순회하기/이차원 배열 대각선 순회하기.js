function solution(board, k) {
    let res = 0;
    for(let i = 0; i < board.length; i++) {
        for(let j = 0; j < board[0].length; j++) {
            if(i + j <= k) res += board[i][j];
        }
    }
    return res;
}