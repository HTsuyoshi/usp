# Lista 3

<br>

1. Considerando o modelo ISO-OSI, em qual camada se encaixa o IP (Internet Protocol)?

    O Internet Protocol se encaixa na camada de rede.
    
<br>

2. Quais as camadas do modelo OSI, e qual o propósito de cada uma?

- Camada de Aplicação: Tornou-se o lugar par aplicações e protocolos que não se encaixam nas camadas abaixo (email, transferência de arquivos, etc...).

- Camada de Apresentação: Trata do significado dos bits, definindo registros e seus campos, e permitindo que o emissor notifique o receptor do formato de cada registro.

- Camada de Seção: Controle de diálogo, identificando qual parte está falando, e fornecendo sincronização. Sequer presente na suíte do TCP/IP. Uma suíte de protocolo (ou pilha de protocolo) é a coleção de protocolos usadas em um sistema em particular.

- Camada de Transporte: Serviços para estabelecimento de comunicação confiável (entrega da mensagem sem perda). Ex: TCP, UDP. Quebra da mensagem da camada de aplicação em pedaços para transmissão, numerando-os e então os enviando.

- Camada de Rede: Responsável pelo roteamento (Como escolher o melhor caminho entre emissor e receptor) Ex: Pacotes IP. Em muitos sistemas distribuídos, a interface de mais baixo nível é a interface de rede.

- Camada de Enlace: Agrupa os bits em unidades (frames), verificando se cada frame é corretamente recebida. Coloca um conjunto de bits no final e início de cada frame, para marcá-los, alem de um checksum para detecção de erros. Quando uma frame chega, o receptor calcula o checksum e compara ao que está na frame. Se eles não batem, ele pede ao emissor para retransmitir a frame. Frames recebem números sequenciais em seu cabeçalho, para identificação.

- Camada de Física: Transmite bits (Quantos volts usar para cada, quantos bits/segundo enviar, etc).

<br>

3. Dê exemplos de protocolos da camada de Aplicação do modelo OSI

    Exemplos de protocolos da camada de Aplicação do modelo OSI podem ser: HTTP, FTP, TFTP, SSH, TelNet, SMTP, DHCP, DNMP.

<br>

4. O que são as Chamadas de Procedimentos Remotos (RPC)?

    As chamadas de Procedimentos Remotos permite que programas chamem procedimentos em outras máquinas, dessa forma podem esconder a comunicação entre chamador & chamado.

<br>

5. Sistemas de e-mail são exemplos típicos de qual tipo de comunicação?

    São exemplos de comunicação síncrona.

<br>

6. Defina comunicação assíncrona e comunicação síncrona. Dê exemplos.

    A comunicação assíncrona:

    - O emissor continua seu trabalho imediatamente após enviar a mensagem.

    - Esta é temporariamente armazenada no middleware

        - aplicativos de mensagem

    A comunicação síncrona:

    - O emissor é bloqueado até ter certeza de que sua requisição foi aceita.

        - ligação telefônica

<br>

7. Defina comunicação persistente e comunicação transiente. Dê exemplos.

    Comunicação Transiente:

    - O middleware armazena a mensagem somente enquanto o emissor e receptor estiverem executando.

    - Ela descarta a mensagem se ela não puder ser encaminhada para o destinatário ou ao próximo servidor.

        - Java

        - Operating system

    Comunicação Persistente:

    - A mensagem é armazenada no middleware de comunicação pelo tempo que for necessário para que seja entregue.

    - Assim, a aplicação remetente não precisa continuar sua execução após o envio da mensagem.

    - Nem a aplicação receptora precisa estar rodando quando a mensagem é enviada.

        - MPI_COMM_WORLD

<br>

8. Um programa que faz uso de RPC para invocar um método cuja implementação se encontra em outro computador interage, na máquina em que este programa está rodando, com um determinado componente do middleware. Que nome tem esse componente?

<br>

9. A camada de transporte hoje nos oferece uma interface simples para mensagens. Que interface é essa?

    A interface é o modelo Socket

<br>

10. Quais operações são permitidas em sockets, segundo o POSIX?

- SOCKET (Cria um novo ponto de comunicação)

- BIND (Especifica um endereço local (IP + porta) ao socket)

- LISTEN (Diz ao SO o nùmero máximo de pedidos de conexão a serem recebidos)

- ACCEPT (Bloqueia o executor até receber um pedido de estabelecimento de conexão)

- CONNECT (Tenta estabelecer uma conexão)

- SEND (Envia dados pela conexão)

- RECEIVE (Recebe dados pela conexão)

- CLOSE (Libera a conexão)

<br>

11. A necessidade de independência de hardware e plataforma levou ao surgimento de um padrão para troca de mensagens. Que padrão é esse?

- Message-Passing Interface (MPI)

<br>

12. Por ser projetada para aplicações paralelas, a Interface de Passagem de Mensagens (MPI) é **mais adequada** para que tipo de comunicação?

- Comunicação Transiente

<br>

13. Como podemos ter um sistema que ofereça comunicação orientada a mensagens de forma assíncrona e persistente?

- Comunicação assíncrona e persistente graças ao uso de filas pelo middleware
- Filas correspondem a buffers em servidores de comunicação

<br>

14. Pensando em como funciona a atribuição de números de telefone, podemos considerar um número de telefone um identificador? Por que?

    Sim, pois cada chip de celular pode ter apenas um número

<br>

15. Cite as características que um identificador precisa ter. 

- Cada identificador se refere a, no máximo, uma entidade
- Cada entidade é referenciada por, no máximo, um identificador
- Um identificador sempre se refere à mesma entidade (nunca é reutilizado)

<br>

16. Explique como funcionam as Tabelas de Hash Distribuídas baseadas no Chord.

    As tabelas distribuídas baseadas no Chord são um sistema peer-to-peer estruturado, os nós são organizados na forma de um anel lógico.
    
    - A cada nó é atribuido um identificador aleatório de m-bits

    - A cada entidade é atribuída uma única chave de m-bits

    - O anel é estendido com vários links de atalho para outros nós

    - Construído de modo que o comprimento do menor caminho entre qualquer par de nós é da ordem de O(log(N)), onde N é o número total e nós

    - Entidades com chave k são armazenadas no nó com o menor $ id \geq k $ (seu sucessor suc(k))

    Busca:

    - Passa a requisição para o nó mais longe, mas sem ultrapassar o nó responsável por ela

<br>

17. O sistema de nomes utilizado no DNS é estruturado e a resolução de nomes DNS é organizada simultaneamente por diversos países e organizações. Ainda assim, não é possível afirmar que um nome associado a um domínio como, por exemplo, https://www.un.org/, está relacionado a uma entidade em um país específico. Qual a alternativa abaixo que melhor explica essa constatação?

    (a) Ainda que a hierarquia de nomes seja gerenciada por países diferentes, nada se pode dizer sobre a localização geográfica do ponto de acesso da entidade referenciada por um nome

    (b) O endereço https://www.un.org/ se refere a um organismo internacional e, por isso, seu servidor encontra-se em águas internacionais

    (c) Um órgão de atribuição de nomes DNS como o registro.br só pode atribuir nomes .com.br a entidades que estejam em solo nacional

    (d) Uma vez atribuído o nome a uma entidade de um país, essa entidade não pode ser movida para outro país

    A alternativa: (a)

<br>

18. Hard link e soft link são exemplos de que tipo de nomes?

    O Hard link e o Soft link são exemplos do tipo de Nomes Estruturados.

<br>

19. Sistemas de arquivos distribuídos são um exemplo de sistemas que usam que tipo de nomes?

    Sistemas de arquivos distribuídos são um exemplo de sistemas que usam Implementação de Espaços de Nomes.

