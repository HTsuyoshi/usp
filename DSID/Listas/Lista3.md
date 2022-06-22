# Lista 1

1. Considerando o modelo ISO-OSI, em qual camada se encaixa o IP (Internet Protocol)?

O Internet Protocol se encaixa na camada de rede

2. Quais as camadas do modelo OSI, e qual o prop ́osito de cada uma?

As camadas do modelo OSI são:

- Camada de Aplicação: Tornou-se o lugar par aaplicações e protocolos que não se encaixam nas camadas abaixo (email, transferência de arquivos, etc...).
- Camada de Apresentação: Trata do significado dos bits, definindo registros e seus campos, e permitindo que o emissor notifique o receptor do formato de cada registro
- Camada de Seção: Controle de diálogo, identificando qual parte está falando, e fornecendo sincronização. Sequer presente na suíte do TCP/IP. Uma suíte de protocolo (ou pilha de protocolo) é a coleção de protocolos usadas em um sistema em particular
- Camada de Transporte: Serviços para estabelecimento de comunicação confiável (entrega da mensagem sem perda). Ex: TCP, UDP. Quebra da mensagem da camada de aplicação em pedaços para transmissão, numerando-os e então os enviando
- Camada de Rede: Responsável pelo roteamento (Como escolher o melhor caminho entre emissor e receptor) Ex: Pacotes IP. Em muitos sistemas distribuídos, a interfae de mais baixo nível é a interface de rede.
- Camada de Enlace: Agrupa os bits em unidades (frames), verificando se cada frame é corretamente recebida. Coloca um conjunto de bits no final e início de cada frame, para marcá-los, alem de um checksum para detecção de erros. Quando uma frame chega, o receptor calcula o checksum e compara ao que está na frame. Se eles não batem, ele pede ao emissor para retransmitir a frame. Frames recebem números sequeniais em seu cabeçalho, para identificação.
- Camada de Física: Transmite bits (Quantos volts usar para cada, quantos bits/segundo enviar, etc)

3. Dˆe exemplos de protocolos da camada de Aplica ̧c ̃ao do modelo OSI

```
Exemplos de protocolos da camada de Aplicação do modelo OSI podem ser: HTTP, FTP, TFTP, SSH, TelNet, SMTP, DHCP, DNMP.
```

4. O que s ̃ao as Chamadas de Procedimentos Remotos (RPC)?

```
As chamadas de Procedimentos Remotos permite que programas chamem procedimentos em outras máquinas, dessa forma podem esconder a comunicação entre chamador & chamado
```

5. Sistemas de e-mail s ̃ao exemplos t ́ıpicos de qual tipo de comunica ̧c ̃ao?

```
```

6. Defina comunica ̧c ̃ao ass ́ıncrona e comunica ̧c ̃ao s ́ıncrona. Dˆe exemplos.

```
Acho que falta algo

A comunicação assíncrona: O cliente envia uma requisição para o servidor, e o servidor retorna imediatamente uma resposta como acknowledge para que o cliente possa continuar o seu processo

A comunicação síncrona:
```

7. Defina comunica ̧c ̃ao persistente e comunica ̧c ̃ao transiente. Dˆe exemplos.

Comunicação Transiente:

- É um modelo simples orientado a mensagens oferecido pela camada de transporte
- Um ponto de c

Comunicação Persistente:

8. Um programa que faz uso de RPC para invocar um m ́etodo cuja implementa ̧c ̃ao se encontra em outro computador interage, na m ́aquina em que este programa est ́a rodando, com um determinado componente do middleware. Que nome tem esse componente?

```
```

9. A camada de transporte hoje nos oferece uma interface simples para mensagens. Que interface  ́e essa?

```
```

10. Quais operações são permitidas em sockets, segundo o POSIX?

```
	- SOCKET (Cria um novo ponto de comunicação)
	- BIND (Especifica um endereço local (IP + porta) ao socket)
	- LISTEN (Diz ao SO o nùmero máximo de pedidos de conexão a serem recebidos)
	- ACCEPT (Bloqueia o executor até receber um pedido de estabelecimento de conexão)
	- CONNECT (Tenta estabelecer uma conexão)
	- SEND (Envia dados pela conexão)
	- RECEIVE (Recebe dados pela conexão)
	- CLOSE (Libera a conexão)
```

11. A necessidade de independência de hardware e plataforma levou ao surgimento de um padrão para troca de mensagens. Que padrão é esse?

```
	- Message-Passing Interface (MPI)
```

12. Por ser projetada para aplicações paralelas, a Interface de Passagem de Mensagens (MPI) é ** mais adequada ** para que tipo de comunicação?

```
	- Comunicação Transiente
```

13. Como podemos ter um sistema que ofereça comunicação orientada a mensagens de forma assı́ncrona e persistente?

```
	- **Filas** pelo middleware
	- Filas correspondem a *buffers* em servidores de comunicação
```


14. Pensando em como funciona a atribui ̧c ̃ao de n ́umeros de telefone, podemos considerar um n ́umero de telefone um identificador? Por que? Um n ́umero de telefone n ̃ao pode ser consi- derando um identificador, pois:

```
```

15. Cite as caracter ́ısticas que um identificador precisa ter. Qual alternativa abaixo  ́e falsa em rela ̧c ̃ao a defini ̧c ̃ao de identificadores?

```
```

16. Explique como funcionam as Tabelas de Hash Distribu ́ıdas baseadas no Chord. Qual a in- forma ̧c ̃ao incorreta sobre Tabelas de Hash Distribu ́ıdas baseadas no Chord?


17. O sistema de nomes utilizado no DNS  ́e estruturado e a resolu ̧c ̃ao de nomes DNS  ́e organizada simultaneamente por diversos pa ́ıses e organiza ̧c ̃oes. Ainda assim, n ̃ao  ́e poss ́ıvel afirmar que um nome associado a um dom ́ınio como, por exemplo, https://www.un.org/, est ́a relacionado a uma entidade em um pa ́ıs espec ́ıfico. Qual a alternativa abaixo que melhor explica essa constata ̧c ̃ao?

(a) Ainda que a hierarquia de nomes seja gerenciada por pa ́ıses diferentes, nada se pode dizer sobre a localiza ̧c ̃ao geogr ́afica do ponto de acesso da entidade referenciada por um nome

(b) O endere ̧co https://www.un.org/ se refere a um organismo internacional e, por isso, seu servidor encontra-se em  ́aguas internacionais

(c) Um  ́org ̃ao de atribui ̧c ̃ao de nomes DNS como o registro.br s ́o pode atribuir nomes .com.br a entidades que estejam em solo nacional

(d) Uma vez atribu ́ıdo o nome a uma entidade de um pa ́ıs, essa entidade n ̃ao pode ser movida para outro pa ́ıs

A alternativa: 

18. Hard link e soft link s ̃ao exemplos de que tipo de nomes?

O Hard link e o Soft link são exemplos do tipo de nome a, pois eles a

19. Sistemas de arquivos distribu ́ıdos s ̃ao um exemplo de sistemas que usam que tipo de nomes?

Sistemas de arquivos distribuídos são um exemplo de sistemas que usam o tipo de nome a
