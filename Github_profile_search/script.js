const APIURL = 'https://api.github.com/users/'

getUser('saifulislamsarfaraz')
/* function getUser(username){
    axios(APIURL + username)
    .then(res => console.log(res))
    .catch(err => console.log(err))
} */

async function getUser( username){
    const res = await axios(APIURL + username)
    console.log(res.data)

}
