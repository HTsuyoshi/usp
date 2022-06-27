# Lista Processamento de Consultas

1. Defina plano de execução da consulta. Dê um exemplo.

Plano de execução da consulta é uma sequência de Avaliações Primitivas.

Um exemplo de plano de execução de consulta seria pegar todos as pessoas com mais de 18 anos de uma tabela de usuarios.

```
idade < 18; use índice 1
 |
 |
saldo
 |
 |
pessoa
```

2. Suponha a consulta $$ _{nomeMusica = "Andança"} _{intérprete = "Beth Carvalho"} $$ (Musica). Considere que a tabela Msuica está organizada por código da música e que existe um índice primário esparso e outro índice secundário por intérprete. Apresente três diferentes planos de execução de consulta para a expressão fornecida.

- Consulta 1:

A primeira consulta pode ser feita usando o índice primário da música e fazendo uma busca sequencial até encontrar a música desejada.


- Consulta 2:

A segunda consulta pode ser feita usando o índice secundário por intérprete e fazer uma busca sequencial até chegar no intérprete ou até passar do intérprete

- Consulta 3:

A terceira consulta pode ser feita usando o índice secundário por intérprete e fazer uma busca binária

3. Suponha a consulta $$ _{nomeMusica = "Andança"} _{intérprete = "Beth Carvalho"} $$ (Musica). Considere que a tabela Msuica está organizada por código da música e que existe um índice primário esparso ordenado (n = 30) e outro índice secundário por intérprete (n = 40)

	1. Apresente três diferentes planos de execução de consulta para a expressão dada

Repitido (?)

	2. Calcule o custo total de cada plano de consulta, considerando $$ N_{musica} = 10000}, V(nomeMusica, Musica) = 3000, V(interprete, Musica) = 1000 $$.

- Consulta 1:

O Custo Total de uma `Busca Linear (A1)` é dado por:

$$ E_{A1} = b_{r} $$

$$ E_{A1} = b_{r} $$

- Consulta 2:

O Custo Total de uma `Busca Linear (A1)` é dado por:

- Consulta 3:

O Custo Total de uma `Busca Binária (A2)` é dado por:

	3. Analise os resultados e explique qual é o melhor plano, justificando sua resposta

4. Suponha a consulta numeroAluno = "123456" (Aluno) e que a relação Aluno está ordenada fisicament por número do aluno. Qual é o custo a consulta para busca linear e busca binária, sabendo que o número do aluno é chave primária? Se houver um índice primário (ordenado) com n = 20 qual seria o custo da consulta usando esse índice?

Considerando que:

$$ SC(A,r) = 1$$

- Busca Sequencial (A1):

$$ E_{A2} = b_{r} $$

$$ E_{A2} = \frac{200000}{40} $$

$$ E_{A2} = 5000 $$

Seria no máximo o custo de 5000 blocos

- Busca Binária (A2):

$$ E_{A2} = [log_{2}(b_{r})] + [\frac{SC(A,r)}{f_{r}}] - 1$$

$$ E_{A2} = [log_{2}(5000)] + [\frac{1}{40}] - 1$$


5. Suponha que para o cálculo da consulta nomeAluno = "John Lennon" (Aluno) haja um índice árvore-B+ primário para o atributo nomeAluno, com n = 10. Considerando os dados fornecidos no final da lista, calcule o custo para a busca linear, busca binária e busca com índice, considerando que nomeAluno não é chave única.

6. Suponha que para o cálculo da consulta nomeAluno = "John Lennon" (Aluno) haja um íncide árvore-B+ primário para o atributo nomeAluno, com n = 20. Calcule o custo para a busca linear e usca com índice, considerando que cidadeAluno não é chave única.

7. Suponha que para o cálculo da consulta 

