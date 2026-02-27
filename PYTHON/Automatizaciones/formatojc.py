# ------------------------------------------------------------------
# Script: Backup automático de carpetas o archivos en formato ZIP
#
# | Argumento | Función                            |
# | --------- | ---------------------------------- |
# | `--all`   | Respalda todo el directorio actual |
# | `--dir`   | Respalda una carpeta específica    |
# | `--file`  | Respalda un archivo específico     |
#
#     python backup.py --all
#     python backup.py --dir api
#     python backup.py --file main.py
# ------------------------------------------------------------------

import os
import zipfile
import argparse


def mostrar_banner():
    azul  = "\033[94m"
    cyan  = "\033[96m"
    reset = "\033[0m"
    banner = f"""
{cyan}
  _____                        _     _             
 |  __ \\                     | | |  | |   
 | |__) |___  ___ _ __   __ _ | | __ | | ___  ___   
 |  _  // _ \\/ __| '_ \\ / _` | |/ _` |/ _ \\/ __|  
 | | \\ \\  __/\\__ \\ |_) | (_| | | (_| | (_) \\__ \\  
 |_|  \\_\\___||___/ .__/ \\__,_|_|\\__,_|\\___/|___/  
                  | |                              
                  |_|                   
{azul}
  ════════════════════════════════════════════
    respaldos.py  |  v1.0 | By Manuel Amell
  ════════════════════════════════════════════
  Formato para profesor: Juan Carlos Garcia Ojeda (JC)
{reset}
"""
    print(banner)
    print(os.getcwd(), "\n")
    print("=============================================================")


# ------------------------------------------------------------------
# Menú interactivo (cuando NO se usan argumentos)
# ------------------------------------------------------------------

def menu():
    """Muestra el menú principal y retorna la opción elegida."""
    print("\nELIJA UNA OPCION:")
    print("\n  1). Hacer ZIP en la carpeta actual")
    print("\n  2). Hacer ZIP en ruta personalizada")

    while True:
        opc = input("\n> ").strip()
        if opc in ("1", "2"):
            return opc
        print("Opción inválida. Ingrese 1 o 2.")


def solicitar_ruta_personalizada():
    """Solicita y valida una ruta de destino ingresada por el usuario."""
    while True:
        ruta = input("\nIngrese la ruta de destino para el ZIP: ").strip()
        if os.path.isdir(ruta):
            return ruta

        crear = input(f"La carpeta '{ruta}' no existe. ¿Desea crearla? (s/n): ").strip().lower()
        if crear == "s":
            try:
                os.makedirs(ruta)
                print(f"Carpeta '{ruta}' creada exitosamente.")
                return ruta
            except OSError as e:
                print(f"No se pudo crear la carpeta: {e}")
        else:
            print("Ingrese una ruta válida.")


def listar_elementos(base_path):
    """Lista carpetas y archivos disponibles en base_path."""
    try:
        elementos = os.listdir(base_path)
    except PermissionError:
        print("Sin permiso para leer esa carpeta.")
        return None

    if not elementos:
        print("No hay elementos disponibles.")
        return None

    print("\nCarpetas y archivos disponibles:\n")
    for i, elemento in enumerate(elementos, start=1):
        ruta = os.path.join(base_path, elemento)
        if os.path.isdir(ruta):
            print(f"  {i}. 📁 {elemento}/")
        else:
            print(f"  {i}. 📄 {elemento}")

    return elementos


# ------------------------------------------------------------------
# Nombre del ZIP
# ------------------------------------------------------------------

def crear_nombre_backup():
    """Genera el nombre del archivo ZIP a partir de los datos del usuario."""
    nombres   = input("Ingrese Nombres (solo): ").strip()
    apellidos = input("Ingrese Apellidos: ").strip()
    codigo    = input("Ingrese Codigo: ").strip()
    return f"{apellidos}_{nombres}_{codigo}.zip"


# ------------------------------------------------------------------
# Creación del ZIP
# ------------------------------------------------------------------

def crear_backup(ruta_origen, carpeta_destino, nombre_backup):
    """Crea el archivo ZIP con el contenido de ruta_origen."""
    if not os.path.exists(ruta_origen):
        print(f"La ruta '{ruta_origen}' no existe.")
        return None

    ruta_backup = os.path.join(carpeta_destino, nombre_backup)

    # Evita sobreescribir un ZIP existente
    if os.path.exists(ruta_backup):
        respuesta = input(f"\nYa existe '{nombre_backup}'. ¿Desea reemplazarlo? (s/n): ").strip().lower()
        if respuesta != "s":
            print("Operación cancelada.")
            return None

    print(f"\nCreando backup en '{ruta_backup}'...\n")

    with zipfile.ZipFile(ruta_backup, 'w', zipfile.ZIP_DEFLATED) as zip_file:

        if os.path.isfile(ruta_origen):
            # Respaldo de archivo individual
            zip_file.write(ruta_origen, os.path.basename(ruta_origen))
            print(f"  Añadido: {os.path.basename(ruta_origen)}")
            total_archivos = 1

        else:
            # Respaldo de carpeta completa
            total_archivos = 0
            for carpeta_actual, _, archivos in os.walk(ruta_origen):
                for archivo in archivos:
                    ruta_archivo  = os.path.join(carpeta_actual, archivo)
                    ruta_relativa = os.path.relpath(ruta_archivo, ruta_origen)
                    zip_file.write(ruta_archivo, ruta_relativa)
                    print(f"  Añadido: {ruta_relativa}")
                    total_archivos += 1

    print(f"\n  Total de archivos añadidos: {total_archivos}")
    return ruta_backup


def mostrar_resumen(ruta_backup, ruta_origen):
    """Imprime el resumen final tras crear el ZIP con colores."""
    VERDE = "\033[92m"
    AZUL  = "\033[94m"
    RESET = "\033[0m"

    tamaño_mb = os.path.getsize(ruta_backup) / (1024 * 1024)

    print(f"\n  {'─' * 54}")
    print(f"  📦 Original  : {AZUL}{ruta_origen}{RESET}")
    print(f"  ✅ Respaldo  : {VERDE}{ruta_backup}{RESET}")
    print(f"  📏 Tamaño    : {tamaño_mb:.2f} MB")
    print(f"  {'─' * 54}")
    print(f"\n  {VERDE}¡Completado con éxito! ✅{RESET}")


# ------------------------------------------------------------------
# Modo interactivo (sin argumentos)
# ------------------------------------------------------------------

def modo_interactivo():
    base_path = os.getcwd()

    # 1. Listar y elegir elemento
    elementos = listar_elementos(base_path)
    if not elementos:
        return

    try:
        seleccion    = int(input("\nSeleccione el número que desea respaldar: "))
        seleccionado = elementos[seleccion - 1]
        ruta_origen  = os.path.join(base_path, seleccionado)
    except (ValueError, IndexError):
        print("Selección inválida.")
        return

    # 2. Elegir destino
    opcion = menu()
    if opcion == "1":
        carpeta_destino = os.path.dirname(os.path.abspath(__file__))
    else:
        carpeta_destino = solicitar_ruta_personalizada()

    # 3. Nombre y creación
    nombre_backup = crear_nombre_backup()
    ruta_backup   = crear_backup(ruta_origen, carpeta_destino, nombre_backup)

    # 4. Resumen y listado de la carpeta destino
    if ruta_backup:
        mostrar_resumen(ruta_backup, ruta_origen)
        print("\nContenido de la carpeta destino:")
        listar_elementos(carpeta_destino)


# ------------------------------------------------------------------
# Modo por argumentos:  --all | --dir <carpeta> | --file <archivo>
# ------------------------------------------------------------------

def modo_argumentos(args):
    base_path       = os.getcwd()
    carpeta_destino = os.path.dirname(os.path.abspath(__file__))
    nombre_backup   = crear_nombre_backup()

    if args.all:
        # Respalda TODO el directorio actual
        ruta_origen = base_path
        print(f"\nRespaldando directorio completo: {base_path}")

    elif args.dir:
        # Respalda una carpeta específica
        ruta_origen = os.path.join(base_path, args.dir)
        if not os.path.isdir(ruta_origen):
            print(f"Error: la carpeta '{args.dir}' no existe en {base_path}")
            return
        print(f"\nRespaldando carpeta: {ruta_origen}")

    elif args.file:
        # Respalda un archivo específico
        ruta_origen = os.path.join(base_path, args.file)
        if not os.path.isfile(ruta_origen):
            print(f"Error: el archivo '{args.file}' no existe en {base_path}")
            return
        print(f"\nRespaldando archivo: {ruta_origen}")

    ruta_backup = crear_backup(ruta_origen, carpeta_destino, nombre_backup)

    if ruta_backup:
        mostrar_resumen(ruta_backup, ruta_origen)
        print("\nContenido de la carpeta destino:")
        listar_elementos(carpeta_destino)


# ------------------------------------------------------------------
# Punto de entrada
# ------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description="Backup automático en formato ZIP"
    )

    grupo = parser.add_mutually_exclusive_group()
    grupo.add_argument("--all",  action="store_true", help="Respalda todo el directorio actual")
    grupo.add_argument("--dir",  metavar="CARPETA",   help="Respalda una carpeta específica")
    grupo.add_argument("--file", metavar="ARCHIVO",   help="Respalda un archivo específico")

    args = parser.parse_args()

    # Si se pasó algún argumento → modo argumentos
    if args.all or args.dir or args.file:
        modo_argumentos(args)
    else:
        # Sin argumentos → menú interactivo
        modo_interactivo()


if __name__ == "__main__":
    mostrar_banner()
    main()
