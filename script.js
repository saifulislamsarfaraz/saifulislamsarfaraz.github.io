const toggle = document.getElementById('toggle');
const close = document.getElementById('close');
const open = document.getElementById('open');
const modal = document.getElementById('modal');

// Toggle nav
toggle.addEventListener('click', () =>document.body.classList.toggle('show-nav')
);

// Show modal
open.addEventListener('click', () => modal.classList.add('show-modal'));

// Hide modal
close.addEventListener('click', () => modal.classList.remove('show-modal'));

// Hide modal on outside click
window.addEventListener('click', e =>
  e.target == modal ? modal.classList.remove('show-modal') : false
);

//github_profile_search
const APIURL = 'https://api.github.com/users/'

/* function getUser(username){
    axios(APIURL + username)
    .then(res => console.log(res))
    .catch(err => console.log(err))
} */

const main = document.getElementById('main')
const form = document.getElementById('form')
const search = document.getElementById('search')

async function getUser(username){
    try{
        const { data } = await axios(APIURL + username)

        createUserCard(data)
        getRepos(username)
    
    }catch(error){
        if(error.response.status == 404){
            createErrorCard('No profile with this User Name')
        }
        
    }
}

async function getRepos(username){
    try{
        const { data } = await axios(APIURL + username +'/repos?sort=created')

        addReposToCard(data)
    
    }catch(error){
    
            createErrorCard('Problem fetching repos')
        
        
    }

}

function createUserCard(user){
        const cardHTML = ` 
    <div class="card">
        <div>
            <img src=" ${user.avatar_url} " alt=" ${user.name} " class="avater">
        </div>
    
        <div class="user-info">
             <h2>${user.name}</h2>
             <p>${user.bio}</p>
            <ul>
                <li> ${user.followers} <strong>Followers</strong></li>
                <li> ${user.following} <strong>Following</strong></li>
                <li> ${user.public_repos} <strong>Repos</strong></li>
            </ul>

              <div id="repos"></div>
        </div>
    </div>
    `

    main.innerHTML = cardHTML
}


function createErrorCard(msg){
    const cardHTML = `
    <div class="card">
        <h1>${msg}</h1>
    </div>
    `
    main.innerHTML = cardHTML
}

function addReposToCard(repos){
    const reposElement = document.getElementById('repos')

    repos
    .slice(0, 5)
    .forEach(repo=>{
        const repoElement = document.createElement('a')
        repoElement.classList.add('repo')
        repoElement.href = repo.html_url
        repoElement.target = '_blank'
        repoElement.innerText = repo.name

        reposElement.appendChild(repoElement)



    })

}

form.addEventListener('submit',(e) => {
    e.preventDefault()

    const user = search.value

    if(user){
        getUser(user)

        search.value = '' 
    }
})

//end github_profile_search