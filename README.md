# Project 2 - Computer Networks (SSC0641)

[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/MatheusSanchez/networkSimulation/blob/main/README.md)
[![pt-br](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/MatheusSanchez/networkSimulation/blob/main/README.pt-br.md)

## About the Project

- **Tested Operating System Versions:** Ubuntu 22.04, Fedora 36
- **Compilers:** g++ 11 and 12
- **Description:**
    
    The purpose of this project is to simulate communication between two computers through protocols. In this context, information and messages are transformed into bits and transmitted. Additionally, during reception, the integrity of the values is verified through studied methods, including even parity, odd parity, and CRC.
    Given that all information exchange occurs on the same machine, data corruption is highly unlikely. For this reason, a random chance of error has been introduced to evaluate the efficiency of various error control methods.
    
## How to Run

To run the simulator, you only need to use the Makefile available in the repository. In the program's root directory, execute the following command to compile the executable file:

```bash
$ make all
```

Next, to run the simulator, simply execute:

```bash
$ make run
```

There are several ways to check the integrity of the transmission. Each model can be selected by changing the ERROR_ROUTINE parameter in the EnlaceLayer.hpp file. In this file, the value of this variable implies the following equivalence:

0. Error Control by Even Parity
1. Error Control by Odd Parity
2. Error Control by CRC-32 Algorithm

You can also change the data error probability in the `ERROR_PROB` parameter in the `Thoroughfare.hpp` file.

Exiting the application can be done simply by typing "exit" in the terminal.