function selectionSort(){
    let min 
    for(let i = 0; i < Array.length - 1; i++){
        min  = i
        for(let j = i + 1; j < Array.length; j++){
            if(array[j] < array[min]){
                min = j  
            }
        }
        if(i!==min){
        let temp = array[j]
        array[i] = array[min]
        array[min] = temp
        }
    }
    return array
}