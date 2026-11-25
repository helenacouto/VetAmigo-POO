#pragma once

#include <memory>
#include <type_traits>
#include <vector>

#include "vetamigo/animal.hpp"
#include "vetamigo/cachorro.hpp"
#include "vetamigo/clinica.hpp"
#include "vetamigo/coelho.hpp"
#include "vetamigo/gato.hpp"
#include "vetamigo/vacinavel.hpp"

// R5: a base
static_assert(std::is_abstract_v<Animal>,
              "Animal deve ser abstrata (tem funcoes puramente virtuais)");
static_assert(std::has_virtual_destructor_v<Animal>,
              "Animal deve ter destrutor virtual");
static_assert(!std::is_copy_constructible_v<Animal>,
              "Animal nao pode ser copiavel (base polimorfica)");

// R6: a interface
static_assert(sizeof(Vacinavel) == sizeof(void*),
              "Vacinavel so pode ter o ponteiro da vtable, nenhum dado");

// R7: as concretas
static_assert(!std::is_abstract_v<Cachorro> && std::is_final_v<Cachorro>,
              "Cachorro deve ser concreta e final");
static_assert(!std::is_abstract_v<Gato> && std::is_final_v<Gato>,
              "Gato deve ser concreta e final");
static_assert(!std::is_abstract_v<Coelho> && std::is_final_v<Coelho>,
              "Coelho deve ser concreta e final");
static_assert(std::is_convertible_v<Cachorro*, Animal*>,
              "Cachorro deve converter para Animal (heranca publica)");

// R8: heranca multipla
static_assert(std::is_base_of_v<Animal, Cachorro>,
              "Cachorro deve derivar de Animal");
static_assert(std::is_base_of_v<Vacinavel, Cachorro>,
              "Cachorro deve derivar de Vacinavel");

// R9: heranca privada (deriva, mas nao substitui)
static_assert(std::is_base_of_v<std::vector<std::unique_ptr<Animal>>, Clinica>,
              "Clinica deve derivar do vector (e feita com ele)");
static_assert(!std::is_convertible_v<Clinica*, std::vector<std::unique_ptr<Animal>>*>,
              "Clinica nao pode converter para o vector (heranca privada)");