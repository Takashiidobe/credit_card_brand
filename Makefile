all:
	mkdir -p build && gcc -Wall -Wpedantic tests.c -o build/tests && ./build/tests
test:
	mkdir -p build && gcc -Wall -Wpedantic tests.c -o build/tests && ./build/tests
release:
	quom card.h distribute.h
docs:
	echo "in progress"
clean:
	rm -rf build
