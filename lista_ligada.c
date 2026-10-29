#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int id;
    char descricao[100];
    struct Node* next;
};

struct Node* head = NULL;

void listarTarefas(struct Node* head)
{
    struct Node* atual = head;
    
    if (atual == NULL)
    {
        printf("Nenhuma tarefa foi encontrada!");
        return;
    }
    while(atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        printf("Descrição: %s\n", atual->descricao);
        atual = atual->next;
    }
};

void inserirTarefas(int id, char descricao[])
{
    struct Node* novoNo = malloc(sizeof(struct Node));
    
    if(novoNo == NULL)
    {
        printf("Erro ao inserir tarefa!");
        return;
    }
    
    novoNo->id = id;
    strcpy(novoNo->descricao, descricao);
    novoNo-> next = NULL;
    
    if(head == NULL)
    {
        head = novoNo;
    }
    else
    {
        struct Node* atual = head;
        
        while(atual->next != NULL)
        {
            atual = atual->next;
        }
        
        atual->next = novoNo;
    }
    
}

void removerTarefa(int id)
{
    struct Node* atual = head;
    struct Node* anterior = NULL;
    
    if(head == NULL)
    {
        printf("Nenhuma tarefa foi encontrada!\n");
        return;
    }
    
    while(atual != NULL && atual->id != id)
    {
        anterior = atual;
        atual = atual->next;
    }
    
    if(atual == NULL)
    {
        printf("Tarefa não encontrada!\n");
        return;
    }
    
    if(anterior == NULL)
    {
        head = atual->next;
    }
    else
    {
        anterior->next = atual->next;
    }
    
    free(atual);
    printf("Tarefa removida com sucesso!\n");
}

int main()
{
    int opcao, id;
    char descricao[100];
    
    do
    {
        printf("\nEscolha uma das opções abaixo:\n");
        printf("1 - Inserir Tarefas\n");
        printf("2 - Listar Tarefas\n");
        printf("3 - Remover Tarefas\n");
        printf("0 - Sair\n");
        printf("Informe a opção que deseja: ");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao)
        {
            case 1:
                printf("Informe o ID da tarefa: ");
                scanf("%d", &id);
                getchar();
                
                printf("Informe a descrição da tarefa: ");
                fgets(descricao, sizeof(descricao), stdin);
                inserirTarefas(id, descricao);

                break;
            case 2:
                listarTarefas(head);
                break;
            case 3:
                printf("Informe o ID da tarefa que deseja excluir: ");
                scanf("%d", &id);
                getchar();
                removerTarefa(id);
                
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção invalída!\n");
        }
    }while(opcao != 0);
    
    return 0;
}