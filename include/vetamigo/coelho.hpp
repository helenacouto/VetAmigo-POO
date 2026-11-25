#pragma once

#include <string>

#include "vetamigo/animal.hpp"

class Coelho final : public Animal {
public:
    Coelho(std::string nomeAnimal, std::string nomeTutor);
    ~Coelho() override;

    std::string especie() const override;
    double valorConsulta() const override;

    static int vivos();
    static int criados();

private:
    static inline int vivos_ = 0;
    static inline int criados_ = 0;
};