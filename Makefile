SHELL := /bin/bash
BUILD := build

.PHONY: all roda verifica limpa

all:
	cmake -S . -B $(BUILD)
	cmake --build $(BUILD)

roda: all
	./$(BUILD)/vetamigo

verifica: all
	@set -o pipefail; ./$(BUILD)/vetamigo | tail -n 1 | grep -qx "vivos=0" \
		&& echo "verifica: OK (vivos=0)" \
		|| { echo "verifica: FALHOU"; exit 1; }

limpa:
	rm -rf $(BUILD)