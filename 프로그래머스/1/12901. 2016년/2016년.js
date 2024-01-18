function solution(a, b) {
    const dateOfMonth = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    const weekdays = ["SUN","MON","TUE","WED","THU","FRI","SAT"];
    
    let days = 4;
    
    for(let i = 0; i < a - 1; i++) {
        days += dateOfMonth[i];
    }
    days += b;

    days %= 7;
    
    return weekdays[days];
}