all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day16

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day16

.PHONY: all clean run build
