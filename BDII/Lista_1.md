# Lista de exercícios n°1

1. Quais os princípais tipo de tecnologia de armazenamento de dados existentes atualmente? Ordene-os em relação ao seu custo.

```
Os principais tipos de tecnologia de armazenamento de dados existentes atualmente, ordenados na ordem decrescente de seu custo são:

- Memória Cache
- Memória Principal
- Memória Flash
- Disco magnético
- Disco Óptico
- Fita magnética
```

2. Como pode ser medido o desempenho de um disco magnético considerando o contexto de bancos de dados que armazenam grandes volumes de informações?

```
O desempenho de um disco magnético pode ser medido pelos seguintes fatores:

- Capacidade
- Custo
- Volatilidade
- Velocidade
- Falhas

Dar uma olhada
```

3. Defina setor e bloco no contexto de bancos de dados. Explique porque esses conceitos são importantes na modelagem de um banco de dados relacional.

```
Setores são a menor unidade que podem ser lidas ou escritas no disco. Seu tamanho pode variar mas são tipicamente de 512 bytes

Blocos são unidades lógicas com um número fixo de setores contíguos e é a menor unidade de transferência entre memória principal e disco. Seu tamanho pode variar de 512 bytes a váios Kb.

Na criação de tabelas o tamanho do bloco deve ser levado em consideração, utilizando o menor número de blocos vazios, evitando espaços vazios e para criar registros do tamanho certo e dessa forma evitar leituras de blocos desnecessárias.
```

4. Defina RAID e explique os níveis existentes.

```
Os RAIDs são formas de armazenar os mesmos dados em diferentes lugares (Usando vários discos) e tem o objetivo de proteger dados em caso de falha.

No RAID nível 0 existe um espalhamento, uma distribuição paralela sem redundância.

No RAID nível 1 são discos espalhados.

No RAID nível 2 existem discos para armazenar bits de paridade. Responsabilidade de bits de paridade é a de sistema de memória.

No RAID nível 3 existe a paridade intercalada por bit. Responsabilidade do controlador de disco. Um só bit de paridade. Mais barato que o nível 2.

No RAID nível 4 existe a paridade intercalada por Bloco.

No RAID nível 5 existe a paridade distribuída intercalada por bloco. Tendo melhor desempenho de leitura-escrita do que nível 4.

No RAID nível 6 redundância P + Q. Armazena duas funçoes de paridade. Consequência: dois discos dedicados. Assegura segurança no caso de avariar 2 discos simultaneamente.
```

5. Explique a organização sequencial de registros em arquivos e cite os problemas dessa organização. Explique como ocorre a busca neste tipo de organização de registros quando são usados índices ordenados secundários.

```
A organização sequencial acontece com registros de tamanhos fixos localizados sequencialmente na memória, os problemas podem ser manter a ordem física após muitas inserções e exclusões e geralmente as inserções são feitas em bloco de estouro.

A busca nesse tipo de organização quando são usados índices ordenados segundários pode ser feita de forma sequencial
```

6. Que fatores devem ser considerados para tomar a decisão de criar um índice em um banco de dados?

```
Os fatores que devem ser considerados para tomar a decisão de criar um índice em um banco de dados são:

- Tipos de acesso: Encontrar registros com atributo que possui um certo valor; encontrar registros com atributos dentro de uma faixa de valores etc;

- Tempo de acesso: Tempo gasto para encontrar um item em particular ou um conjunto de itens;

- Tempo de inserção: Tempo gasto para incluir um novo item (tempo para encontrar o lugar correto e atualizar a estrutura do índice);

- Tempo de exclusão: Tempo gasto para excluir um item (tempo para encontrar o item a ser excluído e atualizar a estrutura de índice);

- Sobrecarga de espaço: Espaço adicional ocupado por uma estrutura de índice (analisar custo e benefício para se manter um índice);
```

7. Diferencie índice primário de índice secundário. Dê um exemplo.

```
As diferenças entre o índice primário e o índice secundário são:

O Índice primário:

- É o índice cuja chave de procura especifica a ordem sequencial (física) do arquivo

- A chave de procura em geral é a chave primária, mas nem sempre isso ocorre - é errôneo utilizar o termo índice primário para designar um índice de chave primária

- Também chamado de índice agrupado ou índice de agrupamento

O Índice secundário:

- As chaves de procura especificam uma ordem diferente da ordem sequencial (física) do arquivo

- Também chamados de índices não agrupados ou índices de não agrupamento
```

8. Diferencie índice denso de índice esparso. Cite suas vantagens e desvantagens. Dê um exemplo.

```
Índice denso:

- Um registro de índice (ou entrada de índice) para cada valor de chave de procura

- Registro contém chave e ponteiro para o primeiro registro com a chave de busca

- Demais registros com mesma chave são armazenados sequencialmente após o primeiro registro

Vantagens:

	- Mais rápido

Desvantagens:

	- Ocupa mais espaço

	- Pior para manutenção para inserções e exclusões

Índice esparso:

- Um registro de índice é criado apenas para alguns valores

- Cada registro de índice contém um valor de chave de procura e um ponteiro para o primeiro registro de dados com esse valor chave de procura

- Para localizar um registro:

	- Encontra-se entrada de índice com maior valor chave de procura que seja menor ou igual ao valor chave de procura desejado

	- Inicia-se no registro apontado pela entrada de índice e segue-se os ponteiros até encontrar o registro desejado

Vantagens:

	- Menos espaço

	- Menos sobrecarga de manutenção para inserções e exclusões

Desvantagens:

	- Mais lento
```

9. O que são índices multiníveis? Dê um exemplo.

```
i
```

10. Explique como ocorre a localização de um registro em um índice multinível. Dê um exemplo.

Considere o arquivo de dados abaixo , organizado sequencialmente, para responder as questões a seguir.


Código | Crédito | Nome    | Cidade
-- | -- | -- | -- |
3      | 2000    | Antonio | Araraquara
4      | 3000    | Beatriz | São Paulo
6      | 5000    | Claudia | Recife
5      | 1000    | Claudia | Recife
9      | 1500    | Lucas   | São Paulo
10     | 2500    | Marina  | Lins
12     | 3000    | Marina  | Araraquara
11     | 4000    | Marina  | Macatuba
13     | 2500    | Mirtes  | Lins
2      | 3000    | Valter  | Araraquara
1      | 4000    | Valter  | Macatuba
7      | 3500    | Tarso   | Recife
8      | 3500    | Tarso   | São Paulo

11. Construa um índice primário ordenado denso.

Feito

12. Construa um índice primário ordenado esparso. Considere que em cada bloco cabem 3 registros de dados.

Feito

13. Construa um índice ordenado secundário para o atributo nome.

14. Construa um índice ordenado secundário para o atributo cidade.

15. Construa um índice ordenado primário esparso multinível. Considere que em cada bloco cabem 2 registros de dados e 3 registros de índice.

16. Construa um índice ordenado secundário multinível para o atributo cidade. Considere que em cada bloco cabem 3 registros de dados e 4 registros de índice.

17. Construa um índice usando árvore B+ com n=3 tendo o atributo nome como chave de procura.

a. Apresente a árvore resultante após a inclusão do nome “Manoel” na árvore criada.

b. Apresente a árvore resultante após a exclusão do nome “Lucas” da árvore criada no item a).

18. Construa um índice secundário usando árvore B+ para o atributo cidade com n=5.

a) Apresente a árvore resultante após a exclusão da cidade Araraquara.

b) Apresente a árvore resultante após a inclusão do seguinte registro de dados.

25 6000 Carlos São Paulo

Comentário [A1]: Como fazer:

1)Achar qtde de folhas = (qtde chaves/(n-1))
2)Preencher folhas
3)Achar qtede de nós nível anterior de acordo com qtde folhas. Qtde nós internos nível anterior = (qtde folhas)/n (precisa ter número de ponteiros suficientes para apontar pras folhas)
4)Primeira chave do nó (exceção do primeiro nó) vai preencher nó interno do nível anterior

19. Que considerações deveriam ser feitas em relaçao à criação do índice da questão anterior para que fosse possível construí-lo como índice ordenado esparso? Neste caso, como seria a inclusão da tupla do item (b)?

```
```

20. Construa um índice usando árvore B+ para o atributo cidade com n=3.

21. Construa um índice usando árvore B para o atributo cidade com n=3.

22. Construa um índice usando árvore B+ para o atributo código com n=5.

23. Construa um índice usando árvore B para o atributo crédito com n=5.

24. Considerando que cada ponteiro ocupa 8 bytes e o tamanho do bloco de disco é 4 Kbytes, calcule considerando os dados apresentados anteriormente (a menos que algo diferente seja especificado):

a. O tamanho ideal do nó (n) para um índice usando árvore B+ para o atributo cidade. Considere que cada cidade é armazenada em 30 bytes.

b. O tamanho ideal do nó (n) para um índice usando árvore B+ para o atributo nome. Considere que cada nome é armazenado em 50 bytes.

c. O tamanho ideal do nó (n) para um índice usando árvore B+ para o atributo código. Considere que cada código é armazenado em 8 bytes.

d. A altura da árvore considerando n = 20 para um índice usando árvore B+ para o atributo nome. Considere que há 60 mil nomes diferentes armazenados no arquivo.

e. A altura da árvore considerando n = 40 para um índice usando árvore B+ para o atributo cidade. Considere que há 20 mil cidades diferentes armazenadas no arquivo.

f. A altura da árvore considerando n = 100 para um índice usando árvore B+ para o atributo código. Considere que o código é chave primária e há 2 milhões de registros armazenados no arquivo.

25. Apresente como os registros poderiam estar armazenados usando hash, considerando uma função hash para o atributo nome e considerando 5 buckets.

26. Apresente como os registros poderiam estar armazenados usando hash, considerando uma função hash para o atributo cidade e considerando 10 buckets.

27. Apresente como os registros poderiam estar armazenados usando hash, considerando uma função hash para o atributo código e considerando 20 buckets.

28. Apresente um índice hash secundário para o atributo crédito considerando que o arquivo está armazenado sequencialmente por código.

29. Apresente um índice hash secundário para o atributo nome considerando que o arquivo está armazenado sequencialmente por código.

30. Apresente passo-a-passo, a construção de um um índice hash extensível para o atributo cidade. Considere a ordem apresentada dos registros para inseri-los (um a cada passo) na estrutura de índice, expandindo a quantidade de buckets quando necessário. Defina a função hash e o tamanho da chave (em bits) gerada por esta função.

Comentário [A2]: Para definer qtde
nós totais (não só folhas) árvore B:
Qtde chaves diferentes q (n-1)
Folhas: colocar valores de chaves a cada n
valores:
Ex: coloca primeiro, segundo, pula 3 (n=3),
4º., 5º., pula 6º. (esses que pula irão
compor os nós dos níveis internos
