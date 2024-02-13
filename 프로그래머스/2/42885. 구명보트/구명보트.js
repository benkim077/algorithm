function solution(people, limit) {
    let l = 0, r = people.length - 1, res = 0;
    people.sort((a, b) => a - b);
    while(l < r) {
        if(people[l] + people[r] <= limit) { l++; r--; res++ }
        else { r--; res++ }
    }
    if(l === r) res++; 
    return res;
}