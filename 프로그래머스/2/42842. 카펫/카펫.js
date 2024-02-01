function solution(brown, yellow) {
    // 다음 조건을 구현하면 된다.
    // (bRow - 1) + (bCol - 1) === brown / 2;
    // bRow > bCol
    // yellow === (bRow - 2) * (bCol)
    
    let bRow = 3; 
    let bCol = 2;
    let isFound = false;
    while(bRow >= bCol) {
        console.log(bRow, bCol);
        // bRow++; bCol = 1;
        for(; bCol <= bRow; bCol++) {
            if(((bRow - 1) + (bCol - 1) === (brown / 2)) && (yellow === (bRow - 2) * (bCol - 2))) {
                isFound = true;
                break;
            }
        }
        
        if(isFound) break;
        if(bRow < bCol) {
            bRow++;
            bCol = 2;
            continue;            
        }
    }
    
    return [bRow, bCol];
}