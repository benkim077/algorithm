function solution(A, B) {
    let res = -1;
    for (let i = 0; i < A.length; i++) {
        let flag = true;
        for (let j = 0; j < A.length; j++) {
            if (A[((A.length - i) % A.length + j) % A.length] !== B[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res = i;
            break;
        }
    }
    return res;
}