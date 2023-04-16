function solution(s) {
    const answer = [];
    
    function changeUpperOrLowerCase(word) {
        return Array.from(word).map((char, idx) => idx % 2 ? char.toLowerCase() : char.toUpperCase()).join('');
    }
    
    s.split(' ').forEach(word => {
        answer.push(changeUpperOrLowerCase(word));
    });
                         
    return answer.join(' ');
}