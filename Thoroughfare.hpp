#ifndef __THOROUGHFARE__
#define __THOROUGHFARE__

#include <bits/stdc++.h>
#include "Logger.hpp"
#include "EnlaceLayer.hpp"

#define ERROR_PROB 7

class Thoroughfare {
   private:

    /**
     * Adiciona deturpaçao aos dados que chegam no meio físico
     * @param message 
     * @return Mensagem com erros aleatórios
     */
    static vector<bool> disorderGenerator(
        const vector<bool>& message);

   public:
    /**
     * Transmite a mensagem para a aplicação receptora, a mensagem tem até 7% de erro
     * @param message 
     */
    static void thoroughfareSender(const vector<bool>& message);
};

#endif