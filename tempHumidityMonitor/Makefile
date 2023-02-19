ard_cli = arduino-cli --config-file ./arduino-cli.yaml
board_type = esp32:esp32
fqbn = esp32:esp32:esp32
board_path = /dev/ttyUSB0

.PHONY: all
all:
	$(MAKE) get-deps
	$(MAKE) build

.PHONY: get-deps
get-deps: get-deps-board get-deps-cpp

.PHONY: get-deps-board
get-deps:
	$(ard_cli) version
	$(ard_cli) core update-index
	$(ard_cli) core list
	$(ard_cli) core install $(board_type)
	pip install pyserial

.PHONY: get-deps-cpp
get-deps-cpp:
	$(ard_cli) lib install WiFi
	# TODO: Figure out a better lib
	$(ard_cli) lib install --git-url https://github.com/DFRobot/DFRobot_DHT11.git

.PHONY: build
build:
	$(ard_cli) compile --fqbn $(fqbn) tempHumidityMonitor.ino
	

.PHONY: upload
upload:
	$(ard_cli) upload --fqbn $(fqbn) -p $(board_path) tempHumidityMonitor.ino
