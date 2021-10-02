class table:
    def __init__(self):
        self.K = []
        self.E = []
        self.Ec = []
        self.D = []
        self.Dc = []
        self.diff = []

    def read_key(self, line):
        key = line.split(':')[1].strip()
        self.K.append(key)

    def read_E_D(self, line):
        line = line.split(':')[1].strip()[1:-1]
        self.E.append(line.split('; ')[0])
        self.D.append(line.split('; ')[1])

    def read_Ec_Dc(self, line):
        line = line.split(':')[1].strip()[1:-1]
        self.Ec.append(line.split('; ')[0])
        self.Dc.append(line.split('; ')[1])

    def bit_diff(self, i):
        total = 0
        byte_s = 32

        E, Ec  = self.E[i], self.Ec[i]
        for x in range(byte_s):
            if ((( int(E[2:], 16) >>  x) & 1) != (( int(Ec[2:], 16) >>  x) & 1)):
                total += 1

        D, Dc  = self.D[i], self.Dc[i]
        for x in range(byte_s):
            if ((( int(D[2:], 16) >>  x) & 1) != (( int(Dc[2:], 16) >>  x) & 1)):
                total += 1

        return total


if __name__ == '__main__':
    f = open('msg_comp.txt', 'r')
    for x in range(6):
        f.readline()

    t = table()
    for x in range(1,17):
        t.read_key(f.readline())
        t.read_E_D(f.readline())

    for x in range(7):
        f.readline()

    for x in range(1,17):
        f.readline()
        t.read_Ec_Dc(f.readline())

    for x in range(1,17):
        print(f'{x} & {t.K[x-1]} & {t.E[x-1]} & {t.Ec[x-1]} & {t.D[x-1]} & {t.Dc[x-1]} & {t.bit_diff(x-1)}\\\\')
        print('\\hline')
