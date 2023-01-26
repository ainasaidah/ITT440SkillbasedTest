import socket

def convertfahrenheit_to_celcius(fahrenheit):
        celcius = ((fahrenheit - 32) * 5)/9
        return celcius

def main():
        port = 8080
        host = "192.168.145.129"
        s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((host,port))
        s.listen(1)
        print(f"The socket is listening on {host}:{port}")

        conn, addr = s.accept()
        print(f"The connection is established from {addr}")

        while True:
                data=conn.recv(1024).decode()
                if not data:
                        break
                print(f"The {data} in fahrenheit is received from {addr}")

        celcius=convertfahrenheit_to_celcius
        conn.send(str(celcius).encode())
        print(f"The {celcius} is send to {addr}")

        conn.close()

if __name__ == "__main__":
        main()
