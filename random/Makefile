make: all

all: lfsr

lfsr:
	g++ lfsr.cpp -o lfsr.out -lgmp

run: clean lfsr
	./lfsr.out

clean:
	rm -f *.out