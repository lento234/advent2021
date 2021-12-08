all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day08

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day08

.PHONY: all clean run build
