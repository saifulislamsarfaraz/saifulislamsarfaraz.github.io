const items = ["Mirpur","Uttara","Mohammadpur","Dhanmondi","Savar",
"Badda","Jatrabari","Gulshan","Bashundhara","Rampura","Motijheel","Basabo","Banani"]; //array to hold all the countries
const root = new MakeNode('\0') //making the root note


//processing Data and adding to the items array
processingData = async () => {
  for (const item of items) {
    add(item, 0, root)
  }
  textFieldHandler({ target: { value: '' } })
}

processingData()

const textField = document.getElementById('text-field')
const list = document.getElementById('list')

textField.addEventListener('input', textFieldHandler)

function handleTap(e) {
  const text = e.innerText
  textField.value = text
}

//function for text-field
function textFieldHandler(e) {
  const value = e.target.value.toUpperCase()
  const predictions = search(value, 0, root)

  list.innerHTML = ''

  for (let p of predictions) {
    p = p.charAt(0).toUpperCase() + p.slice(1)
    list.innerHTML += `<li class="list-group-item clickable" onclick="handleTap(this)"><b>${p.substring(
      0,
      value.length
    )}</b>${p.substring(value.length)}</li>`
  }
}
