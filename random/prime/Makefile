make: all

all: fermat_lfsr fermat_xorshift miller_rabin_lfsr miller_rabin_xorshift

fermat_lfsr:
	g++ fermat_lfsr.cpp -o fermat_lfsr.out -lgmp

fermat_xorshift:
	g++ fermat_xorshift.cpp -o fermat_xorshift.out -lgmp

miller_rabin_lfsr:
	g++ miller_rabin_lfsr.cpp -o miller_rabin_lfsr.out -lgmp

miller_rabin_xorshift:
	g++ miller_rabin_xorshift.cpp -o miller_rabin_xorshift.out -lgmp

clean:
	rm -f *.out