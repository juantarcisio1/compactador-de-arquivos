#ifndef HUFFMAN_NODE
#define HUFFMAN_NODE

#include <cstdint>

class HuffmanNode {
    public:
        unsigned char caractere;
        std::uint64_t freq;
        HuffmanNode* esquerda;
        HuffmanNode* direita;

        // Construtor de Nó Folha
        HuffmanNode(unsigned char caractere, uint64_t frequencia) {
            this->caractere = caractere;
            this->freq = frequencia;
            direita = esquerda = nullptr;
        }

        // Construtor de Nó Interno
        HuffmanNode(HuffmanNode* esquerda, HuffmanNode* direita) {
            this->caractere = 0;
            this->freq = esquerda->freq + direita->freq;
            this->esquerda = esquerda;
            this->direita = direita;
        }

        bool ehFolha() const {
            return ((esquerda == nullptr) && (direita == nullptr));
        }
};

#endif