SKETCH_NAME ?= ServoStreamControl
TESTS_DIR ?= tests
TEMPLATES_DIR ?= templates

AUNITER_BIN ?= ${HOME}/.local/share/AUniter/auniter.sh
ARDUINO_CLI_BIN ?= ${HOME}/.local/bin/arduino-cli
FZF_BIN ?= /bin/fzf \
	--preview "test" \
	--ansi --border sharp --margin 10% --padding 5% --info inline \
	--prompt "   " --pointer "->" \
	--color "bg+:-1,pointer:green,fg+:green,hl:yellow,border:gray"

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
		$(AUNITER_BIN) --cli test $(BOARD_SHORT):$(PORT) $(TESTS_DIR)/$$(ls -1 $(TESTS_DIR) | $(FZF_BIN))

test-all:
	AUNITER_ARDUINO_CLI="$(ARDUINO_CLI_BIN) $(ARDUINO_CLI_LIB_FLAGS) $(ARDUINO_CLI_LOCAL_MODULE_FLAGS)" \
		$(AUNITER_BIN) --cli test $(BOARD_SHORT):$(PORT) $(TESTS_DIR)/*

new-test:
	read -p "Test name: " fr_testname; \
		$(ARDUINO_CLI_BIN) sketch new $(TESTS_DIR)/$$fr_testname; \
		cat $(TEMPLATES_DIR)/TestSketch.ino > $(TESTS_DIR)/$$fr_testname/$$fr_testname.ino

new-unit:
	ff_selunit=$$(ls -1 $(TESTS_DIR) | $(FZF_BIN)); \
		read -p "Unit name: " fr_unitname; \
		unitfile=$(TESTS_DIR)/$$ff_selunit/$$fr_unitname.ino; \
		cat $(TEMPLATES_DIR)/UnitFile.ino > $$unitfile; \
		echo $$unitfile
