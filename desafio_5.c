/*
    Nível 5: Arquitetura Modular e Estruturação de Dados
Tópicos integrados: Structs (registros), vetores de structs, Funções e Procedimentos.

Desafio: O Sistema de Diagnóstico de Frota de Veículos
Para solidificar como os dados complexos circulam no programa, desenvolva um mini-sistema que não rode todo dentro da main().

A Estrutura: Defina uma struct Veiculo contendo:

Placa (vetor de char)

Modelo (vetor de char)

Ano de fabricação (int)

Quilometragem atual (float)

Status de manutenção (int: 0 para "ok", 1 para "necessita reparo")

O Repositório: Na função main, declare um vetor de structs capaz de armazenar até 10 veículos.

Módulo de Funções e Procedimentos (Separação de Responsabilidades):

Procedimento cadastrarVeiculo(...): Recebe o vetor e o índice atual por parâmetro e faz a leitura de um novo veículo.

Função calcularMediaKm(...): Recebe o vetor de structs e retorna a quilometragem média da frota.

Procedimento gerarRelatórioManutencao(...): Percorra a frota e imprima exclusivamente os dados dos veículos que têm mais de 5 anos de uso E quilometragem superior a 100.000 km, alterando automaticamente o campo de status de manutenção desses veículos para 1.

Função buscarPorPlaca(...): Recebe a string de uma placa e o vetor de frota, retornando o índice do veículo encontrado ou -1 se não existir.

*/