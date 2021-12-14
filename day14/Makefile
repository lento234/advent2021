all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day14

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day14

.PHONY: all clean run build
