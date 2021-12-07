all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day03

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day03

.PHONY: all clean run build
