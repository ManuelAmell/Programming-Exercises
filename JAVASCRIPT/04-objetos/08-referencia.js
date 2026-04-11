
/*let a = 1;
let b = a;
b++;
console.log(a , b);*/
//los objetos se crean por referencia(objetos , arrrays , funciones) , el resto se copian 
/*
let a = {};
let b = a ;
b.prop = 1;
console.log(a, b);
*/
let a = {prop: 1};
function suma (n){
    n.prop++;
}
suma (a);
console.log(a);
