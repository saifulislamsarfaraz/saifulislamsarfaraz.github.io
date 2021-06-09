const APIURL = 'https://api.github.com/users/'

getUser('saifulislamsarfaraz')
/* function getUser(username){
    axios(APIURL + username)
    .then(res => console.log(res))
    .catch(err => console.log(err))
} */

const form = document.getElementById('form')

async function getUser( username){
    try{
        const {data} = await axios(APIURL + username)

        console.log(data)
    
    }catch(error){
        console.log(error)
    }
}

form.addEventListener('submit')
