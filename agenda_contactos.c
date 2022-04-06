/*
=============== AGENDA DE CONTACTOS ==============================================================================
=============== Projecto Criado por estudantes da Faculdade de Ciência e Tecnologia, do curso de Informática =====
=============== (Engenharia e Desenvolvimento de Softwares) da Universidade Licungo - Extensão da Beira. =========
=============== Estudantes: Santos Ussene, Milton Miquitaio, Crussi Estevão & Cleyton Israel M. F. Hung ==========
==================================================================================================================
Contribuição de Sumburane!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Agenda(void); //Inicialização
void Listar(void); //Inicialização

struct Agenda {
    char Nome[25];
    char Numero[15];
    char Categoria[35];
}; //Estrutura agenda e as suas variaveis...

struct VarG {
    int Op;
    char Cd;
}; // Estrutura com variaveis globais...

struct VarG Global;
struct Agenda Contacto; // Definição das Estruturas

FILE* Arq; //Ponteiro do arquivo que vai ser gerado simulando um Banco de dados .txt

void Agenda();
void Listar();

int main() {

    system("cls");

    printf("============================================================\n");
    printf("                    AGENDA DE CONTACTOS                     \n");
    printf("============================================================\n");
    printf("====================== Menu Principal ======================\n");
    printf("------------------------------------------------------------\n");
    printf("|||||--------------------------------------------------|||||\n");
    printf("|||||               1. Adicionar Contacto              |||||\n");
    printf("|||||               2. Ver Lista                       |||||\n");
    printf("|||||               3. Sair                            |||||\n");
    printf("|||||==================================================|||||\n");
    printf("============================================================\n\n");

    printf("Digite sua opcao: ");

    scanf("%d", &Global.Op);
    getchar(); // Limpa o buffer...

    switch (Global.Op) {
        case 1:
            Agenda();
            break;
        case 2:
            Listar();
            break;
        case 3:
            system("cls");
            printf("\n\n============================================================\n");
            printf("|||||           Obrigado por usar o programa.          |||||\n");
            printf("|||||                    Ate Ja!!!                     |||||\n");
            printf("============================================================\n\n");
            break;

        default:
            system("cls");
            printf("------------------------------------------------------------\n");
            printf("====================== Opcao Invalida! =====================\n");
            printf("--------------------- Tente novamente... -------------------\n");
            printf("------------------------------------------------------------\n");
            sleep(3);
            main();
            break;
    }
    return 0;
}

void Agenda() {
    system("cls");

    Arq = fopen("contactos.txt", "a"); //Abertura do Arquivo .txt para a inserir dados

    if(Arq == NULL) {
        printf("------------------------------------------------------------\n");
        printf("================= Nenhum Contacto Gravado! =================\n");
        printf("--------------------- Grave primeiro... --------------------\n");
        printf("------------------------------------------------------------\n");
        sleep(3);
        main();
        return 1;

    } else {
        printf("------------------------------------------------------------\n");
        printf("====================== CRIAR CONTACTO ======================\n");
        printf("------------------------------------------------------------\n\n");

        printf("\n====================== Nome => ");
        fgets(Contacto.Nome, 25, stdin);

        printf("\n====================== Numero => +258");
        fgets(Contacto.Numero, 15, stdin);

        printf("\n====================== Categoria => ");
        fgets(Contacto.Categoria, 35, stdin);

        printf("\n==================================================\n");
        printf("Finalizar a criacao? (S para sim / N para negar) "); //Conclusão da criação
        scanf("%c", &Global.Cd);

        if(Global.Cd == 's') {
            fprintf(Arq, "Nome: %sNumero: %sCategoria: %s", Contacto.Nome, Contacto.Numero, Contacto.Categoria);
            fprintf(Arq, "----------------------\n"); //Salva os dados no arquivo .txt já gerado...

            fclose(Arq); //Fecha o arquivo se os dados forem guardados...

            system("cls");
            printf("------------------------------------------------------------\n");
            printf("==================== CONTACTO GUARDADO! ====================\n");
            printf("------------------------------------------------------------\n");
            sleep(3);
            main();
        } else if(Global.Cd == 'n') {
            system("cls");
            printf("------------------------------------------------------------\n");
            printf("======================== CANCELADO! ========================\n");
            printf("------------------- Processando o Menu... ------------------\n");
            printf("------------------------------------------------------------\n");

            fclose(Arq); //Fecha o arquivo se os dados nao forem guardados...

            getchar(); //Corrige o problema quando Global.Cd != 's' && 'n'
            sleep(3);
            main();
        } else {
            printf("------------------------------------------------------------\n");
            printf("====================== Opcao Invalida! =====================\n");
            printf("--------------------- Tente novamente... -------------------\n");
            printf("------------------------------------------------------------\n");
            fclose(Arq);
            sleep(3);
            Agenda();
        }
    }
}

void Listar() {
    system("cls");

    Arq = fopen("contactos.txt", "r"); //Abertura do arquivo para leitura de dados

    if(Arq == NULL) {
        printf("------------------------------------------------------------\n");
        printf("================= Nenhum Contacto Gravado! =================\n");
        printf("--------------------- Grave primeiro... --------------------\n");
        printf("------------------------------------------------------------\n");
        sleep(3);
        main();
    } else {
        printf("------------------------------------------------------------\n");
        printf("==================== LISTA DE CONTACTOS ====================\n");
        printf("------------------------------------------------------------\n");

        char listagem[250]; //String geral para os dados

        while(fgets(listagem, 250, Arq) != NULL) {
            printf("%s", listagem);
        }

        fclose(Arq);

        printf("\n=======================================================\n");
        printf("Voltar ao Menu principal? (S para sim / N para negar) ");
        scanf("%c", &Global.Cd);

        if(Global.Cd == 's') {
            main();
        } else if(Global.Cd != 's' && Global.Cd != 'n') {
            printf("------------------------------------------------------------\n");
            printf("====================== Opcao Invalida! =====================\n");
            printf("--------------------- Tente novamente... -------------------\n");
            printf("------------------------------------------------------------\n");
            sleep(3);
            main();
        }
    }
}
