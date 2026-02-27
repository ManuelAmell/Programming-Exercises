import os

def create_backup(src_dir, dest_file):
    """
    Crea un backup del directorio fuente en el archivo destino especificado.

    :param src_dir: Ruta al directorio fuente.
    :param dest_file: Ruta completa y nombre del archivo de destino.
    """
    try:
        with open(dest_file, 'wb') as f_dest:
            for root, dirs, files in os.walk(src_dir):
                for file in files:
                    src_path = os.path.join(root, file)
                    rel_path = os.path.relpath(src_path, src_dir)
                    dest_path = os.path.join(os.path.dirname(dest_file), rel_path)

                    with open(src_path, 'rb') as f_src:
                        data = f_src.read()
                        f_dest.write(data)
        
        print(f"Backup creado exitosamente en {dest_file}")
    except Exception as e:
        print(f"Error al crear el backup: {e}")

if __name__ == "__main__":
    src_directory = input("Ingrese la ruta del directorio fuente que desea copiar: ")
    dest_zip_file = input("Ingrese el nombre del archivo de destino (sin extensión): ")

    if not dest_zip_file.endswith('.zip'):
        dest_zip_file += '.zip'

    full_dest_path = os.path.join(os.getcwd(), dest_zip_file)

    create_backup(src_directory, full_dest_path)
