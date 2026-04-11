function Punto (x , y ){
    this.x = x;
    this.y = y;
    this.dibujar = function () {
        console.log('Dibujando...');
    }
}
//function es igual a lo de arriba 
/*
const Point = new Function('x', 'y', `
    this.x = x;
    this.y = y;
    this.dibujar = function() {
        console.log('Dibujando...');
    }
`);*/
//extender objetos
let punto = { z:7};
Punto.call(punto , 1 , 2 );
//es exactamente lo mismo lo q cambia es el formato sintactico
Punto.apply(punto, [1 , 2]);
console.log(punto);
