ard_cli = arduino-cli --config-file ./arduino-cli.yaml

.PHONY: all
all:
	$(MAKE) get-deps
	$(MAKE) build

.PHONY: get-deps
get-deps:
	$(ard_cli) version
	$(ard_cli) core update-index
	$(ard_cli) core list
	$(ard_cli) core install esp32:esp32
	
