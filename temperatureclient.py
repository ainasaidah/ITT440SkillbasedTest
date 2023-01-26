import socket

def main():
        port = 8080
        host = "192.168.145.129"

        s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        s.connect((host,port))

        fahrenheit=input("Do input temperature in Fahrenheit: ")
        s.send(fahrenheit.encode())

        celcius=s.recv(1024).decode()
        print(f"The calculated temperature in Celcius: {celcius}")

        s.close()

if __name__=="__main__":
        main()
