<div align="center">

# 💻 Programming Exercises

[![Python](https://img.shields.io/badge/Python-3.12+-3776AB?style=flat-square&logo=python&logoColor=white)](https://python.org)
[![C++](https://img.shields.io/badge/C++-17+-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![Java](https://img.shields.io/badge/Java-17+-ED8B00?style=flat-square&logo=openjdk&logoColor=white)](https://openjdk.org)
[![JavaScript](https://img.shields.io/badge/JavaScript-ES6+-F7DF1E?style=flat-square&logo=javascript&logoColor=black)](https://developer.mozilla.org/en-US/docs/Web/JavaScript)
[![TypeScript](https://img.shields.io/badge/TypeScript-3178C6?style=flat-square&logo=typescript&logoColor=white)](https://www.typescriptlang.org/)
[![HTML](https://img.shields.io/badge/HTML5-E34F26?style=flat-square&logo=html5&logoColor=white)](https://developer.mozilla.org/en-US/docs/Web/HTML)

**Repositorio personal de ejercicios, proyectos y experimentos de programación**

[Explorar](#-estructura-del-repositorio) • [Cómo Usar](#-cómo-usar) • [Tecnologías](#-tecnologías)

</div>

---

## 📂 Estructura del Repositorio

```
Programming-Exercises/
│
├── 🐍 PYTHON/                    # Scripts y proyectos Python
│   ├── Automatizaciones/         # Scripts de automatización
│   │   ├── back_up.py           # Backup de archivos
│   │   ├── CamaraMouse.py       # Control de mouse con cámara
│   │   ├── Carpetas.py          # Creación de carpetas
│   │   ├── Correos.py           # Gestión de correos
│   │   ├── correos2.py          # Envío de correos
│   │   ├── formatojc.py         # Formateo de texto
│   │   ├── music.py             # Reproductor de música
│   │   └── pruebaia.py          # Experimentos con IA
│   │
│   ├── Ciente/                   # Cliente / Servidor
│   │   ├── cliente.py           # Cliente de red
│   │   └── Servidor/
│   │       └── servidor.py      # Servidor de red
│   │
│   ├── Ordenamiento/             # Algoritmos de ordenamiento
│   │   └── sorting_algorithms.py # Implementaciones de sort
│   │
│   ├── PDFs/                     # Generación de PDFs
│   │   ├── clase1.py
│   │   ├── generar_plantilla.py
│   │   └── proyecto.ipynb
│   │
│   ├── Ajedrez.py                # Juego de ajedrez
│   ├── check_ports.py            # Escáner de puertos
│   ├── generar_plantilla.py      # Generador de plantillas
│   ├── gethost.py                # Obtener host/IP
│   ├── integrador.py             # Proyecto integrador
│   ├── params_ports_scan.py      # Escaneo con parámetros
│   ├── pithon.py                 # Script de prueba
│   └── proyecto2.ipynb           # Notebook Jupyter
│
├── 💻 C++/                       # Proyectos y ejercicios en C++
│   ├── Archivos/                 # Manejo de archivos
│   │   ├── notastxt.cpp         # Notas en archivos de texto
│   │   ├── notasbin.cpp         # Notas en archivos binarios
│   │   ├── binario.cpp          # Archivos binarios
│   │   ├── claudeempleados.cpp  # Gestión de empleados
│   │   ├── formateado.cpp       # Formateo de archivos
│   │   ├── metodos.cpp          # Métodos de archivo
│   │   └── plantillabin1.cpp    # Plantilla binaria
│   │
│   ├── Arreglos/                 # Matrices y arreglos
│   │   ├── matristrans.cpp      # Matriz transpuesta
│   │   ├── matriztransp.cpp     # Matriz transpuesta v2
│   │   ├── matrizvector.cpp     # Matriz a vector
│   │   ├── opmatriz.cpp         # Operaciones con matrices
│   │   ├── todoarrmatriz.cpp    # Todos los arreglos
│   │   └── todomatrizv2.cpp     # Matrices v2
│   │
│   ├── Ejercicios/               # 100+ ejercicios de clase
│   │   └── Archivos/            # ej1.cpp ... ej76.cpp, retos, parciales
│   │
│   ├── Esteticos/                # Efectos visuales
│   │   ├── ascii.cpp            # Arte ASCII
│   │   ├── centrado.cpp         # Texto centrado
│   │   ├── colores.cpp          # Colores en terminal
│   │   ├── constantecaracter.cpp
│   │   ├── mainstructs.cpp
│   │   ├── tablas.cpp           # Tablas en terminal
│   │   ├── terminal.cpp         # Efectos de terminal
│   │   └── terminal2.cpp
│   │
│   ├── Funciones/                # Ejercicios de funciones
│   │   ├── algebra.cpp          # Funciones algebraicas
│   │   ├── blackhole.cpp        # Simulación blackhole
│   │   ├── clase1.cpp
│   │   ├── funciones.cpp
│   │   └── numerosamigos.cpp    # Números amigos
│   │
│   ├── Games/                    # Juegos en C++
│   │   └── 1.cpp
│   │
│   ├── Hacker Rank/              # Ejercicios HackerRank
│   │   └── absolutevalue.cpp    # Valor absoluto
│   │
│   ├── Librerias/                # Bibliotecas propias
│   │   ├── arreglos.h
│   │   ├── cadenas_basico.h
│   │   ├── numeros.h
│   │   └── main*.cpp            # Programas de prueba
│   │
│   ├── Ordenamiento/             # Algoritmos de ordenamiento
│   │   ├── animacionburbuja.cpp # Burbuja animado
│   │   ├── bubbleshort.cpp      # Bubble sort
│   │   ├── burbuja.cpp          # Algoritmo burbuja
│   │   ├── inserccion.cpp       # Inserción
│   │   └── random.cpp
│   │
│   ├── Proyectos-Evaluables/     # Proyectos calificables
│   │   ├── proyecto/            # Proyecto completo
│   │   │   ├── Proyecto..cpp
│   │   │   └── wp.h
│   │   ├── formateado.cpp
│   │   ├── PB2025.cpp
│   │   ├── proyecto.cpp
│   │   └── proyecto3C.cpp
│   │
│   ├── Proyectos-small/          # Proyectos pequeños
│   │   ├── contraseñas.cpp      # Gestor de contraseñas
│   │   ├── escanerdepuertos.cpp # Escáner de puertos
│   │   ├── escanerpuertoslinux.cpp # Escáner para Linux
│   │   ├── gcontraseñas.cpp     # Generador de contraseñas
│   │   ├── horario.cpp          # Gestión de horarios
│   │   ├── P1.cpp
│   │   ├── PB.cpp
│   │   └── punteros.cpp
│   │
│   ├── Saber/                    # Ejercicios de repaso
│   │   ├── Avanzado/            # Algoritmos avanzados
│   │   │   ├── combinatoriav.cpp
│   │   │   ├── Dijkstra.cpp     # Algoritmo Dijkstra
│   │   │   └── kruskhal.cpp     # Algoritmo Kruskal
│   │   ├── burbuja.cpp          # Algoritmo burbuja
│   │   ├── inserccion.cpp       # Inserción
│   │   ├── menu.cpp
│   │   ├── modulo.cpp
│   │   ├── recursividaypunteros.txt
│   │   └── sabermatrices.cpp
│   │
│   ├── Structs/                  # Estructuras de datos
│   │   ├── Cadenas/             # Manipulación de cadenas
│   │   │   ├── cadenas.cpp
│   │   │   ├── cadenas1.cpp
│   │   │   └── funcionespredefinidas.cpp
│   │   ├── structs1.cpp         # Ejercicios básicos
│   │   └── structs2.cpp
│   │
│   └── Texto/                    # Archivos de datos de texto
│       ├── datos.txt
│       ├── ejemplo.txt
│       ├── empleados.txt
│       └── estudiantes.txt
│
├── ☕ JAVA/                      # Proyectos Java
│   ├── Basics/                   # Fundamentos de Java
│   │   ├── Archivos.java        # Manejo de archivos
│   │   ├── BusquedaBinaria.java # Búsqueda binaria
│   │   ├── Busqueda.java        # Búsquedas
│   │   ├── Conversiones.java    # Conversiones de tipos
│   │   ├── ExcepcionesPersonalizadas.java
│   │   ├── javaesenciales.java  # Esenciales de Java
│   │   ├── ManejoDeCadenas.java # Cadenas de texto
│   │   ├── OperacionesLista.java
│   │   └── OrdenarObjetos.java  # Ordenamiento de objetos
│   │
│   ├── Clases/                   # Material de clase
│   │   └── Encapsulamiento.zip
│   │
│   ├── Encapsulamiento/          # Ejercicios de encapsulamiento
│   │   └── src/co/edu/unicartagena/session3/
│   │       ├── package1/        # Clases privadas
│   │       ├── package2/        # Clases protegidas
│   │       └── package3/        # App pública
│   │
│   ├── HackerRank/               # Soluciones HackerRank
│   │   ├── src/easy/            # Problemas fáciles
│   │   └── README.md
│   │
│   ├── PDF_TALLERES/             # Documentos de talleres
│   │
│   ├── POO/                      # Programación orientada a objetos
│   │   ├── Abstraccion.java
│   │   ├── ClasesYObjetos.java
│   │   ├── Constructores.java
│   │   ├── Encapsulamiento.java
│   │   ├── Excepciones.java
│   │   ├── Herencia.java
│   │   ├── Interfaces.java
│   │   ├── Polimorfismo.java
│   │   ├── ClasesYObjetos/      # Proyecto Auto
│   │   ├── Metodo_Constructor/  # Proyecto Persona
│   │   ├── ParametrosSinRetorno/# Operaciones
│   │   ├── ParametrosYArgumentos/
│   │   └── SobrecargaDeConstructoesYMetodos/
│   │
│   ├── ProyectosPersonales/      # Proyectos propios
│   │   └── PasswordSecure/      # Gestor de contraseñas
│   │       ├── src/App/App.java
│   │       └── src/password/    # Cuenta + PasswordGenerator
│   │
│   └── TALLERES/                 # Talleres de clase
│       ├── Primer Corte/        # T2, T4 y Diagramas UML
│       │   ├── T2/gestionFigGeom/  # Figuras geométricas
│       │   ├── T4/              # Sistema de organización
│       │   └── Diagramas UML/
│       ├── Segundo Corte/       # T1, T2 y Diagramas UML
│       │   ├── T1/              # Clínica veterinaria
│       │   ├── T2/              # Figuras geométricas
│       │   └── Diagramas UML/
│       └── TercerCorte/         # Talleres 6+
│
├── 🌐 HTML/                      # Proyectos Web
│   ├── index.html               # Página principal
│   ├── index2.html              # Página secundaria
│   └── style.css                # Estilos CSS
│
├── 💛 JAVASCRIPT/                # Ejercicios JavaScript
│   ├── 01-tipos/                # Tipos de datos
│   │   ├── 01-variables.js      # Variables y declaraciones
│   │   ├── 02-primitivos.js     # Tipos primitivos
│   │   ├── 03-constantes.js     # Constantes
│   │   ├── 04-tipado-dinamico.js
│   │   ├── 05-comentarios.js
│   │   ├── 06-objetos.js        # Objetos básicos
│   │   ├── 07-arrays.js         # Arrays y métodos
│   │   ├── 08-funciones.js      # Funciones
│   │   └── 09-argumentos.js     # Argumentos
│   │
│   ├── 02-operadores/           # Operadores
│   │   ├── 01-aritmeticos.js    # Operadores aritméticos
│   │   ├── 02-asignacion.js     # Asignación
│   │   ├── 03-comparacion.js    # Comparación
│   │   ├── 04-logicos.js        # Operadores lógicos
│   │   ├── 05-falsy.js          # Valores falsy
│   │   ├── 06-ordenOperaciones.js
│   │   └── 07-ternario.js       # Operador ternario
│   │
│   ├── 03-control-flujo/        # Control de flujo
│   │   ├── 01-if.js             # Condicionales
│   │   ├── 02-loops.js          # Bucles
│   │   └── 03-switch.js         # Switch case
│   │
│   ├── 04-objetos/              # Objetos avanzados
│   │   ├── 01-intro.js          # Introducción
│   │   ├── 02-dinamico.js       # Objetos dinámicos
│   │   ├── 03-factory.js        # Factory functions
│   │   ├── 04-constructor.js    # Constructores
│   │   ├── 05-atajos.js
│   │   ├── 06-funciones.js
│   │   ├── 07-function.js
│   │   ├── 08-referencia.js     # Referencias
│   │   └── 09-listar-propiedaes.js
│   │
│   ├── index.html               # Página de pruebas
│   └── app.js                   # Aplicación principal
│
├── 🔷 TYPESCRIPT/               # Ejercicios TypeScript
│   ├── AprendiendoTS/           # Proyecto React + Vite
│   │   ├── src/                 # Código fuente
│   │   │   ├── App.tsx          # Componente principal
│   │   │   ├── main.tsx         # Punto de entrada
│   │   │   └── assets/          # Recursos estáticos
│   │   ├── public/              # Archivos públicos
│   │   ├── package.json         # Dependencias
│   │   ├── tsconfig.json        # Configuración TS
│   │   └── vite.config.ts       # Configuración Vite
│   └── Helloworld.ts            # Archivo de prueba
│
└── 📚 cleancode.pdf              # Libro Clean Code
```

---

## 🛠️ Tecnologías

| Lenguaje | Uso Principal | Archivos |
|----------|--------------|----------|
| **Python** 🐍 | Automatización, Redes, IA, Algoritmos | 20 archivos |
| **C++** 💻 | Estructuras de datos, Algoritmos, Juegos | 200+ archivos |
| **Java** ☕ | POO, Talleres, HackerRank, Proyectos | 70+ archivos |
| **JavaScript** 💛 | Fundamentos, Objetos, Control de flujo | 29 archivos |
| **TypeScript** 🔷 | Tipos, React + Vite | 1 proyecto |
| **HTML/CSS** 🌐 | Desarrollo Web frontend | 3 archivos |

---

## 🚀 Cómo Usar

### Clonar el repositorio

```bash
git clone https://github.com/ManuelAmell/Programming-Exercises.git
cd Programming-Exercises
```

### Ejecutar según el lenguaje

<details>
<summary><b>🐍 Python</b></summary>

```bash
cd PYTHON
python nombre_script.py
```
</details>

<details>
<summary><b>💻 C++</b></summary>

```bash
cd C++
g++ -o programa archivo.cpp
./programa
```
</details>

<details>
<summary><b>☕ Java</b></summary>

```bash
cd JAVA
javac NombreClase.java
java NombreClase
# Para proyectos modulares (con src/), compilar desde la raíz del proyecto:
# javac -d out src/**/*.java && java -cp out NombreClase
```
</details>

<details>
<summary><b>💛 JavaScript</b></summary>

```bash
cd JAVASCRIPT
# Abre index.html en tu navegador o ejecuta con Node.js
node 01-tipos/01-variables.js
```
</details>

<details>
<summary><b>🌐 HTML/CSS</b></summary>

Abre los archivos directamente en tu navegador web.
</details>

---

## 📊 Estadísticas del Repositorio

<div align="center">

| Lenguaje | Líneas aproximadas | Proyectos |
|----------|-------------------|-----------|
| C++ | 15,000+ | 15+ categorías |
| Python | 3,500+ | 8 categorías |
| Java | 5,000+ | 8 categorías |
| JavaScript | 700+ | 4 categorías |
| TypeScript | 150+ | 1 proyecto |
| HTML/CSS | 300+ | 1 proyecto |

</div>

---

## ✨ Características Destacadas

- 🎯 **Algoritmos de Ordenamiento**: Implementaciones de Bubble Sort, Insertion Sort, Dijkstra y Kruskal
- 🔒 **Seguridad**: Generador y gestor de contraseñas, escáner de puertos (Python y C++)
- 🤖 **Automatización**: Scripts para backup, correos, control de mouse y creación de carpetas
- 🌐 **Redes**: Cliente/Servidor en Python y escaneo de puertos
- 🎮 **Juegos**: Ajedrez en Python y juegos en C++
- ☕ **POO en Java**: Abstracción, herencia, polimorfismo, encapsulamiento e interfaces
- 🏫 **Talleres**: Clínica veterinaria, figuras geométricas y sistema de organización
- 📐 **Geometría**: Sistema de gestión de figuras geométricas en Java
- 📁 **Archivos**: Manejo de archivos de texto y binarios en C++
- ⚛️ **TypeScript**: Proyecto React + Vite con fundamentos del lenguaje

---

## 📝 Notas

> Este repositorio es personal y se actualiza continuamente con nuevos ejercicios y proyectos.

<div align="center">

**⭐ ¡Gracias por visitar mi repositorio!**

</div>
