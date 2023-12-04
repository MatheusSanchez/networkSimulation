#ifndef __LOG_H__
#define __LOG_H__

using namespace std;

class Logger {
    /**
     * @brief Logs para vizualizaçao personalizada, cada um é usado em um momento das camadas;
    */
   public:
    static void logBeginOfLayer(const string& layer) {
        cout << Logger::green(("[" + layer + "]" +
                               string(60 - (layer.size()), '-') + "[START]"))
             << endl;
    }

    static void logEndOfLayer(const string& layer) {
        cout << Logger::green(("[" + layer + "]" +
                               string(60 - (layer.size()), '-') + "[ END ]"))
             << endl;
    }

    static void logInfo(const string& message,
                        const string& typeMessage = "INFO",
                        const bool endLine = true) {
        cout << Logger::blue("[" + typeMessage + "]: ") + message;

        if (endLine) {
            cout << endl;
        }
    }

    /**
     * @brief Adicionando cor ao print no terminal para melhorar o debug
     */
    static string red(const string& str) {
        return string{"\033[1m\033[31m" + str + "\033[0m"};
    }

    static string green(const string& str) {
        return string{"\033[1m\033[32m" + str + "\033[0m"};
    }

    static string blue(const string& str) {
        return string{"\033[1m\033[34m" + str + "\033[0m"};
    }

    /**
     * @brief Printa o array de booleans no terminal
    */

    static string bitsAsString(const vector<bool>& bits) {
        string stringBits = "";

        for (int i = 0; i < bits.size(); i++) {
            if(bits[i]){
                stringBits += '1';
            }else{
                stringBits += '0';
            }
            if ((i + 1) % 8 == 0) stringBits += " ";
        }
        return stringBits;
    }

    /**
     * @brief Print para comparar dois arrays
    */

    static void printDifference(const vector<bool>& og,
                                const vector<bool>& comp) {
        cout << Logger::green(string(28, '-') + "[Diferenças]" +
                              string(28, '-'))
             << endl;

        for (int i = 0, j = 0; i < og.size(); i++, j++) {
            cout << ((og[i] != comp[i])
                              ? Logger::red(to_string(comp[i]))
                              : to_string(comp[i]));

            
            if ((j + 1) % 8 == 0) cout << " ";

            
        }

        cout << endl;
        cout << endl;
    }
};

#endif