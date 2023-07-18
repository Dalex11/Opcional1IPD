import subprocess

# Ruta al ejecutable 'hola'. Asegúrate de proporcionar la ruta correcta.
ejecutable_hola = './secuencial'

# Nombre del archivo donde se escribirá la salida
nombre_archivo_salida = 'salida_hola.txt'

with open(nombre_archivo_salida, 'w') as archivo_salida:
    for _ in range(5):
        try:
            resultado = subprocess.run([ejecutable_hola], capture_output=True, text=True)
            salida_hola = resultado.stdout
            archivo_salida.write(f"Resultado (Iteración {_+1}):\n{salida_hola}\n\n")
        except FileNotFoundError:
            archivo_salida.write(f"Error: No se encontró el ejecutable '{ejecutable_hola}'.\n")
            break