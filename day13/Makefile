all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day13

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day13

.PHONY: all clean run build
