#include <stdlib.h>
#include <stdio.h>

typedef struct disciplina{
  int codigo;
  char *nome;
  float nota_final;
}aluno;

typedef struct aluno{
  int matricula;
  char *nome;
  char *telefone;
  char *email;
  int semestre;
  disciplina *disciplinas;
  aluno  *filho_esq;
  aluno  *filho_dir;
}aluno;

aluno *raiz = NULL;

void cadastrar_aluno(aluno *raiz,int matricula,char *nome,char* telefone,char *email);

void remover_aluno(aluno *raiz,int matricula);

void editar_aluno(aluno *raiz,int matricula);

aluno* buscar_dados_aluno(aluno *raiz,int matricula);

aluno *read_banco_de_dados(FILE *banco_de_dados);

void write_banco_de_dados(aluno *raiz,FILE *banco_de_dados);
