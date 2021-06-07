/* function logItems(n){
    for(let i = 0; i < n; i++){
        console.log(i)
    }
    for(let j = 0; j < n; j++){
        console.log(j)
    }
} */

// n + n = 2n time comlexity 
// drop constant so big o notation basically O(n)



//nasted for loop add time complexity O(n^2)
/* function logItems(n){
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            console.log(i, j)
        }
    }
} */
// basically here the number of output n * n = n^2 

// if we add another for loop 
/* function logItems(n){
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            for(let k = 0; k < n; k++){
                console.log(i, j, k)
            }
           
        }
    }
} */

// So here the output is n * n * n = n^3 
// time comlexity n^3
function logItems(a, b){
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            console.log(i, j)
        }
    }
}

// the time complexity should be O(a + b) dont be botherd about it becouse here passing variable a, b and we don't say that a equal to b 
// logItems(a , b)

//drop non dominants tarm
function logItems(a, b){
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            console.log(i, j)
        }
    }
    for(let k = 0; j < n; k++){
        console.log(k)
    }
}
//Time complexity O(n * n + n) 
// we drop non dominants tarm O(n * n)


//time complexity O(1)
/* function addOperation(n){
    return n + n + n 
}

addOperation (10) */

logItems(10)