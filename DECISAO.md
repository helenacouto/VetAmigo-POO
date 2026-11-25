# Decisões de projeto

## 1. Por que a base é abstrata?

Não existe "animal genérico" atendido na clínica: a base não sabe qual é a espécie nem quanto custa a consulta, então `especie()` e `valorConsulta()` não fazem sentido nela. Se tivessem corpo padrão, uma espécie nova que esquecesse de sobrescrever herdaria um valor errado em silêncio. Sendo puras, o compilador obriga cada derivada a responder.

## 2. Por que cada herança é da forma que é?

- Pública (`Cachorro`, `Gato` e `Coelho` de `Animal`): cada um é um animal e precisa poder ser usado onde um animal é esperado, como no acervo polimórfico da clínica.
- Múltipla (`Cachorro` de `Animal` e `Vacinavel`): o cachorro é um animal e também cumpre o contrato de poder receber vacina. A interface não tem dado nenhum, então não há estado duplicado nem ambiguidade.
- Privada (`Clinica` de `std::vector`): a clínica é feita com um vector, mas não é um vector. Reexpus só `begin`, `end`, `size` e `empty`. Deixei de expor `push_back`, `insert`, `erase`, `clear` e `operator[]`, porque ninguém de fora deve inserir no meio da lista, apagar um prontuário ou trocar um paciente. O cadastro só entra pelo `+=`.

## 3. Quem é dono de quê?

A `Clinica` é dona dos animais: eles ficam em `std::unique_ptr<Animal>` dentro do vector, e quando a clínica é destruída ela destrói todos. Isso está no tipo, e o `+=` recebe `std::unique_ptr<Animal>` por valor, o que transfere a posse para a clínica no momento do cadastro. Nenhum objeto é criado com `new` nem destruído com `delete`; tudo nasce com `std::make_unique`.

## 4. Por que cada operador é membro ou livre?

O `operator<<` é livre porque o operando da esquerda é o `ostream`, que não é uma classe minha, então não tenho como acrescentar um membro nele. O `operator+=` é membro porque o operando da esquerda é a própria `Clinica`, que é quem muda quando um paciente é cadastrado, e ele devolve `Clinica&`, como o `+=` embutido faz.

## Uso de assistente de IA
Usei o Claude (Sonnet 5.5) como guia do projeto: ele escreveu rascunhos da estrutura geral do projeto, do README e do DECISAO.md e tirou minhas dúvidas, e eu revisei e testei tudo com `make verifica`. O único erro que identifiquei foi uma contagem na explicação dele, que citou 13 asserções no `contrato.hpp` quando são 12, sem nenhum efeito no código.