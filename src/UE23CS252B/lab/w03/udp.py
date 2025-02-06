from socket import *


def start_server(port):
    serverSocket = socket(AF_INET, SOCK_DGRAM)
    serverSocket.bind(("", port))
    print(f"Server started on port {port}...")

    while True:
        msg, clientAddr = serverSocket.recvfrom(2048)
        print(f"Client ({clientAddr}): {msg.decode()}")
        response = msg.decode().upper()
        serverSocket.sendto(response.encode(), clientAddr)


def start_client(ip, port):
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    print(f"Connected to server {ip}:{port}")
    while True:
        message = input("You: ")
        if message.lower() == "exit":
            print("Exiting chat...")
            break
        clientSocket.sendto(message.encode(), (ip, port))
        res, _ = clientSocket.recvfrom(2048)
        print("Server: ", res.decode())
    clientSocket.close()


# main
mode = input("Run as server (s) or client (c)? ").strip().lower()
if mode == "s":
    port = int(input("Enter port: "))
    start_server(port)
elif mode == "c":
    ip = input("Enter server IP: ").strip()
    port = int(input("Enter server port: "))
    start_client(ip, port)
else:
    print("Invalid option. Exiting.")
