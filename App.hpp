#ifndef __APP_RECEIVER__
#define __APP_RECEIVER__

#include <bits/stdc++.h>
#include "Logger.hpp"

class App {
    /**
     * @brief Transforma o vetor de bits (booleanos) em uma mensagem ASCII
     */
   public:
   static void appReceiver(vector<bool>& bytes);

   /**
    * @brief Faz a conversão da mensagem recebida para bits salvando em um vetor de booleanos, conseguimos trabalhar com os bits nesse formato
    */
   static void appSender(const std::string& msg);
};

#endif