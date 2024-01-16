function solution(names, yearnings, photos) {
    const m = new Map();
    for(let i = 0; i < names.length; i++) {
        m.set(names[i], yearnings[i]);
    }
    
    return photos.map(photo => {
        return photo.reduce((acc, name) => {
            return m.get(name) ? acc + m.get(name) : acc;
        }, 0);
    })
}