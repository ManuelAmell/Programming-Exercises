import time
import cv2
from cvzone.HandTrackingModule import HandDetector
import pyautogui
import numpy as np
import math

# ═══════════════════════════════════════════════════════════════════
# 🎮 CONFIGURACIÓN DEL SISTEMA DE CONTROL DE MOUSE
# ═══════════════════════════════════════════════════════════════════

# 📷 CONFIGURACIÓN DE CÁMARA (optimizada para rendimiento)
ANCHO_CAM = 640          # ⚡ 640 es buen balance entre calidad y FPS
ALTO_CAM = 480           # ⚡ 480 mantiene buena detección
FPS_CAMARA = 60          # 🎬 FPS objetivo de la cámara

# ⚡ VELOCIDAD DEL MOUSE
SUAVIZADO_NORMAL = 4   # 🎯 Reducido para más respuesta (antes 7)
SUAVIZADO_PRECISION = 10 # 🎯 Reducido para más respuesta (antes 15)
VELOCIDAD_NORMAL = 5 # 🚀 Aumentado para más velocidad (antes 1.3)
VELOCIDAD_PRECISION = 4 # 🐢 Aumentado ligeramente (antes 0.4)

# 🎯 UMBRALES DE DISTANCIA (en píxeles)
DIST_CLICK = 24               # ✋ Distancia para ejecutar click (25-40)
DIST_ZONA_PRECISION = 38    # ⚠️ Inicio de modo precisión (50-80)
DIST_ZONA_PREPARACION = 45  # 📍 Inicio de reducción de velocidad (80-120)

# 🛡️ ANTI-REBOTE (evita clicks accidentales)
FRAMES_CONFIRMACION = 2     # 🎬 Reducido para respuesta más rápida (antes 4)
COOLDOWN_CLICK = 0.2         # ⏱️ Reducido para clicks más rápidos (antes 0.25)

# 🎨 CONFIGURACIÓN VISUAL
TAMAÑO_CIRCULO_NORMAL = 10    # ⭕ Tamaño de círculos en dedos
TAMAÑO_CIRCULO_CLICK = 14    # ⭕ Tamaño al hacer click
GROSOR_LINEA = 2             # 📏 Grosor de línea entre dedos

# 🎨 COLORES DEL TEMA (BGR)
COLOR_PRIMARIO = (100, 200, 255)  # 🔵 Azul claro
COLOR_EXITO = (80, 220, 100)      # 🟢 Verde éxito
COLOR_ADVERTENCIA = (60, 200, 255) # 🟡 Amarillo advertencia
COLOR_PELIGRO = (70, 100, 255)    # 🔴 Rojo peligro
COLOR_TEXTO = (255, 255, 255)     # 📝 Texto blanco
COLOR_SOMBRA = (0, 0, 0)          # 🌑 Sombra negra para contraste

# ═══════════════════════════════════════════════════════════════════
# 🚀 INICIALIZACIÓN DEL SISTEMA
# ═══════════════════════════════════════════════════════════════════

webcam = cv2.VideoCapture(0)
webcam.set(cv2.CAP_PROP_FRAME_WIDTH, ANCHO_CAM)
webcam.set(cv2.CAP_PROP_FRAME_HEIGHT, ALTO_CAM)
webcam.set(cv2.CAP_PROP_FPS, FPS_CAMARA)
webcam.set(cv2.CAP_PROP_BUFFERSIZE, 1)  # ⚡ Buffer mínimo = menos latencia

# ⚡ Optimizaciones adicionales de cámara
webcam.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))  # Codec más rápido
webcam.set(cv2.CAP_PROP_AUTOFOCUS, 0)  # Desactivar autofocus para estabilidad

# Inicializar detector de manos con configuración optimizada
rastreador = HandDetector(detectionCon=0.75, maxHands=1, minTrackCon=0.5)

if not webcam.isOpened():
    print("❌ Error: No se pudo abrir la cámara")
    exit()

# Obtener resolución de pantalla
ancho_pantalla, alto_pantalla = pyautogui.size()
pyautogui.FAILSAFE = False

# 📊 Variables de estado del sistema
xp, yp = ancho_pantalla // 2, alto_pantalla // 2
frames_cerca_click = 0
click_activo = False
ultimo_tiempo_click = 0
modo_precision = "NORMAL"
clicks_realizados = 0

# 📈 Variables para cálculo de FPS suavizado
fps_historico = []
fps_mostrar = 0

print("=" * 70)
print("🎮 CONTROL DE MOUSE CON VISIÓN POR COMPUTADORA - VERSIÓN OPTIMIZADA")
print("=" * 70)
print("✅ Sistema iniciado correctamente")
print(f"📺 Pantalla: {ancho_pantalla}x{alto_pantalla} | Cámara: {ANCHO_CAM}x{ALTO_CAM}")
print("⚡ Optimizaciones aplicadas para máximo rendimiento")
print("\n⌨️  Presiona 'Q' en la ventana para salir\n")
print("-" * 70)

# ═══════════════════════════════════════════════════════════════════
# 🧮 FUNCIONES DEL SISTEMA
# ═══════════════════════════════════════════════════════════════════

def calcular_velocidad_adaptativa(distancia_dedos):
    """🎯 Calcula velocidad y suavizado según la distancia entre dedos"""
    if distancia_dedos > DIST_ZONA_PREPARACION:
        return VELOCIDAD_NORMAL, SUAVIZADO_NORMAL, "NORMAL"
    elif distancia_dedos > DIST_ZONA_PRECISION:
        factor = (distancia_dedos - DIST_ZONA_PRECISION) / (DIST_ZONA_PREPARACION - DIST_ZONA_PRECISION)
        velocidad = VELOCIDAD_PRECISION + (VELOCIDAD_NORMAL - VELOCIDAD_PRECISION) * factor
        suavizado = SUAVIZADO_PRECISION + (SUAVIZADO_NORMAL - SUAVIZADO_PRECISION) * factor
        return velocidad, suavizado, "PREPARANDO"
    else:
        return VELOCIDAD_PRECISION, SUAVIZADO_PRECISION, "PRECISIÓN"


def mover_mouse_inteligente(x_actual, y_actual, x_objetivo, y_objetivo, velocidad, suavizado):
    """🖱️ Mueve el mouse con suavizado hacia la posición objetivo"""
    dx = x_objetivo - x_actual
    dy = y_objetivo - y_actual
    
    x_nuevo = x_actual + (dx * velocidad) / suavizado
    y_nuevo = y_actual + (dy * velocidad) / suavizado
    
    x_nuevo = max(0, min(ancho_pantalla - 1, x_nuevo))
    y_nuevo = max(0, min(alto_pantalla - 1, y_nuevo))
    
    return x_nuevo, y_nuevo


def texto_con_sombra(imagen, texto, pos, fuente, escala, color, grosor, sombra_offset=2):
    """📝 Dibuja texto con sombra para mejor legibilidad"""
    x, y = pos
    # Sombra
    cv2.putText(imagen, texto, (x + sombra_offset, y + sombra_offset),
               fuente, escala, COLOR_SOMBRA, grosor + 1, cv2.LINE_AA)
    # Texto principal
    cv2.putText(imagen, texto, (x, y),
               fuente, escala, color, grosor, cv2.LINE_AA)


def dibujar_interfaz_transparente(imagen, distancia, modo, fps, clicks, velocidad_actual):
    """🎨 Dibuja una interfaz minimalista sin fondos opacos"""
    h, w = imagen.shape[:2]
    
    # ═══════════════════════════════════════════════════════════════
    # 🎨 DETERMINAR COLORES SEGÚN EL MODO
    # ═══════════════════════════════════════════════════════════════
    
    if modo == "NORMAL":
        color_modo = COLOR_EXITO
        icono_modo = "●"
        texto_modo = "NORMAL"
    elif modo == "PREPARANDO":
        color_modo = COLOR_ADVERTENCIA
        icono_modo = "◐"
        texto_modo = "PREPARANDO"
    else:
        color_modo = COLOR_PELIGRO
        icono_modo = "◉"
        texto_modo = "PRECISION"
    
    padding = 10
    
    # ═══════════════════════════════════════════════════════════════
    # 📊 INFORMACIÓN SUPERIOR IZQUIERDA
    # ═══════════════════════════════════════════════════════════════
    
    # Línea decorativa de color según modo
    cv2.line(imagen, (padding, padding + 5), (padding + 150, padding + 5), 
             color_modo, 3, cv2.LINE_AA)
    
    # Estado del sistema
    texto_con_sombra(imagen, "ESTADO", (padding, padding + 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.45, COLOR_TEXTO, 1)
    
    # Modo con icono y color
    texto_con_sombra(imagen, f"{icono_modo} {texto_modo}", (padding, padding + 55),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, color_modo, 2)
    
    # Distancia
    texto_con_sombra(imagen, f"Dist: {int(distancia)}px", (padding, padding + 80),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.4, COLOR_TEXTO, 1)
    
    # Velocidad
    texto_con_sombra(imagen, f"Vel: {velocidad_actual:.1f}x", (padding, padding + 100),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.4, COLOR_TEXTO, 1)
    
    # ═══════════════════════════════════════════════════════════════
    # 📊 INFORMACIÓN SUPERIOR DERECHA
    # ═══════════════════════════════════════════════════════════════
    
    panel_derecha_x = w - 170
    
    # Línea decorativa
    cv2.line(imagen, (panel_derecha_x, padding + 5), (w - padding, padding + 5), 
             COLOR_PRIMARIO, 3, cv2.LINE_AA)
    
    # Título
    texto_con_sombra(imagen, "METRICAS", (panel_derecha_x, padding + 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.45, COLOR_TEXTO, 1)
    
    # FPS con color según rendimiento
    color_fps = COLOR_EXITO if fps > 25 else COLOR_ADVERTENCIA if fps > 20 else COLOR_PELIGRO
    texto_con_sombra(imagen, f"FPS: {int(fps)}", (panel_derecha_x, padding + 55),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, color_fps, 2)
    
    # Clicks
    texto_con_sombra(imagen, f"Clicks: {clicks}", (panel_derecha_x, padding + 80),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.4, COLOR_TEXTO, 1)
    
    # Estado del mouse
    mouse_texto = "Mouse: ON" if distancia < 500 else "Mouse: OFF"
    texto_con_sombra(imagen, mouse_texto, (panel_derecha_x, padding + 100),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.35, COLOR_TEXTO, 1)
    
    # ═══════════════════════════════════════════════════════════════
    # 📊 BARRA DE PROXIMIDAD (parte inferior) - Transparente
    # ═══════════════════════════════════════════════════════════════
    
    barra_h = 50
    barra_y = h - barra_h - padding
    barra_x = padding + 10
    barra_w = w - (padding * 2) - 20
    barra_grosor = 3
    
    # Marco de la barra (solo contorno)
    cv2.rectangle(imagen, (barra_x, barra_y + 10), 
                 (barra_x + barra_w, barra_y + barra_h - 10), 
                 (200, 200, 200), barra_grosor, cv2.LINE_AA)
    
    # Calcular progreso
    if distancia <= DIST_ZONA_PREPARACION:
        progreso = 1 - (distancia / DIST_ZONA_PREPARACION)
        progreso = max(0, min(1, progreso))
        relleno_w = int((barra_w - 10) * progreso)
        
        # Determinar color del relleno
        if progreso > 0.7:
            color_barra = COLOR_EXITO
            texto_estado = "✓ LISTO PARA CLICK"
        elif progreso > 0.4:
            color_barra = COLOR_ADVERTENCIA
            texto_estado = "◐ ACERCANDO..."
        else:
            color_barra = COLOR_PELIGRO
            texto_estado = "○ PREPARANDO..."
        
        # Dibujar relleno de la barra
        if relleno_w > 10:
            cv2.rectangle(imagen, (barra_x + 5, barra_y + 15), 
                         (barra_x + 5 + relleno_w, barra_y + barra_h - 15), 
                         color_barra, -1, cv2.LINE_AA)
        
        # Texto centrado con sombra
        texto_size = cv2.getTextSize(texto_estado, cv2.FONT_HERSHEY_SIMPLEX, 0.6, 2)[0]
        texto_x = barra_x + (barra_w - texto_size[0]) // 2
        texto_y = barra_y + (barra_h + texto_size[1]) // 2
        
        texto_con_sombra(imagen, texto_estado, (texto_x, texto_y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, COLOR_TEXTO, 2, 3)
    else:
        # Mensaje cuando no hay mano cerca
        texto = "Acerca los dedos para activar"
        texto_size = cv2.getTextSize(texto, cv2.FONT_HERSHEY_SIMPLEX, 0.5, 1)[0]
        texto_x = barra_x + (barra_w - texto_size[0]) // 2
        texto_y = barra_y + (barra_h + texto_size[1]) // 2
        
        texto_con_sombra(imagen, texto, (texto_x, texto_y),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (200, 200, 200), 1)
    
    # ═══════════════════════════════════════════════════════════════
    # 💡 INSTRUCCIÓN DE SALIDA (esquina inferior derecha)
    # ═══════════════════════════════════════════════════════════════
    
    texto_con_sombra(imagen, "Presiona 'Q' para salir", (w - 195, h - 8),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.4, (200, 200, 200), 1)
    
    return imagen


# ═══════════════════════════════════════════════════════════════════
# 🔄 LOOP PRINCIPAL OPTIMIZADO
# ═══════════════════════════════════════════════════════════════════

try:
    tiempo_anterior = time.time()
    frame_count = 0
    
    while True:
        frame_count += 1
        
        # 📸 Capturar frame
        exito, imagen = webcam.read()
        if not exito:
            continue

        # 🔄 Voltear imagen (optimizado)
        imagen = cv2.flip(imagen, 1)
        
        # 👋 Detectar manos
        coordenadas, imagen = rastreador.findHands(imagen, draw=True, flipType=False)
        
        distancia = 999
        velocidad_actual = VELOCIDAD_NORMAL
        
        # ═══════════════════════════════════════════════════════════
        # ✋ PROCESAMIENTO DE MANO
        # ═══════════════════════════════════════════════════════════
        
        if coordenadas:
            mano = coordenadas[0]
            lmList = mano["lmList"]
            
            # 📍 Puntos clave
            x_indice, y_indice = lmList[8][0], lmList[8][1]
            x_pulgar, y_pulgar = lmList[4][0], lmList[4][1]
            
            # 📏 Calcular distancia
            distancia = math.hypot(x_pulgar - x_indice, y_pulgar - y_indice)
            
            # ⚡ Velocidad adaptativa
            velocidad, suavizado, modo_precision = calcular_velocidad_adaptativa(distancia)
            velocidad_actual = velocidad
            
            # 🎨 Color según modo
            color_modo = COLOR_EXITO if modo_precision == "NORMAL" else \
                        COLOR_ADVERTENCIA if modo_precision == "PREPARANDO" else COLOR_PELIGRO
            
            # 🎨 Visualización optimizada de la mano
            grosor = GROSOR_LINEA + 1 if distancia < DIST_CLICK else GROSOR_LINEA
            cv2.line(imagen, (x_indice, y_indice), (x_pulgar, y_pulgar), color_modo, grosor, cv2.LINE_AA)
            
            if distancia < DIST_CLICK:
                # Efecto de click
                cv2.circle(imagen, (x_indice, y_indice), TAMAÑO_CIRCULO_CLICK, COLOR_EXITO, cv2.FILLED, cv2.LINE_AA)
                cv2.circle(imagen, (x_pulgar, y_pulgar), TAMAÑO_CIRCULO_CLICK, COLOR_EXITO, cv2.FILLED, cv2.LINE_AA)
                cv2.circle(imagen, (x_indice, y_indice), TAMAÑO_CIRCULO_CLICK + 6, COLOR_EXITO, 2, cv2.LINE_AA)
            else:
                cv2.circle(imagen, (x_indice, y_indice), TAMAÑO_CIRCULO_NORMAL, color_modo, cv2.FILLED, cv2.LINE_AA)
                cv2.circle(imagen, (x_pulgar, y_pulgar), TAMAÑO_CIRCULO_NORMAL, color_modo, cv2.FILLED, cv2.LINE_AA)
            
            # 🖱️ Movimiento del mouse
            margen = 80
            x_mouse_obj = np.interp(x_indice, [margen, ANCHO_CAM - margen], [0, ancho_pantalla])
            y_mouse_obj = np.interp(y_indice, [margen, ALTO_CAM - margen], [0, alto_pantalla])
            
            xp, yp = mover_mouse_inteligente(xp, yp, x_mouse_obj, y_mouse_obj, velocidad, suavizado)
            pyautogui.moveTo(xp, yp, duration=0, _pause=False)
            
            # 🖱️ Detección de click
            tiempo_actual = time.time()
            
            if distancia < DIST_CLICK:
                frames_cerca_click += 1
                
                if (frames_cerca_click >= FRAMES_CONFIRMACION and 
                    not click_activo and 
                    (tiempo_actual - ultimo_tiempo_click) > COOLDOWN_CLICK):
                    
                    pyautogui.click(xp, yp)
                    click_activo = True
                    ultimo_tiempo_click = tiempo_actual
                    clicks_realizados += 1
                    print(f"🖱️  Click #{clicks_realizados} → ({int(xp)}, {int(yp)})")
            else:
                frames_cerca_click = 0
                click_activo = False
        
        # ═══════════════════════════════════════════════════════════
        # 📊 CÁLCULO DE FPS SUAVIZADO
        # ═══════════════════════════════════════════════════════════
        
        tiempo_actual = time.time()
        fps_instantaneo = 1 / (tiempo_actual - tiempo_anterior) if tiempo_anterior != 0 else 0
        tiempo_anterior = tiempo_actual
        
        # Promedio móvil de FPS para visualización más estable
        fps_historico.append(fps_instantaneo)
        if len(fps_historico) > 10:
            fps_historico.pop(0)
        fps_mostrar = sum(fps_historico) / len(fps_historico)
        
        # ═══════════════════════════════════════════════════════════
        # 🖼️ RENDERIZAR INTERFAZ TRANSPARENTE
        # ═══════════════════════════════════════════════════════════
        
        imagen = dibujar_interfaz_transparente(imagen, distancia, modo_precision, 
                                              fps_mostrar, clicks_realizados, velocidad_actual)
        
        cv2.imshow("Control de Mouse - Vision Pro", imagen)
        
        # ⚡ Optimización: waitKey mínimo
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

except KeyboardInterrupt:
    print("\n\n⛔ Detenido por el usuario (Ctrl+C)")

finally:
    # 🧹 Limpieza
    webcam.release()
    cv2.destroyAllWindows()
    
    print("\n" + "=" * 70)
    print("📊 ESTADÍSTICAS FINALES")
    print("=" * 70)
    print(f"🖱️  Total de clicks: {clicks_realizados}")
    print(f"⚡ FPS promedio: {int(fps_mostrar)}")
    print(f"🎬 Frames procesados: {frame_count}")
    print("✅ Programa cerrado correctamente")
    print("=" * 70)