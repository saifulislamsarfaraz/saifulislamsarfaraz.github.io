class Node {
    constructor(value){
        this.value = value
        this.next = null
        this.prev = null
    }
}

class DoublyLinkedList{
    constructor (value){
        const newNode = new Node(value)
        this.head = newNode
        this.tail = this.head
        this.length = 1
    }


        push(value){
        const newNode = new Node(value)
        if(!this.head){
            this.head = newNode
            this.tail = newNode
        }else{
            this.tail.next = newNode
            newNode.prev = this.tail
            this.tail = newNode
        }
        this.length++
        return this
    }

    pop(){
        if(this.length===0)
        return undefined

        let temp = this.tail
        this.tail = this.tail.prev
        this.tail.next = null
        temp.prev = null
	return this 

        
    }




























}

let myDoublyLinkedList = new DoublyLinkedList(10)
myDoublyLinkedList
