function suma(a ,b){//aqui se llaman parametros
    console.log(arguments);
    return a + b;
}

suma (12);
let resultado = suma(12, 24);//los valores se lllaman argumentos
console.log(resultado);
console.log(typeof suma);