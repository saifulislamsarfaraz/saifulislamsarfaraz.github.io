class Node{
    constructor(value) {
        this.value = value
        this.left = null
        this.right = null
    }
}

class BST{
    constructor(){
        this.root = null
    }

    insert(value){
        const newNode = new Node(value)
        if(root === null){
            this.root = newNode
            return this
        }
        let temp = this.root
        while(true){
            if(newNode.value === temp.value){
                return undefined
            }
            if(newNode.value < temp.value){
                if(temp.left===null){
                    temp.left = newNode
                    return this
                }
                temp = temp.left
            }else{
                if(temp.right===null){
                    temp.right = newNode
                    return this
                }
                temp = temp.right
            }
        }
    }

    search(value){
        if(root === null){
            return undefined
        }
        let temp = this.root
        while(temp){
            if(value < temp.value){

                temp = temp.left
            }else if(value > temp.value){
                temp = temp.right
            }else{
                return true
            }
        }
        return false
    }































}

let tree = new BST()
tree.insert(10)
tree.insert(12)
tree.insert(13)
tree.insert(14)
tree.insert(15)
