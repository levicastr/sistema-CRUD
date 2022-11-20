#include <stdlib.h>
#include <stdio.h>

#ifndef LIB
#define LIB

typedef struct disciplina{
  int codigo;
  char *nome;
  float nota_final;
}disciplina;

typedef struct aluno{
  int matricula;
  struct aluno  *filho_esq;
  struct aluno  *filho_dir;
}aluno;

aluno *raiz = NULL;

void cadastrar_aluno(int matricula);//falta char *nome,char* telefone,char *email

void remover_aluno(aluno *raiz,int matricula);

void editar_aluno(aluno *raiz,int matricula);

aluno* buscar_dados_aluno(aluno *raiz,int matricula);

// aluno *read_banco_de_dados(FILE *banco_de_dados);

// void write_banco_de_dados(aluno *raiz,FILE *banco_de_dados);

#endif