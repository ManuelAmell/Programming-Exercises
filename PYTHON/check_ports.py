import socket
import sys

def checkPortsSocket(ip, portlist):
    try:
        for port in portlist:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(5)
            result = sock.connect_ex((ip, port))
            if result == 0:
                print("Port {} abierto  en {}".format(ip, port))

            else:
                print("Port {}  cerrado en {}".format(ip, port))
            sock.close()
    except socket.error as error:
        print(str(error))
        print("Error de Conexion")
        sys.exit()
checkPortsSocket("127.0.0.1",  [8080, 80,443])
