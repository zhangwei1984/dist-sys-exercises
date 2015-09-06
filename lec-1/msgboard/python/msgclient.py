# CS 6421 - Simple Message Board Client in Python
# Chenghu He and Wei Zhang
# Run with:     python msgclient.py

#!/usr/bin/python

import socket

host = "gwutestbench.koding.io"
portnum = 5555

# your code here!
name = "Chenghu He & Wei"
msg = "Welcome to dist-sys class!"

if len(sys.argv) < 4:
    print 'Usage: ' + sys.argv[0] + 'hostname name msg'
    sys.exit(1)

host = sys.argv[1]
name = sys.argv[2]
msg = sys.argv[3]

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
clientsocket.connect((host, portnum))

print name
print msg
clientsocket.send(name + "\n")
clientsocket.send(msg + "\n")

clientsocket.close()

print("Sent message to server!")
