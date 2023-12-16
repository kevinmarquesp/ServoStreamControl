## Development Road map
### Notes and reminders
+ Estruturação básica do projeto:
    + As funcionalidades que envolvem interagir com o usuário de alguma forma,
      pela porta serial nesse projeto, vão ficar na própria pasta do sketch.
    + Dentro da pasta `src/` vão ficar funções que não interagem muito com o
      mundo do lado de fora, apenas gospe dados com base no que consumiu.
        + Apesar disso, os arquivos que lidam com o estado dos servos motores
          estarão ai; por conta disso, essas funções vão acabar tendo *side
          effects*...

### Todo list
+ [ ] **Feature**: Começar escrevendo as funções locais nos arquivos `.ino`
    + [ ] **Code**: Função para ler o input do usuário
    + [ ] **Code**: Função que confere se o input é um comando válido pelo sinal de `$`
    + [ ] **Code**: Funções que mostram uma mensagem de forma, minimamente, formatada na tela (*success*, *errors* & *debug*)
