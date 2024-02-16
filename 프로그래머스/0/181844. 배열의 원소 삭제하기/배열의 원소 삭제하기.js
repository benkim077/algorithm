function solution(arr, delete_list) {
    const res = [];
    for(let i = 0; i < arr.length; i++) {
        if(!delete_list.includes(arr[i])) res.push(arr[i]);
    }
    return res;
}