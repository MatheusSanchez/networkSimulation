
#include <bits/stdc++.h>

#include "App.hpp"
#include "EnlaceLayer.hpp"
#include "Logger.hpp"
#include "ParityAlgsTests.hpp"

using namespace std;

int main() {
    
    Logger::logBeginOfLayer("Aplicaçao Transmissora");
    string msg{};


    while (true) { // Loop para a aplicaçao ficar pedindo input
        Logger::logInfo("Digite sua mensagem: ", "INPUT", false);
        getline(cin, msg);

        if (msg.compare("exit") == 0) {
            cout << Logger::red("[EXIT]" + string(20, '=') + "[EXIT]" +
                                string(20, '=') + "[EXIT]")
                 << endl;
            break;
        }

        Logger::blue("Mensagem Recebida: " + msg);
        App::appSender(msg);
    }

    Logger::logEndOfLayer("Aplicaçao Transmissora");

    return 0;
}