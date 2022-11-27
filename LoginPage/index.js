
const nameBox = document.querySelector("#name")
const gmailBox = document.querySelector("#gmail")
const passBox = document.querySelector("#pass")
const loginbut = document.querySelector("#loginbutt")
const viewbut = document.querySelector("#view")
let temp = 0;

const loginBox = [nameBox,gmailBox,passBox,viewbut]

for (let index = 0; index < loginBox.length; index++){
  loginBox[index].addEventListener('mouseover',backgroundAnimation(loginBox[index]))  
}
loginbut.addEventListener('mouseover',customAnimation(loginbut))

document.querySelector("#loginbutt").onclick = function(){
check(nameBox,gmailBox,passBox); 
}

loginBox[3].onclick = () =>{
  passView();
}

function backgroundAnimation(object){
   
        object.addEventListener('mouseover',() =>{
            object.style.backgroundColor = 'rgb(216, 213, 213)'
           })
           object.addEventListener('mouseout', () => 
           object.style.backgroundColor = 'white')

}

function customAnimation(object){

    object.addEventListener('mouseover',() =>{
        object.style.backgroundColor = 'lightgreen'
       })
       object.addEventListener('mouseout', () => 
       object.style.backgroundColor = 'white')

}

function check(checkName,checkEmail,checkPassword){

  checkName = document.querySelector("#name").value
  checkEmail =  document.querySelector("#gmail").value;
  checkPassword =  document.querySelector("#pass").value

  var valid = false;

  const nameformat = /^[a-zA-Z0-9]+$/
  const mailformat = /^[^\s@]+@[^\s@]+$/
  const passformat = /^(?=.*[0-9])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{7,15}$/

  if(checkName.match(nameformat)){
  valid = false
     }
   else{
    valid = false
    nameBox.style.backgroundColor = 'rgb(236, 98, 98)'
   }
    if(checkEmail.match(mailformat)){
      valid = true
    }
    else{
      valid = false
      gmailBox.style.backgroundColor = 'rgb(236, 98, 98)'
    }
    if(checkPassword != ""){
    if(checkPassword.match(passformat)){
      valid = true
     }
     else{
     valid = false
     passBox.style.backgroundColor = 'rgba(255, 255, 0, 0.521)'
      }
    }
    else{
      valid = false
     passBox.style.backgroundColor = 'rgb(236, 98, 98)'
    }
    if(valid == true){window.open("http://127.0.0.1:5500/index2.html")
       valid == false
    }
    else loginbut.style.backgroundColor = 'rgb(236, 98, 98)'

    
}
function passView(i) {
    
 switch (temp) {
    case 0:
    passBox.type = "text"
    temp =1   
    break;

    case 1: 
    passBox.type = "password"
    temp =0
    break;
 }
 
}
