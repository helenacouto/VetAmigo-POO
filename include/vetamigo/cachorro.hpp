#pragma once

#include <string>
#include <vector>

#include "vetamigo/animal.hpp"
#include "vetamigo/vacinavel.hpp"

// É um Animal e cumpre o contrato Vacinavel (herança múltipla)
class Cachorro final : public Animal, public Vacinavel {
public:
    Cachorro(std::string nomeAnimal, std::string nomeTutor);
    ~Cachorro() override;

    std::string especie() const override;
    double valorConsulta() const override;

    bool aplicarVacina(const std::string& vacina) override;
    int totalVacinas() const override;

    static int vivos();
    static int criados();

private:
    std::vector<std::string> vacinas_;
    static inline int vivos_ = 0;
    static inline int criados_ = 0;
};