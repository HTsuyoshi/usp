# Lista 2

1. Cite os principais estilos arquiteturais em sistemas distribuídos.

Multicamadas (Sistemas cliente-servidor)
Orientada a Objetos (Sistemas de Objetos distribuídos)
Publish/Subscribe (Desaclopado no espaço)
Espaço de dados compartilhados (Desacoplado no Espaço e Tempo)

2. Um estilo arquitetural pode ser definido em termos de que?

Um estilo arquitetural pode ser definido em termos de Componenes (Substituíveis) com interfaces bem definidas, O modo como os componentes são conectados entre si, Como os dados são trocados entre componentes e Como esses componentes e conectores são configurados conjuntamente em um sistema

3. Quais as principais caracteristicas do estilo arquitetural REST (RESTful)?

As principais características do estilo arquitetural RESTful são que essa arquitetura envia mensagens de um serviço para outro serviço de forma auto-descritiva

Recursos são entidades abstraras (Não podem ser utilizadas por serviços)

4. Como interceptadores permitem que o middleware seja adaptado a condicoes especificas de uma aplicacao?

Interceptadores permitem que o middleware seja adaptado à codições específicas deixando o comportanmento do middleware dinâmico, interceptando as chamadas feitas entre a aplicação e o middleware e o middlweare e a máquina local.

5. Considere a afirma ̧cao: “A organizacao de sistemas cliente-servidor em fat clients (clientes gordos) nao configura um sistema distribuıdo, ja que a quase totalidade das operacoes (interface, aplica ̧c ̃ao e parte da persistência)  ́e realizada em um unico computador (o cliente), tornando um processo servidor irrelevante”. Isso esta correto? Justifique.

Não, pois o servidor ainda é necessário para atualizar as informações dos clientes.

6. O que  ́e uma rede de overlay?

Uma rede overlay é uma rede na qual cada processo tem uma lista local de outros nós com os quais ele pode se comunicar

7. Um sistema peer-to-peer cuja rede de overlay  ́e organizada em formato de anel  ́e um sistema estruturado? Explique

Sim, pois os sistemas estruturados são organizados seguindo uma estrutura de dados distribuídas específica, e no caso citado no enunciado é um sistema organizado na estrutura de nós

8. No contexto de sistemas distribuidos, como podemos esconder latências de comunicacão no lado do cliente?

Podemos esconder latências de comunicação permitindo chamadas bloqueantes sem bloquear o processo, facilitando assim a comunicação na forma de múltiplas conexões ao mesmo tempo. Geralmente iniciando uma comunicação e imediatamente procedendo com alguma tarefa.

9. Em um servidor multithread, em que uma thread se encarrega de receber as requisicoes passando-as a outras para solucao, como se chamam as threads que recebem as requisicoes e as que efetivamente as executam?

As threads que recebem as requisições são chamadas de Dispatcher threads e as threads que executam são chamadas de Worker threads

10. Essencialmente, como podemos prover a virtualizacao em sistemas distribuıdos?

Em sistemas distribuídos, podemos prover a virtualização d

11. Quais as duas maneiras pelas quais a virtualizacao pode ocorrer, no contexto de sistemas distribuidos?

As duas maneiras pelas quais a virtualização pode ocorrer são via um Runtime System ou via uma camada Virtual Machine Monitor acima do hardware

Runtime System:
	- Fornecendo um conjunto abstrato de instruções para as aplicações.
	- Modelo de máquina virtual de processo (A virtualização ocorre para um único processo).
	- Conjunto separado de instruções e um interpretador/emulador, rodanddo sobre o SO (Ex: Java VM)

Camada acima do harware:
	- Oferecendo um conjunto completo de instruções como interface
	- Modelo de monitor nativo de máquina virtual, simultaneamente oferecido a diferentes processos
	- Podendo inclusive executar múltiplos SOs e suas aplicações (Ex: VMware)

12. Em qual dos dois modos de virtualizacao podemos ter diferentes Sistemas Operacionais executando concorrentemente na mesma plataforma?

Podemos ter diferentes Sistemas Operacionais executando concorrentemente no modo de virtualização que usa uma camada Virtual Machine Monitor acima do hardware

13. Qual modo de virtualizacao limita-se a virtualizacao de apenas um  ́unico processo?

O modo de virtualização que se limita a virtualização de apenas um único processo é o Runtime System

14. Em um sistema distribuıdo com varios servidores replicados, como podemos implementar a transparência de replicacao no lado do cliente?

Podemos implementar a trasparência de replicação no lado de cliente fazendo múltiplas requisições usando o stub do cliente, que coleta respostas, e passa uma única resposta à aplicação cliente

15. O que  ́e um servidor iterativo?

O próprio servidor trata da requisição, retornando a resposta ao cliente e cada requisição é tratada antes de atender a próxima requisição

16. O que  ́e um servidor concorrente?

O servidor não trata a resquisição, ao invés disso ele usa um despachante (dispatcher), que pega a requisição e repassa seu tratamento e uma thread/processo separado, esperando então pela próxima requisição.
17. O que define a mobilidade fraca (weak mobility), dentro da migracao de codigo?

Dentro da migração do código a mobilidade fraca é definida pela trasferência de um segmento de código, possivelmente com alguns dados de inicialização, e após a transferência o código precisa ser inicizalidado novamente.

18. O que define a mobilidade forte (strong mobility), dentro da migracao de codigo?

Dentro da migração do código a mobilidade forte é definida pela possibilidade de conseguir migrar um processo durante sua execução, ou seja o processo é parado e, após ser migrado, pode continuar a sua execução exatamente de onde parou

