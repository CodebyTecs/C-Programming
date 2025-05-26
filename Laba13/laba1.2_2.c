#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *nextd;
    int data;
    struct node *next;
};
typedef struct node node_t;

node_t *newNode(int data) {
    node_t *newnode = malloc(sizeof(node_t));
    if (!newnode) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    newnode->nextd = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node_t *AppendS(int n, node_t *S) {
    node_t *node = newNode(n); 

    if (!node) {
        return S; 
    } 

    if (S == NULL) {
        return node; 
    }

    node_t *temp = S;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node; 

    return S;
}

node_t *AppendD(int n, node_t *D) {
    node_t *node = newNode(n); 

    if (!node) {
        return D; 
    } 

    if (D == NULL) {
        return node; 
    }

    node_t *temp = D;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node; 

    return D;
}

void Link(node_t *S, node_t *D) {
    node_t *temp = S;
    node_t *tempd = D;

    while (temp != NULL && tempd != NULL) {
        temp->nextd = tempd;

        temp = temp->next;
        tempd = tempd->next;
    }

    while (temp != NULL) {
        temp->nextd = NULL;
        temp = temp->next;
    }
}

void printList(node_t *S) {
    printf("Основной список: ");
    node_t *temp = S;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Дополнительные узлы: ");
    node_t *tempd = S;
    while (tempd != NULL) {
        if (tempd->nextd != NULL)
            printf("%d -> ", tempd->nextd->data);
        tempd = tempd->next;
    }
    printf("NULL\n");
}

void freeList(node_t *S) {
    node_t *temp;
    while (S) {
        temp = S;
        S = S->next;
        if (temp->nextd) {
            free(temp->nextd); 
        }
        free(temp); 
    }

    node_t *D = NULL;
}

int main() {
    int data;
    char sym;
    node_t *S = NULL;
    node_t *D = NULL;

    printf("Введите числа (0 для завершения):\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;
        S = AppendS(data, S);
    }

    printf("Введите числа (0 для завершения):\n");
    while (1) {
        scanf("%d", &data);
        if (data == 0) break;
        D = AppendD(data, D);
    }

    Link(S, D);

    printList(S);

    node_t *temp = S;

     while(1){

        printf("Текущий элемент списка: %d \n", S->data);
        printf("Введите одну из команд (S - вниз D - вправо): ");
        scanf(" %c", &sym);

        switch (sym){

            case 'D':
            if (S->next!=NULL){
                S=S->next;
            }
            else{
                printf("Достигнут конец\n");
                printf("\n");

                S = temp;
                break;
            }
            break;

            case 'S':
            if (S->nextd != NULL){
                S = S->nextd;
            }
            else{
                printf("Достигнут конец\n");
                printf("\n");

                S = temp;
                break;
            }
            break;
        }
    }

    freeList(S);

    return 0;
}




