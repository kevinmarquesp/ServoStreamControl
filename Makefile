SKETCH_NAME ?= ServoStreamControl
PARALLEL_SERVO_LIB ?= vendor/ParallelServo
TESTS_DIR ?= tests

AUNITER_BIN ?= ${HOME}/.local/share/AUniter/auniter.sh
ARDUINO_CLI_BIN ?= ${HOME}/.local/bin/arduino-cli

ARDUINO_CLI_MODULE_FLAGS ?= --library module/abstract \
							--library module/commands

ARDUINO_CLI_LIB_FLAGS ?= --library vendor/ParallelServo \
						 --library vendor/StringSplitter

BOARD_SHORT ?= uno
BOARD_LONG ?= arduino:avr:uno
PORT ?= /dev/ttyUSB0

AUNITER_BIN ?= ${HOME}/.local/share/AUniter/auniter.sh

compile:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_LIB_FLAGS) --fqbn $(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

upload:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_LIB_FLAGS) --upload --fqbn $(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

test:
	AUNITER_ARDUINO_CLI="$(ARDUINO_CLI_BIN) $(ARDUINO_CLI_LIB_FLAGS) $(ARDUINO_CLI_MODULE_FLAGS)" \
		$(AUNITER_BIN) --cli test $(BOARD_SHORT):$(PORT) $(TESTS_DIR)/*
