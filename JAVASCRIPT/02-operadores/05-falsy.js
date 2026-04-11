// Valores falsy en JavaScript:
// Son valores que se consideran "false" en contextos booleanos
// false
// 0
// '' (cadena vacía)
// undefined
// NaN
// null 

let nombre = 'Amell';

// El operador OR (||) devuelve el PRIMER valor truthy que encuentre
// Si 'nombre' tiene valor (es truthy), se asigna ese
// Si fuera falsy, entonces usaría 'anonimo'
let username = nombre || 'anonimo';

console.log(username); // Imprime: Amell


function fn1() {
    console.log('Funcion 1');
    return false;    
}

function fn2() {
    console.log('Funcion 2');
    return true;
}

// El operador AND (&&):
// Evalúa de izquierda a derecha
// Si encuentra un valor falsy, se detiene y lo devuelve (corto circuito)
// Si todos son truthy, devuelve el último valor

let x = fn1() && fn2();

// En este caso:
// fn1() retorna false → ya es falsy
// Entonces NO se ejecuta fn2() (corto circuito)
// x vale false