import socket
import errno

host = "127.0.0.1"
port = 1337

try:
    mysocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    mysocket.connect((host, port))

    print("Conectado al host " + str(host) + " en el puerto: " + str(port))

    mysocket.send("Hello\n".encode())
    message = mysocket.recv(1024)

    print("Received message from the client\n")
    msg = message.decode()
    mysocket.sendall(msg.encode())

except socket.error as e:
    print("Socket error", e)

finally:
    
    mysocket.close()

    