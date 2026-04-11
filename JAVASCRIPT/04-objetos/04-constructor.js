function Usuario(){// Aqui es bueno el UpperCamelCase
    this.id = 1;
    this.recuperarClave = function (){// aqui pasa a llamarse metodos
        console.log('recuperando clave');
    }
}
let usuario1 = new Usuario;
console.log(usuario1);