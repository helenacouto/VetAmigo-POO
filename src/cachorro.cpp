#include "vetamigo/cachorro.hpp"

#include <algorithm>
#include <utility>

Cachorro::Cachorro(std::string nomeAnimal, std::string nomeTutor)
    : Animal(std::move(nomeAnimal), std::move(nomeTutor)) {
    ++vivos_;
    ++criados_;
}

Cachorro::~Cachorro() { --vivos_; }

std::string Cachorro::especie() const { return "Cachorro"; }

double Cachorro::valorConsulta() const { return 120.0; }

bool Cachorro::aplicarVacina(const std::string& vacina) {
    if (std::find(vacinas_.begin(), vacinas_.end(), vacina) != vacinas_.end()) {
        return false;  // já aplicada
    }
    vacinas_.push_back(vacina);
    return true;
}

int Cachorro::totalVacinas() const { return static_cast<int>(vacinas_.size()); }

int Cachorro::vivos() { return vivos_; }
int Cachorro::criados() { return criados_; }