"""
ENVÍO DE CORREOS POR GMAIL - VERSIÓN SIMPLE
Edita las coordenadas manualmente abajo
"""

import pyautogui
import pyperclip
import webbrowser
import time
import os

# ============================================
# CONFIGURACIÓN DEL CORREO
# ============================================

DESTINATARIO = "ejemplo@correo.com"

ASUNTO = "Mi asunto" 

CUERPO = """Hola,

Este es el contenido de mi correo.

Saludos"""

ARCHIVO_ADJUNTO = None  # Ejemplo: "C:\\Users\\tu_nombre\\archivo.pdf"

ENVIAR_AUTOMATICO = True  # True = envía solo, False = tú haces click


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
# NO EDITES NADA ABAJO DE ESTA LÍNEA
# ============================================

def enviar_correo():
    """Envía el correo usando las coordenadas configuradas"""

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
    else:
        print("\n✅ Correo preparado")
        print("⚠️  Ve a Gmail y presiona 'Enviar' manualmente")

    print("="*60 + "\n")



if __name__ == "__main__":
    enviar_correo()