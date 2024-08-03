function nnanpa(x){
    let lili = ["A", "M", "L", "T", "W"]
    let nanpa = [100, 20, 5, 2, 1]
    let suli = [0, 0, 0, 0, 0]
    let nimi = ["ale", "mute", "luka", "tu", "wan"]
    let y = x
    let s = ""

    for(let i=0; i<nanpa.length; i++){
        while(y >= nanpa[i]){
            y -= nanpa[i]
            suli[i]++
        }
    }

    if(suli[0] > 1)
        s += nnanpa(suli[0])
    if(suli[0] > 0)
        s += lili[0]

    for(let i=1; i<nanpa.length; i++)
        for(let j=0; j<suli[i]; j++)
            s += lili[i]
    
    return s
}

function nnnanpa(x){
    let lili = ["A", "M", "L", "T", "W"]
    let nimi = ["ale", "mute", "luka", "tu", "wan"]

    let t = nnanpa(x).split("")
    let s = ""
    for(let i=0; i<t.length; i++){
        let j=0
        for(j=0; j<lili.length && lili[j]!=t[i]; j++);
        s += nimi[j]
        if(i<t.length-1)
            s += " "
    }

    return s
}

console.log(nnnanpa(73))