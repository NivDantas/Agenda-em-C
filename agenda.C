#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char data[20];
char horario[10];
char desc[140]; 
char prioridade[10];

typedef struct Agenda {
    char data[20];
    char horario[10];
    char desc[140];
    char prioridade[10];
    struct Agenda *prox;
} Agenda;

Agenda *criar_agenda() {
    return NULL;
}

Agenda *insereFinal(Agenda *a, char data[],char horario[], char desc[], char prioridade[]) {
    Agenda *novo = (Agenda*)malloc(sizeof(Agenda));
    Agenda *ls = (Agenda*)malloc(sizeof(Agenda));
    ls = a;
    strcpy(novo->data, data);
    strcpy(novo->horario, horario);
    strcpy(novo->desc, desc);
    strcpy(novo->prioridade, prioridade);
    if (a == NULL){
      return novo;
    }
    while (ls->prox != NULL){
    ls = ls->prox;
    }
    ls->prox = novo;
    return a;
}

Agenda *agendar_evento(Agenda *a){
  scanf("%s", data);
  scanf("%s", horario);
  scanf("%s", desc);
  scanf("%s", prioridade);
  a = insereFinal(a, data, horario, desc, prioridade);
  return a;
}

void quantificar_evento(Agenda *a){
  int contador = 0;
          while(a!=NULL){
            a = a->prox;
            contador++;
          }
          printf("%d\n", contador);
}
void proximo_evento(Agenda *a){
  if (a == NULL){
    printf("Lista nula\n");
    return;
  }
  printf("%s %s %s %s\n", a->data, a->horario, a->desc, a->prioridade);
}

Agenda *alterar(Agenda *a){
  scanf("%s", data);
  scanf("%s", horario);
  Agenda *novo = (Agenda*)malloc(sizeof(Agenda));
  novo = a;
  while(a!=NULL){
    if(strcmp(novo->data, data) == 0 && strcmp(novo->horario, horario) == 0){
      scanf("%s", data);
      scanf("%s", horario);
      scanf("%s", desc);
      scanf("%s", prioridade);
      strcpy(novo->data, data);
      strcpy(novo->horario, horario);
      strcpy(novo->desc, desc);
      strcpy(novo->prioridade, prioridade);
      return a;
  }
  novo = novo->prox;
}

printf("Valor não encontrado");
return 0;
}

Agenda *cancelar(Agenda *a){
  if (a == NULL){
    printf("Lista nula\n");
    return 0;
  }
  scanf("%s", data);
  scanf("%s", horario);
  Agenda *novo = (Agenda*)malloc(sizeof(Agenda));
  Agenda *anterior = (Agenda*)malloc(sizeof(Agenda));
  novo = a;
  if(strcmp(novo->data, data) == 0 && strcmp(novo->horario, horario) == 0){
  printf("%s %s %s %s\n", novo->data, novo->horario, novo->desc, novo->prioridade);
  novo = a->prox;
  return novo;
  }
  while(a!=NULL){
    if(strcmp(novo->data, data) == 0 && strcmp(novo->horario, horario) == 0){
      printf("%s %s %s %s\n", anterior->prox->data, anterior->prox->horario, anterior->prox->desc, anterior->prox->prioridade);
      anterior->prox = novo->prox;
      return a;
  }
  anterior = novo;
  novo = novo->prox;
}

printf("Valor não encontrado");
return 0;
}

Agenda *concluir(Agenda *a){
  if (a == NULL){
    printf("Lista nula\n");
    return 0;
  }
  Agenda *novo = (Agenda*)malloc(sizeof(Agenda));
  novo = a->prox;
  return novo;
}


int main() {
    Agenda *a;
    a = criar_agenda();
    int comando = 0;
    while(comando != -1){
        scanf("%d", &comando);
        if(comando == 1){
          a = agendar_evento(a);
        }
        else if(comando == 2){
          quantificar_evento(a);
        }
        else if(comando == 3){
          proximo_evento(a);
        }
        else if (comando == 4){
          a = alterar(a);
        }
        else if (comando == 5){
          a = cancelar(a);
        }
        else if (comando == 6){
          a = concluir(a);
        }
    }
    return 0;
}