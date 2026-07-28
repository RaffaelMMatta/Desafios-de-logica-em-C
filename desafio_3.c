/*
    Nível 3: Manipulação Baixo Nível de Vetores e Strings
Tópicos integrados: Vetores (1D), strings, tabela ASCII.

Desafio: O Criptografador e Analisador de Padrões de Texto
A linguagem C não possui um tipo "String" real — tudo é um vetor de char terminado em \0. 
Escreva um programa que leia uma frase pelo teclado (usando leitura segura para espaços, como fgets).

Análise sem Bibliotecas: Sem usar funções de <string.h> (exceto para ler o tamanho, se necessário), 
percorra o vetor e conte: o número de vogais, de consoantes, de espaços em branco e de caracteres especiais/numéricos.

Transformação In-Place (Cifra de César Condicional): Modifique o próprio vetor na memória. 
Shift de +3 posições na tabela ASCII, mas apenas nas consoantes (ex: 'b' vira 'e', 'z' vira 'c'). 
Vogais, espaços e números devem permanecer intactos.

Inversão de Palavras: Inverta a ordem dos caracteres da string inteira diretamente no vetor original (sem criar um vetor auxiliar), 
garantindo que o caractere nulo \0 continue exatamente no final da cadeia.
*/

#include <stdio.h>
#include <string.h>

#define MAX 100
//===============================================
void contador(int *consoante, int *vogal, int *especiais, int *espacos, char *texto);
void pula_linha(char *texto);
void in_place(char *texto);
void inverter(char *texto);
//========================================


int main(){
    int consoante = 0, vogal = 0, especiais = 0, espacos = 0;
    char texto[MAX];
    printf("Digite um texto: ");
    fgets(texto, MAX, stdin);
    pula_linha(texto);
    contador(&consoante, &vogal, &especiais, &espacos, texto);
    printf("vogais: %d / consoante: %d / especiais/numeros: %d / espaços: %d\n", vogal, consoante, especiais, espacos);
    in_place(texto);
    printf("Texto criptografado: %s\n", texto);
    inverter(texto);
    printf("Texto invertido: %s\n", texto);

    return 0;
}


void contador(int *consoante, int *vogal, int *especiais, int *espacos, char *texto){
    for(int i = 0; i < MAX; i++){
        if(texto[i] == '\0')
            break;
        else if(texto[i] == ' '){
            (*espacos)++;
            continue;
        }       
        else if((texto[i] >= 'a' && texto[i] <= 'z') || (texto[i] >= 'A' && texto[i] <= 'Z'))
        {
            if(texto[i] == 'a' || texto[i] == 'e' || texto[i] == 'i' || texto[i] == 'o' || texto[i] == 'u' || texto[i] == 'A' || 
                texto[i] == 'E' || texto[i] == 'I' || texto[i] == 'O' || texto[i] == 'U'){
                
                (*vogal)++;
            }
            else{
                (*consoante)++;
            
            }
            continue;
        }
        else {
            (*especiais)++;

        }
    }
}

void pula_linha(char *texto){
    for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] == '\n'){
            texto[i] = '\0';
            break;
        }
    }
}

void in_place(char *texto) {
    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        int eh_letra = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        int eh_vogal = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
       
        if (eh_letra && !eh_vogal) {
         
            if ((c >= 'x' && c <= 'z') || (c >= 'X' && c <= 'Z')) {
                texto[i] -= 23; 
            } else {
                texto[i] += 3; 
            }
        }
    }
}

void inverter(char *texto) {
    int i = 0;
    int j = 0;
    char aux;
    
    while (texto[j] != '\0') {
    j++;
    }
    j--;
    while (i < j) {
        aux = texto[i];
        texto[i] = texto[j];
        texto[j] = aux;

        i++;
        j--;
    }
}