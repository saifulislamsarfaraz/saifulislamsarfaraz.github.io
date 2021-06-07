function logItems(n){
    for(let i = 0; i < n; i++){
        console.log(i)
    }
    for(let j = 0; j < n; j++){
        console.log(j)
    }
}

// n + n = 2n time comlexity 
// drop constant so big o notation basically O(n)
function logitems1(n){
    while(!n){
        console.log(n)
        n--;
    }
}
logitems1(15)
logItems(15)