"""
ENVÍO DE CORREOS POR GMAIL - VERSIÓN SIMPLE
Edita las coordenadas manualmente abajo
"""

import pyautogui
import pyperclip
import webbrowser
import time
import os
import re

# ============================================
# CONFIGURACIÓN DE BASE DE DATOS
# ============================================

def inicializar_base_de_datos():
    """Crea el archivo de base de datos si no existe en la carpeta del script"""
    # Obtener ruta del directorio donde está este script
    script_dir = os.path.dirname(os.path.abspath(__file__))
    db_path = os.path.join(script_dir, "database_correos.txt")
    
    if os.path.exists(db_path):
        print(f"✅ Base de datos encontrada: {db_path}")
        return db_path
    
    print(f"⚠️ Base de datos no encontrada. Creando: {db_path}")
    
    contenido_db = """# ╔══════════════════════════════════════════════════════════════════════════════╗
# ║                     BASE DE DATOS - REGISTRO DE CORREOS                        ║
# ║                        Formato: TXT Estructurado                             ║
# ╚══════════════════════════════════════════════════════════════════════════════╝
#
# ESTRUCTURA POR REGISTRO:
# ---
# CORREO: <email_destinatario>
# ASUNTO: <asunto_completo>
# FECHA: <YYYY-MM-DD>
# HORA: <HH:MM:SS>
# ADJUNTOS: <SI/NO> - <nombre_archivo> (si aplica)
# ESTADO: <ENVIADO/FALLIDO/PENDIENTE>
# CONTENIDO:
# <cuerpo_completo_del_correo>
# ---
#
# ═══════════════════════════════════════════════════════════════════════════════

[REGISTROS_ENVIOS]

---
CORREO: ejemplo@correo.com
ASUNTO: [ProyectoX] Mi asunto
FECHA: 2025-02-11
HORA: 12:00:00
ADJUNTOS: NO
ESTADO: PLANTILLA
CONTENIDO:
Hola Amell,

Este es el contenido de mi correo.

Fecha: 2025-02-11

Saludos
---

# ═══════════════════════════════════════════════════════════════════════════════
#                    Última actualización: {fecha}
# ═══════════════════════════════════════════════════════════════════════════════
""".format(fecha=time.strftime("%Y-%m-%d %H:%M"))
    
    with open(db_path, 'w', encoding='utf-8') as f:
        f.write(contenido_db)
    
    print(f"✅ Base de datos creada exitosamente")
    return db_path

# Inicializar base de datos al cargar el script
RUTA_BASE_DATOS = inicializar_base_de_datos()


def cargar_ultimo_correo():
    """Carga el último correo enviado desde la base de datos y actualiza las variables"""
    global DESTINATARIO_RAW, ASUNTO_BASE, CUERPO, ARCHIVO_ADJUNTO_RAW
    
    try:
        with open(RUTA_BASE_DATOS, 'r', encoding='utf-8') as f:
            contenido = f.read()
        
        # Buscar todos los registros (entre --- y ---)
        import re
        registros = re.findall(r'---\n(.*?\n)---', contenido, re.DOTALL)
        
        if not registros:
            print("ℹ️  No hay registros previos en la base de datos")
            return
        
        # Tomar el último registro
        ultimo = registros[-1]
        
        # Extraer campos
        correo_match = re.search(r'CORREO:\s*(.+)', ultimo)
        asunto_match = re.search(r'ASUNTO:\s*(.+)', ultimo)
        adjunto_match = re.search(r'ADJUNTOS:\s*(\w+)\s*-\s*(.+)', ultimo)
        contenido_match = re.search(r'CONTENIDO:\n(.*?)(?=\n# ═|$)', ultimo, re.DOTALL)
        
        if correo_match:
            DESTINATARIO_RAW = correo_match.group(1).strip()
        if asunto_match:
            # Remover prefijo si existe para ASUNTO_BASE
            asunto_completo = asunto_match.group(1).strip()
            ASUNTO_BASE = asunto_completo.replace(PREFIJO_ASUNTO, "")
        if contenido_match:
            CUERPO = contenido_match.group(1).strip()
        if adjunto_match:
            tiene_adj = adjunto_match.group(1).strip()
            nombre_adj = adjunto_match.group(2).strip()
            if tiene_adj == "SI" and nombre_adj != "Ninguno":
                ARCHIVO_ADJUNTO_RAW = nombre_adj
            else:
                ARCHIVO_ADJUNTO_RAW = None
        
        print(f"📥 Último correo cargado desde la base de datos:")
        print(f"   Para: {DESTINATARIO_RAW}")
        print(f"   Asunto: {ASUNTO_BASE}")
        
    except Exception as e:
        print(f"⚠️  Error al cargar último correo: {e}")
        print("   Usando valores por defecto")


# ============================================
# CARGAR ÚLTIMO CORREO AL INICIAR
# ============================================
cargar_ultimo_correo()


# ============================================
# VARIABLES DEL ÚLTIMO CORREO ENVIADO
# ============================================

ULTIMO_CORREO = None
ULTIMO_ASUNTO = None
ULTIMO_CONTENIDO = None
ULTIMO_ADJUNTO = None
ULTIMO_FECHA = None
ULTIMO_HORA = None
ULTIMO_ESTADO = None


def guardar_en_base_datos(correo, asunto, contenido, adjunto, estado="ENVIADO"):
    """Guarda un registro de correo enviado en la base de datos"""
    global ULTIMO_CORREO, ULTIMO_ASUNTO, ULTIMO_CONTENIDO, ULTIMO_ADJUNTO, ULTIMO_FECHA, ULTIMO_HORA, ULTIMO_ESTADO
    
    from datetime import datetime
    
    fecha = datetime.now().strftime("%Y-%m-%d")
    hora = datetime.now().strftime("%H:%M:%S")
    
    # Guardar en variables globales
    ULTIMO_CORREO = correo
    ULTIMO_ASUNTO = asunto
    ULTIMO_CONTENIDO = contenido
    ULTIMO_ADJUNTO = adjunto
    ULTIMO_FECHA = fecha
    ULTIMO_HORA = hora
    ULTIMO_ESTADO = estado
    
    tiene_adjunto = "SI" if adjunto else "NO"
    nombre_adjunto = os.path.basename(adjunto) if adjunto else "Ninguno"
    
    registro = f"""
---
CORREO: {correo}
ASUNTO: {asunto}
FECHA: {fecha}
HORA: {hora}
ADJUNTOS: {tiene_adjunto} - {nombre_adjunto}
ESTADO: {estado}
CONTENIDO:
{contenido}
---
# ═══════════════════════════════════════════════════════════════════════════════
"""
    
    # Verificar que el archivo existe, si no, inicializarlo
    if not os.path.exists(RUTA_BASE_DATOS):
        print(f"⚠️ Base de datos no encontrada, inicializando: {RUTA_BASE_DATOS}")
        inicializar_base_de_datos()
    
    # Leer contenido actual
    with open(RUTA_BASE_DATOS, 'r', encoding='utf-8') as f:
        lineas = f.readlines()
    
    # Encontrar donde termina el último registro (antes del footer)
    # Buscar la línea que contiene "Última actualización"
    indice_footer = len(lineas) - 3  # Aproximadamente
    for i, linea in enumerate(lineas):
        if "Última actualización" in linea:
            indice_footer = i - 1
            break
    
    # Insertar nuevo registro antes del footer
    lineas.insert(indice_footer, registro)
    
    # Actualizar fecha de última actualización
    for i, linea in enumerate(lineas):
        if "Última actualización" in linea:
            lineas[i] = f"#                    Última actualización: {fecha} {hora}\n"
            break
    
    # Escribir archivo actualizado
    with open(RUTA_BASE_DATOS, 'w', encoding='utf-8') as f:
        f.writelines(lineas)
    
    print(f"📝 Registro guardado en base de datos: {correo}")


# ============================================
# CONFIGURACIÓN DEL CORREO
# ============================================

# Permitir múltiples destinatarios separados por coma
# Ejemplo: "a@correo.com, b@correo.com, c@correo.com"
DESTINATARIO_RAW = "ejemplo@correo.com"

# Limpiar espacios y convertir a lista
lista_destinatarios = [x.strip() for x in DESTINATARIO_RAW.split(",") if x.strip()]

# Validar formato de correo
correo_regex = r"^[^@\s]+@[^@\s]+\.[^@\s]+$"
destinatarios_validos = []
destinatarios_invalidos = []

for correo in lista_destinatarios:
    if re.match(correo_regex, correo):
        destinatarios_validos.append(correo)
    else:
        destinatarios_invalidos.append(correo)

if destinatarios_invalidos:
    print(f"⚠️ Destinatarios inválidos: {', '.join(destinatarios_invalidos)}")

if not destinatarios_validos:
    raise ValueError("❌ No hay destinatarios válidos para enviar el correo")

DESTINATARIO = ", ".join(destinatarios_validos)

# ============================================
# ASUNTO
# ============================================

ASUNTO_BASE = "Mi asunto"

# Prefijo automático para todos los correos
PREFIJO_ASUNTO = "[ProyectoX] "

# Construir asunto final y limpiar saltos de línea
ASUNTO = (PREFIJO_ASUNTO + ASUNTO_BASE).strip()
ASUNTO = ASUNTO.replace("\n", " ").replace("\r", " ")

# ============================================
# CUERPO
# ============================================

# Variables para f-strings (dinamismo)
nombre = "Amell"
fecha = "2025-02-11"

CUERPO_TEMPLATE = f"""Hola {nombre},

Este es el contenido de mi correo.

Fecha: {fecha}

Saludos"""

# Limpiar espacios al inicio y final
CUERPO = CUERPO_TEMPLATE.strip()

# ============================================
# ADJUNTO
# ============================================

ARCHIVO_ADJUNTO_RAW = None  # Ejemplo: "C:\\Users\\tu_nombre\\archivo.pdf"

# Validar ruta si se especifica adjunto
ARCHIVO_ADJUNTO = None
if ARCHIVO_ADJUNTO_RAW:
    ruta_limpia = ARCHIVO_ADJUNTO_RAW.strip()
    if os.path.exists(ruta_limpia):
        ARCHIVO_ADJUNTO = ruta_limpia
    else:
        print(f"⚠️ Archivo no encontrado: {ruta_limpia}")
        print("   Se enviará el correo sin adjunto")

ENVIAR_AUTOMATICO = True  # True = envía solo, False = tú haces click


# ============================================
# CARGAR ÚLTIMO CORREO AL INICIAR (después de definir variables)
# ============================================
cargar_ultimo_correo()


# ============================================
# ⚠️ COORDENADAS - EDITA AQUÍ TUS COORDENADAS ⚠️
# ============================================
# 
# INSTRUCCIONES PARA OBTENER COORDENADAS:
# 1. mapear coordenadas
# 2. Abre Gmail
# 3. Coloca el mouse sobre "Redactar" y anota las coordenadas
# 4. Haz click en "Redactar" para abrir el popup
# 5. Coloca el mouse sobre "Enviar" y anota las coordenadas
# 6. Reemplaza los números abajo con TUS coordenadas
#
# EJEMPLO:
# Si slurp -p te mostró:
#   Sobre Redactar: X = 90  Y = 233
#   Sobre Enviar:   X = 1254  Y = 1048
#
# Entonces escribes:

COORDENADA_REDACTAR_X = 90   # ← Cambia este número
COORDENADA_REDACTAR_Y = 233  # ← Cambia este número

COORDENADA_ENVIAR_X = 1254    # ← Cambia este número  
COORDENADA_ENVIAR_Y = 1048   # ← Cambia este número


# ============================================
# VARIABLES DEL ÚLTIMO CORREO ENVIADO
# ============================================

ULTIMO_CORREO = None
ULTIMO_ASUNTO = None
ULTIMO_CONTENIDO = None
ULTIMO_ADJUNTO = None
ULTIMO_FECHA = None
ULTIMO_HORA = None
ULTIMO_ESTADO = None


# ============================================
# NO EDITES NADA ABAJO DE ESTA LÍNEA
# ============================================

def enviar_correo():
    """Envía el correo usando las coordenadas configuradas"""
    
    # Declarar que usaremos las variables globales para actualizarlas al final
    global DESTINATARIO, ASUNTO, CUERPO, ARCHIVO_ADJUNTO

    # Copias locales
    destinatario = DESTINATARIO
    asunto = ASUNTO
    cuerpo = CUERPO
    archivo_adjunto = ARCHIVO_ADJUNTO

    print("\n" + "="*60)
    print("📧 ENVIANDO CORREO")
    print("="*60)
    print(f"\nDestinatario: {destinatario}")
    print(f"Asunto: {asunto}")
    print(f"Archivo: {archivo_adjunto if archivo_adjunto else 'Ninguno'}")
    print(f"Modo: {'AUTOMÁTICO' if ENVIAR_AUTOMATICO else 'MANUAL'}")

    confirmar = input("\n¿Continuar con estos datos? (s = sí / n = Cancelar / Tecla Cualquiera = ingresar manualmente): ").strip().lower()

    if confirmar =='n':
        print("Cancelando...")
        return None 
    elif confirmar !='s':
        print("\n✏️ Ingresando datos manualmente:\n")
    
        destinatario = input("📩 Destinatario: ").strip()
        asunto = input("📝 Asunto: ").strip()

        print("✏️ Escribe el contenido del correo.")
        print("   (Presiona ENTER en una línea vacía para finalizar)\n")
        
        lineas = []
        while True:
            linea = input()
            if linea == "":
                break
            lineas.append(linea)

        cuerpo_manual = "\n".join(lineas)

        if cuerpo_manual.strip():
            cuerpo = cuerpo_manual  # Solo reemplaza si escribió algo

        archivo_adjunto = input("📎 Ruta del archivo (Enter si ninguno): ").strip()
        if archivo_adjunto == "":
            archivo_adjunto = None

    # Abrir Gmail
    print("\n1️⃣  Abriendo Gmail...")
    webbrowser.open("https://mail.google.com/mail/u/0/#inbox")

    print("   ⏳ Esperando 15 segundos...")
    for i in range(15, 0, -1):
        print(f"      {i}...", end='\r')
        time.sleep(1)

    # Click en Redactar
    print(f"\n\n2️⃣  Click en Redactar ({COORDENADA_REDACTAR_X}, {COORDENADA_REDACTAR_Y})...")
    pyautogui.click(COORDENADA_REDACTAR_X, COORDENADA_REDACTAR_Y)
    time.sleep(3)

    # Destinatario
    print("3️⃣  Escribiendo destinatario...")
    pyperclip.copy(destinatario)
    pyautogui.hotkey('ctrl', 'v')
    time.sleep(1)
    pyautogui.press('tab')
    time.sleep(1)

    # Asunto
    print("4️⃣  Escribiendo asunto...")
    pyperclip.copy(asunto)
    pyautogui.hotkey('ctrl', 'v')
    time.sleep(1)
    pyautogui.press('tab')
    time.sleep(1)

    # Cuerpo
    print("5️⃣  Escribiendo mensaje...")
    pyperclip.copy(cuerpo)
    pyautogui.hotkey('ctrl', 'v')
    time.sleep(2)

    # Adjuntar
    if archivo_adjunto and os.path.exists(archivo_adjunto):
        print("6️⃣  Adjuntando archivo...")
        pyautogui.hotkey('ctrl', 'shift', 'a')
        time.sleep(3)
        pyperclip.copy(archivo_adjunto)
        pyautogui.hotkey('ctrl', 'v')
        time.sleep(1)
        pyautogui.press('enter')
        time.sleep(4)

    # Enviar
    if ENVIAR_AUTOMATICO:
        print(f"\n7️⃣  Click en Enviar ({COORDENADA_ENVIAR_X}, {COORDENADA_ENVIAR_Y})...")
        time.sleep(2)
        pyautogui.click(COORDENADA_ENVIAR_X, COORDENADA_ENVIAR_Y)
        time.sleep(2)
        print("\n✅ ¡CORREO ENVIADO!")
        # Guardar en base de datos
        guardar_en_base_datos(destinatario, asunto, cuerpo, archivo_adjunto, estado="ENVIADO")
    else:
        print("\n✅ Correo preparado")
        print("⚠️  Ve a Gmail y presiona 'Enviar' manualmente")
        # Guardar en base de datos como pendiente
        guardar_en_base_datos(destinatario, asunto, cuerpo, archivo_adjunto, estado="PENDIENTE")

    # Actualizar variables globales con el último correo enviado
    DESTINATARIO = destinatario
    ASUNTO = asunto
    CUERPO = cuerpo
    ARCHIVO_ADJUNTO = archivo_adjunto

    print("="*60 + "\n")



if __name__ == "__main__":
    enviar_correo()