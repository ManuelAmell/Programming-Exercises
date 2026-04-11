console.log('Ciclo Do While :')
let i = 1;
while ( i <= 10){
    
    if (i %2 === 0){
         console.log(i, '= par ');
         //break;FFT
    }
    else {
        console.log(i, '= No par');
        //continue; FFT
    }
    i++;
}
//Do While
let j=1;
console.log('Ciclo Do While :')
do {

    if (j %2 === 0){
         console.log(j, '= par ');
    }
    else {
        console.log(j, '= Impar');
    }
    j++;
}while (j <= 10)
//FOR
console.log('Ciclo FOR :')
for(let i = 0; i < 10; i++){
      if (i %2 === 0){
         console.log(i, '= par ');
    }
    else {
        console.log(i, '= No par');
    }
  
}
// For of 
console.log('Ciclo FOR OF : Para mostrar elemntos ')
let animales = ['Perro', 'Gato ', 'Leon' , 'Trex']
for (let animal of animales){
    console.log(animal);
}
// For in
console.log('Ciclo FOR IN : para mostrar propiedades o atributos')
let user = {
    id :1 ,
    name : 'Manuel A' ,
    age : 20 ,
};
for (let prop in user ){
    console.log(prop , user[prop]);
}