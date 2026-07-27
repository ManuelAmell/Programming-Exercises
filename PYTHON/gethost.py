#!/usr/bin/env python3
#esto sirve para obtener el nombre del host, la ip de un dominio, el nombre del host a partir de una ip y el nombre de dominio completo a partir de un nombre de host
import socket
import sys

def main():
    print("gethostname")
    print(socket.gethostname())

    try:
        print("gethostbyname")
        print(socket.gethostbyname("developers.shodan.io"))
        print("gethostbyaddr")
        print(socket.gethostbyaddr("216.117.2.180"))

        print("getfqdn")
        print(socket.getfqdn("www.google.com"))

    except socket.error as error:
        print(str(socket.error))
        print("Error de conexion")


if __name__ == "__main__":
    main()
    sys.exit()