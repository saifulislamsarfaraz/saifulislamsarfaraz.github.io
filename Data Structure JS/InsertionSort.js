function insertionSort(Array){
    let temp
    for(let i = 1; i < Array.length; i++){
        temp = Array[i]
        for(var j = i-1; Array[j] > temp && j > -1; j--){
            Array[j+1] = Array[j]
        }
        Array[j+1] = temp
    }
    return Array
}