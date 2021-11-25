from bitdiff import table

class table2(table):
    def __init__(self):
        self.K = []
        self.Kc = []
        self.E = []
        self.Ec = []
        self.D = []
        self.Dc = []
        self.diff = []

    def read_key_c(self, line):
        key_c = line.split(':')[1].strip()
        self.Kc.append(key_c)

if __name__ == '__main__':
    f = open('key_comp.txt', 'r')
    for x in range(6):
        f.readline()

    t = table2()
    for x in range(1,17):
        t.read_key(f.readline())
        t.read_E_D(f.readline())

    for x in range(7):
        f.readline()

    for x in range(1,17):
        t.read_key_c(f.readline())
        t.read_Ec_Dc(f.readline())

    for x in range(1,17):
        print(f'{x} & {t.K[x-1]} & {t.Kc[x-1]} & {t.E[x-1]} & {t.Ec[x-1]} & {t.D[x-1]} & {t.Dc[x-1]} & {t.bit_diff(x-1)}\\\\')
        print('\\hline')
