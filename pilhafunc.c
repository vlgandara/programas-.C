#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node New_No;

int tam;

int menu(void);
void inicia(New_No *PILHA);
void opcao(New_No *PILHA, int op);
void exibe(New_No *PILHA);
void libera(New_No *PILHA);
void push(New_No *PILHA);
New_No *pop(New_No *PILHA);


int main(void)
{
 New_No *PILHA = (New_No *) malloc(sizeof(New_No));
 if(!PILHA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(PILHA);
 int opt;

 do{
  opt=menu();
  opcao(PILHA,opt);
 }while(opt);

 free(PILHA);
 return 0;
 }
}

void inicia(New_No *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;

 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Zerar PILHA\n");
 printf("2. Exibir PILHA\n");
 printf("3. PUSH\n");
 printf("4. POP\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}

void opcao(New_No *PILHA, int op)
{
 New_No *tmp;
 switch(op){
  case 0:
   libera(PILHA);
   break;

  case 1:
   libera(PILHA);
   inicia(PILHA);
   break;

  case 2:
   exibe(PILHA);
   break;

  case 3:
   push(PILHA);
   break;

  case 4:
   tmp= pop(PILHA);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->num);
   break;

  default:
   printf("Comando invalido\n\n");
 }
}

int vazia(New_No *PILHA)
{
 if(PILHA->prox == NULL)
  return 1;
 else
  return 0;
}

New_No *aloca()
{
 New_No *novo=(New_No *) malloc(sizeof(New_No));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: "); scanf("%d", &novo->num);
  return novo;
 }
}


void exibe(New_No *PILHA)
{
 if(vazia(PILHA)){
  printf("PILHA vazia!\n\n");
  return ;
 }

 New_No *tmp;
 tmp = PILHA->prox;
 printf("PILHA:");
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n        ");
 int count;
 for(count=0 ; count < tam ; count++)
  printf("  ^  ");
 printf("\nOrdem:");
 for(count=0 ; count < tam ; count++)
  printf("%5d", count+1);


 printf("\n\n");
}

void libera(New_No *PILHA)
{
 if(!vazia(PILHA)){
  New_No *proxNode,
     *atual;

  atual = PILHA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}

void push(New_No *PILHA)
{
 New_No *novo=aloca();
 novo->prox = NULL;

 if(vazia(PILHA))
  PILHA->prox=novo;
 else{
  New_No *tmp = PILHA->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = novo;
 }
 tam++;
}


New_No *pop(New_No *PILHA)
{
 if(PILHA->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  New_No *ultimo = PILHA->prox,
              *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}