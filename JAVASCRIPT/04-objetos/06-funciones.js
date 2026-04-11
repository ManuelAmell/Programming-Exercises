//las funciones tambien son objetos de primera clase
//  , tienen propiedades y se pueden asignar a cosas
//  y se puede pasar como argumentos
function Usuario(nombre){
    this.nombre = nombre;
}
console.log(Usuario.name);
console.log(Usuario.length);

const U = Usuario;
let user = new U('Nicolas');
console.log (user);
function of(Fn, arg){
    return new Fn(arg);
}
let user1 = of(Usuario , 'chancho ');
console.log(user1);

function returned(){
    return function(){
        console.log('hola mundo');
    }
}
let saludo = returned();
saludo ();