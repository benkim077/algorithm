function solution(keymaps, targets) {
    const cnts = Array.from({length: 26}, e => 104);
    const mnCnts = cnts.map(getMinCount);
    return targets.map(target => {
        let sum = 0;
        for(let i = 0; i < target.length; i++) {
            const cost = mnCnts[target[i].charCodeAt() - 65]
            if(cost > 100) return -1;
            sum += cost;
        }
        return sum;
    })
    
    function getMinCount(cnt, idx) {
        let res = cnt;
        for(let i = 0; i < keymaps.length; i++) {
            const keymap = keymaps[i];
            const order = keymap.getOrder(String.fromCharCode(idx + 65));
            if(order > 0) res = Math.min(res, order);
        }
        return res;
    }
}

String.prototype.getOrder = function(char) {
    return this.indexOf(char) + 1;
}
