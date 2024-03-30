function solution(arr) {
    let prev, x = 0;
    while(true) {
        prev = arr;
        arr = go(arr);
        if(isSameArr(arr, prev)) break;
        x++;
    }
    return x;
}

function go(_arr) {
    const arr = [..._arr];
    for(let i = 0; i < arr.length; i++) {
        if(arr[i] >= 50 && !(arr[i] & 1)) arr[i] /= 2;
        if(arr[i] < 50 && arr[i] & 1) arr[i] = arr[i] * 2 + 1;
    }
    return arr;
}

function isSameArr(arr1, arr2) {
    for(let i = 0; i < arr1.length; i++) {
        if (arr1[i] !== arr2[i]) return false; 
    }
    return true;
}