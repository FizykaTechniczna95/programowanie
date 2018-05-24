import sys

key = open("{}".format(sys.argv[1]), "r").readlines()[0].split()
key = [ int(i) for i in key ]
file = open("msg.txt", 'w')
file.write(str( (key[0]**key[1])%key[2] ))
file.close()
