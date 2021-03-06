

# This file was *autogenerated* from the file ex_1.sage
from sage.all_cmdline import *   # import sage library

_sage_const_1 = Integer(1); _sage_const_2 = Integer(2); _sage_const_11 = Integer(11)
INPUT  = []
OUTPUT = []

def read_line(line: str, n_line: int):
    items = line.split('|')
    for i in range(len(items)):
        items[i]  = items[i].strip()
        if i == len(items) - _sage_const_1 :
            break
    INPUT.append([])
    INPUT[n_line] = items[:len(items) - _sage_const_2 ]
    OUTPUT.append(items[len(items) - _sage_const_1 ].split('= ')[_sage_const_1 ])

if __name__ == '__main__':
    with open('./data.txt', 'r') as file:
        file.readline()
        for i in range(_sage_const_11 ):
            read_line(file.readline(), i)
        print(INPUT)
        print(OUTPUT)


