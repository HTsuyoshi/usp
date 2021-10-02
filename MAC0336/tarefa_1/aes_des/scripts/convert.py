def conv_bin(n):
    for i in n:
        if type(i) == str:
            i = int(i)
        print('{:04b}'.format(i), end=' ')
    print()

def printer(nro):
    print(f'nro: {nro_usp}')
    print('bin: ', end='')
    conv_bin(nro + nro)
    print('hex: ', end='')
    conv_hex(nro + nro)
    print()

def conv_hex(n):
    for i in n:
        if type(i) == str:
            i = int(i)
        print('0x0{:01x}'.format(i), end=' ')
    print()

def birth(date):
    print(f'date: {date}')
    print('bin: ', end='')
    conv_bin(date)
    print('hex: ', end='')
    conv_hex(date)
    print()

if __name__ == '__main__':
    nro_usp = '29876522'
    printer(nro_usp)

    nro_usp = '11796022'
    printer(nro_usp)

    nascimento = '29109900'
    birth(nascimento)

    nascimento = '29070100'
    birth(nascimento)
