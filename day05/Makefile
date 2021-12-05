all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day05

clean:
	$(RM) -rvf build

.PHONY: all clean run build