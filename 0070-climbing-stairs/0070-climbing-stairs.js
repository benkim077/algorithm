var memo = {};

/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(memo[n]) return memo[n];
    return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
};
