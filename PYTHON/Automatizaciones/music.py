import subprocess
import os

# Colores ANSI
BLUE = "\033[94m"
GREEN = "\033[92m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
RESET = "\033[0m"

def seleccionar_archivo(ruta):
    ruta = ruta.strip().replace('"', '').replace("'", "")

    if os.path.isfile(ruta):
        return ruta

    elif os.path.isdir(ruta):
        txt_files = [f for f in os.listdir(ruta) if f.lower().endswith(".txt")]
        if not txt_files:
            print(f"{YELLOW}No se encontraron archivos .txt en la carpeta.{RESET}")
            return None

        print(f"\n{CYAN}Archivos .txt encontrados:{RESET}")
        for i, f in enumerate(txt_files, start=1):
            print(f"{i}) {f}")

        opcion = input(f"{YELLOW}Elige el número del archivo: {RESET}").strip()
        if not opcion.isdigit() or int(opcion) < 1 or int(opcion) > len(txt_files):
            print(f"{YELLOW}Opción inválida.{RESET}")
            return None

        return os.path.join(ruta, txt_files[int(opcion)-1])

    else:
        print(f"{YELLOW}La ruta ingresada no existe.{RESET}")
        return None


def descargar_canciones(ruta_archivo):
    if not ruta_archivo:
        return

    # Carpeta destino
    ruta_script = os.path.dirname(os.path.abspath(__file__))
    carpeta_destino = os.path.join(ruta_script, "Descargas_Playlist")
    os.makedirs(carpeta_destino, exist_ok=True)

    # Leer canciones ya descargadas
    canciones_existentes = set(
        os.path.splitext(f)[0] for f in os.listdir(carpeta_destino) if f.lower().endswith(".mp3")
    )

    # Leer todas las canciones del txt
    with open(ruta_archivo, "r", encoding="utf-8") as f:
        lineas = [linea.strip() for linea in f if linea.strip()]

    if not lineas:
        print(f"{YELLOW}El archivo está vacío.{RESET}")
        return

    # Filtrar solo las canciones que aún no están
    pendientes = [c for c in lineas if c not in canciones_existentes]

    if not pendientes:
        print(f"{GREEN}✅ Todas las canciones ya están descargadas.{RESET}")
        return

    print(f"\n{GREEN}=== Iniciando descargas... ==={RESET}\n")

    for i, linea in enumerate(pendientes, start=1):
        busqueda = f"{linea} official audio"
        print(f"{CYAN}[{i}/{len(pendientes)}] Descargando:{RESET} {busqueda}")

        # Guardar como "Artista - Canción.mp3" automáticamente
        nombre_archivo = linea.replace("/", "_")  # evitar / en nombres de archivo
        ruta_salida = os.path.join(carpeta_destino, f"{nombre_archivo}.%(ext)s")

        subprocess.run([
            "yt-dlp",
            "-x",
            "--audio-format", "mp3",
            "--audio-quality", "0",
            "-o", ruta_salida,
            "ytsearch1:" + busqueda
        ])

    print(f"\n{GREEN}✅ Descargas completadas!{RESET}")
    print(f"{GREEN}Canciones descargadas:{len(pendientes)}, canciones ya existentes omitidas:{len(lineas)-len(pendientes)}{RESET}")


# ===== MENÚ PRINCIPAL =====
print(BLUE + "="*50 + RESET)
print(GREEN + "      🎵 Amellist PlayDownloads 🎵      " + RESET)
print(BLUE + "="*50 + RESET)

ruta_input = input(f"{YELLOW}Ingresa la ruta del archivo .txt o de la carpeta: {RESET}")
archivo_seleccionado = seleccionar_archivo(ruta_input)
descargar_canciones(archivo_seleccionado)