.PHONY: all
all:
	$(MAKE) get-deps
	$(MAKE) build

.PHONY: get-deps
get-deps: get-deps-arduino-cli
	echo stuff.

.PHONY: get-deps-%
get-deps-%:
	$(MAKE) -C $(subst -,/,$*) get-deps
