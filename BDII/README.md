# Anotações

[Lista 1](./Lista_1.md)

[Lista 2](./Lista_2.md)

[Livro](./DBSC.md)

## Transação

- `Atomicidade`: Todas as operações executadas, não faz nenhuma delas ou desfaz tudo se houver falha no SGBD

- `Consistencia`: Execução de transação isolada (sem outra transação simultânea) deve manter consistência dos dados. `Dever do programador da aplicação`

- `Isolamento`: Uma transição não "percebe" outra transação - para uma determinada transação, ou transação terminou antes dela ou começou depois

- `Durabilidade`: após uma transaçao completada, mudanças persistem no BD, mesmo se houver falhas no sistema

### Estados de transação

- `ativa`: enquanto está executando;

– `parcialmente confirmada`: após execução instrução final;

– `parcialmente confirmada`: após execução instrução final;

– `falha`: quando descobre-se que execução normal não pode prosseguir;

– `abortada`: depois que transação foi revertida e o BD foi restaurado ao estado anterior ao início da transação;

– `confirmada`: após término bem sucedido

Diagrama de estados:

```
     +-> parcial conf --> confirmada
     |    |
ativa     |
     |    v
     +-> falha ---------> abortada
```

### Seriação de conflito

- Se um schedule S puder ser transformado em um schedule S\' por uma séria de trocas de instruções não conflitantes, dizemos que S e S\' são `equivalentes em confito`

- Um schedule é `serial de conflito` se for equivalente em conflito a um schedule serial

### Seriação de visão

Dois schedules S e S\' são `equivalentes em visão` se:

1. Para cada item de dados $Q$, a transação $T_{i}$ ler o valor de $Q$ no schedule $S$

	- Então a transação $T_{i}$ em S\' também precisa ler o valor inicial de $Q$

	- Ou seja: schedule inicial e final têm que ter um read (Q) correspondente

2. Para cada item de dados $Q$, se a transação $T_{i}$ executar read(Q) no schedule $S$:

	- Se esse valor foi produzido por uma operação write(Q) executada pela transação $T_{j}$

	- Então a operação read(Q) da transação $T_{i}$ no schedule S\' tabém precisa ler o valor inicial de $Q$ que foi produzido pela mesma operação write(Q) da transação $T_(j)$

3. Para cade iem de dados Q:

	- A transação que realiza a operação write(Q) final no schedule S precisa realizar a operação write(Q) final no schedule S\'

### Exercícios

1. Dado o schedule a seguir, verifique se ele é serial de conflito por meio da troca de instruções para gerar schedule equivalente.gerar schedule equivalent

```
+----+----+----+
| T1 | T2 | T3 |
+----+----+----+
| rX |    |    |
+----+----+----+
| wX |    |    |
+----+----+----+
|    |    | rY |
+----+----+----+
|    | rY |    |
+----+----+----+
|    | wY |    |
+----+----+----+
|    |    | rZ |
+----+----+----+
|    | rX |    |
+----+----+----+
|    | rZ |    |
+----+----+----+
| wX |    |    |
+----+----+----+
| rY |    |    |
+----+----+----+
|    |    | wY |
+----+----+----+
|    | wX |    |
+----+----+----+
| rX |    |    |
+----+----+----+
|    |    | wX |
+----+----+----+
|    | wZ |    |
+----+----+----+
|    |    | wZ |
+----+----+----+
```

Resolução:

```
+----+----+----+
| T1 | T2 | T3 |
+----+----+----+
| rX |    |    |
+----+----+----+
| wX |    |    | -+
+----+----+----+  |-> Conflito
|    | rX |    | -+
+----+----+----+
| wX |    |    |
+----+----+----+
| rX |    |    | -+
+----+----+----+  |-> Conflito
|    | wX |    | -+
+----+----+----+  |-> Conflito
|    |    | wX | -+
+----+----+----+
|    |    | rY |
+----+----+----+
|    | rY |    | -+
+----+----+----+  |-> Conflito
|    | wY |    | -+
+----+----+----+  |-> Conflito
| rY |    |    | -+
+----+----+----+  |-> Conflito
|    |    | wY | -+
+----+----+----+
|    |    | rZ | -+
+----+----+----+  |
|    | rZ |    |  |-> Conflito
+----+----+----+  |
|    | wZ |    | -+
+----+----+----+  |-> Conflito
|    |    | wZ | -+
+----+----+----+
```

Ele não é serial de conflito, pois não consigo formar 3 transações seriais sem ter algum conflito entre os dados


2. Dado o schedule a seguir, prove, elaborando o gráfico de precedência, se ele é ou não serial de conflito

```
+----+----+----+----+
| T1 | T2 | T3 | T4 |
+----+----+----+----+
| rX |    |    |    |
+----+----+----+----+
| wX |    |    |    |
+----+----+----+----+
|    |    | rY |    |
+----+----+----+----+
|    | rY |    |    |
+----+----+----+----+
|    | wY |    |    |
+----+----+----+----+
|    |    | rZ |    |
+----+----+----+----+
|    | rX |    |    |
+----+----+----+----+
|    |    |    | rX |
+----+----+----+----+
| wX |    |    |    |
+----+----+----+----+
| rY |    |    |    |
+----+----+----+----+
|    |    | wY |    |
+----+----+----+----+
|    |    |    | wX |
+----+----+----+----+
| rX |    |    |    |
+----+----+----+----+
|    |    | wX |    |
+----+----+----+----+
|    |    |    | wX |
+----+----+----+----+
|    |    | wZ |    |
+----+----+----+----+
```

Resolução:

```
+----+----+----+----+
| T1 | T2 | T3 | T4 |
+----+----+----+----+
| rX |    |    |    |
+----+----+----+----+
| wX |    |    |    |
+----+----+----+----+
|    | rX |    |    |
+----+----+----+----+
|    |    |    | rX |
+----+----+----+----+
| wX |    |    |    |
+----+----+----+----+
|    |    |    | wX |
+----+----+----+----+
| rX |    |    |    |
+----+----+----+----+
|    |    | wX |    |
+----+----+----+----+
|    |    |    | wX |
+----+----+----+----+
|    |    | rY |    |
+----+----+----+----+
|    | rY |    |    |
+----+----+----+----+
|    | wY |    |    |
+----+----+----+----+
| rY |    |    |    |
+----+----+----+----+
|    |    | wY |    |
+----+----+----+----+
|    |    | rZ |    |
+----+----+----+----+
|    |    | wZ |    |
+----+----+----+----+
```

Criando o grafo:

```
           +----+
   +------ | T1 | <-----+
   |       +----+       |
   v         ^          v
+----+       |        +----+
| T3 | <-----+------> | T2 |
+----+       |        +----+
   ^         v
   |       +----+
   +-----> | T4 |
           +----+
```

Como o grafo é circular, o schedule não é um serial de conflito

3. Dado o schedule a seguir, verifique se ele é serial de visão.

```
+----+----+----+
| T1 | T2 | T3 |
+----+----+----+
| rX |    |    |
+----+----+----+
| wX |    |    |
+----+----+----+
|    |    | rY |
+----+----+----+
|    | rY |    |
+----+----+----+
|    | wY |    |
+----+----+----+
|    |    | rZ |
+----+----+----+
|    | rX |    |
+----+----+----+
|    | rZ |    |
+----+----+----+
| wX |    |    |
+----+----+----+
| rY |    |    |
+----+----+----+
|    |    | wY |
+----+----+----+
|    | wX |    |
+----+----+----+
| rX |    |    |
+----+----+----+
|    |    | wX |
+----+----+----+
|    | wZ |    |
+----+----+----+
|    |    | wZ |
+----+----+----+
```

Resolução:

```
+----+----+----+
| T1 | T2 | T3 |
+----+----+----+
| rX |    |    |
+----+----+----+
| wX |    |    |
+----+----+----+
|    | rX |    |
+----+----+----+
| wX |    |    |
+----+----+----+
| rX |    |    |
+----+----+----+
|    | wX |    |
+----+----+----+
|    |    | wX |
+----+----+----+
|    |    | rY | -+
+----+----+----+  |-> Estraga Serialização de visão (?)
|    | rY |    | -+
+----+----+----+
|    | wY |    |
+----+----+----+
| rY |    |    |
+----+----+----+
|    |    | wY |
+----+----+----+
|    |    | rZ |
+----+----+----+
|    | rZ |    |
+----+----+----+
|    | wZ |    |
+----+----+----+
|    |    | wZ |
+----+----+----+
```


4. O que é um `schedule recuperável`? Dẽ um exemplo

Um schedule recuperável é aquele em que, para cada part de transações $T_{i}$ e $T_{j}$, tal que $T_{j}$ leia um item de dados previamente escrito por $T_{j}$, a operação commit de $T_{i}$ aparee antes da operação commit de $T_{i}$

5. Dê um exemplo de `schedule em cascata`. Qual é o problema deste tipo de schedule

Um exemplo de schedule em cascata pode ser:

```
+----+----+----+
| T1 | T2 | T3 |
+----+----+----+
| rA |    |    |
+----+----+----+
| rB |    |    |
+----+----+----+
| wA |    |    |
+----+----+----+
|    | rA |    |
+----+----+----+
|    | wA |    |
+----+----+----+
|    |    | rA |
+----+----+----+
```

Nesse caso a transação T2 depende da transação T1 e a transação T3 depende da transação T2 que é considerado um schedule em cascata. O problema desse tipo de schedule é que caso ocorra uma falha na transação T1 a transação T2 e a transação T3 terão de ser canceladas assim acabam tendo trabalho desperdiçados.
