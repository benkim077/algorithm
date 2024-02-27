function solution(my_string) {
    const res = [];
    for(let i = 0; i < my_string.length; i++) {
        const post = my_string.slice(i);
        res.push(post);
    }
    res.sort();
    return res;
}