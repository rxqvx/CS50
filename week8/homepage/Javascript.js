const texto='';
let resp;
function Login(event)
{
  event.preventDefault();

  var resp = document.getElementById('resp');
  var user = document.getElementById("name1").value;
  var pass = document.getElementById("name2").value;
  var texto='';

  texto ="Hello, your name is "+ user+ " " +pass;

  resp.innerHTML = texto;
}

