# ------------------------------------------------------------------
# Proyecto: Automatización de archivos HTML o cualquiera por fecha
#
# Este script mueve automáticamente todos los archivos .html 
# desde la carpeta de origen 'PruebaCarpeta' a una nueva carpeta
# cuyo nombre se genera con la fecha actual (YYYY-MM-DD_Archivos).
#
# Funcionalidades:
# 1. Crear la carpeta con fecha si no existe.
# 2. Recorrer la carpeta de origen y detectar archivos .html.
# 3. Mover los archivos a la carpeta correspondiente.
# 4. Contar y mostrar cuántos archivos se movieron.
#
# Beneficios:
# - Mantener los archivos HTML organizados por fecha.
# - Evitar mezclar archivos antiguos con nuevos.
# - Fácil de adaptar a otros tipos de archivos o rutas.
#
# Posibles mejoras futuras:
# - Soporte para más tipos de archivo (.pdf, .txt, etc.).
# - Manejo de errores si un archivo está abierto o bloqueado.
# - Automatización diaria mediante cron jobs o tareas programadas.
# ------------------------------------------------------------------

import os
import shutil
from datetime import datetime

fecha = datetime.now().strftime("%Y-%m-%d")
nueva_carpeta = f"{fecha}_Archivos"

# ruta base donde se creará la nueva carpeta
ruta_base = "/home/amell/Documents/Programming-Exercises/PYTHON/Automatizaciones"
ruta_nueva_carpeta = os.path.join(ruta_base, nueva_carpeta)

# crear la carpeta si no existe
if not os.path.exists(ruta_nueva_carpeta):
    os.makedirs(ruta_nueva_carpeta)
    print(f"Carpeta '{ruta_nueva_carpeta}' creada.")

carpeta_origen = os.path.join(ruta_base, "PruebaCarpeta")
contador = 0

for archivo in os.listdir(carpeta_origen):
#elegir tipo de archivo q desea mover /si los quieres mover todos solo  descomentar 
    if archivo.endswith(".html"):
        origen = os.path.join(carpeta_origen, archivo)
        destino = os.path.join(ruta_nueva_carpeta, archivo)  # apunta a la carpeta creada

        shutil.move(origen, destino)
        contador += 1

print(f"Se movieron {contador} archivos a la carpeta '{ruta_nueva_carpeta}'.")
