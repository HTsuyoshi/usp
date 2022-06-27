INPUT  = []
OUTPUT = []

def read_line(line: str, n_line: int):
    items = line.split('|')
    for i in range(len(items)):
        items[i]  = items[i].strip()
        if i == len(items) - 1:
            break
    INPUT.append([])
    INPUT[n_line] = items[:len(items) - 2]
    OUTPUT.append(items[len(items) - 1].split('= ')[1])

def decision_tree(index: int) -> str:

    pass
    return 'yes'

def decision_tree_test():
    for i in range(len(INPUT)):
        if decision_tree != OUTPUT[i]:
            print(f'{"*"*10} Error {"*"*10}')
            return
        print(f'{"*"*10} Test {i} correct! {"*"*10}')

if __name__ == '__main__':
    with open('./data.txt', 'r') as file:
        file.readline()
        for i in range(11):
            read_line(file.readline(), i)

    print(f'{"*"*10} Data {"*"*10}')
    print(INPUT)
    print(OUTPUT)

    print(f'{"*"*10} Decision {"*"*10}')

