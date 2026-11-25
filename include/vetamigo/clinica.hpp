#pragma once

#include <memory>
#include <string>
#include <vector>

#include "vetamigo/animal.hpp"

// A clínica é feita com um vector, não é um vector (herança privada)
class Clinica : private std::vector<std::unique_ptr<Animal>> {
    using Base = std::vector<std::unique_ptr<Animal>>;

public:
    // Só o que faz sentido para a clínica fica visível
    using Base::begin;
    using Base::end;
    using Base::empty;
    using Base::size;

    explicit Clinica(std::string nomeClinica);

    const std::string& nome() const;

    // Única porta de entrada: cadastrar um paciente
    Clinica& operator+=(std::unique_ptr<Animal> animal);

private:
    std::string nome_;
};