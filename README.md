# VSSSEmbarcado

Código embarcado (Arduino) do VSSS separado em três pastas. A *arduino_libraries* contém código-fonte para as bibliotecas de *Arduino*
desenvolvidas pelos integrantes do GER. A *emissor* possui o código-fonte principal do *Arduino* ligado
ao computador. E por fim, a *jogador*, que possui o código-fonte principal do *Arduino* que controla cada
robô.

## Bibliotecas Arduino

Para ter acesso a todas as bibliotecas externas usadas pelo VSSS, baixe a biblioteca do *RF24* como submodulo git: faça `git clone --recursive ...` 
ou ` git submodule init && git submodule update` caso já tenha clonado o repositório.

### Instalando as bibliotecas

Para acessar as bibliotecas de dentro da IDE do Arduino, copie o conteúdo de *arduino_libraries* para a sua pasta local (algo como 
*Documents/Arduino/libraries/*) e reinicie a IDE, caso esteja aberta. Ela deve reconhecer automaticamente a adição de novas bibliotecas.
Verifique em *File* > *Examples*, na parte inferior em *Examples from custom libraries*.

## Código do Emissor

Caso queira depurar a execução da transmissão de mensagem do Arduino emissor ligado ao computador, remova ou comente a linha `#undef DEBUG_MODE`

## Código do Jogador

Ao fazer *upload* do código para os robôs, certifique-se de que `#define PLAYER n` está com o jogador corretamente definido, sendo
`n` 0, 1 ou 2.
