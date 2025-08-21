class MakeNode {
  constructor(ch) {
    this.ch = ch
    this.isTerminal = false
    this.map = {} // key -> anotherNode
    this.words = []
  }
}

//adding word to tree recursively
function add(str, i, root) {
  if (i === str.length) {
    root.isTerminal = true
    return
  }

  if (!root.map[str[i]]) {
    root.map[str[i]] = new MakeNode(str[i])
  }

  root.words.push(str)
  add(str, i + 1, root.map[str[i]])
}

//searching word from tree recursively
function search(str, i, root) {
  if (i === str.length) {
    return root.words
  }

  if (!root.map[str[i]]) {
    return []
  }

  return search(str, i + 1, root.map[str[i]])
}
