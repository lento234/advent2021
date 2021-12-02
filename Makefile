.PHONY: clean build help interact compile run
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

help: ## Print help
	@python -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

clean: ## Clean up
	@rm -rvf build
	@rm -rvf day*/build
	
build: ## Compile all days
	cmake -H. -B build && make -j -C build

run: ## Run all days
	@cd build;\
	for day in `ls -dtr day*`; do \
		cd $$day && ./$$day && cd ..; \
	done

docker: ## Build a docker image
	DOCKER_BUILDKIT=1 docker build --progress=auto -t mrlento234/advent2021:latest . 

docker-interact: ## Run a docker image interactively
	DOCKER_BUILDKIT=1 docker run -it --rm mrlento234/advent2021:latest bash

docker-push:
	docker push mrlento234/advent2021:latest

docker-run: ## Run all days inside docker
	docker run --rm mrlento234/advent2021:latest	
