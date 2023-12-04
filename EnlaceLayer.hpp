#ifndef __ENLACE_LAYER__
#define __ENLACE_LAYER__
#include <bits/stdc++.h>

#include "App.hpp"
#include "Logger.hpp"
#include "Thoroughfare.hpp"
#include "ParityAlgsTests.hpp"

/*
0. Controle de Erros por Paridade Par
1. Controle de Erros por Paridade Ímpar
2. Controle de Erros pelo algoritmo CRC-32
*/

#define ERROR_ROUTINE 2

class EnlaceLayer  {
   public:
    /**
     * Envia o frame para a camada de transporte, aplicando
     * algoritmos de controle
     */
    static void enlaceLayerSender(vector<bool> frame);
    /**
     * Recebe o frame e envia para a camada de aplicacao
     */
    static void enlaceLayerReceiver(vector<bool> frame);

    /**
     * Altera o frame adicionando bits para controle de erros, assim
     * coonseguimos checar a integridade no handleErrorReceiver
     */
    static vector<bool> handleError(vector<bool> frame);

    /**
     * Checa a integridade do frame recebido da camada de transporte
     */
    static bool handleErrorReceiver(vector<bool> frame);
};

#endif