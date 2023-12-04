# Trabalho 2 - Redes de Computadores (SSC0641)

[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/MatheusSanchez/networkSimulation/blob/main/README.md)
[![pt-br](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/MatheusSanchez/networkSimulation/blob/main/README.pt-br.md)

## Sobre o Trabalho

- **Versões do sistema operacional testadas:** Ubuntu 22.04, Fedora 36
- **Compiladores:** g++ 11 e 12
- **Descrição:**
    
    O propósito deste projeto é simular a comunicação entre dois computadores por meio de protocolos. Neste contexto, as informações e mensagens são transformadas em bits e transmitidas. Além disso, durante o recebimento, verifica-se a integridade dos valores por meio dos métodos estudados, que incluem o bit de paridade par, o bit de paridade ímpar e o CRC.
    Dado que toda a troca de informações ocorre na mesma máquina, é altamente improvável que ocorra corrupção de dados. Por esse motivo, introduziu-se uma chance aleatória de erro, a fim de avaliar a eficiência dos vários métodos de controle de erros.
    
## Como Executar

Para executar o simulador, é necessário apenas utilizar o Makefile disponível
no repositório. No diretório raiz do programa, execute o seguinte comando para
compilar o arquivo executável:

```bash
$ make all
```

Em seguida, para executar o simulador basta rodar:

```bash
$ make run
```

Há diversas formas de conferir a integridade da transmissão. Cada modelo pode ser selecionado alterando o paramêtro `ERROR_ROUTINE`
no arquivo `EnlaceLayer.hpp`. Neste, o valor desta variável implica na seguinte equivalência:

0. Controle de Erros por Paridade Par
1. Controle de Erros por Paridade Ímpar 
2. Controle de Erros pelo algoritmo CRC-32

Voce pode também trocar a probabilidade do erro nos dados no paramêtro `ERROR_PROB`
no arquivo `Thoroughfare.hpp`. 

A saída da aplicação pode ser realizada simplesmente ao digitar "exit" no terminal.
