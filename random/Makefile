make: all

all: lfsr

lfsr:
	g++ lfsr.cpp -o out.out -lgmp

run: clean lfsr
	./out.out

clean:
	rm -f *.out