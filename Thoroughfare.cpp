#include "Thoroughfare.hpp"

vector<bool> Thoroughfare::disorderGenerator(const vector<bool>& message) {
    std::vector<bool> disorderedMessage;

    for (bool bit : message) {
        if ((rand() % 100) <= ERROR_PROB) {
            disorderedMessage.push_back(!bit);
        } else {
            disorderedMessage.push_back(bit);
        }
    }

    return disorderedMessage;
}

void Thoroughfare::thoroughfareSender(const vector<bool>& message) {
    vector<bool> finalMessage{};

    Logger::logBeginOfLayer("Camada Física de Transmissao");

    Logger::logInfo(Logger::bitsAsString(message), "-deturpação");
    finalMessage = Thoroughfare::disorderGenerator(message);
    Logger::logInfo(Logger::bitsAsString(finalMessage), "+deturpação");

    Logger::printDifference(message, finalMessage);

    Logger::logEndOfLayer("Camada Física de Transmissao");

    EnlaceLayer::enlaceLayerReceiver(finalMessage);
}
