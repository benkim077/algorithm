function solution(order) {
    let res = 0;
    order.forEach(menu => {
        if(menu.includes("americano")) { 
            res += 4500; 
            return; 
        }
        if(menu.includes("latte")) {
            res += 5000;
            return;
        }
        res += 4500;
    })
    
    return res;
}