## Development Road map
### Notes and reminders
+ Funções terminadas em `_l` significam que são **locais**
    + Não é esperado que outros arquivos as usem, exceto pelo arquivo onde ela
      foi declarada.

+ Estruturação básica do projeto:
    + As funcionalidades que envolvem interagir com o usuário de alguma forma,
      pela porta serial nesse projeto, vão ficar na própria pasta do sketch.
    + Dentro da pasta `src/` vão ficar funções que não interagem muito com o
      mundo do lado de fora, apenas gospe dados com base no que consumiu.
        + ~~Apesar disso, os arquivos que lidam com o estado dos servos motores
          estarão ai; por conta disso, essas funções vão acabar tendo *side
          effects*...~~
        + As funções dos comandos devem ter acesso a um ponteiro pra lista
          ligada de `ParallelServo`'s

### Todo list
+ [ ] **Module**: Criar uma função que separa o sufixo do prefixo de um comando
+ [x] ~~**Feature**: Começar escrevendo as funções locais nos arquivos `.ino`~~
    + [x] ~~**Sketch**: Função para ler o input do usuário~~
        + [x] ~~**Module**: Criar uma função que verifica se o input do usário é um comando válido~~
    + [x] ~~**Sketch**: Mostrar um erro se o input não for um comando válido~~
        + [x] ~~**Sketch**: Funções que mostram uma mensagem de forma, minimamente, formatada na tela (*success*, *errors* & *debug*)~~
