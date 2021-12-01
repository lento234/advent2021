.DEFAULT_GOAL := help
define PRINT_HELP_PYSCRIPT
import re, sys

for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

BROWSER := python -c "$$BROWSER_PYSCRIPT"

help:
	@python -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

build: ## Build a docker image
	DOCKER_BUILDKIT=1 docker build --progress=auto -t mrlento234/advent2021:latest . 

interact: ## Run a docker image interactively
	DOCKER_BUILDKIT=1 docker run -it --rm mrlento234/advent2021:latest bash

compile: ## Compile all days
	cmake -H. -B build && make -C build

run:
	./build/day$(DAY)/day$(DAY)
