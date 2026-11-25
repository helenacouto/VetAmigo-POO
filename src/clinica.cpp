#include "vetamigo/clinica.hpp"

#include <utility>

Clinica::Clinica(std::string nomeClinica) : nome_(std::move(nomeClinica)) {}

const std::string& Clinica::nome() const { return nome_; }

Clinica& Clinica::operator+=(std::unique_ptr<Animal> animal) {
    if (animal) {
        push_back(std::move(animal));
    }
    return *this;
}