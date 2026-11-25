#include "vetamigo/gato.hpp"

#include <utility>

Gato::Gato(std::string nomeAnimal, std::string nomeTutor)
    : Animal(std::move(nomeAnimal), std::move(nomeTutor)) {
    ++vivos_;
    ++criados_;
}

Gato::~Gato() { --vivos_; }

std::string Gato::especie() const { return "Gato"; }

double Gato::valorConsulta() const { return 90.0; }

int Gato::vivos() { return vivos_; }
int Gato::criados() { return criados_; }