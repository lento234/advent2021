all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day11

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day11

.PHONY: all clean run build
