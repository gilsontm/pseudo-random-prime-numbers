make: all

all: lfsr

lfsr:
	g++ lfsr.cpp -o lfsr -lgmp

run: clean lfsr
	./lfsr

clean:
	rm -f lfsr