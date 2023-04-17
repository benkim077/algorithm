function solution(keyinput, board) {
    var answer = [0, 0];
    const [_width, _height] = board;
    const [width, height] = [Math.floor(_width / 2), Math.floor(_height / 2)];
    
    function move (_positionX, _positionY, direction) {
        let [positionX, positionY] = [_positionX, _positionY];
        if (direction === 'up') {
            positionY += 1;
        } else if (direction === 'down') {
            positionY -= 1;
        } else if (direction === 'left') {
            positionX -= 1;
        } else {
            positionX += 1;
        }
        
        // 보드 안에 들어가는 경우
        if (Math.abs(positionX) <= width && Math.abs(positionY) <= height) {
            return [positionX, positionY];
        } else {
            return [_positionX, _positionY];
        }
    }
    
    keyinput.forEach(input => {
        [answer[0], answer[1]] = move(answer[0], answer[1], input);
    })
    
    return answer;
}