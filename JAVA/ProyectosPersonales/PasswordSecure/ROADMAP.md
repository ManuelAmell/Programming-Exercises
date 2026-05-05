# 🛡️ PasswordSecure - Ideas y Roadmap de Desarrollo

<div align="center">

## Gestor de Contraseñas Seguro en Java

**Estado actual**: Aplicación CLI básica con almacenamiento en archivo de texto

</div>

---

## 📋 Índice
- [Ideas de Mejora](#ideas-de-mejora)
- [Roadmap de Implementación](#roadmap-de-implementación)
- [Recomendaciones Inmediatas](#recomendaciones-inmediatas)

---

## 💡 Ideas de Mejora

### 🔒 1. Seguridad y Cifrado
| Característica | Descripción | Prioridad |
|----------------|-------------|-----------|
| **Cifrado de datos** | Implementar AES-256 para proteger credenciales | 🔴 Alta |
| **Contraseña maestra** | Sistema de autenticación con hashing (bcrypt/Argon2) | 🔴 Alta |
| **Generador mejorado** | Opciones de complejidad: mayúsculas, minúsculas, números, símbolos | 🟡 Media |
| **Autobloqueo** | Bloqueo automático tras período de inactividad | 🟢 Baja |

### 🎯 2. Funcionalidades Principales
- ✅ **Búsqueda y filtrado** - Buscar por sitio web o usuario
- ✅ **Edición y eliminación** - Modificar/borrar credenciales existentes  
- ✅ **Categorización** - Agrupar por tipos (Redes sociales, Bancos, Trabajo)
- ✅ **Copiar al portapapeles** - Función segura con auto-limpieza
- ✅ **Generador integrado** - Crear contraseñas desde la app

### 💾 3. Persistencia de Datos
```java
// Actual: Archivo de texto plano
Credenciales.txt

// Objetivo: Base de datos SQLite
├── Base de datos local cifrada
├── Exportar/Importar (JSON cifrado)
└── Sincronización cloud (futuro)
```

### 🎨 4. Interfaz de Usuario
**Opción A** - Mejorar CLI actual
- Menú con navegación por teclas
- Mostrar/ocultar contraseñas con `******`
- Tablas formateadas con ASCII

**Opción B** - GUI con JavaFX
- Ventana principal con tabla de credenciales
- Formularios para añadir/editar
- Interfaz moderna y responsive

### ⚙️ 5. Calidad de Código
- ✅ Manejo de excepciones robusto
- ✅ Logging con SLF4J/Log4j2
- ✅ Tests unitarios con JUnit 5
- ✅ Documentación Javadoc completa
- ✅ CI/CD con GitHub Actions

---

## 🗓️ Roadmap de Implementación

### 📍 Fase 1: Fundamentos de Seguridad
> **Objetivo**: Convertirla en un gestor de contraseñas REALMENTE seguro

| Semana | Tarea | Entregable |
|--------|-------|------------|
| **1** | Sistema de autenticación con contraseña maestra | `AuthManager.java` + Login al inicio |
| **2** | Cifrado AES-256 de credenciales | `EncryptionService.java` + Archivos cifrados |
| **3** | Generador de contraseñas mejorado | Opciones de complejidad en menú |

### 📍 Fase 2: Funcionalidades Esenciales
> **Objetivo**: Operaciones CRUD completas y búsqueda

| Semana | Tarea | Entregable |
|--------|-------|------------|
| **4** | Editar y eliminar credenciales | Métodos `editarCuenta()` y `eliminarCuenta()` |
| **5** | Sistema de búsqueda | Filtro por sitio/usuario |
| **6** | Portapapeles seguro | Auto-limpieza tras 30 segundos |

### 📍 Fase 3: Mejora de UX y Datos
> **Objetivo**: Mejorar experiencia de usuario y persistencia

| Semana | Tarea | Entregable |
|--------|-------|------------|
| **7** | Migración a SQLite | Base de datos + `DatabaseManager.java` |
| **8** | CLI mejorado | Menú visual + paginación |
| **9** | Categorización | Campo `categoria` + filtro por tipo |

### 📍 Fase 4: Avanzado y Producción
> **Objetivo**: Funciones avanzadas y preparar para release

| Semana | Tarea | Entregable |
|--------|-------|------------|
| **10** | Exportar/Importar | JSON cifrado + backup/restore |
| **11** | Tests y documentación | Cobertura >80% + Javadoc completo |
| **12** | GUI con JavaFX | Ventana principal + formularios |

### 🔮 Fase 5: Futuro (Opcional)
- [ ] Sincronización en la nube (Google Drive, Dropbox)
- [ ] Autofill para navegadores
- [ ] Análisis de seguridad de contraseñas
- [ ] Notificaciones de contraseñas débiles/duplicadas
- [ ] Versión móvil (Android/Web)

---

## ⚡ Recomendaciones Inmediatas

### 🚨 Hacer AHORA mismo:
1. **Añadir `.gitignore`**
   ```
   Credenciales.txt
   *.db
   *.log
   /bin/
   /target/
   ```

2. **Priorizar el cifrado** - Es lo más crítico para un gestor de contraseñas

3. **Mejorar manejo de excepciones**
   ```java
   // Actual
   e.printStackTrace();
   
   // Mejor
   logger.error("Error al guardar credencial", e);
   System.err.println("Error: No se pudo guardar la contraseña");
   ```

4. **Renombrar variables** - Evitar caracteres especiales
   ```java
   // Actual: contraseña
   // Mejor: contrasena o password
   ```

### 📊 Estadísticas del Proyecto Actual
- **Lenguaje**: Java
- **Archivos fuente**: 3 clases principales
- **Almacenamiento**: Archivo de texto plano (INSEGURO)
- **Interfaz**: CLI básico
- **Tests**: ❌ Ninguno

---

<div align="center">

## 🚀 ¿Por dónde empezar?

**Recomendación**: Comienza por la **Fase 1**, semanas 1-2. Sin cifrado y contraseña maestra, no es un gestor de contraseñas seguro.

**Siguiente paso sugerido**: 
```bash
# 1. Crea .gitignore
# 2. Implementa AuthManager.java
# 3. Añade cifrado AES-256
```

</div>

---

*Última actualización: 25/04/2026*<br>
*Versión actual: 0.1.0*<br>
*Estado: En desarrollo activo*
