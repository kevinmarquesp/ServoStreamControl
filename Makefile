## Diretórios do próprio projeto, pra facilitar caso seja melhor mudar a
## convensão de nome de alguma coisa
SKETCH_NAME ?= ServoStreamControl
TESTS_DIR ?= test
TEMPLATES_DIR ?= templates
VENDOR_DIR ?= vendor

## Esses detalhes podem ser diferentes na sua máquina, leia as documentações do
## arduino-cli e altere essas linhas caso necessário
BOARD_SHORT ?= uno
BOARD_LONG ?= arduino:avr:uno
PORT ?= /dev/ttyUSB0

## Esses arquivos devem estar localizados na máquina do desenvolvedor para que
## tudo posse ser compilado e/ou testado corretamente, é importante que o
## sketch final não dependa deles e o projeto seja facilmente compilado apenas
## com o Arduino IDE!
ARDUINO_CLI_BIN ?= ${HOME}/.local/bin/arduino-cli
AUNITER_BIN ?= ${HOME}/.local/share/AUniter/auniter.sh  #modifyed! (veja o README.md)

## O desenvolvedor não precisará baixar na máquina as bibliotecas que estiverem
## em `vendor/`, a usabilidade no que se diz nos `#include`'s se mantém a mesma
ARDUINO_CLI_VENDOR_FLAGS ?= --library $(VENDOR_DIR)/ParallelServo \
							--library $(VENDOR_DIR)/StringSplitter \
							--library $(VENDOR_DIR)/LinkedList

## Essas flags serão úteis para a suite de testes apenas
ARDUINO_CLI_SRC_FLAGS ?= --library $(SKETCH_NAME)/src/cmd \
					     --library $(SKETCH_NAME)/src

# --------------------------------------------------------------------------- #

compile:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_VENDOR_FLAGS) --fqbn \
		$(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

upload:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_VENDOR_FLAGS) --upload --fqbn \
		$(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

test:
	AUNITER_ARDUINO_CLI="$(ARDUINO_CLI_BIN) $(ARDUINO_CLI_VENDOR_FLAGS) \
		$(ARDUINO_CLI_SRC_FLAGS)" $(AUNITER_BIN) --cli test \
		$(BOARD_SHORT):$(PORT) $(TESTS_DIR)/*
