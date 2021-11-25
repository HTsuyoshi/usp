from sage.all import *
import random

NRO_USP = 117960
DATA_NAS = 29072001
MOD_CONST = 6789
EXP_CONST = 2345

# RANDOM TESTS

def get_random(n: int) -> int:
    return int(random.random() * pow(10, n))

# Modular exponentiation
def test_1() -> None:
    passed_tests = 0
    while passed_tests < 1000:
        e, x, y = get_random(6), get_random(6), get_random(6)
        ring = Integers(y)

        if e < 0 or x < 0 or y < 0:
            continue

        my_ans = exp_modular(x, y, e)
        correct = ring(x) ** e 

        assert my_ans == correct, f'my={my_ans}, correct={correct}, test={passed_tests}'

        passed_tests += 1

# Miller and rabin primality test
def test_2() -> None:
    passed_tests = 0
    failed = 0

    while passed_tests < 1000:
        prime = random_prime(n = 1000000, lbound = 2)

        if miller_rabin(prime, 1000):
            failed += 1

        passed_tests += 1

    print(f'Miller rabin got wrong {failed} times')

    pass

# RSA
def test_3() -> None:

    def euler_func(q, r):
        return (q-1) * (r-1)

    passed_tests = 0
    while passed_tests < 1000:

        offset = 1000

        r = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)
        q = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)

        while r == q:
            r = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)
            q = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)

        if not r.is_prime() and q.is_prime():
            continue

        n = q * r
        t = euler_func(q, r)

        s = 0
        while len(str(s)) < 10:
            s = get_random(10)
            try:
                p = pow(s, -1, t)
            except ZeroDivisionError:
                s = 0

        ring = Integers(t)
        p = ring(p)
        assert p * s == 1

        x_0 = randint(10 ** 15, 10 ** 16) 
        y_0 = RSA(x_0, p, n)

        x_1 = RSA(y_0, s, n)
        assert x_0 == x_1, f'Inverse doesn\'t match'

        y_1 = RSA(x_1, p, n)
        assert y_0 == y_1, f'RSA of x_0 and x_1 doesn\'t match'

        passed_tests += 1
    pass

# Modular exponentiation
def exp_modular(x: int, y: int, e: int) -> int:
    assert x > 0 and y > 0 and e > 0

    bits = Integer(e).bits()
    bits.reverse()
    temp = 1
    res = 1

    #for j in range(len(bits)-1, -1, -1):
    for bit in bits:
        temp = (temp * temp) % y
        res = (temp * x) % y

        if bit:
            mask = -1
        else:
            mask = 0

        temp = (res & mask) | (temp & ~mask)

    return temp

# Miller and rabin primality test
def miller_rabin(y: int, w: int) -> bool:
    assert y > 2, 'O Número precisa maior que 2'
    assert y % 2 != 0, 'O Número precisa ser ímpar'
    assert w > 0, 'O Número de testemunhas precisa ser maior que 0'

    def get_c_t(y):
        y, t = y-1, 0

        while y % 2 == 0:
            if y == 0:
                break
            t, y = t+1, y/2

        return y, t

    def get_bit_len(n):
        return len(Integer(n).bits())

    def get_witness(y):
        prime = random_prime(get_bit_len(y))
        while prime < 1 or prime > y - 1:
            prime = random_prime(get_bit_len(y))

        return prime

    c, t = get_c_t(y)

    for _ in range(w):
        ring = Integers(y)
        a = ring(get_witness(y))
        r_0 = a ** c
        r_1 = r_0 ** 2
        for _ in range(t):
            if r_1 == 1 and r_0 != 1 and r_0 != -1:
                return False
            r_1, r_0 = r_0 ** 2, r_1

    if r_1 != 1:
        return false

    return True

# RSA
def RSA(x: int, p: int, n: int) -> int:
    ring = Integers(n)
    m = ring(x) ** p
    return m

# Exercicio 1
def exercicio_1(NRO_USP: int) -> None:
    print('Exercício 1\n')

    # some tests
    test_1()

    # ex 1.1
    print('implementado\n')

    # ex 1.2
    print(f'Nro USP: {NRO_USP}\n')

    # ex 1.3
    ring = Integers(MOD_CONST)

    my_ans, correct = exp_modular(x=NRO_USP, y=MOD_CONST, e=EXP_CONST), ring(NRO_USP) ** EXP_CONST
    assert my_ans == correct, f'my={my_ans}, correct={correct}'

    print(f'ring(NRO_USP) ** EXP_CONST')
    print(f'Nro USP: {ring(NRO_USP) ** EXP_CONST}\n')

    # ex 1.4
    # proof here
    # Justificar a complexidade de tempo de execução deste algoritmo que é O(loge)

# Exercicio 2
def exercicio_2() -> None:
    print('Exercício 2\n')

    test_2()

    # Ex 1
    i = 2
    while True:
        if miller_rabin(DATA_NAS + i, 8):
            print(f'{DATA_NAS + i} é primo')
            break
        else:
            print(f'{DATA_NAS + i} não é primo')
            i += 2

    if Integer(DATA_NAS + i).is_prime():
        print('\né realmente primo')
    else:
        print('\nnão era um primo')

    # ex 2
    # proof here
    # Deduzir e justificar o tempo de execução deste algoritmo como função de we de y

# Exercicio 3
def exercicio_3() -> None:
    test_3()
    print('Exercício 3\n')

    # Ex 1
    offset = 1000

    r = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)
    q = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)

    while r == q:
        r = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)
        q = random_prime(n = DATA_NAS + offset, lbound = DATA_NAS)

    assert r.is_prime() and q.is_prime(), f'{r} ou {q} não é primo'

    print(f'r = {r}, q = {q}\n')

    # Ex 2
    n = q * r
    print(f'n = q * r = {q} x {r} = {n}\n')

    # Ex 3
    def euler_func(q, r):
        return (q-1) * (r-1)

    t = euler_func(q, r)
    print(f'totient = (q-1)*(r-1) = {q - 1} {r - 1} = {t}\n')

    # Ex 4
    s = 0
    while len(str(s)) < 10:
        s = get_random(10)
        try:
            p = pow(s, -1, n)
        except ZeroDivisionError:
            s = 0

    print(f's = {s}\n')

    # Ex 5
    ring = Integers(n)
    p = ring(p)
    print(f'p = {p}, s = {s}, s*p = {p * s} mod {n}\n')

    # Ex 6
    ring = Integers(t)
    p = pow(s, -1, t)
    print(f'p = {p}, s = {s}, s*p = {p * s} mod {t}\n')
    assert p * s == 1

    # Ex 7 
    x_0 = str(NRO_USP)*2 + str(NRO_USP)[:3]
    assert len(x_0) == 15, f'Len expected: 15, recieved: {len(x_0)}'
    x_0 = int(x_0)

    # Ex 8
    print(f'x_0 = {x_0}\n')

    # Ex 9 
    y_0 = RSA(x_0, p, n)
    print(f'y_0 = {y_0}\n')

    # Ex 10
    x_1 = RSA(y_0, s, n)
    print(f'x_1 = {x_1}\n')
    assert x_0 == x_1, f'Inverse doesn\'t match'

    # Ex 11
    y_1 = RSA(x_1, p, n)
    print(f'y_1 = {y_1}\n')
    assert y_0 == y_1, f'RSA of x_0 and x_1 doesn\'t match'


if __name__ == '__main__':
    exercicio_1(NRO_USP)
    exercicio_2()
    exercicio_3()

    pass


