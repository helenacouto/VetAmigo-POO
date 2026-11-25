#pragma once

#include <string>

// Contrato do domínio: quem pode receber vacina. Sem nenhum dado.
class Vacinavel {
public:
    virtual ~Vacinavel() = default;

    virtual bool aplicarVacina(const std::string& vacina) = 0;
    virtual int totalVacinas() const = 0;
};