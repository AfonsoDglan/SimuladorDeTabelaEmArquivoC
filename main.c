#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct disciplina{
    char nomeDaDisciplina [30];
	char numeroDaDisciplina [10];
	char departamento [10];
	int creditos;
}Disciplina;

typedef struct turma{
    int idTurma;
    char numeroDaDisciplina [10];
    char semestre [10];
    int ano;
    char professor [25];
}Turma;

typedef struct historico{
    int numeroDoEstudante;
    int idTurma;
    int nota;
}Historico;


//Assinatura das minhas funções.
void MenuPrincipal();//ok
void MenuTabelas();//ok
void CamposDisciplina();//ok
void CamposTurma();//ok
void CamposHistorico();//ok
void InsertDisciplina(Disciplina *Linha);//ok
void InsertTurma(Turma *Linha);//ok
void InsertHistorico(Historico *Linha);//ok
Disciplina * PreencherDisciplina();//ok
Historico * PreencherHistorico();//ok
Turma * PreencherTurma();//ok
int MostrarTabelaDisciplina();//ok
int MostrarTabelaTurma();//ok
int MostrarTabelaHistorico();//ok
void AlterarDisciplina();//ok
void AlterarTurma();//ok
void AlterarHistorico();//ok

int main() {
    setlocale(LC_ALL,"Portuguese");
    int saida = 1;
    while(saida == 1){
        int opcaoPrincipal;
        MenuPrincipal();
        scanf("%d",&opcaoPrincipal);
        switch (opcaoPrincipal){
        case 1:
            MenuTabelas();
            int opcaoTabela;
            scanf("%d",&opcaoTabela);
            switch (opcaoTabela){
            case 1:
                InsertDisciplina(PreencherDisciplina());
                getchar();
                break;
            case 2:
                InsertHistorico(PreencherHistorico());
                break;
            case 3:
                InsertTurma(PreencherTurma());
                break;
            case 4:
                break;
            default:
                printf("\tOPÇÃO INVÁLIDA TENTE NOVAMENTE.\n");
                break;
            }
            break;
        case 2:
            MenuTabelas();
            scanf("%d",&opcaoTabela);
            switch (opcaoTabela){
            case 1:
                AlterarDisciplina();
                break;
            case 2:
                AlterarHistorico();
                break;
            case 3:
                AlterarTurma();
                break;
            case 4:
                break;
            default:
                printf("\tOPÇÃO INVÁLIDA TENTE NOVAMENTE.\n");
                break;
            }
            break;
        case 3:
            //falta excluir
            break;
        case 4:
            MenuTabelas();
            scanf("%d",&opcaoTabela);
            switch (opcaoTabela){
            case 1:
                MostrarTabelaDisciplina();
                break;
            case 2:
                MostrarTabelaHistorico();
                break;
            case 3:
                MostrarTabelaTurma();
                break;
            case 4:
                break;
            default:
                printf("\tOPÇÃO INVÁLIDA TENTE NOVAMENTE.\n");
                break;
            }
            break;
        case 5:
            MostrarTabelaDisciplina();
            MostrarTabelaTurma();
            MostrarTabelaHistorico();
            break;
        case 6:
            saida = 0;
            break;
        default:
            printf("\tOPÇÃO INVÁLIDA TENTE NOVAMENTE.\n");
            break;
        }
    }
}

void MenuPrincipal(){
    printf("\t***************************************************************\n");
    printf("\t**                     MENU PRINCIPAL                        **\n");
    printf("\t***************************************************************\n");
    printf("\t[ 1 ] Inserir Novo Registros.\n");
    printf("\t[ 2 ] Atualização De Algum Campo.\n");
    printf("\t[ 3 ] Remoção De Registros.\n");
    printf("\t[ 4 ] Mostrar Uma Tabela.\n");
    printf("\t[ 5 ] Mostrar Todas Tabelas.\n");
    printf("\t[ 6 ] SAIR.\n");
    printf("\tOpção: ");
}

void MenuTabelas(){
    printf("\t***************************************************************\n");
    printf("\t**                        TABELAS                            **\n");
    printf("\t***************************************************************\n");
    printf("\t[ 1 ] Disciplina.\n");
    printf("\t[ 2 ] Histórico.\n");
    printf("\t[ 3 ] Turma.\n");
    printf("\t[ 4 ] Deseja VOLTAR.\n");
    printf("\tOpção: ");
}

void CamposDisciplina(){
    printf("\t***************************************************************\n");
    printf("\t**               CAMPOS DA TABELA DISCIPLINA                 **\n");
    printf("\t***************************************************************\n");
    printf("\t[ 1 ] Nome da Disciplina.\n");
    printf("\t[ 2 ] Número da Disciplina.\n");
    printf("\t[ 3 ] Departamento.\n");
    printf("\t[ 4 ] Creditos.\n");
    printf("\t[ 5 ] Deseja VOLTAR.\n");
    printf("\tOpção: ");
}

void CamposTurma(){
    printf("\t***************************************************************\n");
    printf("\t**               CAMPOS DA TABELA TURMA                      **\n");
    printf("\t***************************************************************\n");
    printf("\t[ 1 ] ID da Turma.\n");
    printf("\t[ 2 ] Número da Disciplina.\n");
    printf("\t[ 3 ] Semestre.\n");
    printf("\t[ 4 ] Ano.\n");
    printf("\t[ 5 ] Professor.\n");
    printf("\t[ 6 ] Deseja VOLTAR.\n");
    printf("\tOpção: ");
}

void CamposHistorico(){
    printf("\t***************************************************************\n");
    printf("\t**               CAMPOS DA TABELA HISTORICO                  **\n");
    printf("\t***************************************************************\n");
    printf("\t[ 1 ] Número do Estudante.\n");
    printf("\t[ 2 ] ID da Turma.\n");
    printf("\t[ 3 ] Nota.\n");
    printf("\t[ 4 ] Deseja VOLTAR.\n");
    printf("\tOpção: ");
}
void InsertDisciplina(Disciplina *Linha){
    FILE *arq;
    arq = fopen("Disciplina.dat","ab");
    fwrite(Linha,sizeof(Disciplina),1,arq);
    free(Linha);
    fclose(arq);
}
void InsertTurma(Turma *Linha){
    FILE *arq;
    arq = fopen("Turma.dat","ab");
    fwrite(Linha,sizeof(Turma),1,arq);
    free(Linha);
    fclose(arq);
}
void InsertHistorico(Historico *Linha){
    FILE *arq;
    arq = fopen("Historico.dat","ab");
    fwrite(Linha,sizeof(Historico),1,arq);
    free(Linha);
    fclose(arq);
}
Disciplina * PreencherDisciplina(){
    Disciplina *disciplinaInsert = (Disciplina*)malloc(sizeof(Disciplina));
    printf("\tNome da Disciplina: ");
    scanf("%s",disciplinaInsert->nomeDaDisciplina);
    printf("\n\tNúmero da Disciplina: ");
    scanf("%s",disciplinaInsert->numeroDaDisciplina);
    printf("\n\tDepartamento: ");
    scanf("%s",disciplinaInsert->departamento);
    printf("\n\tCreditos: ");
    scanf("%d",&disciplinaInsert->creditos);
    return disciplinaInsert;
}

Historico * PreencherHistorico(){
    Historico *historico = (Historico*)malloc(sizeof(Historico));
    printf("\tNúmero do Estudante: ");
    scanf("%d",&historico->numeroDoEstudante);
    printf("\n\tID da Turma: ");
    scanf("%d",&historico->idTurma);
    printf("\n\tNota: ");
    scanf("%d",&historico->nota);
    return historico;
}

Turma * PreencherTurma(){
    Turma *turma = (Turma*)malloc(sizeof(Turma));
    printf("\tID da Turma: ");
    scanf("%d",&turma->idTurma);
    printf("\n\tNúmero da Disciplina: ");
    scanf("%s",turma->numeroDaDisciplina);
    printf("\n\tSemestre: ");
    scanf("%s",turma->semestre);
    printf("\n\tAno: ");
    scanf("%d",&turma->ano);
    printf("\n\tProfessor: ");
    scanf("%s",turma->professor);
    return turma;
}

int MostrarTabelaDisciplina(){
    FILE *arq;
    Disciplina disciplina;
    int i = 1;
    arq = fopen("Disciplina.dat","rb");
    printf("\t***************************************************************\n");
    printf("\t**              REGISTROS DA TABELA DISCIPLINA               **\n");
    printf("\t***************************************************************\n");
    while(fread(&disciplina,sizeof(Disciplina),1,arq)) {
        printf("\n\t-------------------- Registro %d --------------------\n\n",i);
		printf("\t%s --> %s --> %s --> %d\n",disciplina.nomeDaDisciplina,disciplina.numeroDaDisciplina,disciplina.departamento,disciplina.creditos);
        i++;
    }
    fclose(arq);
    return i;
}
int MostrarTabelaTurma(){
    FILE *arq;
    Turma turma;
    int i = 1;
    arq = fopen("Turma.dat","rb");
    printf("\t***************************************************************\n");
    printf("\t**                REGISTROS DA TABELA TURMA                  **\n");
    printf("\t***************************************************************\n");
    while(fread(&turma,sizeof(Turma),1,arq) == 1) {
        printf("\n\t-------------------- Registro %d --------------------\n\n",i);
		printf("\t%d --> %s --> %s --> %d --> %s\n",turma.idTurma,turma.numeroDaDisciplina,turma.semestre,turma.ano,turma.professor);
        i++;
    }
    fclose(arq);
    return i;
}
int MostrarTabelaHistorico(){
    FILE *arq;
    Historico historico;
    int i = 1;
    arq = fopen("Historico.dat","rb");
    printf("\t***************************************************************\n");
    printf("\t**                REGISTROS DA TABELA HISTORICO              **\n");
    printf("\t***************************************************************\n");
    while(fread(&historico,sizeof(Historico),1,arq)) {
        printf("\n\t-------------------- Registro %d --------------------\n\n",i);
		printf("\t%d --> %d --> %d\n",historico.numeroDoEstudante,historico.idTurma,historico.nota);
        i++;
    }
    fclose(arq);
    return i;
}

void AlterarDisciplina(){
    FILE *file = fopen("Disciplina.dat", "rb+");
    Disciplina disciplina;
    int id,op;
    if(file){
        int i = MostrarTabelaDisciplina();
        printf("\t\nDigite o indice do contato que deseja alterar:");
        scanf("%d", &id);
        getchar();
        id--;
        if(id >= 0 && id < i - 1){
            fseek(file, id * sizeof(Disciplina), SEEK_SET);
            printf("\t\n[ 1 ] DESEJA ALTERAR TODOS OS CAMPOS.");
            printf("\t\n[ 2 ] CAMPO EM ESPECIFICO.");
            printf("\t\nOPÇÃO: ");
            scanf("%d",&op);
            if(op == 1){
                fwrite(PreencherDisciplina(), sizeof(Disciplina), 1, file);
            }else{
                fread(&disciplina,sizeof(Disciplina),1,file);
                printf("\t\n[ 1 ] ALTERAR O NOME DA DISCIPLINA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO NOME DA DISCIPLINA");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Nome da Disciplina: ");
                    scanf("%s",disciplina.nomeDaDisciplina);
                }
                printf("\t\n[ 1 ] ALTERAR O NÚMERO DA DISCIPLINA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO NÚMERO DA DISCIPLINA");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Número da Disciplina: ");
                    scanf("%s",disciplina.numeroDaDisciplina);
                }
                printf("\t\n[ 1 ] ALTERAR O DEPARTAMENTO");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO  NO DEPARTAMENTO");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Departamento: ");
                    scanf("%s",disciplina.departamento);
                }
                printf("\t\n[ 1 ] ALTERAR O CREDITOS");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO CREDITOS");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Creditos: ");
                    scanf("%d",&disciplina.creditos);
                }
                fseek(file, id * sizeof(Disciplina), SEEK_SET);
                fwrite(&disciplina, sizeof(Disciplina), 1, file);
            }
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");
    }
}


void AlterarHistorico(){
    FILE *file = fopen("Historico.dat", "rb+");
    Historico historico;
    int id,op;
    if(file){
        int i = MostrarTabelaHistorico();
        printf("\t\nDigite o indice do contato que deseja alterar:");
        scanf("%d", &id);
        getchar();
        id--;
        if(id >= 0 && id < i - 1){
            fseek(file, id * sizeof(Historico), SEEK_SET);
            printf("\t\n[ 1 ] DESEJA ALTERAR TODOS OS CAMPOS.");
            printf("\t\n[ 2 ] CAMPO EM ESPECIFICO.");
            printf("\t\nOPÇÃO: ");
            scanf("%d",&op);
            if(op == 1){
                fwrite(PreencherHistorico(), sizeof(Historico), 1, file);
            }else{
                fread(&historico,sizeof(Historico),1,file);
                printf("\t\n[ 1 ] ALTERAR O NÚMERO DO ESTUDANTE");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO NÚMERO DO ESTUDANTE");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Digite o Número do Estudante: ");
                    scanf("%d",&historico.numeroDoEstudante);
                }
                printf("\t\n[ 1 ] ALTERAR O ID DA TURMA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO ID DA TURMA");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("Digite o ID da Turma: ");
                    scanf("%d",&historico.idTurma);
                }
                printf("\t\n[ 1 ] ALTERAR A NOTA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NA NOTA");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                if (op == 1){
                    printf("Digite a Nota: ");
                    scanf("%d",&historico.nota);
                }
                fseek(file, id * sizeof(Historico), SEEK_SET);
                fwrite(&historico, sizeof(Historico), 1, file);
            }
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");
    }
}

void AlterarTurma(){
    FILE *file = fopen("Turma.dat", "rb+");
    Turma turma;
    int id,op;
    if(file){
        int i = MostrarTabelaTurma();
        printf("Retorno de i: %d",i);
        printf("\t\nDigite o indice do registro que deseja alterar:");
        scanf("%d", &id);
        getchar();
        id--;
        if(id >= 0 && id < i - 1){
            fseek(file, id * sizeof(Turma), SEEK_SET);
            printf("\t\n[ 1 ] DESEJA ALTERAR TODOS OS CAMPOS.");
            printf("\t\n[ 2 ] ALTERAR CAMPO EM ESPECIFICO.");
            printf("\t\nOPÇÃO: ");
            scanf("%d",&op);
            if(op == 1){
                fwrite(PreencherTurma(), sizeof(Turma), 1, file);
            }else{
                fread(&turma,sizeof(Turma),1,file);
                printf("\t\n[ 1 ] ALTERAR O ID DA TURMA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO ID DA TURMA.");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("\t\nDigite o ID da Turma: ");
                    scanf("%d",&turma.idTurma);
                }
                printf("\t\n[ 1 ] ALTERAR O NÚMERO DA DISCIPLINA");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO NÚMERO DA DISCIPLINA");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("\t\nDigite o Número da Disciplina: ");
                    scanf("%s",turma.numeroDaDisciplina);
                }
                printf("\t\n[ 1 ] ALTERAR O SEMESTRE");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO SEMESTRE");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("\t\nDigite o Semestre: ");
                    scanf("%s",turma.semestre);
                }
                printf("\t\n[ 1 ] DESEJA ALTERAR O ANO");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO ANO");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("\t\nDigite o Ano: ");
                    scanf("%d",&turma.ano);
                }
                printf("\t\n[ 1 ] ALTERAR O PROFESSOR");
                printf("\t\n[ 2 ] NÃO FAZER ALTERAÇÃO NO PROFESSOR");
                printf("\t\nOPÇÃO: ");
                scanf("%d",&op);
                getchar();
                if (op == 1){
                    printf("\t\nDigite o Professor: ");
                    scanf("%s",turma.professor);
                }
                fseek(file, id * sizeof(Turma), SEEK_SET);
                fwrite(&turma, sizeof(Turma), 1, file);
            }
        }
        fclose(file);
    }
    else{
        printf("\nErro ao abrir arquivo!\n");
    }
}