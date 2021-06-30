function bubbleSort(array){
    for(let i = array.length-1; i > 0; i--){
        for(let j = 0; j < i; j++){
            if(array[j]>array[j+1]){
                let temp = array[i]
                array[i] = array[j+1]
                array[j+1] = temp
            }
        }
    }
    return array
}

bubbleSort(1,6,5,4,2,1)