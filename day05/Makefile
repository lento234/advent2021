all: build run

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./day05

clean:
	$(RM) -rvf build

mem-prof:
	cd build && valgrind ./day05

.PHONY: all clean run build
