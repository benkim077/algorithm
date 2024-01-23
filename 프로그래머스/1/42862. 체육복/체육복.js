function solution(n, lost, reserve) {
    const nums = Array(n + 1).fill(1); nums[0] = 0;
    lost.forEach(e => {
        nums[e]--;
    });
    reserve.forEach(e => {
        nums[e]++;
    })
    
    for(let i = 1; i < nums.length; i++) {
        if(nums[i] > 0) continue;
        if(nums[i - 1] > 1) {
            nums[i - 1]--; nums[i]++;
            continue;
        } 
        if(nums[i + 1] > 1) {
            nums[i + 1]--; nums[i]++;
            continue;
        }
    }
    
    return nums.reduce((acc, e) => {
        if(e > 0) return acc + 1;
        else return acc;
    }, 0)
}