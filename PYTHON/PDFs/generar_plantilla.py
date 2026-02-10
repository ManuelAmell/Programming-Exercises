"""
GENERADOR SIMPLE DE PLANTILLAS AZULES
======================================
Script fácil de editar para generar plantillas profesionales en PNG

INSTRUCCIONES:
1. Edita la sección "CONFIGURACIÓN" abajo para personalizar
2. Ejecuta: python generar_plantilla.py
3. Las imágenes PNG se guardarán en la carpeta outputs/
"""

from PIL import Image, ImageDraw, ImageFont
import os

# ============================================
# CONFIGURACIÓN - EDITA AQUÍ
# ============================================

# Colores (puedes cambiarlos)
AZUL_OSCURO = "#0A2463"      # Azul marino
AZUL_MEDIO = "#3E92CC"       # Azul brillante
AZUL_CLARO = "#D8E9F0"       # Azul muy claro
BLANCO = "#FFFFFF"
GRIS_OSCURO = "#2C3E50"

# Tamaño de la plantilla (en píxeles)
ANCHO = 2480    # Ancho A4 en 300 DPI
ALTO = 3508     # Alto A4 en 300 DPI

# Carpeta de salida (se crea en el mismo directorio del script)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
CARPETA_SALIDA = os.path.join(BASE_DIR, "PLANTILLAS GENERADAS")

# ============================================
# FUNCIONES PARA CREAR PLANTILLAS
# ============================================

def crear_plantilla_simple(archivo_salida):
    """Plantilla simple con encabezado azul"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Encabezado azul oscuro
    draw.rectangle([0, 0, ANCHO, 400], fill=AZUL_OSCURO)
    
    # Línea decorativa azul medio
    draw.rectangle([0, 400, ANCHO, 420], fill=AZUL_MEDIO)
    
    # Pie de página con línea azul claro
    draw.rectangle([0, ALTO-150, ANCHO, ALTO-130], fill=AZUL_CLARO)
    draw.rectangle([0, ALTO-130, ANCHO, ALTO], fill=AZUL_MEDIO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


def crear_plantilla_lateral(archivo_salida):
    """Plantilla con barra lateral azul"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Barra lateral izquierda azul oscuro
    draw.rectangle([0, 0, 600, ALTO], fill=AZUL_OSCURO)
    
    # Detalles decorativos en la barra
    for i in range(5):
        y = 400 + (i * 300)
        draw.rectangle([50, y, 550, y+100], fill=AZUL_MEDIO)
    
    # Línea superior en área de contenido
    draw.rectangle([600, 0, ANCHO, 80], fill=AZUL_CLARO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


def crear_plantilla_minimalista(archivo_salida):
    """Plantilla minimalista con líneas azules"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Línea superior gruesa
    draw.rectangle([0, 0, ANCHO, 50], fill=AZUL_OSCURO)
    draw.rectangle([0, 50, ANCHO, 100], fill=AZUL_MEDIO)
    
    # Líneas decorativas en el lateral
    draw.rectangle([0, 0, 30, ALTO], fill=AZUL_MEDIO)
    
    # Línea inferior
    draw.rectangle([0, ALTO-80, ANCHO, ALTO-30], fill=AZUL_CLARO)
    draw.rectangle([0, ALTO-30, ANCHO, ALTO], fill=AZUL_OSCURO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


def crear_plantilla_corporativa(archivo_salida):
    """Plantilla corporativa con bloques de color"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Encabezado con bloques de color
    draw.rectangle([0, 0, ANCHO//3, 350], fill=AZUL_OSCURO)
    draw.rectangle([ANCHO//3, 0, (ANCHO//3)*2, 350], fill=AZUL_MEDIO)
    draw.rectangle([(ANCHO//3)*2, 0, ANCHO, 350], fill=AZUL_CLARO)
    
    # Barra decorativa central
    draw.rectangle([200, 350, ANCHO-200, 380], fill=AZUL_MEDIO)
    
    # Pie de página
    draw.rectangle([0, ALTO-200, ANCHO, ALTO-150], fill=AZUL_CLARO)
    draw.rectangle([0, ALTO-150, ANCHO, ALTO], fill=AZUL_OSCURO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


def crear_plantilla_moderna(archivo_salida):
    """Plantilla moderna con diseño diagonal"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Triángulo diagonal superior
    puntos = [(0, 0), (ANCHO, 0), (ANCHO, 800), (0, 500)]
    draw.polygon(puntos, fill=AZUL_OSCURO)
    
    # Segundo triángulo más claro
    puntos2 = [(0, 500), (ANCHO, 800), (ANCHO, 1000), (0, 700)]
    draw.polygon(puntos2, fill=AZUL_MEDIO)
    
    # Barra inferior
    draw.rectangle([0, ALTO-200, ANCHO, ALTO], fill=AZUL_CLARO)
    draw.rectangle([0, ALTO-250, ANCHO, ALTO-200], fill=AZUL_MEDIO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


def crear_plantilla_elegante(archivo_salida):
    """Plantilla elegante con marco"""
    
    img = Image.new('RGB', (ANCHO, ALTO), BLANCO)
    draw = ImageDraw.Draw(img)
    
    # Marco exterior azul oscuro
    grosor = 80
    draw.rectangle([0, 0, ANCHO, grosor], fill=AZUL_OSCURO)
    draw.rectangle([0, ALTO-grosor, ANCHO, ALTO], fill=AZUL_OSCURO)
    draw.rectangle([0, 0, grosor, ALTO], fill=AZUL_OSCURO)
    draw.rectangle([ANCHO-grosor, 0, ANCHO, ALTO], fill=AZUL_OSCURO)
    
    # Marco interior azul medio
    grosor_int = 40
    margen = grosor + 30
    draw.rectangle([margen, margen, ANCHO-margen, margen+grosor_int], fill=AZUL_MEDIO)
    draw.rectangle([margen, ALTO-margen-grosor_int, ANCHO-margen, ALTO-margen], fill=AZUL_MEDIO)
    draw.rectangle([margen, margen, margen+grosor_int, ALTO-margen], fill=AZUL_MEDIO)
    draw.rectangle([ANCHO-margen-grosor_int, margen, ANCHO-margen, ALTO-margen], fill=AZUL_MEDIO)
    
    # Esquinas decorativas azul claro
    esquina = 150
    draw.rectangle([grosor, grosor, grosor+esquina, grosor+20], fill=AZUL_CLARO)
    draw.rectangle([grosor, grosor, grosor+20, grosor+esquina], fill=AZUL_CLARO)
    
    img.save(archivo_salida, 'PNG', dpi=(300, 300))
    print(f"✓ Creada: {archivo_salida}")


# ============================================
# EJECUTAR - Genera todas las plantillas
# ============================================

if __name__ == "__main__":
    print("\n" + "="*50)
    print("GENERADOR DE PLANTILLAS AZULES")
    print("="*50 + "\n")
    
    # Crear carpeta de salida si no existe
    os.makedirs(CARPETA_SALIDA, exist_ok=True)
    
    # Generar todas las plantillas
    crear_plantilla_simple(f"{CARPETA_SALIDA}/plantilla_1_simple.png")
    crear_plantilla_lateral(f"{CARPETA_SALIDA}/plantilla_2_lateral.png")
    crear_plantilla_minimalista(f"{CARPETA_SALIDA}/plantilla_3_minimalista.png")
    crear_plantilla_corporativa(f"{CARPETA_SALIDA}/plantilla_4_corporativa.png")
    crear_plantilla_moderna(f"{CARPETA_SALIDA}/plantilla_5_moderna.png")
    crear_plantilla_elegante(f"{CARPETA_SALIDA}/plantilla_6_elegante.png")
    
    print(f"\n✅ ¡Listo! Se generaron 6 plantillas en: {CARPETA_SALIDA}")
    print("\nAhora puedes:")
    print("1. Abrir las imágenes PNG en tu editor favorito")
    print("2. Agregar texto, logos e imágenes")
    print("3. Convertir a PDF con cualquier programa\n")
