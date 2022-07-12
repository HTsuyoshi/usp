# Roteiro do Seminário de DSID

[Paper](https://pdos.csail.mit.edu/archive/6.824-2006/papers/nfs033.pdf)

## O que é NFS?

### Introdução

Network File System ou NFS foi feito pelo Sun Microsystems em 1980.

É uma aplicação Cliente/Serviço que provê um armazenamento compartilhado entre os clientes de uma rede.

Um cliente NFS pode adicionar o sistema remoto no sistema local do cliente e fazer ele funcionar como se fosse um sistema UNIX local.

Múltiplos usuários podem montar o mesmo sistema remoto e, dessa forma, compartilhar arquivos.

### Como surgiu?

Os computadores antes de 1980 eram muito caros, por isso múltiplos usuários compartilhavam o mesmo sistema de arquivos.

No começo de 1980 as *workstations* foram criadas e isso permitiu que cada engenheiro tivesse seu computador privado.

Mas os usuários queriam ter uma forma de compartilhar arquivos dos sistema

O NFS ajudou também na manutenção das *workstations* dos usuários, já que como as *workstations* estão no server em um mesmo filesystem é necessário fazer backup em apenas no server.

### Objetivos

O NFS foi pensado com 4 objetivos em mente, sendo eles:

1 - Funcionar com as aplicações ainda existentes, ou seja, deve prover as mesmas semânticas de um sistema UNIX local

2 - O NFS deve ser fácil de implantar

3 - O cliente deve ser implementável em outros sistemas operacionais como Microsoft DOS

4 - Deve ser eficiente o suficiente para que os usuários consigam tolerar

## Naming remote files and directories

### Primeira conexão

Para os programas os arquivos parecem que estão no computador local.

Um exemplo é tentar abrir um arquivo usando o comando `OPEN("/users/gustavo/nota.txt", READONLY)`, pois não é possível saber se o diretório `users` e o diretório `gustavo` são locais ou não.

Para isso acontecer, a raiz do sistema remoto deve ser montado no namespace local, para isso é usado um programa separado chamado `mounter`.

O `mounter` utiliza o remote procedure call para o servidore remoto e pede pelo `file handle`, com nome de 32 bytes, para o inode do path.

`file handle`: é uma referência temporária que o sistema operacional usa para referenciar um arquivo aberto ou referenciado pelo usuário

`inode`: guardam metadados sobre todos os arquivos dentro de sistema como: tamanho, permissão, dono/grupo, Localização, data, etc... Mas não guardam nome nem os dados

### Por que usar file handle?

Para referenciar os arquivos no sistem de arquivos remoto, também é possível utilizar o caminho absoluto do arquivo, mas isso acaba criando alguns problemas que o `file handle` pode resolver.

Para ver um exemplo disso em prática, supomos que um programa no cliente 1 esteja modificando um diretório no servidor, e ao mesmo tempo um certo programa 2 modifique o nome do diretório 

Exemplo na página 2 do paper

## The NFS remote procedure calls

### Como são feitas as chamadas remotas?

Pegando como um exemplo o código do exemplo anterior

O usuário tenta abrir um arquivo chamado `nota.txt` e depois tenta ler o conteúdo desse arquivo para dentro de um buffer

O progama então faz uma `remote procedure call` para o servidor procurando pelo arquivo chamado `nota.txt` no diretório atual `dirfh` que foi obtido na última vez que o sistema foi montado

O servidor então recebe o pega o identificador do `dirfh` e procura pelo arquivo dentro do diretório `dirfh`


## a

