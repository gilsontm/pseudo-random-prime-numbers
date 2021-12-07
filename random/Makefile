make: all

all: lfsr xorshift

lfsr:
	g++ lfsr.cpp -o lfsr.out -lgmp

xorshift:
	g++ xorshift.cpp -o xorshift.out -lgmp

clean:
	rm -f *.out