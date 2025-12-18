Push Swap
Description

  O Push Swap é um projeto cujo objetivo é ordenar uma pilha de inteiros utilizando um conjunto limitado de operações e uma pilha auxiliar.
  O programa recebe uma lista de números inteiros como argumento, armazena-os em uma pilha principal (stack_a) e deve ordená-los em ordem crescente utilizando a menor quantidade possível de operações permitidas.
  
  Este projeto utiliza duas pilhas:
  
  stack_a: pilha principal, inicialmente contendo todos os números.
  
  stack_b: pilha auxiliar, inicialmente vazia.
  
  A abordagem adotada neste projeto é baseada em arrays, com uma estratégia de ordenação do tipo chunk-based greedy, utilizando indexação prévia dos valores para facilitar comparações e decisões.

Algorithm Overview (Chunk Greedy)

  Antes do processo de ordenação, todos os números são indexados:
  
  Os valores são ordenados em uma cópia do array.
  
  Cada número original é substituído pelo seu índice ordenado (0 até n - 1).
  
  Isso permite trabalhar com valores pequenos, contínuos e previsíveis.

Estratégia de Chunks

  O algoritmo divide o conjunto de números em chunks (blocos):
  
  O tamanho do chunk é calculado com base no número total de elementos.
  
  Cada chunk representa um intervalo de índices (start até end).
  
  O objetivo é mover gradualmente os valores de stack_a para stack_b, chunk por chunk.

Fase 1 — Envio para stack_b
  
  O algoritmo procura, em stack_a, o primeiro valor que pertença ao intervalo do chunk atual.
  
  A pilha é rotacionada (ra ou rra) de forma otimizada, escolhendo sempre o menor número de movimentos para trazer o valor ao topo.
  
  O valor é enviado para stack_b (pb).
  
  Dependendo da posição do valor dentro do chunk, stack_b pode ser rotacionada (rb) para manter uma organização favorável.
  
  O processo se repete até que todos os valores do chunk tenham sido movidos.

Fase 2 — Retorno ordenado para stack_a
  
  Após todos os chunks serem enviados para stack_b, o algoritmo começa a devolver os valores.
  
  Sempre busca o maior índice presente em stack_b.
  
  stack_b é rotacionada (rb ou rrb) até que esse valor esteja no topo.
  
  O valor é empurrado de volta para stack_a (pa).
  
  Esse processo garante que os valores retornem já em ordem crescente.
  
  Ao final, stack_a estará completamente ordenada.

Instructions
Compilação

  Para compilar o projeto, execute:
  
  make
  
  
  Isso irá gerar o executável push_swap.
  
  Execução
  
  Você pode executar o programa passando os números diretamente:
  
  ./push_swap 4 67 3 87 23
  
  
  Ou utilizando uma variável de ambiente (ARG):
  
  ARG="4 67 3 87 23"
  ./push_swap $ARG
  
  
  Para validar o resultado com o checker:
  
  ARG="4 67 3 87 23"
  ./push_swap $ARG | ./checker_OS $ARG
  
  
  Se a saída for OK, a pilha foi corretamente ordenada.
  
  Teste com números aleatórios (shuf)
  
  Para gerar uma sequência aleatória de números automaticamente:
  
  ARG=$(shuf -i 1-100 -n 50 | tr '\n' ' ')
  ./push_swap $ARG | ./checker_OS $ARG
  
  
  Esse comando gera 50 números aleatórios entre 1 e 100 e testa o algoritmo.

Resources
Referências Técnicas

  Manual da linguagem C (man gcc, man malloc)
  
  Documentação oficial da 42 sobre o projeto Push Swap
  
  Artigos sobre greedy algorithms
  
  Conteúdos sobre chunk-based sorting strategies
  
  Operações de pilhas e análise de complexidade

Uso de Inteligência Artificial

  Ferramentas de IA (como o ChatGPT) foram utilizadas exclusivamente como apoio conceitual, para:
  
  Discussão de estratégias de ordenação
  
  Análise lógica do algoritmo
  
  Organização da arquitetura do projeto
  
  Revisão conceitual das decisões tomadas
  
  Todo o código foi escrito manualmente, com total compreensão do funcionamento das estruturas e operações utilizadas.
