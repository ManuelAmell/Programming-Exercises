#include <iostream>
using namespace std;

int main() {
    // \n: Salto de línea
    cout << "Hola\nMundo\n"; // Imprime "Hola", luego salta de línea y luego "Mundo"

    // \r: Retorno de carro (vuelve al inicio de la línea)
    cout << "123456\rXYZ\n"; // Imprime "XYZ456" porque "XYZ" sobreescribe "123"

    // \t: Tabulación horizontal (como presionar Tab)
    cout << "Columna1\tColumna2\tColumna3\n";

    // \v: Tabulación vertical (salto vertical, poco usado)
    cout << "Primera\vSegunda\vTercera\n"; // Puede verse extraño en algunos compiladores

    // \f: Avance de página (form feed), también poco usado
    cout << "Primera\fSegunda\n"; // Efecto depende del sistema, puede que no se note

    // \b: Retroceso de espacio (backspace, borra el carácter anterior)
    cout << "Hola\b!\n"; // Intenta borrar la 'a' y poner '!', resultado: "Hol!"

    // \a: Alerta sonora
    cout << "Suena alerta\a\n"; // Emitirá un pitido si tu sistema lo permite

    // \\: Imprimir barra invertida
    cout << "Ruta en Windows: C:\\Program Files\\\n";

    // \': Comilla simple
    cout << "Caracter especial: \' \n";

    // \": Comilla doble
    cout << "Texto entre comillas dobles: \"Hola\"\n";

    // \?: Signo de interrogación (raro que se use, pero sirve para evitar ambigüedades con trigraphs antiguos)
    cout << "¿Esto es valido? \?\n";

    // \000: Número octal
    char octalChar = '\101'; // 101 en octal es 65 en decimal, que es 'A'
    cout << "Carácter desde octal \\101: " << octalChar << "\n";

    // \xhhh: Número hexadecimal
    char hexChar = '\x42'; // 0x42 es 66 en decimal, que es 'B'
    cout << "Carácter desde hexadecimal \\x42: " << hexChar << "\n";

    // Constante cadena dividida en varias líneas con '\'
    cout << "Esto es una cadena\
 que continúa en la siguiente línea\n";

    return 0;
}
