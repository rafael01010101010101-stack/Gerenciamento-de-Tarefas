# Gerenciamento-de-Tarefas# Gerenciamento de Tarefas com Lista Ligada em C

## Descrição

Programa desenvolvido em linguagem C para gerenciar tarefas por meio de uma lista ligada simples. Cada tarefa possui um ID e uma descrição, permitindo inserir, listar e remover tarefas.

## Funcionalidades

- **Inserir tarefas:** cadastra uma tarefa com ID e descrição, adicionando-a ao final da lista.
- **Listar tarefas:** exibe o ID e a descrição de todas as tarefas cadastradas.
- **Remover tarefas:** exclui uma tarefa com base no ID informado.
- **Menu interativo:** permite escolher a operação desejada até que o usuário selecione a opção de sair.

## Estrutura de dados

O programa utiliza uma lista ligada simples, composta por nós (`Node`). Cada nó armazena o ID da tarefa, sua descrição e um ponteiro para o próximo nó.

O ponteiro `head` indica o início da lista e começa com `NULL`, representando uma lista vazia. Os nós são alocados dinamicamente com `malloc()` e liberados com `free()` quando uma tarefa é removida.

## Tecnologias utilizadas

- Linguagem C
- Ponteiros
- Alocação dinâmica de memória
- Lista ligada simples
- Estruturas (`struct`)

## Execução

O programa pode ser compilado e executado em um compilador de C, como o OnlineGDB.
