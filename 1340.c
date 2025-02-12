//Nicolas Ramos da Silva 178197


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanhomax 1000  // Tamanho máximo de operações

// Estrutura para simular uma pilha
typedef struct {
    int items[tamanhomax];  // Array para armazenar os elementos da pilha
    int top;  // Índice do topo da pilha
} Stack;

// Estrutura para simular uma fila
typedef struct {
    int items[tamanhomax];  // Array para armazenar os elementos da fila
    int front, rear;  // Índices do início e do final da fila
} Queue;

// Estrutura para simular uma fila de prioridade (heap máximo)
typedef struct {
    int items[tamanhomax];  // Array para armazenar os elementos da fila de prioridade
    int size;  // Tamanho atual da fila de prioridade
} PriorityQueue;

// Funções para a pilha
void pushStack(Stack *s, int x) {
    s->items[++(s->top)] = x;  // Adiciona o elemento x ao topo da pilha
}

int popStack(Stack *s) {
    return s->items[(s->top)--];  // Remove e retorna o elemento do topo da pilha
}

// Funções para a fila
void enqueue(Queue *q, int x) {
    q->items[++(q->rear)] = x;  // Adiciona o elemento x ao final da fila
}

int dequeue(Queue *q) {
    return q->items[(q->front)++];  // Remove e retorna o elemento do início da fila
}

// Funções para a fila de prioridade
void pushPriorityQueue(PriorityQueue *pq, int x) {
    int i = ++(pq->size);  // Incrementa o tamanho da fila de prioridade
    while (i > 1 && x > pq->items[i / 2]) {  // Ajusta a posição do novo elemento no heap
        pq->items[i] = pq->items[i / 2];  // Move o pai para baixo
        i /= 2;  // Atualiza o índice para o pai
    }
    pq->items[i] = x;  // Insere o novo elemento na posição correta
}

int popPriorityQueue(PriorityQueue *pq) {
    int max = pq->items[1];  // Armazena o maior elemento (raiz do heap)
    int last = pq->items[(pq->size)--];  // Remove o último elemento e decrementa o tamanho
    int i = 1;
    while (2 * i <= pq->size) {  // Ajusta o heap após a remoção
        int child = 2 * i;  // Índice do filho esquerdo
        if (child < pq->size && pq->items[child + 1] > pq->items[child]) {
            child++;  // Escolhe o filho com o maior valor
        }
        if (last >= pq->items[child]) {
            break;  // Se o último elemento está na posição correta, para
        }
        pq->items[i] = pq->items[child];  // Move o filho para cima
        i = child;  // Atualiza o índice para o filho
    }
    pq->items[i] = last;  // Insere o último elemento na posição correta
    return max;  // Retorna o maior elemento
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {  // Lê o número de operações até o final do arquivo (EOF)
        Stack stack = { .top = -1 };  // Inicializa a pilha
        Queue queue = { .front = 0, .rear = -1 };  // Inicializa a fila
        PriorityQueue pq = { .size = 0 };  // Inicializa a fila de prioridade

        int isStack = 1, isQueue = 1, isPriorityQueue = 1;  // Flags para verificar a estrutura

        for (int i = 0; i < n; i++) {  // Loop para processar cada operação
            int op, x;
            scanf("%d", &op);  // Lê o tipo da operação (1 ou 2)

            if (op == 1) {  // Operação de inserção
                scanf("%d", &x);  // Lê o valor a ser inserido
                pushStack(&stack, x);  // Insere na pilha
                enqueue(&queue, x);  // Insere na fila
                pushPriorityQueue(&pq, x);  // Insere na fila de prioridade
            } else if (op == 2) {  // Operação de remoção
                scanf("%d", &x);  // Lê o valor esperado após a remoção

                // Verifica se a pilha está correta
                if (isStack && (stack.top == -1 || popStack(&stack) != x)) {
                    isStack = 0;  // Se não corresponder, a pilha não é válida
                }
                // Verifica se a fila está correta
                if (isQueue && (queue.front > queue.rear || dequeue(&queue) != x)) {
                    isQueue = 0;  // Se não corresponder, a fila não é válida
                }
                // Verifica se a fila de prioridade está correta
                if (isPriorityQueue && (pq.size == 0 || popPriorityQueue(&pq) != x)) {
                    isPriorityQueue = 0;  // Se não corresponder, a fila de prioridade não é válida
                }
            }
        }

        // Determina o tipo da estrutura com base nas flags
        if (isStack + isQueue + isPriorityQueue == 0) {
            printf("impossible\n");  // Nenhuma estrutura é válida
        } else if (isStack + isQueue + isPriorityQueue > 1) {
            printf("not sure\n");  // Mais de uma estrutura é válida
        } else if (isStack) {
            printf("stack\n");  // A estrutura é uma pilha
        } else if (isQueue) {
            printf("queue\n");  // A estrutura é uma fila
        } else if (isPriorityQueue) {
            printf("priority queue\n");  // A estrutura é uma fila de prioridade
        }
    }

    return 0;  
}
