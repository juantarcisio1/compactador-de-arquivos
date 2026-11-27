#include "FrequencyCounter.h"
#include <fstream>
#include <stdexcept>

FrequencyCounter::FrequencyCounter() {
    frequencias.fill(0);
    totalBytes = 0;
}

void FrequencyCounter::contar(const std::string& caminho) {
    std::ifstream arquivo(caminho, std::ios::binary);

    if(!arquivo.is_open()) {
        throw std::runtime_error("Nao foi possivel abrir o arquivo.");
    }

    frequencias.fill(0);
    totalBytes = 0;

    char byte;

    while (arquivo.get(byte)) {
        frequencias[static_cast<unsigned char>(byte)]++;
        totalBytes++;
    }

    if (!arquivo.eof() || arquivo.bad()) {
        throw std::runtime_error("Erro durante a leitura do arquivo.");
    } 
}

std::uint64_t FrequencyCounter::getFrequencia(unsigned char byte) const {
    return frequencias[byte];
}

std::uint64_t FrequencyCounter::getTotalBytes() const {
    return totalBytes;
}