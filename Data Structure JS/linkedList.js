class Node {
    constructor(value){
        this.value = value
        this.next = null
    }
}

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

    shift(){
        if(!this.head){
            return undefined
        }
        let temp = this.head
        this.head = this.head.next
        temp.next = null 
        length--
        if(length === 0){
            this.head = null
            this.tail = null
        }
        return temp
    }

    get(index){
        if(index < 0 || index >= this.length){
            return undefined
        }
        let temp = this.head 
        for(let i = 0; i < index; i++){
            temp = temp.next
        }
        return temp
    }

    set(index, value){
        let temp = this.get(index)
        if(temp){
            temp.value = value
            return true
        }
        return false
    }

}

let myLinkedList = new LinkedList(18)
myLinkedList.push(12)
myLinkedList.push(13)
myLinkedList.push(42)
myLinkedList.pop()
myLinkedList.unshift(20)
myLinkedList.get(3)//index value passing 
myLinkedList.set(3,20)




