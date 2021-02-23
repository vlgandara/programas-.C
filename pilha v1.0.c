#include <stdio.h>
#include <stdlib.h>

struct Novo_No{
 int i;
 struct Novo_No *prox;
};
typedef struct Novo_No New_No;

int tam;

int menu(void); // Espelho das funções do programa
void inicia(New_No *Pilha);
void opcao(New_No *Pilha, int op);
void libera(New_No *Pilha);
void push(New_No *Pilha);
New_No *pop(New_No *Pilha);


int main(void)
{
 New_No *Pilha = (New_No *) malloc(sizeof(New_No));
 if(!Pilha){
  printf("Sem espaço para alocamento!\n");
  exit(1);
 }else{
 inicia(Pilha);
 int opt;

 do{  // Faça opt=menu enquanto opt = True
  opt=menu();
  opcao(Pilha,opt);
 }while(opt);

 free(Pilha);
 return 0;
 }
}

void inicia(New_No *Pilha)
{
 Pilha->prox = NULL;
 tam=0;
}

int menu(void)
{
 int opt;

 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. PUSH\n");
 printf("2. POP\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}

void opcao(New_No *Pilha, int op)
{
 New_No *tmp;
 switch(op){
  case 0:
   libera(Pilha);
   break;

  case 1:
   push(Pilha);
   break;

  case 2:
   tmp= pop(Pilha);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->i);
   break;

  default:
   printf("Opção inválida!\n\n");
 }
}

int vazia(New_No *Pilha)
{
 if(Pilha->prox == NULL)
  return 1;
 else
  return 0;
}

New_No *aloca()
{
 New_No *Novo=(New_No *) malloc(sizeof(New_No));
 if(!Novo){
  printf("Sem espaço para alocamento!\n");
  exit(1);
 }else{
  printf("Novo item da pilha: "); scanf("%d", &Novo->i);
  return Novo;
 }
}

void libera(New_No *Pilha) // função que libera o espaço na memória
{
 if(!vazia(Pilha)){
  New_No *proxNo,
     *atual;

  atual = Pilha->prox;
  while(atual != NULL){
   proxNo = atual->prox;
   free(atual);
   atual = proxNo;
  }
 }
}

void push(New_No *Pilha)
{
 New_No *Novo=aloca();
 Novo->prox = NULL;

 if(vazia(Pilha))
  Pilha->prox=Novo;
 else{
  New_No *tmp = Pilha->prox;

  while(tmp->prox != NULL)
   tmp = tmp->prox;

  tmp->prox = Novo;
 }
 tam++;
}


New_No *pop(New_No *Pilha)
{
 if(Pilha->prox == NULL){
  printf("A pilha já está vazia!\n\n");
  return NULL;
 }else{
  New_No *ultimo = Pilha->prox,
              *penultimo = Pilha;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}
