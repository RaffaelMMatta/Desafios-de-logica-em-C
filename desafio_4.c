/*
    Nível 4: Matrizes e Lógica Espacial
Tópicos integrados: Matrizes (arrays multidimensionais), loops aninhados.

Desafio: O Radar de Zonas de Calor (Matriz 5x5)
Construa uma matriz de inteiros 5x5 preenchida com valores que representam temperaturas em diferentes zonas de um terreno (você pode inseri-los via teclado ou gerá-los de forma pseudoaleatória).

Varredura de Subgrade: Escreva um algoritmo com loops aninhados que percorra a matriz e localize qual subgrade 3x3 dentro da matriz 5x5 possui a maior média de temperatura. Imprima as coordenadas (linha/coluna) do canto superior esquerdo dessa subgrade vencedora.

Filtro de Anomalias (Deteção de Picos): Percorra a matriz identificando "picos de calor". Um elemento é considerado um pico se a temperatura dele for estritamente maior do que a de todos os seus vizinhos imediatos (cima, baixo, esquerda, direita e diagonais). Atenção às bordas e cantos da matriz, que possuem menos vizinhos — sua lógica de índices não pode tentar acessar posições inválidas de memória (ex: índice -1).

*/