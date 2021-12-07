all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day04

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day04

.PHONY: all clean run build
