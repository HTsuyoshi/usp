# Lista Processamento de Consultas

1. Defina plano de execução da consulta. Dê um exemplo.

O plano de execução da consulta é uma sequência de operações primitivas (`Avaliações Primitivas`) que podem ser usados para avaliar a consulta

Um exemplo de plano de execução de consulta seria pegar todos as pessoas com mais de 18 anos de uma tabela de usuarios não ordenada. No exemplo abaixo é usado o índice primário para selecionar todas as pessoas com idade acima de 18 anos:

```
saldo
 |
 |
idade < 18; usar índice primário
 |
 |
pessoa
```

2. Suponha a consulta $$ \sigma_{nomeMusica = "Andança"} \sigma_{intérprete = "Beth Carvalho"} $$ (Musica). Considere que a tabela Musica está organizada por código da música e que existe um índice primário esparso e outro índice secundário por intérprete. Apresente três diferentes planos de execução de consulta para a expressão fornecida.

- Planos de Execução de Consulta 1:

Na consulta do intérprete pode ser feita uma busca binária

Na consulta do nome da música pode ser feita uma busca sequencial no resultado da consulta dos intérpretes

- Planos de Execução de Consulta 2:

Na consulta do intérprete pode ser feita uma busca sequencial

Na consulta do nome da música pode ser feita uma busca sequencial no resultado da consulta dos intérpretes

- Planos de Execução de Consulta 3:

Na consulta do intérprete pode ser feita uma busca com índice secundário

Na consulta do nome da música pode ser feita uma busca sequencial no resultado da consulta dos intérpretes

3. Suponha a consulta $$ \sigma_{nomeMusica = "Andança"} \sigma_{intérprete = "Beth Carvalho"} $$ (Musica). Considere que a tabela Musica está organizada por código da música e que existe um índice primário esparso ordenado (n = 30) e outro índice secundário por intérprete (n = 40)

- Apresente três diferentes planos de execução de consulta para a expressão dada

Repitido (?)

- Calcule o custo total de cada plano de consulta, considerando $$ N_{musica} = 10000}, V(nomeMusica, Musica) = 3000, V(interprete, Musica) = 1000 $$.

	- Consulta 1:

O Custo Total de uma `Busca Binária (A2)` é dado por:

$$ E_{A2} = log_{2}(b_{r}) + [\frac{SC(A,r)}{f_{r}}] - 1 $$

$$ E_{A2} = log_{2}(b_{r}) + [\frac{\frac{10000}{1000}}{40}] - 1 $$

$$ E_{A2} = log_{2}(b_{r}) + [\frac{10}{40}] - 1 $$

$$ E_{A2} = log_{2}(b_{r}) + [\frac{1}{4}] - 1 $$

$$ E_{A2} = log_{2}(b_{r}) + 1 - 1 $$

$$ E_{A2} = log_{2}(\frac{10000}{30}) + 1 - 1 $$

$$ E_{A2} = log_{2}(\frac{1000}{3}) + 1 - 1 $$

$$ E_{A2} = 9 $$

O Custo Total de uma `Busca Linear (A1)` é dado por:

$$ E_{A1} = \frac{b_{r}}{30} $$

$$ E_{A1} = \frac{\frac{10000}{3000}}{30} $$

$$ E_{A1} = \frac{\frac{10}{3}}{30} $$

$$ E_{A1} = \frac{10}{90} $$

$$ E_{A1} = \frac{1}{9} $$

$$ E_{A1} = 1 $$

	- Consulta 2:

O Custo Total de uma `Busca Linear (A1)` é dado por:

	- Consulta 3:

O Custo Total de uma `Busca Binária (A2)` é dado por:

3. Analise os resultados e explique qual é o melhor plano, justificando sua resposta

4. Suponha a consulta numeroAluno = "123456" (Aluno) e que a relação Aluno está ordenada fisicament por número do aluno. Qual é o custo a consulta para busca linear e busca binária, sabendo que o número do aluno é chave primária? Se houver um índice primário (ordenado) com n = 20 qual seria o custo da consulta usando esse índice?

Considerando que:

$$ SC(A,r) = 1 $$

- Busca Sequencial (A1):

$$ E_{A2} = \frac{b_{r}}{2} $$

$$ E_{A2} = \frac{\frac{200000}{40}}{2} $$

$$ E_{A2} = 2500 $$

Seria no máximo o custo de 2500 blocos

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1$$

$$ E_{A2} = \lceil log_{2}(5000) \rceil + \lceil \frac{1}{40} \rceil - 1$$

$$ E_{A2} = \lceil log_{2}(5000) \rceil $$

$$ E_{A2} = 13 $$

Considerando `n = 10`:

- Busca Primária de Chave Única (A3):

$$ E_{A3} = HT_{i} + 1 $$

$$ E_{A3} = \lceil log_{\frac{20}{2}}(200000) \rceil + 1 $$

$$ E_{A3} = \lceil log_{10}(200000) \rceil + 1 $$

$$ E_{A3} = 6 + 1 $$

$$ E_{A3} = 7 $$

5. Suponha que para o cálculo da consulta nomeAluno =”John Lennon”(Aluno) haja um índice árvore-B+ primário para o atributo nomeAluno, com n=10. Considerando os dados fornecidos no final da lista, calcule o custo para a busca linear, busca binária e busca com índice, considerando que nomeAluno não é chave única.

- Busca Linear (A1):

$$ E_{A1} = b_{r} $$

$$ E_{A1} = \frac{200000}{40} $$

$$ E_{A1} = 5000 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(200000) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1$$

$$ E_{A2} = \lceil log_{2}(200000) \rceil + \lceil \frac{\frac{200000}{100000}}{40} \rceil - 1$$

$$ E_{A2} = \lceil log_{2}(200000) \rceil + \lceil \frac{2}{40} \rceil - 1$$

$$ E_{A2} = \lceil log_{2}(200000) \rceil $$

$$ E_{A2} = \lceil log_{2}(200000) \rceil $$

$$ E_{A2} = 18 $$

- Busca Índice Chave não Única (A4):

$$ E_{A4} = HT_{i} + \lceil \frac{SC(A,r)}{f_{r}} \rceil $$

$$ E_{A4} = \lceil log_{\frac{10}{2}}(200000) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil $$

$$ E_{A4} = \lceil log_{5}(200000) \rceil + \lceil \frac{2}{40} \rceil $$

$$ E_{A4} = 8 + 1 $$

$$ E_{A4} = 9 $$

6. Suponha que para o cálculo da consulta nomeAluno = ”John Lennon” (Aluno) haja um índice árvore-B+ primário para o atributo nomeAluno, com n=20. Calcule o custo para a busca linear, busca binária e busca com índice, considerando que nomeAluno é chave única.

- Busca Sequencial (A1):

$$ E_{A1} = \frac{\frac{200000}{40}}{2} $$

$$ E_{A1} = 2500 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1 $$

$$ E_{A2} = \lceil log_{2}(\frac{200000}{40}) \rceil $$

$$ E_{A2} = \lceil log_{2}(5000) \rceil $$

$$ E_{A2} = 13 $$

- Busca Primária de Chave Única (A3):

$$ E_{A3} = HT_{i} + 1 $$

$$ E_{A3} = \lceil log_{\frac{20}{2}}(200000) \rceil + 1 $$

$$ E_{A3} = \lceil log_{10}(200000) \rceil + 1 $$

$$ E_{A3} = 5 + 1 $$

$$ E_{A3} = 6 $$

7. Suponha que para o cálculo da consulta σcidadeAluno =”Fortaleza”(Aluno) haja um índice árvore-B secundário para o atributo cidade, com n=30. Calcule o custo para a busca linear e busca com índice, considerando que cidadeAluno não é chave única.

- Busca Sequencial (A1):

$$ E_{A1} = \frac{200000}{40} $$

$$ E_{A1} = 5000 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1 $$

$$ E_{A2} = \lceil log_{2}(5000) \rceil + \lceil \frac{\frac{200000}{500}}{40} \rceil - 1 $$

$$ E_{A2} = 13 + \lceil \frac{400}{40} \rceil - 1 $$

$$ E_{A2} = 13 + \lceil 10 \rceil - 1 $$

$$ E_{A2} = 13 + 9 $$

$$ E_{A2} = 22 $$

- Busca Secundária de Chave não Única (A5):

$$ E_{A5} = HT_{i} + 1 $$

$$ E_{A3} = \lceil log_{\frac{30}{2}}(200000) \rceil + 1 $$

$$ E_{A3} = \lceil log_{15}(200000) \rceil + 1 $$

$$ E_{A3} = 4 + 1 $$

$$ E_{A3} = 5 $$

8. Suponha que para o cálculo da consulta σnomeAluno >=”Valeska Popozuda”(Aluno) haja um índice árvore-B+ primário para o atributo nomeAluno, com n=20. Calcule o custo para a busca linear e busca com índice, considerando que nomeAluno não é chave única.

- Busca Sequencial (A1):

$$ E_{A1} = \frac{200000}{40} $$

$$ E_{A1} = 5000 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1 $$

$$ E_{A2} = \lceil log_{2}(5000) \rceil + \lceil \frac{\frac{200000}{100000}}{40} \rceil - 1 $$

$$ E_{A2} = 13 + \lceil \frac{2}{40} \rceil - 1 $$

$$ E_{A2} = 13 $$

- Comparação Primária de Chave não Única (A6):

$$ E_{A5} = HT_{i} + \frac{b_{r}}{2} $$

$$ E_{A3} = \lceil log_{\frac{20}{2}}(200000) \rceil + frac{5000}{2} $$

$$ E_{A3} = \lceil log_{10}(200000) \rceil + 2500 $$

$$ E_{A3} = 5 + 2500 $$

$$ E_{A3} = 2505 $$

9. Suponha que para o cálculo da consulta σnomeAluno >=”Valeska Popozuda”(Aluno) haja um índice árvore-B+ secundário para o atributo nomeAluno, com n=20. Calcule o custo para a busca linear e busca com índice, considerando que nomeAluno é chave única.

- Busca Sequencial (A1):

$$ E_{A1} = \frac{200000}{40} $$

$$ E_{A1} = 5000 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1 $$

$$ E_{A2} = \lceil log_{2}(5000) \rceil + \lceil \frac{\frac{200000}{100000}}{40} \rceil - 1 $$

$$ E_{A2} = 13 + \lceil \frac{2}{40} \rceil - 1 $$

$$ E_{A2} = 13 $$

- Comparação de índice Secundária de Chave não Única (A7):

$$ E_{A7} = HT_{i} + \frac{LB_{i}}{2} + \frac{n_{r}}{2} $$

$$ E_{A7} =  \lceil log_{\frac{20}{2}}(200000) \rceil + \frac{\frac{100000}{\frac{20}{2}}}{2} + \frac{200000}{2} $$

$$ E_{A7} =  \lceil log_{\frac{20}{2}}(200000) \rceil + \frac{\frac{100000}{10}}{2} + \frac{200000}{2} $$

$$ E_{A7} =  \lceil log_{\frac{20}{2}}(200000) \rceil + \frac{10000}{2} + \frac{200000}{2} $$

$$ E_{A7} =  \lceil log_{\frac{20}{2}}(200000) \rceil + 5000 + \frac{200000}{2} $$

$$ E_{A7} = 5 + 5000 + 100000 $$

$$ E_{A7} = 105005 $$

10. Suponha que para o cálculo da consulta nomeAluno < ”John Lennon”(Aluno) haja um índice árvore-B+ secundário para o atributo nomeAluno, com n=10. Calcule o custo para a busca linear e busca com índice, considerando que nomeAluno não é chave única.

- Busca Sequencial (A1):

$$ E_{A1} = \frac{200000}{40} $$

$$ E_{A1} = 5000 $$

- Busca Binária (A2):

$$ E_{A2} = \lceil log_{2}(b_{r}) \rceil + \lceil \frac{SC(A,r)}{f_{r}} \rceil - 1 $$

$$ E_{A2} = 13 $$

- Busca Secundária de Chave não Única (A7):

$$ E_{A7} = HT_{i} + \frac{LB_{i}}{2} + \frac{n_{r}}{2} $$

$$ E_{A7} = \lceil log_{\frac{20}{2}}(200000) \rceil + \frac{\frac{100000}{\frac{20}{2}}}{2} + \frac{200000}{2} $$

$$ E_{A7} = \lceil log_{10}(200000) \rceil + \frac{10000}{2} + 100000 $$

$$ E_{A7} = \lceil log_{10}(200000) \rceil + 5000 + 100000 $$

$$ E_{A7} = 5 + 5000 + 100000 $$

$$ E_{A7} = 105005 $$

11. Suponha que para o cálculo de consulta nomeAluno < ”John Lennon” ^ media > 7 (Aluno) haja um índice árvore-B+ primário para o atributo nomeAluno, com n=10 (chave não é única) e um índice secundário para média (chave não é única), com n=20:

- Apresente quatro diferentes planos de execução de consulta para a expressão dada

	- Consulta 1:

```
a
```

	- Consulta 2:

```
a
```

	- Consulta 3:

```
a
```

	- Consulta 4:

```
a
```

- Calcule o custo total de cada plano de consulta

	- Consulta 1:

	- Consulta 2:

	- Consulta 3:

	- Consulta 4:

- Análise os resultados e explique qual é o melhor plano, justificando sua resposta.

12. Considerando os dados disponibilizados no final da lista e sabendo que cabem 21 blocos na memória da máquina, qual é o custo para classificar a Relação aluno usando o algoritmo sort-merge-externo?

$$ E = b_{r}(2 |log_{M-1}(\frac{b_{r}}{M})| + 1)$$

$$ E = \frac{200000}{40}(2 \lceil log_{21-1}(\frac{\frac{200000}{40}}{21}) \rceil + 1)$$

$$ E = 5000(2 \lceil log_{21-1}(\frac{5000}{21}) \rceil + 1)$$

$$ E = 5000(16 + 1)$$

$$ E = 5000 \times 17$$

$$ E = 85000 $$
