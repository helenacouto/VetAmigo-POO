#include "vetamigo/animal.hpp"

#include <iomanip>
#include <ostream>
#include <sstream>
#include <utility>

Animal::Animal(std::string nomeAnimal, std::string nomeTutor)
    : nome_(std::move(nomeAnimal)), tutor_(std::move(nomeTutor)) {}

const std::string& Animal::nome() const { return nome_; }
const std::string& Animal::tutor() const { return tutor_; }

std::string Animal::ficha() const {
    std::ostringstream texto;
    texto << nome_ << " (" << especie() << "), tutor: " << tutor_
          << ", consulta: R$ " << std::fixed << std::setprecision(2)
          << valorConsulta();
    return texto.str();
}

std::ostream& operator<<(std::ostream& saida, const Animal& animal) {
    return saida << animal.ficha();
}