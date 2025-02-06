from socket import *


def start_server(port):
    serverSocket = socket(AF_INET, SOCK_DGRAM)
    serverSocket.bind(("", port))
    print(f"Chat room started on port {port}...")
    clients = set()

    while True:
        msg, clientAddr = serverSocket.recvfrom(2048)
        if clientAddr not in clients:
            clients.add(clientAddr)
        message = msg.decode()
        print(f"{clientAddr}: {message}")
        for client in clients:
            if client != clientAddr:
                serverSocket.sendto(f"{clientAddr}: {message}".encode(), client)


def start_client(ip, port):
    clientSocket = socket(AF_INET, SOCK_DGRAM)
    name = input("Enter your name: ")
    print(f"Connected to chat room {ip}:{port}")

    def receive_messages():
        while True:
            try:
                res, _ = clientSocket.recvfrom(2048)
                print(res.decode())
            except:
                break

    from threading import Thread

    Thread(target=receive_messages, daemon=True).start()

    while True:
        message = input()
        if message.lower() == "exit":
            print("Exiting chat...")
            break
        clientSocket.sendto(f"{name}: {message}".encode(), (ip, port))

    clientSocket.close()


if __name__ == "__main__":
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
