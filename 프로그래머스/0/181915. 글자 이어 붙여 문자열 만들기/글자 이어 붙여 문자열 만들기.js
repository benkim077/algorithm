function solution(my_string, index_list) {
    let ans = "";
    index_list.forEach(idx => {
        ans += my_string[idx];
    })
    return ans;
}