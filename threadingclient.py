import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(("192.168.145.129", 8888))

quote = client.recv(1024).decode()
print("Quote of the Day: " + quote)

client.close()
