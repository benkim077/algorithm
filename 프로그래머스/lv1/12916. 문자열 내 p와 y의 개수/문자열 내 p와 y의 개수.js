function solution(s){
    var answer = true;

    cnt = s.split('').reduce((total, x) => {
        if (x == 'p' || x == 'P') {
            return total + 1
        } else if (x == 'y' || x == 'Y') {
            return total - 1
        } else {
            return total
        }
    }, 0)
    
    console.log(cnt)
    answer = cnt ? false : true
    return answer;
}