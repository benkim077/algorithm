function solution(n, arr1, arr2) {
    const map1 = makeMap(arr1);
    const map2 = makeMap(arr2);
    
    const decrypted = Array(n).fill().map(e => Array(n).fill(0));
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < n; j++) {
            decrypted[i][j] = map1[i][j] | map2[i][j];
        }
    }

    return decrypted.map(arr => {
        return arr.reduce((acc,num) => num ? acc + '#' : acc + ' ', '');
    });
    
    
    function makeMap (array) {
        const res = Array(n).fill().map(e => Array(n).fill(0));
        for(let i = 0; i < n; i++) {
            const binary = Number(array[i]).toString(2).padStart(n, '0');

            for(let j = 0; j < binary.length; j++) {
                res[i][j] = res[i][j] | binary[j];
            }
        }
        return res;
    }
    
}