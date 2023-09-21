/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    const targetVal = val;
    function toBe(val) {
        if (val === targetVal) return true;
        else throw new Error("Not Equal");
    }
    function notToBe(val) {
        if (val !== targetVal) return true;
        else throw new Error("Equal");
    }
    return {
        toBe, notToBe
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */