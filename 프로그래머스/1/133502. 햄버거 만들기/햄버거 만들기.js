function solution(ingredient) {
    const burgerSize = 4;
    let res = 0;
    const stk = new Stack();
    for(let i = 0; i < ingredient.length; i++) {
        stk.push(ingredient[i]);
        if(stk.size() >= burgerSize) {
            if(check()) {
                res++;
                // console.log("success")
                for(let j = 0; j < burgerSize; j++) stk.pop();
            }
        }
    }
    
    function check() {
        const burgerOrder = [1, 2, 3, 1];
        const duplicated = new Stack();
        
        const temp = [];
        for(let i = 0; i < burgerSize; i++) {
            const top = stk.pop();
            duplicated.push(top);
            temp.push(top);
        }
        
        for(let i = 0; i < burgerSize; i++) {
            stk.push(temp.pop());
        }
        // console.log(duplicated)
        for(let i = 0; i < burgerSize; i++) {
            if(duplicated.pop() != burgerOrder[i]) return false;
        }
        return true;
    }
    
    return res;
}



class Stack {
    constructor() {
        this.arr = [];
    }
    
    push(n) {
        this.arr.push(n);
    }
    
    pop() {
        return this.arr.pop();
    }
    
    size() {
        return this.arr.length;
    }
    
    peek() {
        return this.arr[length - 1];
    }
}
