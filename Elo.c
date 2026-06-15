# Projeto-Elo


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_USUARIOS "C:\\Users\\kauan\\Desktop\\emc2\\usuarios.txt"
#define ARQ_DIARIO   "C:\\Users\\kauan\\Desktop\\emc2\\diario.txt"

void criarArquivos();
int login(char tipo[]);

void menuAdministrador();
void menuEnfermeiro();
void menuFamiliar();

void cadastrarEnfermeiro();
void cadastrarFamiliar();
void listarUsuarios();

void cadastrarRegistro();
void listarRegistros();

int main()
{
    criarArquivos();

    int opcao;
    char tipo[20];

    do
    {
        system("cls");

        printf("=====================================\n");
        printf("               Elo                    \n");
        printf("=====================================\n");
        printf("1 - Fazer Login\n");
        printf("0 - Sair\n");
        printf("=====================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao)
        {
            case 1:

                if(login(tipo))
                {
                    if(strcmp(tipo, "ADM") == 0)
                        menuAdministrador();

                    else if(strcmp(tipo, "ENFERMEIRO") == 0)
                        menuEnfermeiro();

                    else if(strcmp(tipo, "FAMILIAR") == 0)
                        menuFamiliar();
                }

                break;

            case 0:
                printf("\nSistema encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    }while(opcao != 0);

    return 0;
}

void criarArquivos()
{
    FILE *arq;

    arq = fopen(ARQ_USUARIOS, "r");

    if(arq == NULL)
    {
        arq = fopen(ARQ_USUARIOS, "w");

        fprintf(arq, "ADM;admin;1234\n");

        fclose(arq);
    }
    else
    {
        fclose(arq);
    }

    arq = fopen(ARQ_DIARIO, "a");
    fclose(arq);
}

int login(char tipo[])
{
    FILE *arq;

    char usuario[50];
    char senha[50];

    char tipoArq[20];
    char usuarioArq[50];
    char senhaArq[50];

    system("cls");

    printf("========== LOGIN ==========\n");

    printf("Usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    arq = fopen(ARQ_USUARIOS, "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir usuarios.txt\n");
        system("pause");
        return 0;
    }

    while(fscanf(arq,
                 "%[^;];%[^;];%[^\n]\n",
                 tipoArq,
                 usuarioArq,
                 senhaArq) == 3)
    {
        if(strcmp(usuario, usuarioArq) == 0 &&
           strcmp(senha, senhaArq) == 0)
        {
            strcpy(tipo, tipoArq);

            fclose(arq);

            printf("\nLogin realizado com sucesso!\n");
            system("pause");

            return 1;
        }
    }

    fclose(arq);

    printf("\nUsuario ou senha incorretos.\n");
    system("pause");

    return 0;
}

void menuAdministrador()
/*=========================================================
admin
1234
=========================================================
*/
{
    int op;

    do
    {
        system("cls");

        printf("========== ADMINISTRADOR ==========\n");
        printf("1 - Novo Registro\n");
        printf("2 - Consultar Registros\n");
        printf("3 - Cadastrar Enfermeiro\n");
        printf("4 - Cadastrar Familiar\n");
        printf("5 - Listar Usuarios\n");
        printf("0 - Sair\n");
        printf("===================================\n");
        printf("Opcao: ");

        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                cadastrarRegistro();
                break;

            case 2:
                listarRegistros();
                break;

            case 3:
                cadastrarEnfermeiro();
                break;

            case 4:
                cadastrarFamiliar();
                break;

            case 5:
                listarUsuarios();
                break;
        }

    }while(op != 0);
}

void menuEnfermeiro()
{
    int op;

    do
    {
        system("cls");

        printf("========== ENFERMEIRO ==========\n");
        printf("1 - Novo Registro\n");
        printf("2 - Consultar Registros\n");
        printf("0 - Sair\n");
        printf("================================\n");
        printf("Opcao: ");

        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                cadastrarRegistro();
                break;

            case 2:
                listarRegistros();
                break;
        }

    }while(op != 0);
}

void menuFamiliar()
{
    int op;

    do
    {
        system("cls");

        printf("========== FAMILIAR ==========\n");
        printf("1 - Consultar Registros\n");
        printf("0 - Sair\n");
        printf("==============================\n");
        printf("Opcao: ");

        scanf("%d", &op);
        getchar();

        switch(op)
        {
            case 1:
                listarRegistros();
                break;
        }

    }while(op != 0);
}

void cadastrarEnfermeiro()
{
    FILE *arq;

    char usuario[50];
    char senha[50];

    arq = fopen(ARQ_USUARIOS, "a");

    system("cls");

    printf("===== CADASTRO ENFERMEIRO =====\n");

    printf("Usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    fprintf(arq,
            "ENFERMEIRO;%s;%s\n",
            usuario,
            senha);

    fclose(arq);

    printf("\nEnfermeiro cadastrado!\n");
    system("pause");
}

void cadastrarFamiliar()
{
    FILE *arq;

    char usuario[50];
    char senha[50];

    arq = fopen(ARQ_USUARIOS, "a");

    system("cls");

    printf("===== CADASTRO FAMILIAR =====\n");

    printf("Usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';

    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    fprintf(arq,
            "FAMILIAR;%s;%s\n",
            usuario,
            senha);

    fclose(arq);

    printf("\nFamiliar cadastrado!\n");
    system("pause");
}

void listarUsuarios()
{
    FILE *arq;

    char linha[200];

    arq = fopen(ARQ_USUARIOS, "r");

    system("cls");

    printf("===== USUARIOS CADASTRADOS =====\n\n");

    while(fgets(linha, sizeof(linha), arq))
    {
        printf("%s", linha);
    }

    fclose(arq);

    printf("\n");
    system("pause");
}

void cadastrarRegistro()
{
    FILE *arq;

    char data[20];
    char idoso[100];
    char humor[100];
    char alimentacao[200];
    char medicamentos[200];
    char atividades[200];
    char observacoes[300];

    arq = fopen(ARQ_DIARIO, "a");

    system("cls");

    printf("===== NOVO REGISTRO =====\n");

    printf("Data: ");
    fgets(data, sizeof(data), stdin);

    printf("Nome do Idoso: ");
    fgets(idoso, sizeof(idoso), stdin);

    printf("Humor: ");
    fgets(humor, sizeof(humor), stdin);

    printf("Alimentacao: ");
    fgets(alimentacao, sizeof(alimentacao), stdin);

    printf("Medicamentos: ");
    fgets(medicamentos, sizeof(medicamentos), stdin);

    printf("Atividades: ");
    fgets(atividades, sizeof(atividades), stdin);

    printf("Observacoes: ");
    fgets(observacoes, sizeof(observacoes), stdin);

    fprintf(arq,"\n=========================================\n");
    fprintf(arq,"Data: %s", data);
    fprintf(arq,"Idoso: %s", idoso);
    fprintf(arq,"Humor: %s", humor);
    fprintf(arq,"Alimentacao: %s", alimentacao);
    fprintf(arq,"Medicamentos: %s", medicamentos);
    fprintf(arq,"Atividades: %s", atividades);
    fprintf(arq,"Observacoes: %s", observacoes);
    fprintf(arq,"=========================================\n");

    fclose(arq);

    printf("\nRegistro salvo com sucesso!\n");
    system("pause");
}

void listarRegistros()
{
    FILE *arq;

    char linha[500];

    arq = fopen(ARQ_DIARIO, "r");

    system("cls");

    printf("===== HISTORICO DO IDOSO =====\n\n");

    while(fgets(linha, sizeof(linha), arq))
    {
        printf("%s", linha);
    }

    fclose(arq);

    printf("\n");
    system("pause");
}
