# Lista 1

1. Temporizadores (clocks) em diferentes computadores podem ficar fora de sincronia, por estes oscilarem a taxas levemente diferentes. Que nome damos à diferença observada quando da leitura de dois clocks?

```
O nome que damos a diferença observada quando da leitura de dois clocks é dada por Clock skew.
```

2. Para determinar o horário atual, um processo pode acessar um servidor de tempo (em outra máquina). O problema, então, é como incluir no cálculo o tempo gasto no envio, processamento, e devolução da requisição feita. Nesse sentido, que protocolo é usado para estimar o atraso de tempo entre duas máquinas?

```
O protocolo que é usado para estimar o atraso de tempo entre duas máquinas é o protocolo NTP (Network Time Protocol).
```

3. Quando sincronizamos os clocks (de fato, seus contadores) de dois computadores, uma possibilidade é adiantarmos o clock do mais atrasado. Por que não podemos atrasar o clock do mais adiantado, ou seja, por que não podemos fazer ele “voltar no tempo”?

```
Não podemos atrasar o clock do mais adiantado, pois isso poderia criar um risco de ter um arquivo com uma data anterior à sua fonte.
```

4. Quando sincronizamos a clock (de fato, seu contador) de um computador em relação a alguma referência, não podemos reduzir seu valor, ou seja, não podemos “voltar no tempo”. Como fazer então se o clock desse computador estiver à frente do clock de referência?

```
Caso o clock desse computador estiver a frente do clock de referência o clock deve ser desacelerado até que a redução desejada seja gradualmente atingida.
```

5. Dos algoritmos de exclusão mútua vistos (centralizado, distribuı́do (Ricart & Agrawala), token ring e descentralizado), qual funciona mesmo quando a identidade dos membros do grupo não é conhecida a priori?

```
Não tenho certeza.

Dos algoritos de exclusão mútua, o algoritmo que funciona mesmo quando a identidade dos membros do grupo não é conhecida é o algoritmo de comparação
```

6. Comparando o algoritmo de exclusão mútua centralizado, visto em sala, com o algoritmo distribuı́do proposto por Ricart & Agrawala, qual deles é mais eficiente e mais tolerante a falhas?

```
Não tenho certeza.

Comparando o algoritmo de exclisão mútua centralizado e o algoritmo distribuído proposto por Ricard & Agrawala, o mais eficiente e mais tolerante a falhas é o algoritmo distribuído! Pois no algoritmo centralizado, caso o coordenador caia os outro processos não vão conseguir se comunicar entre si, enquanto no algoritmo distribuído é possivel continnuar se comunicando com outros processos. E o algoritmo centralizado precisa executar todos os processos um de cada vez, dessa forma criando um gargalo de entrada e saída, diferente do algoritmo centralizado o algoritimo distribuído vai dividir todo esse trabalho para muitos outros processos, dessa forma criando uma eficiência maior.
```

7. Descreva o funcionamento do algoritmo de eleição de bully.

O algorito de bully se inicia quando algum processo percebe que o coordenador não está mais respondendo a requisições.

O processo que vai começar a eleição é chamado de $$P_{k}$$ e envia uma mensagem ELECTION para todos os processos com identificadores maior que o seu:

$$ P_{k+1}, P_{k+2}, \dots, P_{N-1} $$

Se ninguém responder, $$ P_{k} $$ ganha a eleição e se torna o coordenador

Se um dos seus nós com maior id responder, esse assume

- A elleição e o trabalho de $$ P_{k} $$ termina

- O maior sempre ganha, por isso o nome de "Algoritmo do valentão"

Depois que o processo estiver pronto para assumir, anuncia a sua liderança para todos os outros processos.

8. Descreva o funcionamento do algoritmo de eleição em anel.

A prioridade dos processos é obtida organizando-os em um anel lógico

- O processo com maior prioridade deve ser eleiot coordenador

Quando um processo nota que o coordenador caiu, constrói uma mensagem de eleiç~ao, contendo seu id

- Envia então a mensagem ao seu sucessor

- Se um sucessor estiver indisponível, a mensagem é enviada ao próximo sucessor, e assim por diante

Se uma mensagem for repassada, o novo remetente adiciona seu id a ela, enviando-a ao seu sucessor

- Os ids são adicionados a uma lista, registrando por onde a mensagem parou

- Quando a mensagem volta ao nó que iniciou, todos tiveram a chance de anunciar a sua presença

O nó inicial reconhece que a mensgaem voltou quando vê seu id na lista de identificadores

O tipo da mensagem é então mudado para COORDINATOR e circulada novamente

- Conterá assim uma lista dos processos vivos

- Serve para informar a todos quem é o coordenador (o membro da lista com maior id) e quais são os membros do novo anel

Uma vez que essa mensagem tenha circulado, ela é removida, e todos voltam ao trabalho
