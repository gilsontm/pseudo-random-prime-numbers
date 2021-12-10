make: all

all: miller_rabin_lfsr miller_rabin_xorshift

miller_rabin_lfsr:
	g++ miller_rabin_lfsr.cpp -o miller_rabin_lfsr.out -lgmp

miller_rabin_xorshift:
	g++ miller_rabin_xorshift.cpp -o miller_rabin_xorshift.out -lgmp

clean:
	rm -f *.out