//personajes de TV
let nombre = "tanjiro";
let anime = "Demon Slayer";
let edad = 16;

let personaje = {//par llave - valor
    nombre: "Tanjiro",
    anime: "Demon Slayer" ,
    edad:16 ,
};
console.log(personaje);
console.log(personaje.nombre);
console.log(personaje['anime']);

personaje.edad = 13;
//o 
personaje['edad']= 16;

delete personaje.anime;