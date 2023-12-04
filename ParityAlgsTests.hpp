#ifndef __PARTITY_ALGS_TESTS__
#define __PARTITY_ALGS_TESTS__
#include <bits/stdc++.h>

#include "Logger.hpp"

class PartityAlgsTests {
   public:
    /**
     * @brief Adiciona Bit de paridade Par
     */
    static vector<bool> evenParity(vector<bool> frame);

    /**
     * @brief Teste de integridade utilizando paridade par.
     */
    static bool evenParityTest(vector<bool>& frame);

    /**
     * @brief Adiciona Bit de paridade Ímpar
     */
    static vector<bool> oddParity(vector<bool> frame);

    /**
     * @brief Teste de integridade utilizando paridade ímpar.
     */
    static bool oddParityTest(vector<bool>& frame);

    /**
     * @brief Executa o algoritmo CRC-32
     */
    static vector<bool> crc32(vector<bool> frame);

    /**
     * @brief Teste de integridade utilizando o algoritmo CRC-32
     */
    static bool crc32Test(vector<bool>& frame) ;

    /**
     * @brief Testa a paridade do frame (true if even)
     */
    static bool evenTest(vector<bool> frame);
   
};

#endif