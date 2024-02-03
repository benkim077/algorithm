function solution(n, words) {
    let loserNumber = 0, count = 0, prev = '', currentNumber = 0;
    const cnts = Array(n + 1).fill(0);
    const set = new Set();
    words.some((word, idx) => {
        // console.log(idx);
        currentNumber = (idx % n) + 1;
        if(idx !== 0) {
            if(set.has(word) | word[0] !== prev) {
                loserNumber = currentNumber;
                cnts[currentNumber]++;
                return true;
            }
        }
        set.add(word);
        prev = word[word.length - 1];
        cnts[currentNumber]++;
    })
    
    return [loserNumber, cnts[loserNumber]]
}