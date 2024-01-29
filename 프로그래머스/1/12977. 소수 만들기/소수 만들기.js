function solution(nums) {
    let res = 0;
    const max_length = Math.max(...nums) * 3;
    const che = Array(max_length).fill(true);
    for(let i = 2; i < max_length; i++) {
        if(che[i]) {
            for(let j = 2; i * j < max_length; j++) {
                che[i * j] = false;
            }
        }
    }
    
    for(let i = 0; i < nums.length; i++) {
        for(let j = i + 1; j < nums.length; j++) {
            for(let k = j + 1; k < nums.length; k++) {
                if(che[nums[i] + nums[j] + nums[k]]) res++;
            }
        }
    }
    return res;
}
