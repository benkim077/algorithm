function solution(my_string, queries) {
    
    queries.forEach(([s, e]) => {
        let front = "";
        let mid = "";
        let end = "";
        for(let i = 0; i < my_string.length; i++) {
            if (i < s) {
                front += my_string[i];
            } else if (s <= i && i <= e) {
                mid = my_string[i] + mid;
            } else {
                end += my_string[i];
            }
        }
        my_string = front + mid + end;
    });
    
    return my_string;
}