/*
    Desafio: O Validador de Datas e Calculadora de Dia da Semana
Escreva um programa que receba três números inteiros representando um dia, mês e ano (ex: 29, 2, 2024).

Validação Lógica: Use operadores lógicos (&&, ||, !) e estruturas if/else para validar se a data existe no calendário gregoriano.

Atenção às regras do ano bissexto: ele deve ser divisível por 4, exceto os divisíveis por 100, a menos que também sejam divisíveis por 400.

Meses têm quantidades de dias diferentes (30, 31 ou 28/29).

Cálculo do Dia da Semana: Se a data for válida, aplique uma fórmula matemática de congruência (como a Congruência de Zeller ou um algoritmo de contagem de dias acumulados desde o ano 1) para descobrir em qual dia da semana essa data caiu.

Saída: Utilize um switch-case com o resultado do cálculo (0 a 6) para imprimir o dia por extenso (ex: "Quarta-feira"). Se a data for inválida, exiba uma mensagem de erro com a causa exata.

*/

#include <stdio.h>
int validar_dia(int, int, int);
int validar_mes(int);
int validar_bissexto(int);
char *dia_semana(int, int, int);
int main()
{
    int dia, mes, ano, validacao;
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mês: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    if (validar_mes(mes))
        validacao = validar_dia(dia, mes, ano);
    else
    {
        printf("data inexistente!\n");
        return 0;
    }

    if (validacao)
    {
        printf("%02d/%02d/%d é uma data valida!\n", dia, mes, ano);
        printf("Dia da semana: %s\n", dia_semana(dia, mes, ano));
    }
    else
        printf("%02d/%02d/%d é uma data invalida!\n", dia, mes, ano);

    return 0;
}

int validar_mes(int mes)
{
    if (mes >= 1 && mes <= 12)
        return 1;
    return 0;
}

int validar_dia(int dia, int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia <= 31 && dia >= 1)
            return 1;

        return 0;
    }
    else if (mes == 2)
    {
        if (validar_bissexto(ano) && (dia <= 29 && dia >= 1))
            return 1;
        else if (dia <= 28 && dia >= 1)
            return 1;
        return 0;
    }
    else
    {
        if (dia <= 30 && dia >= 1)
            return 1;

        return 0;
    }
}

int validar_bissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        return 1;
    return 0;
}

char *dia_semana(int dia, int mes, int ano)
{
    if (mes == 1 || mes == 2)
    {
        mes += 12;
        ano -= 1;
    }
    int z = (dia + (13 * (mes + 1) / 5) + ano + (ano / 4) - (ano / 100) + (ano / 400)) % 7;
    switch (z)
    {
    case 1:
        return "Domingo";
    case 2:
        return "Segunda-feira";
    case 3:
        return "Terça-feira";
    case 4:
        return "Quarta-feira";
    case 5:
        return "Quinta-feira";
    case 6:
        return "Sexta-feira";
    case 0:
        return "Sabado";
    default:
        return "ERROR";
    }
}
