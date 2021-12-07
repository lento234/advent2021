all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day01

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day01

.PHONY: all clean run build
