#include "ParityAlgsTests.hpp"

vector<bool> PartityAlgsTests::evenParity(vector<bool> frame) {
    Logger::logInfo(("Adicionando o bit de paridade"), "PARIDADE-PAR");

    Logger::logInfo(("[" + Logger::bitsAsString(frame) + "]"));
    frame.insert(frame.begin(), PartityAlgsTests::evenTest(frame));
    Logger::logInfo(("[" + Logger::bitsAsString(frame) + "]"));

    return frame;
}
vector<bool> PartityAlgsTests::oddParity(vector<bool> frame) {
    Logger::logInfo(("Adicionando o bit de paridade"), "PARIDADE-IMPAR");

    Logger::logInfo(("[" + Logger::bitsAsString(frame) + "]"));
    frame.insert(frame.begin(), !PartityAlgsTests::evenTest(frame));
    Logger::logInfo(("[" + Logger::bitsAsString(frame) + "]"));

    return frame;
}

vector<bool> PartityAlgsTests::crc32(vector<bool> frame) {
    Logger::logInfo(("Executando CRC32"), "CRC32");

    vector<bool> remaining = frame;
    remaining.resize(remaining.size() + 32);

    // 100000100110000010001110110110111 -> x32 + x26 + x23 + x22 + x16 + x12 +
    // x11 + x10 + x8 + x7 + x5 + x4 + x2 + x1 + x0
    vector<bool> polynomial{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1,
                            0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    Logger::logInfo("[" + Logger::bitsAsString(polynomial) + "]", "Polinomio");

    for (int i = 0; i < remaining.size() - 32; i++) {
        if (remaining[i]) {
            for (int j = 0; j < polynomial.size(); j++) {
                remaining[i + j] = remaining[i + j] ^ polynomial[j];
            }
        }
        remaining[i] = frame[i];
    }

    Logger::logInfo("[" + Logger::bitsAsString(remaining) + "]", "Resto");

    return remaining;
}

bool PartityAlgsTests::evenTest(vector<bool> frame) { // true if even
    bool even = false;

    for (auto bit : frame) {
        if (bit) {
            even = !even;
        }
    }

    return !even;
}

bool PartityAlgsTests::evenParityTest(std::vector<bool>& frame) {
    bool parity = frame[0];
    frame.erase(frame.begin());

    if (parity) {
        if (PartityAlgsTests::evenTest(frame)) {
            return false;
        } else {
            return true;
        }
    } else {
        if (PartityAlgsTests::evenTest(frame)) {
            return true;
        } else {
            return false;
        }
    }
}

bool PartityAlgsTests::oddParityTest(std::vector<bool>& frame) {
    bool parity = frame[0];
    frame.erase(frame.begin());

    if (parity) {
        if (!PartityAlgsTests::evenTest(frame)) {
            return false;
        } else {
            return true;
        }
    } else {
        if (!PartityAlgsTests::evenTest(frame)) {
            return true;
        } else {
            return false;
        }
    }
}

bool PartityAlgsTests::crc32Test(std::vector<bool>& frame) {
    std::vector<bool> remaining = frame;
    std::vector<bool> polinomio{1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
                                0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1,
                                1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    remaining.resize(remaining.size());

    for (int i = 0; i < remaining.size() - 32; i++) {
        if (remaining[i]) {
            for (int j = 0; j < polinomio.size(); j++) {
                remaining[i + j] = remaining[i + j] ^ polinomio[j];
            }
        }
        remaining[i] = frame[i];
    }

    Logger::logInfo("[" + Logger::bitsAsString(remaining) + "]", "Resto");

    bool hasError = false;
    for (int i = 0; i < polinomio.size() - 1; i++) {
        frame.erase(frame.end());
        if (!hasError) hasError = remaining[remaining.size()];
        remaining.erase(remaining.end());
    }

    return hasError;
}
