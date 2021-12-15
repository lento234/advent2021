all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day15

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day15

.PHONY: all clean run build
