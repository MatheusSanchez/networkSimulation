#include "EnlaceLayer.hpp"

void EnlaceLayer::enlaceLayerSender(vector<bool> frame) {
    Logger::logBeginOfLayer("Camada de Enlace");
    frame = handleError(frame);
    Thoroughfare::thoroughfareSender(frame);
}

vector<bool> EnlaceLayer::handleError(vector<bool> frame) {
    Logger::logInfo(
        ("Escolhendo heuristica de tratamento de inconsistencias."));

    switch (ERROR_ROUTINE) {
        case 0:
            Logger::logInfo(("Paridade Par."));
            return PartityAlgsTests::evenParity(frame);
        case 1:
            Logger::logInfo(("Paridade Impar."));
            return PartityAlgsTests::oddParity(frame);
        case 2:
            Logger::logInfo(("Polinomios."));
            return PartityAlgsTests::crc32(frame);
    }

    return frame;
}

void EnlaceLayer::enlaceLayerReceiver(vector<bool> frame) {
    Logger::logInfo("Camada de Enlace Receptora", "Camada de Enlace");

    if (EnlaceLayer::handleErrorReceiver(frame)){
        cout << Logger::red(string(30, '-')) << endl;
        cout << Logger::red(string(7, '-') + "[ERRO DETECTADO]" + string(7, '-'))
             << endl;
        cout << Logger::red(string(30, '-')) << endl;
    }

    Logger::logInfo("Binário Recebido", Logger::bitsAsString(frame));
  
    App::appReceiver(frame);
}

bool EnlaceLayer::handleErrorReceiver(vector<bool> frame) {
    Logger::logInfo(
        ("Escolhendo heuristica de teste de integridade"));

    switch (ERROR_ROUTINE) {
        case 0:
            Logger::logInfo(("Paridade Par."));
            return PartityAlgsTests::evenParityTest(frame);
        case 1:
            Logger::logInfo(("Paridade Impar."));
            return PartityAlgsTests::oddParityTest(frame);
        case 2:
            Logger::logInfo(("Polinomios."));
            return PartityAlgsTests::crc32Test(frame);
    }

    return false;
}

