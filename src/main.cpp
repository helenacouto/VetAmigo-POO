#include <iostream>
#include <memory>

#include "vetamigo/cachorro.hpp"
#include "vetamigo/clinica.hpp"
#include "vetamigo/coelho.hpp"
#include "vetamigo/contrato.hpp"
#include "vetamigo/gato.hpp"
#include "vetamigo/vacinavel.hpp"

namespace {

int totalVivos() { return Cachorro::vivos() + Gato::vivos() + Coelho::vivos(); }
int totalCriados() { return Cachorro::criados() + Gato::criados() + Coelho::criados(); }

}  // namespace

int main() {
    {
        Clinica clinica("VetAmigo");
        clinica += std::make_unique<Cachorro>("Thor", "Helena");
        clinica += std::make_unique<Gato>("Mia", "Helena");
        clinica += std::make_unique<Coelho>("Pipo", "Carlos");

        std::cout << "=== 1. o acervo polimorfico ===\n";
        for (const auto& animal : clinica) {
            std::cout << animal->ficha() << '\n';
        }

        std::cout << "=== 2. os operadores ===\n";
        for (const auto& animal : clinica) {
            std::cout << *animal << '\n';
        }
        std::cout << "pacientes em " << clinica.nome() << ": " << clinica.size() << '\n';
        (clinica += std::make_unique<Cachorro>("Luna", "Carlos"))
            += std::make_unique<Gato>("Tom", "Carlos");
        std::cout << "depois de += encadeado: " << clinica.size() << '\n';

        auto rex = std::make_unique<Cachorro>("Rex", "Ana");
        Vacinavel& paciente = *rex;
        paciente.aplicarVacina("antirrabica");
        bool repetida = paciente.aplicarVacina("antirrabica");
        std::cout << "vacinas de " << rex->nome() << ": " << paciente.totalVacinas()
                  << " (repetida aceita? " << (repetida ? "sim" : "nao") << ")\n";
    }

    std::cout << "=== 3. os contadores ===\n";
    {
        Clinica plantao("Plantao");
        plantao += std::make_unique<Cachorro>("Bidu", "Rita");
        plantao += std::make_unique<Gato>("Felix", "Rita");
        plantao += std::make_unique<Coelho>("Bolinha", "Rita");
        std::cout << "dentro do escopo: pacientes=" << plantao.size()
                  << " vivos=" << totalVivos() << " criados=" << totalCriados() << '\n';
    }
    std::cout << "depois do escopo: vivos=" << totalVivos()
              << " criados=" << totalCriados() << '\n';

    std::cout << "vivos=" << totalVivos() << '\n';
    return 0;
}