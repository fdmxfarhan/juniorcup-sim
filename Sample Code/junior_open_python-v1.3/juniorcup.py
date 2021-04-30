import socket

UDP_IP = '127.0.0.1'
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, 3000))

class Robot:
    """
    Robot controller
    """
    def __init__(self, id):
        self.cmp = 0
        self.imin = 0
        self.min = 0
        self.ldr_b = 0
        self.ldr_f = 0
        self.ldr_l = 0
        self.ldr_r = 0
        self.shb = 0
        self.shf = 0
        self.shl = 0
        self.shr = 0
        self.min = 0
        self.team = bytes('a' + str(id), 'utf-8') 
    def sensor(self):
        try:
            sock.sendto(self.team, (UDP_IP, 8000))
            data, addr = sock.recvfrom(1024)
            # print(data)
            self.cmp = int(data[2:5])
            self.imin = int(data[5:7])
            self.ldr_b = int(data[7:11])
            self.ldr_f = int(data[11:15])
            self.ldr_l = int(data[15:19])
            self.ldr_r = int(data[19:23])
            self.shb = int(data[23:27])
            self.shf = int(data[27:31])
            self.shl = int(data[31:35])
            self.shr = int(data[35:39])
            self.min = int(data[39:43])
        except:
            print('[ Error ] Robot is not connected:(')
    def motor(self, ml1, ml2, mr2, mr1):
        b = bytearray()
        b.append(ord('m'))
        b.append(ord(self.team.decode()[0]))
        b.append(ord(self.team.decode()[1]))
        if(ml1 >= 0):
            b.append(ord('+'))
            b.append(ord(str(int((ml1/100)%10))))
            b.append(ord(str(int((ml1/10)%10))))
            b.append(ord(str(int((ml1/1)%10))))
        else:
            b.append(ord('-'))
            b.append(ord(str(int((-ml1/100)%10))))
            b.append(ord(str(int((-ml1/10)%10))))
            b.append(ord(str(int((-ml1/1)%10))))
        if(ml2 >= 0):
            b.append(ord('+'))
            b.append(ord(str(int((ml2/100)%10))))
            b.append(ord(str(int((ml2/10)%10))))
            b.append(ord(str(int((ml2/1)%10))))
        else:
            b.append(ord('-'))
            b.append(ord(str(int((-ml2/100)%10))))
            b.append(ord(str(int((-ml2/10)%10))))
            b.append(ord(str(int((-ml2/1)%10))))
        if(mr2 >= 0):
            b.append(ord('+'))
            b.append(ord(str(int((mr2/100)%10))))
            b.append(ord(str(int((mr2/10)%10))))
            b.append(ord(str(int((mr2/1)%10))))
        else:
            b.append(ord('-'))
            b.append(ord(str(int((-mr2/100)%10))))
            b.append(ord(str(int((-mr2/10)%10))))
            b.append(ord(str(int((-mr2/1)%10))))
        if(mr1 >= 0):
            b.append(ord('+'))
            b.append(ord(str(int((mr1/100)%10))))
            b.append(ord(str(int((mr1/10)%10))))
            b.append(ord(str(int((mr1/1)%10))))
        else:
            b.append(ord('-'))
            b.append(ord(str(int((-mr1/100)%10))))
            b.append(ord(str(int((-mr1/10)%10))))
            b.append(ord(str(int((-mr1/1)%10))))
        # print(b)
        sock.sendto(b, (UDP_IP, 8000))
    def printAll(self):
        print(  
            'cmp: ' + str(self.cmp) + 
            ' imin: ' + str(self.imin) + 
            ' min: ' + str(self.min) + 
            ' ldr_b: ' + str(self.ldr_b) + 
            ' ldr_f: ' + str(self.ldr_f) + 
            ' ldr_l: ' + str(self.ldr_l) + 
            ' ldr_r: ' + str(self.ldr_r) +
            ' shf: ' + str(self.shf) + 
            ' shr: ' + str(self.shr) + 
            ' shb: ' + str(self.shb) + 
            ' shl: ' + str(self.shl)
        )
