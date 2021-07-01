function maxStockProfit(priceArray){
    var maxProfit = -1;
    var buyPrice = 0;
    var sellPrice = 0;
    
    var changeBuyPrice = true;

    for(let i = 0; i < priceArray.length; i++){
        if(changeBuyPrice)buyPrice = priceArray[i]
        sellPrice = priceArray[i+1]


        if(sellPrice < buyPrice){
            changeBuyPrice = true;
        }else{
            let tempProfit = sellPrice - buyPrice;
            if(tempProfit > maxProfit){
                maxProfit = tempProfit;
            }
            changeBuyPrice = false;
        }
    }
    return maxProfit;
}

maxStockProfit([10,6,25,36,100,2,3])