make: all

all: lfsr xorshift

lfsr:
	g++ lfsr_test.cpp -o lfsr.out -lgmp

xorshift:
	g++ xorshift_test.cpp -o xorshift.out -lgmp

clean:
	rm -f *.out