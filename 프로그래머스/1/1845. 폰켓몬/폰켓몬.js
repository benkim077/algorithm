function solution(nums) {
    const s = new Set(nums);
    
    if(s.size >= nums.length / 2) return nums.length / 2;
    else return s.size;
}