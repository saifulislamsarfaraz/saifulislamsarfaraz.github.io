const open = document.getElementById('open')
const close = document.getElementById('close')
const container = document.querySelector('.container')
const openLeft = document.getElementById('openLeft')
const closeLeft = document.getElementById('closeLeft')
//const container = document.querySelector('.container')


close.addEventListener('click', () => container.classList.remove('show-nav'))


open.addEventListener('click', () => container.classList.add('show-nav'))

closeLeft.addEventListener('click', () => container.classList.remove('show-nav1'))


openLeft.addEventListener('click', () => container.classList.add('show-nav1'))


const search = document.querySelector('.search')
const btn_search = document.querySelector('.btn_search')
const input_search = document.querySelector('.input_search')


btn_search.addEventListener('click', () => {
  search.classList.toggle('active')
  input_search.focus()
})

const loadText = document.querySelector('.loading-text')
const img = document.querySelector('.img');

let load = 0;

let int = setInterval(blurring, 30);

function blurring() {

  load++;

  if (load > 199) {
    clearInterval(int);
  }
  loadText.innerText = `${load}%`
  loadText.style.opacity = scale(load, 0, 100, 1, 0)
  img.style.filter = `blur(${scale(load, 0, 100, 30, 0)}px)`

}

const scale = (num, in_min, in_max, out_min, out_max) => {

  return ((num - in_min) * (out_max - out_min)) / (in_max - in_min) + out_min
}






