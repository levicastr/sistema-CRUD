#include "lib.h"

void cadastrar_aluno(aluno *raiz,int matricula,char *nome,char* telefone,char *email){
  if(raiz == NULL){
    aluno *new_aluno = malloc(sizeof(aluno));
    raiz = new_aluno;
  }else{
    buscar_dados_aluno(raiz,matricula); 
  }
}

void remover_aluno(aluno *raiz,int matricula);

void editar_aluno(aluno *raiz,int matricula);

aluno* buscar_dados_aluno(aluno *raiz,int matricula);

aluno *read_banco_de_dados(FILE *banco_de_dados){
  aluno *raiz = malloc(sizeof(aluno));

}

void write_banco_de_dados(aluno *raiz,FILE *banco_de_dados);

void main(){
  FILE *banco_de_dados = fopen("banco_de_dados.txt","r");

}