function solution(progresses, speeds) {
    const res = [];
    let head = 0;
    
    while (head < progresses.length) {
        for (let i = 0; i < progresses.length; i++) {
            progresses[i] += speeds[i];
        }
        // console.log(progresses, head);
        
        let count = 0;
        for (let i = head; i < progresses.length; i++) {
            if (progresses[i] >= 100) {
                head++;
                count++;
            } else {
                break;
            }
        }
        if (count > 0) {
            res.push(count);
        }

    }
    
    return res;
}