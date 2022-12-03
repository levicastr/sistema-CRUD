#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

aluno* buscar_dados_aluno(aluno* raiz, int matricula){
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

void cadastrar_aluno(int matricula,char* nome,char* numero, char* email,int quantidade_disciplinas, disciplina **disciplinas,endereco* endereco_aluno){//ok
    aluno* aux = buscar_dados_aluno(raiz, matricula);
    if(aux == NULL || aux->matricula != matricula){// vazia ou eu posso adicionar
        aluno* novo_aluno = malloc (sizeof(aluno));
        novo_aluno->matricula = matricula;
        novo_aluno->nome_aluno = malloc(sizeof(char)*200);
        novo_aluno->numero_aluno = malloc(sizeof(char)*200);
        novo_aluno->email_aluno = malloc(sizeof(char)*200);

        strcpy(novo_aluno->nome_aluno,nome);
        strcpy(novo_aluno->numero_aluno,numero);
        strcpy(novo_aluno->email_aluno,email);
        novo_aluno->endereco_aluno = endereco_aluno;
        novo_aluno->quantidade_disciplinas = quantidade_disciplinas;
        novo_aluno->disciplinas = disciplinas;
        novo_aluno->filho_esq = NULL;
        novo_aluno->filho_dir = NULL;
        quantidade_alunos++;
        if(aux == NULL){ //add na raiz
            raiz = novo_aluno;
        }else{
            if(matricula < aux->matricula){
                aux->filho_esq = novo_aluno;
            }else{
                aux->filho_dir = novo_aluno;
            }
        }
    }else{//nao posso deixar add novamente pq neste caso havera chaves duplicadas
        printf("Cadastro inválido. Chave duplicada\n");
    }
}

aluno* remover_aluno(aluno *raiz, int matricula) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover_aluno
        if(raiz->matricula == matricula) {
            // remove nós folhas (nós sem filhos)
            if(raiz->filho_esq == NULL && raiz->filho_dir == NULL) {
                free(raiz);
                quantidade_alunos--;
                printf("Elemento folha removido: %d !\n", matricula);
                return NULL;
            }
            else{
                // remover_aluno nós que possuem dois 2 filho
                if(raiz->filho_esq != NULL && raiz->filho_dir != NULL){
                    aluno *aux = raiz->filho_esq; // subárvore à filho_esq
                    while(aux->filho_dir != NULL)
                        aux = aux->filho_dir; // obtêm o nó mais a filho_dir
                    raiz->matricula = aux->matricula;
                    aux->matricula = matricula;
                    printf("Elemento trocado: %d !\n", matricula);
                    raiz->filho_esq = remover_aluno(raiz->filho_esq, matricula);
                    return raiz;
                }
                else{
                    // remover_aluno nós que possuem apenas 1 filho
                    aluno *aux;
                    if(raiz->filho_esq != NULL)
                        aux = raiz->filho_esq;
                    else
                        aux = raiz->filho_dir;
                    free(raiz);
                    quantidade_alunos--;
                    printf("Elemento com 1 filho removido: %d !\n", matricula);
                    return aux;
                }
            }
        } else {
            if(matricula < raiz->matricula)
                raiz->filho_esq = remover_aluno(raiz->filho_esq, matricula);
            else
                raiz->filho_dir = remover_aluno(raiz->filho_dir, matricula);
            return raiz;
        }
    }
}


void editar_aluno(int matricula);

void imprimir_aluno(int matricula);

void read_banco_de_dados(FILE *banco_de_dados){//ok
    int aux, matricula, codigo_disciplina;
    float nota_final_disciplina;
    char nome[200], numero[200], email[200],nome_disciplina[200] ;  
    fscanf(banco_de_dados,"%i",&aux);
    for(int i = aux; 0 < i;i--){
        int quantidade_disciplinas = 0;
        fscanf(banco_de_dados,"%i",&matricula);
        fscanf(banco_de_dados,"%s",nome);
        fscanf(banco_de_dados,"%s",numero);
        fscanf(banco_de_dados,"%s",email);
        endereco* endereco = malloc(sizeof(endereco));
        endereco->nome_rua = malloc(sizeof(char)*200);
        fscanf(banco_de_dados,"%i",&endereco->numero_casa);
        fscanf(banco_de_dados,"%s",endereco->nome_rua);
        fscanf(banco_de_dados,"%i",&endereco->cep);

        fscanf(banco_de_dados,"%i",&quantidade_disciplinas);
        disciplina** disciplinas = malloc(sizeof(disciplina*)*quantidade_disciplinas);//ponteiro de disciplina
        for(int y = 0; y < quantidade_disciplinas;y++){
            disciplinas[y] = malloc(sizeof(disciplina));
            disciplinas[y]->nome_disciplina = malloc(sizeof(char)*200);
            fscanf(banco_de_dados,"%i",&disciplinas[y]->codigo_disciplina);
            fscanf(banco_de_dados,"%s",disciplinas[y]->nome_disciplina);
            fscanf(banco_de_dados,"%f",&disciplinas[y]->nota_final_disciplina);
        }
        cadastrar_aluno(matricula,nome,numero,email,quantidade_disciplinas,disciplinas,endereco);
    }
}

void in_ordem(aluno* aux, FILE *backup){
    if(aux == NULL){
        return;
    }else{
        in_ordem(aux->filho_esq,backup);
        fprintf(backup,"\n%i",aux->matricula);
        fprintf(backup,"\n%s",aux->nome_aluno);
        fprintf(backup,"\n%s",aux->numero_aluno);
        fprintf(backup,"\n%s",aux->email_aluno);
        fprintf(backup,"\n%i",aux->endereco_aluno->numero_casa);
        fprintf(backup,"\n%s",aux->endereco_aluno->nome_rua);
        fprintf(backup,"\n%i",aux->endereco_aluno->cep);
        fprintf(backup,"\n%i",aux->quantidade_disciplinas);
        for(int i = 0; i< aux->quantidade_disciplinas ;i++){
            fprintf(backup,"\n%i",aux->disciplinas[i]->codigo_disciplina);
            fprintf(backup,"\n%s",aux->disciplinas[i]->nome_disciplina);
            fprintf(backup,"\n%f",aux->disciplinas[i]->nota_final_disciplina);
        }
        in_ordem(aux->filho_dir,backup);
    }
}
void write_banco_de_dados(FILE *backup){
    fprintf(backup,"%i",quantidade_alunos);
    in_ordem(raiz, backup);
}

int main(){
    FILE* banco_de_dados = fopen("banco_de_dados.txt","r");
    FILE* backup = fopen("backup.txt","w");
    read_banco_de_dados(banco_de_dados);
   
    remover_aluno(raiz,511354);
   
    write_banco_de_dados(backup);
    fclose(banco_de_dados);
    fclose(backup);
  return 0;
}