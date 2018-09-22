.PHONY: up
up:
	docker-compose up --build -d

.PHONY: down
down:
	docker-compose down

.PHONY: shell
shell:
	docker-compose exec --user `id -u`:`id -g` develop bash

.PHONY: build
build:
	g++ --std=c++14 -D_GLIBCXX_USE_CXX11_ABI=0 main.cc
