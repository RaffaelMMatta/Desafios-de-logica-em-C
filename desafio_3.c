/*
    Nível 3: Manipulação Baixo Nível de Vetores e Strings
Tópicos integrados: Vetores (1D), strings, tabela ASCII.

Desafio: O Criptografador e Analisador de Padrões de Texto
A linguagem C não possui um tipo "String" real — tudo é um vetor de char terminado em \0. Escreva um programa que leia uma frase pelo teclado (usando leitura segura para espaços, como fgets).

Análise sem Bibliotecas: Sem usar funções de <string.h> (exceto para ler o tamanho, se necessário), percorra o vetor e conte: o número de vogais, de consoantes, de espaços em branco e de caracteres especiais/numéricos.

Transformação In-Place (Cifra de César Condicional): Modifique o próprio vetor na memória. Shift de +3 posições na tabela ASCII, mas apenas nas consoantes (ex: 'b' vira 'e', 'z' vira 'c'). Vogais, espaços e números devem permanecer intactos.

Inversão de Palavras: Inverta a ordem dos caracteres da string inteira diretamente no vetor original (sem criar um vetor auxiliar), garantindo que o caractere nulo \0 continue exatamente no final da cadeia.



*/