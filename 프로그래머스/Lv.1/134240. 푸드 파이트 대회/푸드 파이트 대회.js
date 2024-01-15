function solution(food) {
    let res = '', reversed = '';
    
    for(let i = 1; i < food.length; i++) {
        res = res + String(i).repeat(food[i] / 2);
        reversed = String(i).repeat(food[i] / 2) + reversed;
    }
    return res + '0' + reversed;
}