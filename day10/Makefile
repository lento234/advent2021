all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day10

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day10

.PHONY: all clean run build
