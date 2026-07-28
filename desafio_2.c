#include <stdio.h>
#define MAX_CHAR 40
#define MAX_TRANS 100
float depositar(float saldo, char extrato[MAX_TRANS][MAX_CHAR], int *erros_consecutivos);
float sacar(float saldo, char extrato[MAX_TRANS][MAX_CHAR], int *erros_consecutivos);
void imprimir_extrato(float saldo, char extrato[MAX_TRANS][MAX_CHAR]);

int main()
{
    float saldo = 0.0;
    int cond = 0;
    int erros_consecutivos = 0;
    char extrato[MAX_TRANS][MAX_CHAR] = {0};
    do
    {
        if (erros_consecutivos >= 3)
        {
            printf("\n[ALERTA DE SEGURANÇA] Conta bloqueada por múltiplas tentativas suspeitas!\n");
            break; // Sai do do-while imediatamente
        }
        printf("================================\n");
        printf("===                          ===\n");
        printf("=== MENU DO CAIXA ELETRÔNICO ===\n");
        printf("===                          ===\n");
        printf("================================\n");
        printf("1 -> Depósito\n");
        printf("2 -> Saque\n");
        printf("3 -> Extrato\n");
        printf("4 -> Sair\n");
        scanf("%d", &cond);

        if (cond == 4)
            break;
        switch (cond)
        {
        case 1:
            saldo += depositar(saldo, extrato, &erros_consecutivos);
            break;
        case 2:
            saldo -= sacar(saldo, extrato, &erros_consecutivos);
            break;
        case 3:
            imprimir_extrato(saldo, extrato);
            break;
        default:
            printf("Opção inválida!\n");
            erros_consecutivos++;
            break;
        }
    } while (1);

    return 0;
}
float depositar(float saldo, char extrato[MAX_TRANS][MAX_CHAR], int *erros_consecutivos)
{
    float valor;
    printf("Digite o valor do depósito: ");
    scanf("%f", &valor);
    if (valor <= 0)
    {
        printf("Valor inválido! Tente novamente.\n");
        (*erros_consecutivos)++;
        return 0; // devolve nenhum valor se o usuário exceder o número máximo de tentativas
    }
    (*erros_consecutivos) = 0; // resetar contador de erros consecutivos após operação bem-sucedida
    printf("Depósito realizado com sucesso!\n");
    for (int i = 0; i < MAX_TRANS; i++)
    {
        if (extrato[i][0] == '\0')
        {
            snprintf(extrato[i], MAX_CHAR, "Depósito: R$ %.2f", valor);
            break;
        }
    }
    return valor;
}
float sacar(float saldo, char extrato[MAX_TRANS][MAX_CHAR], int *erros_consecutivos)
{
    float valor;
    printf("Digite o valor do saque: ");
    scanf("%f", &valor);
    if (valor <= 0 || valor > saldo || valor > 1000)
    {
        printf("Valor inválido! Tente novamente.\n");
        (*erros_consecutivos)++;
        return 0; // devolve nenhum valor se o usuário exceder o número máximo de tentativas
    }
    (*erros_consecutivos) = 0; // resetar contador de erros consecutivos após operação bem-sucedida
    printf("Saque realizado com sucesso!\n");
    for (int i = 0; i < MAX_TRANS; i++)
    {
        if (extrato[i][0] == '\0')
        {
            snprintf(extrato[i], MAX_CHAR, "Saque: R$ %.2f", valor);
            break;
        }
    }
    return valor;
}

void imprimir_extrato(float saldo, char extrato[MAX_TRANS][MAX_CHAR])
{

    for (int i = 0; i < MAX_TRANS; i++)
    {
        if (extrato[i][0] != '\0')
        {
            printf("%s\n", extrato[i]);
        }
        else
        {
            break;
        }
    }
    printf("Saldo atual: %.2f\n", saldo);
}

/*
        Nível 2: Controle de Fluxo Acumulativo e Interrupções
Tópicos integrados: while, do-while, for, break, continue.

Desafio: O Caixa Eletrônico com Auditoria e Bloqueio de Segurança
Crie um simulador de caixa eletrônico rodando em um loop principal (do-while) que apresente um menu interativo: 1. Depósito | 2. Saque | 3. Extrato | 4. Sair.

Regras de Negócio:

O saldo inicial é zero. O usuário pode fazer depósitos e saques sucessivos.

Em uma operação de saque, se o valor solicitado for maior que o saldo ou ultrapassar o limite por transação de R$ 1.000,00, exiba um aviso e use o comando continue para abortar o restante do bloco e voltar ao início do menu sem registrar a transação.

Segurança (Loops Contados e Interrupção):

O usuário tem um limite máximo de 3 transações de saque por sessão (use um laço for ou contador integrado).

Se o usuário digitar um valor inválido (negativo ou zero) por 3 vezes consecutivas em qualquer operação, o sistema deve acionar um alerta de fraude e usar o comando break para encerrar o programa imediatamente, ignorando a opção "Sair".

Nível 3: Manipulação Baixo Nível de Vetores e Strings

*/