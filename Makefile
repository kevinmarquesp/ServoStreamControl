SKETCH_NAME ?= ServoStreamControl
TESTS_DIR ?= tests

AUNITER_BIN ?= ${HOME}/.local/share/AUniter/auniter.sh
ARDUINO_CLI_BIN ?= ${HOME}/.local/bin/arduino-cli

ARDUINO_CLI_LOCAL_MODULE_FLAGS ?= --library $(SKETCH_NAME)/src/shell \
								  --library $(SKETCH_NAME)/src/commands \
								  --library $(SKETCH_NAME)/src
ARDUINO_CLI_LIB_FLAGS ?= --library vendor/ParallelServo \
						 --library vendor/StringSplitter

BOARD_SHORT ?= uno
BOARD_LONG ?= arduino:avr:uno
PORT ?= /dev/ttyUSB0

compile:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_LIB_FLAGS) --fqbn $(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

upload:
	$(ARDUINO_CLI_BIN) compile $(ARDUINO_CLI_LIB_FLAGS) --upload --fqbn $(BOARD_LONG) --port $(PORT) $(SKETCH_NAME)

test:
	AUNITER_ARDUINO_CLI="$(ARDUINO_CLI_BIN) $(ARDUINO_CLI_LIB_FLAGS) $(ARDUINO_CLI_LOCAL_MODULE_FLAGS)" \
		$(AUNITER_BIN) --cli test $(BOARD_SHORT):$(PORT) $(TESTS_DIR)/*
