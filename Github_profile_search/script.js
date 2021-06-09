const APIURL = 'https://api.github.com/users/'

/* function getUser(username){
    axios(APIURL + username)
    .then(res => console.log(res))
    .catch(err => console.log(err))
} */

const form = document.getElementById('form')
const main = document.getElementById('main')
const search = document.getElementById('search')

async function getUser( username){
    try{
        const {data} = await axios(APIURL + username)


        createUserCard(data)
    
    }catch(error){
        console.log(error)
    }
}

function createUserCard(card){
        const cardHTML = ` 
        <div class="card">
        <div>
            <img src="https://randomuser.me/api/portraits/men/32.jpg" alt="" class="avater">
        </div>
    
        <div class="user-info">
             <h2>jhondoe</h2>
            <ul>
                <li>300 <strong>Followers</strong></li>
                <li>100 <strong>Following</strong></li>
                <li>50 <strong>Repos</strong></li>
            </ul>

              <div id="repo">
                <a href="#" class="repo">Repo 1</a>
                <a href="#" class="repo">Repo 2</a>
                <a href="#" class="repo">Repo 3</a>
              </div>
        </div>
    </div>
    `

    main.innerHTML = cardHTML
}

form.addEventListener('submit',(e) => {
    e.preventDefault()

    const user = search.value

    if(user){
        getUser(user)

        search.value = '' 
    }
})
