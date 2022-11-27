#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

// void cadastrar_aluno(aluno *raiz,int matricula,char* nome,char* numero, char* email,disciplina** disciplinas){

// }


// aluno remover_aluno(aluno *raiz,int matricula){

// }


// void editar_aluno(aluno *raiz,int matricula){

// }

aluno* buscar_dados_aluno(aluno* raiz,int matricula){
    if(raiz == NULL){
        return NULL; //vazia
    }else if(matricula == raiz->matricula){
        return raiz; //encontrei :D
    }else if(matricula<raiz->matricula){ //buscar no lado esq
        if(raiz->filho_esq != NULL){
            return buscar_dados_aluno(raiz->filho_esq,matricula);
        }else{//esq esta vazia
            return raiz; //pai do elemento que não foi encontrado
        }
    }else{//buscar no lado dir
        if(raiz->filho_dir != NULL){
            return buscar_dados_aluno(raiz->filho_dir,matricula);
        }else{//dir esta vazia
            return raiz; //pai do elemento que não foi encontrado
        }
    }
}

// aluno *read_banco_de_dados(FILE *banco_de_dados){

// }

// void write_banco_de_dados(aluno *raiz,FILE *banco_de_dados){

// }

int main(){
  aluno *eu = malloc(sizeof(aluno));
  eu->matricula = 511354;
  eu->filho_dir = NULL;
  eu->filho_esq = NULL;
  aluno *tu = malloc(sizeof(aluno));
  raiz = eu;
  tu = buscar_dados_aluno(raiz,511354);
  printf("\n%i\n",tu->matricula);

  return 0;
}