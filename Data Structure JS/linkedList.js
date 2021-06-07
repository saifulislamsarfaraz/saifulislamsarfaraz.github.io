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
}

let myLinkedList = new LinkedList(18)
myLinkedList.push(12)
myLinkedList.push(13)
myLinkedList.push(42)
