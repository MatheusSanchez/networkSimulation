#include "App.hpp"
#include "EnlaceLayer.hpp"

void App::appReceiver(vector<bool>& bits) {
    string msg{};
    bitset<8> bytes{};
    unsigned long character;
    int i = 0;

    Logger::logBeginOfLayer("Camada de Aplicaçao");
    Logger::logInfo("Convertendo para ASCII.");

    for (auto b : bits) {
        bytes[7 - i++ % 8] = b;

        if (i % 8 == 0) {
            character = bytes.to_ulong();
            msg += static_cast<char>(character);
        }
    }

    Logger::logInfo(msg, "Mensagem Recebida");
}

void App::appSender(const std::string& msg) {
    Logger::logBeginOfLayer("Camada de Aplicaçao Transmissora");
    Logger::logInfo("Convertendo os Bits.");
    Logger::logInfo(("Mensagem original: " + msg));

    // convertendo para bits
    vector<bool> frame;

    for (auto character : msg) {
        bitset<8> bits(character);
        string bitsAsString = bits.to_string();
        for (int i = 0; i < bitsAsString.size(); i++) {
            frame.push_back(bitsAsString[i] == '1');
        }
    }

    Logger::logInfo("Mensagem Convertida: " + Logger::bitsAsString(frame));
    
    EnlaceLayer::enlaceLayerSender(frame);
}
