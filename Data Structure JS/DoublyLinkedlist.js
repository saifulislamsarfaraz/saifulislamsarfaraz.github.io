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
<<<<<<< HEAD
        this.length--
        if(this.length===0){
            this.head = null
            this.tail = null
        }
        return temp        
    }

    
    unShift(){
        const newNode = new Node()
     if(!this.head){
         this.head = newNode
         this.tail = newNode
     }else{
        newNode.next = this.head   
        this.head.prev = newNode
     }       
     
=======
	return this 

        
>>>>>>> d54e627f6d7de1ad88aac12e6b37f733fe5ff984
    }




























}

let myDoublyLinkedList = new DoublyLinkedList(10)
myDoublyLinkedList
