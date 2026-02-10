# ------------------------------------------------------------------
# Script: Backup automático de carpetas en formato ZIP
#
# Descripción:
# Este script permite crear un backup de una carpeta de origen
# dentro de otra carpeta de destino en formato .zip. Si el usuario
# no ingresa una ruta de destino, se crea automáticamente una 
# carpeta llamada 'backup' junto al script.
#
# Funcionalidades:
# - Genera un nombre de archivo basado en la fecha y hora actual.
# - Crea la carpeta de destino si no existe.
# - Comprime todos los archivos y subcarpetas de la carpeta de origen.
# - Muestra un resumen con la cantidad de archivos añadidos y el tamaño del backup.
#
# Uso:
# Ejecutar el script y seguir las indicaciones en la consola.
# ------------------------------------------------------------------

import os
import datetime
import zipfile

def crear_nombre_backup():
    """Genera un nombre para el archivo de backup basado en la fecha y hora actual"""
    fecha_hora = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    return f"backup_{fecha_hora}.zip"

def crear_backup(carpeta_origen, carpeta_destino):
    """Crea un backup en zip de la carpeta de origen dentro de la carpeta destino"""
    
    # Verificar si la carpeta de origen existe
    if not os.path.exists(carpeta_origen):
        print(f"ERROR: La carpeta de origen '{carpeta_origen}' no existe.")
        return None

    # Crear carpeta destino si no existe
    if not os.path.exists(carpeta_destino):
        print(f"Creando carpeta destino '{carpeta_destino}'...")
        os.makedirs(carpeta_destino)

    # Nombre y ruta del backup
    nombre_backup = crear_nombre_backup()
    ruta_backup = os.path.join(carpeta_destino, nombre_backup)

    print(f"Creando backup en '{ruta_backup}'...")

    with zipfile.ZipFile(ruta_backup, 'w', zipfile.ZIP_DEFLATED) as zip_file:
        # Recorrer todos los archivos y carpetas en la carpeta de origen
        for carpeta_actual, subcarpetas, archivos in os.walk(carpeta_origen):
            for archivo in archivos:
                ruta_archivo = os.path.join(carpeta_actual, archivo)
                # Guardar el archivo en el zip con ruta relativa a la carpeta origen
                ruta_relativa = os.path.relpath(ruta_archivo, carpeta_origen)
                zip_file.write(ruta_archivo, ruta_relativa)
                print(f"Añadido: '{ruta_relativa}'")

    print(f"Backup completado: '{ruta_backup}'")
    return ruta_backup

def main():
    carpeta_origen = input("Ingrese la ruta de la carpeta que desea respaldar: ")
    carpeta_destino = input(
        "Ingrese la ruta donde desea guardar el backup (deja en blanco para usar la carpeta 'backup' junto al script): "
    )

    # Si no se ingresa ruta, crear carpeta 'backup' junto al script
    if not carpeta_destino:
        carpeta_destino = os.path.join(os.path.dirname(os.path.abspath(__file__)), "backup")

    # Crear backup
    ruta_backup = crear_backup(carpeta_origen, carpeta_destino)

    if ruta_backup:
        tamaño_mb = os.path.getsize(ruta_backup) / (1024*1024)
        print(f"\nTamaño del Backup: {tamaño_mb:.2f} MB")
        print("\n¡Backup completado con éxito!")

if __name__ == "__main__":
    main()
