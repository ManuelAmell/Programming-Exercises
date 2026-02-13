# Instalación (ejecutar en terminal si es necesario):
# pip install reportlab

from reportlab.lib.pagesizes import letter
from reportlab.lib import colors
from reportlab.platypus import SimpleDocTemplate, Table, TableStyle, Paragraph, Spacer
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from datetime import datetime

# Función para obtener datos del usuario
def obtener_datos_proyecto():
    """
    Solicita al usuario información sobre el proyecto
    Retorna un diccionario con los datos ingresados
    """
    print("=== GENERADOR DE REPORTE DE PROYECTO ===\n")
    
    nombre_proyecto = input("Nombre del proyecto: ")
    descripcion = input("Descripción del proyecto: ")
    horas_trabajadas = float(input("Horas trabajadas: "))
    desarrollador = input("Nombre del desarrollador: ")
    fecha = input("Fecha (DD/MM/YYYY) [Presiona Enter para hoy]: ")
    
    # Si no ingresa fecha, usa la fecha actual
    if not fecha:
        fecha = datetime.now().strftime("%d/%m/%Y")
    
    # Retorna un diccionario con toda la información
    return {
        'nombre_proyecto': nombre_proyecto,
        'descripcion': descripcion,
        'horas': horas_trabajadas,
        'desarrollador': desarrollador,
        'fecha': fecha
    }

# Función para generar el PDF
def generar_pdf(datos_proyecto, nombre_archivo="reporte.pdf"):
    """
    Crea un archivo PDF con los datos del proyecto
    
    Parámetros:
    - datos_proyecto: diccionario con la información
    - nombre_archivo: nombre del archivo PDF a generar
    """
    
    # Crear el documento PDF
    doc = SimpleDocTemplate(nombre_archivo, pagesize=letter)
    
    # Lista de elementos que irán en el PDF
    elementos = []
    
    # Obtener estilos predefinidos
    estilos = getSampleStyleSheet()
    
    # Crear estilos personalizados
    titulo_style = ParagraphStyle(
        'titulo_custom',
        parent=estilos['Heading1'],
        fontSize=24,
        textColor=colors.HexColor('#1f4788'),
        spaceAfter=30,
        alignment=1  # Centrado
    )
    
    # Título del documento
    titulo = Paragraph("REPORTE DE PROYECTO", titulo_style)
    elementos.append(titulo)
    elementos.append(Spacer(1, 0.3*inch))
    
    # Crear tabla con los datos
    datos_tabla = [
        ['Campo', 'Valor'],
        ['Proyecto', datos_proyecto['nombre_proyecto']],
        ['Descripción', datos_proyecto['descripcion']],
        ['Horas Trabajadas', str(datos_proyecto['horas'])],
        ['Desarrollador', datos_proyecto['desarrollador']],
        ['Fecha', datos_proyecto['fecha']]
    ]
    
    # Tabla con estilos
    tabla = Table(datos_tabla, colWidths=[2*inch, 4*inch])
    tabla.setStyle(TableStyle([
        ('BACKGROUND', (0, 0), (-1, 0), colors.HexColor('#1f4788')),
        ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
        ('ALIGN', (0, 0), (-1, -1), 'LEFT'),
        ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
        ('FONTSIZE', (0, 0), (-1, 0), 14),
        ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
        ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
        ('GRID', (0, 0), (-1, -1), 1, colors.black)
    ]))
    
    elementos.append(tabla)
    elementos.append(Spacer(1, 0.5*inch))
    
    # Construir el PDF
    doc.build(elementos)
    print(f"\n✓ PDF generado correctamente: {nombre_archivo}")

# Ejecutar el programa completo
try:
    datos = obtener_datos_proyecto()
    generar_pdf(datos, "reporte_proyecto.pdf")
except Exception as e:
    print(f"Error: {e}")