#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"
    
    //globais
    char palavraSecretra[TAMANHO_PALAVRA];
    char chutes[26];
    int chutesDados = 0;

void abertura(){
    printf("***************************\n");
    printf("**     Jogo Da Forca     **\n");
    printf("***************************\n\n");
}

void chuta(){

    char chute;
    scanf(" %c", &chute);
    chutes[chutesDados] = chute;
    chutesDados++;
}

int jaChutou(char letra){
    int achou = 0;

    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(){
        for(int i = 0 ; i < (int)strlen(palavraSecretra); i++){
            
            //aqui estava o jaChutou
            int achou = jaChutou(palavraSecretra[i]);

            if(achou){
                printf("%c ", palavraSecretra[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");
}

void adicionaPalavra(){
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S'){
        char novaPalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? \n");
        scanf("%s", novaPalavra);

        FILE* f;
        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("Nao e foi possivel adicinar sua palavra \n ouve um erro na base da dados");
            exit(1);
        }
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++; // fazermos isso para incrementar o indice do arquivo
        //fazer notas
        fseek(f, 0, SEEK_SET); // fazemos isso pois o incremento é na variavel, então voltamos ela para o indice do arquivo
        fprintf(f, "%d", qtd); // e aqui escrevemos o novo valor do indice

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra);

        fclose(f);
    }
}

void escolhePalavra(){
    FILE* f ;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("desculpe, banco de palavras nao disponivel\n\n");
        exit(1);
    }
    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    for(int i = 0;i <= randomico; i++){
        fscanf(f, "%s", palavraSecretra);
    }

    fclose(f);
}

int acertou(){
    for(int i = 0; i <(int)strlen(palavraSecretra); i++){
        if(!jaChutou(palavraSecretra[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    
    int erros = 0;

    for(int i = 0; i < chutesDados; i++){
        int existe = 0;

        for(int j = 0; j < (int)strlen(palavraSecretra); j++){          
            if(chutes[i] == palavraSecretra[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

int main(){
    


   
    
//********************************************************************
    escolhePalavra();
    abertura();

    do{

        desenhaForca();
        chuta();
       

    }while(!acertou() && !enforcou());
   

    if(acertou()){
        printf("Parabens voce ganhou\n");
        printf("A palavra era %s", palavraSecretra);
        adicionaPalavra();
    }else{
        printf("voce perdeu, tente de novo\n");
        printf("A palavra era %s", palavraSecretra);
    }
}