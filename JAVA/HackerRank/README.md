# HackerRank Solutions

Este proyecto contiene mis soluciones a problemas de HackerRank organizadas por dificultad.

## Estructura del Proyecto

```
HackerRank/
├── src/
│   ├── easy/       # Problemas fáciles
│   ├── medium/     # Problemas medios
│   └── hard/       # Problemas difíciles
├── bin/            # Archivos compilados (generado automáticamente)
└── README.md       # Este archivo
```

## Cómo Agregar una Nueva Solución

1. Identifica la dificultad del problema (easy, medium, hard)
2. Crea un archivo Java en la carpeta correspondiente: `src/easy/`, `src/medium/`, o `src/hard/`
3. Nombra el archivo según el problema (usa CamelCase): `NombreDelProblema.java`
4. Usa el package correspondiente:
   - `package easy;` para problemas fáciles
   - `package medium;` para problemas medios
   - `package hard;` para problemas difíciles

## Plantilla para Nuevas Soluciones

```java
package easy; // o medium, o hard

import java.util.*;

/**
 * HackerRank Problem: [Nombre del Problema]
 * Difficulty: [Easy/Medium/Hard]
 * URL: [URL del problema en HackerRank]
 */
public class NombreDelProblema {
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Tu código aquí
        
        scanner.close();
    }
}
```

## Ejemplo de Nombres de Archivos

- `JavaStdinAndStdout.java` ✅
- `TwoSum.java` ✅
- `ReverseArray.java` ✅
- `problem1.java` ❌ (no descriptivo)
- `test.java` ❌ (no descriptivo)

## Ejecutar una Solución

1. Abre Eclipse
2. Navega a la solución en el Package Explorer
3. Clic derecho → Run As → Java Application
