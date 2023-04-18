function solution(id_pw, db) {
    var answer = '';
    
    const [id, pw] = id_pw;
    const flag = 
    
    db.find(dbData => {
        const [dbId, dbPw] = dbData;
        if (id !== dbId) {
            answer = 'fail';
            
        } else {
            if (pw !== dbPw) {
                answer = 'wrong pw';
                return true;
            } else {
                answer = 'login';
                return true;
            }
        }
        // console.log(dbData, answer);
    })
    
    return answer;
}