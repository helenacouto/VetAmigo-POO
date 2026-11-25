#pragma once

#include <iosfwd>
#include <string>

class Animal {
public:
    Animal(std::string nomeAnimal, std::string nomeTutor);
    virtual ~Animal() = default;

    // Base polimórfica não se copia por valor
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

    const std::string& nome() const;
    const std::string& tutor() const;

    // Operações que cada espécie responde à sua maneira
    virtual std::string especie() const = 0;
    virtual double valorConsulta() const = 0;

    // A moldura é da base; o conteúdo vem das puras
    std::string ficha() const;

private:
    std::string nome_;
    std::string tutor_;
};

std::ostream& operator<<(std::ostream& saida, const Animal& animal);