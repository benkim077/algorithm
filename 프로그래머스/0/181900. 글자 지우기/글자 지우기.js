function solution(my_string, indices) {
    let res = "";
    
    const bool_list = Array(my_string.length).fill(true);
    indices.forEach((idx => {
        bool_list[idx] = false;
    }));
    
    for(let i = 0; i < my_string.length; i++) {
        if(bool_list[i]) res += my_string[i];
    }
    
    return res;
}