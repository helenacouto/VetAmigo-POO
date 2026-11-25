# VetAmigo

Trabalho prático da Unidade II de Programação Orientada a Objetos (UFPB, 2026.2), em C++17.

## O tema

A VetAmigo é uma clínica veterinária de bairro que quer sair do caderninho de papel. Cada paciente é um animal de uma espécie (cachorro, gato ou coelho), com um tutor e um valor de consulta que depende da espécie. A clínica guarda os seus pacientes e é responsável por eles: quando ela fecha, os registros vão junto.

Alguns animais cumprem um contrato do domínio, o de poder receber vacina. O sistema também precisa provar que nenhum registro ficou para trás, por isso cada espécie conta quantos objetos foram criados e quantos continuam vivos.

## Como compilar e rodar

Requisitos: CMake 3.16 ou superior e um compilador com suporte a C++17 (GCC ou Clang).

```
make            # configura e compila
make roda       # compila e executa a demonstração
make verifica   # compila com -Werror, roda e confere que a última linha é vivos=0
make limpa      # apaga a pasta build/
```

## As cinco classes

| Classe | Papel | Forma de herança |
|---|---|---|
| `Animal` | base abstrata, com `especie()` e `valorConsulta()` puras e `ficha()` não virtual | nenhuma |
| `Vacinavel` | interface pura, o contrato "pode receber vacina" | nenhuma |
| `Cachorro` | concreta `final`, com contadores `vivos`/`criados` | pública de `Animal` e pública de `Vacinavel` (múltipla) |
| `Gato` e `Coelho` | concretas `final`, com contadores `vivos`/`criados` | pública de `Animal` |
| `Clinica` | coleção dos pacientes, com `operator+=` | privada de `std::vector<std::unique_ptr<Animal>>` |

## Saída de `make roda`

```
=== 1. o acervo polimorfico ===
Thor (Cachorro), tutor: Helena, consulta: R$ 120.00
Mia (Gato), tutor: Helena, consulta: R$ 90.00
Pipo (Coelho), tutor: Carlos, consulta: R$ 70.00
=== 2. os operadores ===
Thor (Cachorro), tutor: Helena, consulta: R$ 120.00
Mia (Gato), tutor: Helena, consulta: R$ 90.00
Pipo (Coelho), tutor: Carlos, consulta: R$ 70.00
pacientes em VetAmigo: 3
depois de += encadeado: 5
vacinas de Rex: 1 (repetida aceita? nao)
=== 3. os contadores ===
dentro do escopo: pacientes=3 vivos=3 criados=9
depois do escopo: vivos=0 criados=9
vivos=0
```