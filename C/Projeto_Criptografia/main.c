#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    //string mensagem
    char entrada[128];
    //string sem espaços
    char espaco[128];
    //tamanho da string
    int tamanho;
    //posição das letras na string
    int posicao[128];
}mensagem;

typedef struct{
    //string chave
    char entrada[128];
    //posição das letras na string
    int posicao[128];
    //string sem espaços
    char espaco[128];
    //tamanho da string
    int tamanho;

}chave;

int troca(char palavra[128], int cont){
    int p=0;
    switch(palavra[cont]){
        case 'a':
            p=0;
            break;
        case 'b':
            p=1;
            break;
        case 'c':
            p=2;
            break;
        case 'd':
            p=3;
            break;
        case 'e':
            p=4;
            break;
        case 'f':
            p=5;
            break;
        case 'g':
            p=6;
            break;
        case 'h':
            p=7;
            break;
        case 'i':
            p=8;
            break;
        case 'j':
            p=9;
            break;
        case 'k':
            p=10;
            break;
        case 'l':
            p=11;
            break;
        case 'm':
            p=12;
            break;
        case 'n':
            p=13;
            break;
        case 'o':
            p=14;
            break;
        case 'p':
            p=15;
            break;
        case 'q':
            p=16;
            break;
        case 'r':
            p=17;
            break;
        case 's':
            p=18;
            break;
        case 't':
            p=19;
            break;
        case 'u':
            p=20;
            break;
        case 'v':
            p=21;
            break;
        case 'w':
            p=22;
            break;
        case 'x':
            p=23;
            break;
        case 'y':
            p=24;
            break;
        case 'z':
            p=25;
            break;
        }
        return p;
}

void valida(char *texto) {
    int cont, erro;

    do {
        fflush(stdin);
        gets(texto);

        for(cont=0;texto[cont]!='\0';cont++){
            if((texto[cont]>='a' && texto[cont]<='z')){
                erro = 0;
            }
            else{
                erro = 1;
                break;
            }
        }
        if(erro == 1) {
            printf("Inválido, não é permitido acentos nem caracteres especiais. Digite apenas letras.\n");
        }
    } while(erro == 1);
}


int main()
{
    char vigenere_matriz [26] [26] = {
    { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
    { 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
    { 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
    { 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
    { 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
    { 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
    { 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
    { 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
    { 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
    { 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
    { 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
    { 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
    { 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
    { 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
    { 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
    { 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
    { 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
    { 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
    { 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
    { 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
    { 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
    { 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
    { 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
    { 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
    { 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
    { 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}};

    char cod [128];
    char descod[128];
    //struct mensagem
    mensagem msg;
    //struct chave
    chave chv;
    //Variaveis para a matriz
    int p1=0;
    //contador
    int cont=0, cont_e=0;
    //variavel da função
    int posicao=0;
    int menu=0, menu2=0;
    //variavel de validação de erro
    int erro = 0;
    setlocale(LC_ALL, "");

    printf("Bem-vindo(a) ao programa de criptografia!\n");

    do{
        printf("\nEscolha uma opção:\n1 - Criptografar mensagem.\n2 - Descriptografar mensagem. \n3 - Sair do programa.\n");
        scanf("%d", &menu);
        erro=0;

        switch (menu)
        {
            case 1:
                system("cls");
                printf("Criptografar mensagem.\n");

                //entrada de dados e validação
                printf("Digite a mensagem: ");
                valida(msg.entrada);
                cont_e=0;
                for(cont=0; msg.entrada[cont]!='\0'; cont++){
                    if(msg.entrada[cont]!=' '){
                        msg.espaco[cont_e]=msg.entrada[cont];
                        cont_e++;
                    }
                }

                printf("\nDigite a chave: ");
                valida(chv.entrada);

                //laço usando função para a mensagem
                for(cont = 0; msg.espaco[cont]!='\0'; cont++){
                    posicao=troca(msg.espaco,cont);
                    msg.posicao[cont] = posicao;
                }
                //laço usando função para a chave
                msg.tamanho=strlen(msg.espaco);
                for(cont = 0; chv.entrada[cont]!='\0'; cont++){
                    posicao=troca(chv.entrada,cont);
                    chv.posicao[cont] = posicao;
                }

                chv.tamanho=strlen(chv.entrada);
                for(cont= 0;cont<msg.tamanho;cont++){
                    cod[cont]=vigenere_matriz[msg.posicao[cont]][chv.posicao[cont%chv.tamanho]];
                }

                printf("Mensagem criptografada: ");
                puts(cod);
                cont_e = 0;
                system("pause");
                break;

            case 2:
                do{
                    system("cls");
                    printf("Descriptografar mensagem.\n");
                    printf("\nEscolha uma opção:");
                    printf("\n1- Descriptografar texto");
                    printf("\n2- Descriptografar Frase Anterior");
                    printf("\n3- Menu Anterior\n");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\nInsira a frase codificada: ");
                            fflush(stdin);
                            valida(cod);

                            printf("\nInsira a chave: ");
                            fflush(stdin);
                            valida(chv.entrada);

                            for(cont = 0; chv.entrada[cont]!='\0'; cont++){
                                posicao=troca(chv.entrada,cont);
                                chv.posicao[cont] = posicao;
                            }
                            cont_e=0;
                            for (cont=0;cod[cont_e]!='\0';cont++){
                            p1=chv.posicao[cont_e%chv.tamanho];

                            if(vigenere_matriz[p1][cont]==cod[cont_e]){
                                descod[cont_e]=vigenere_matriz[0][cont];
                                cont=0;
                                cont_e++;
                                }
                            }
                            printf("\nMensagem descriptografada: ");
                            puts(descod);
                            system("pause");
                            break;
                        case 2:
                            cont_e=0;
                            for (cont=0;cod[cont_e]!='\0';cont++){
                            p1=chv.posicao[cont_e%chv.tamanho];

                            if(vigenere_matriz[p1][cont]==cod[cont_e]){
                                descod[cont_e]=vigenere_matriz[0][cont];
                                cont=0;
                                cont_e++;
                                }
                            }
                            printf("\nMensagem descriptografada: ");
                            puts(descod);
                            system("pause");
                            break;
                        case 3:

                            break;
                        default:
                            printf("\nOpção Inválida.");
                            erro = 1;

                    }
                }while(menu2 !=3 || erro == 1);
                break;

            case 3:
                break;

            default:
                printf("Opção inválida.\n");
                erro = 1;
            }
        }while(menu != 3 || erro == 1);

    return 0;
}
