function solution(str_list) {
    const res = [];
    
    for(let i = 0; i < str_list.length; i++) {
        switch (str_list[i]) {
            case 'l' :{
                for(let j = 0; j < i; j++) {
                    res.push(str_list[j]);
                }
                return res;
            }
            case 'r' :{
                for(let j = i + 1; j < str_list.length; j++) {
                    res.push(str_list[j]);
                }
                return res;
            }
            default:
                break;
        }
    }
    
    return res;
}