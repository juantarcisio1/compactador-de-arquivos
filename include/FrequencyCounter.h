#ifndef FREQUENCY_COUNTER
#define FREQUENCY_COUNTER

#include <cstdint>
#include <string>
#include <array>

class FrequencyCounter {
    private:
        std::array<std::uint64_t, 256> frequencias;
        std::uint64_t totalBytes;

    public:
        FrequencyCounter();
        void contar(const std::string& caminho);
        std::uint64_t getFrequencia(unsigned char byte) const;
        std::uint64_t getTotalBytes() const;
};

#endif