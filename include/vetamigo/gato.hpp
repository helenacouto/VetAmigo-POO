#pragma once

#include <string>

#include "vetamigo/animal.hpp"

class Gato final : public Animal {
public:
    Gato(std::string nomeAnimal, std::string nomeTutor);
    ~Gato() override;

    std::string especie() const override;
    double valorConsulta() const override;

    static int vivos();
    static int criados();

private:
    static inline int vivos_ = 0;
    static inline int criados_ = 0;
};