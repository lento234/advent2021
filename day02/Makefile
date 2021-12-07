all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day02

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day02

.PHONY: all clean run build
