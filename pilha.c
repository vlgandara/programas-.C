#include <stdio.h>
#include <stdlib.h>

struct Novo_No{ // Estrutura do N� com um inteiro (4 bytes) e um ponteiro apontando para um pr�ximo N� (8 bytes)
 int i;
 struct Novo_No *prox;
};
typedef struct Novo_No New_No;

int tam;

int menu(void); // Espelho das funções do programa
void iniciar(New_No *Pilha);
void opcao(New_No *Pilha, int op);
void esvaziar(New_No *Pilha);
void push(New_No *Pilha);
New_No *pop(New_No *Pilha);


int main(void)
{
 New_No *Pilha = (New_No *) malloc(sizeof(New_No)); // Alocamento de raiz
 if(!Pilha){
  printf("Sem espaço para alocamento!\n");
  exit(1);
 }else{
 iniciar(Pilha);
 int opt;

 do{  // Faça opt=menu enquanto opt = True, 0 para terminar
  opt=menu();
  opcao(Pilha,opt);
 }while(opt);

 free(Pilha);
 return 0;
 }
}

void iniciar(New_No *Pilha) // Prepara a pilha para ser inicializada
{
 Pilha->prox = NULL;
 tam=0;
}

int menu(void) // Menu de seleção
{
 int opt;

 printf("Escolha uma opção:\n");
 printf("0. Sair\n");
 printf("1. PUSH\n");
 printf("2. POP\n");
 printf("Opcao: "); scanf("%d", &opt);

 return opt;
}

void opcao(New_No *Pilha, int op) // Switch Case
{
 New_No *tmp;
 switch(op){
  case 0: // Caso para Esvaziar a pilha e sair do programa
   esvaziar(Pilha);
   break;

  case 1: // Caso para Push
   push(Pilha);
   break;

  case 2: // Caso para Pop
   tmp= pop(Pilha);
   if(tmp != NULL)
   printf("Retirado: %3d\n\n", tmp->i);
   break;

  default:
   printf("Opção inválida!\n\n");
 }
}

int vazia(New_No *Pilha) // Verificação de pilha vazia
{
 if(Pilha->prox == NULL)
  return 1;
 else
  return 0;
}

New_No *alocar() // Alocamento de espaço para Novo Nó
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

void esvaziar(New_No *Pilha) // Função que libera o espaço na memória
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

void push(New_No *Pilha)  // Função para comando Push da Pilha
{
 New_No *Novo=alocar();
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


New_No *pop(New_No *Pilha)          // Comando Pop da Pilha
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
