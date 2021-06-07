class Cookie{
    constructor(color){
        this.color = color
    }
    getColor(){
        return this.color
    }
    setColor(){
        this.color = color 
    }
}

let cookieOne = new Cookie ("Green")
let cookieTwo = new Cookie("blue")

/* output
cookieOne.getColor()
Green
cookieTwo.getColor()
blue 
cookieOne.setColor("Red")
cookieOne.getColor()
Red */