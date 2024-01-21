function solution(cardsA, cardsB, goal) {
    let idxA = 0, idxB = 0;
    while(idxA + idxB < goal.length) {
        if(idxA < cardsA.length && cardsA[idxA] === goal[idxA + idxB]) {
            // console.log(cardsA[idxA]);
            idxA++;
        } else if(idxB < cardsB.length && cardsB[idxB] === goal[idxA + idxB]) {
            // console.log(cardsB[idxB]);
            idxB++;
        } else {
            return "No";
        }
        
    }
    return "Yes";
}