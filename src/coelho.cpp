#include "vetamigo/coelho.hpp"

#include <utility>

Coelho::Coelho(std::string nomeAnimal, std::string nomeTutor)
    : Animal(std::move(nomeAnimal), std::move(nomeTutor)) {
    ++vivos_;
    ++criados_;
}

Coelho::~Coelho() { --vivos_; }

std::string Coelho::especie() const { return "Coelho"; }

double Coelho::valorConsulta() const { return 70.0; }

int Coelho::vivos() { return vivos_; }
int Coelho::criados() { return criados_; }