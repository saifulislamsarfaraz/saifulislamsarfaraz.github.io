class LinkedList{
    constructor(value){
        const newNode = new Node(value)
        this.head = newNode
        this.tail = this.head
        tails.length = 1
    }

    push (value){
        const newNode = new Node(value)
        if(!this.head){
            this.head = newNode
            this.tail = newNode
        } else{
            this.tail.next = newNode 
            this.tail = newNode
        }
        this.length++
        return this
    }

    pop(){
        if(!this.head){
            return undefined
        }
        let temp = this.head
        let pre = this.head
        while(this.head){
            pre = temp 
            temp.next = temp
        }
        this.tail = pre
        this.tail.next = null
        length--

        if(length===0){
            this.head = null
            this.tail = null
        }
        return temp
    }

    //unshift 

    unshift(value){
        const newNode = new Node(value)
        if(!this.head){
            this.head = newNode
            this.tail = newNode
        }else{
            newNode.next = this.head
            this.head = newNode
        }
        length++
        return this
    }
}

let myLinkedList = new LinkedList(18)
myLinkedList.push(12)
myLinkedList.push(13)
myLinkedList.push(42)
myLinkedList.pop()