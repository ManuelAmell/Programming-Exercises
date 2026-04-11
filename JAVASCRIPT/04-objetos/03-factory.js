function crearUsuario(name , email){
   return {
    email ,
     name ,
     activo : true ,
     recuperarClave : function () {
        console.log('Recupernd Clave...')
         } , 
    };
}
let user1 = crearUsuario ('manuel', 'cromo@gmail');
let user2 = crearUsuario ('Amell', 'cromo@gmail');

console.log ( user1, user2);