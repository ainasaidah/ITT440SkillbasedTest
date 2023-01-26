import threading
import random
import socket

quotes = ["A goal without a plan is just a wish.", "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle>
,"The best way to predict your future is to create it."]

def handle_client(client_socket):
        quote = random.choice(quotes)
        client_socket.send(quote.encode())
        client_socket.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("192.168.145.129", 8888))
server.listen(5)

while True:
        client, address = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()


