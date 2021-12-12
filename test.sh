#!/bin/bash

LFSR_COMPILED="random/lfsr.out"
XORSHIFT_COMPILED="random/xorshift.out"
FERMAT_LFSR_COMPILED="random/prime/fermat_lfsr.out"
FERMAT_XORSHIFT_COMPILED="random/prime/fermat_xorshift.out"
MILLER_RABIN_LFSR_COMPILED="random/prime/miller_rabin_lfsr.out"
MILLER_RABIN_XORSHIFT_COMPILED="random/prime/miller_rabin_xorshift.out"

SMALL_PRIME_NUMBERS=10000
LARGE_PRIME_NUMBERS=30
PSEUDORANDOM_NUMBERS=1000000
LOG_FILE="log.txt"

make -C random/prime clean
make -C random clean
make -C random/prime
make -C random

echo "Relatório de tempos de execução:" > $LOG_FILE

echo "Números pseudo-aleatórios (com LFSR)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 40   $PSEUDORANDOM_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 56   $PSEUDORANDOM_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 80   $PSEUDORANDOM_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 128  $PSEUDORANDOM_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 168  $PSEUDORANDOM_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 224  $PSEUDORANDOM_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 256  $PSEUDORANDOM_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 512  $PSEUDORANDOM_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 1024 $PSEUDORANDOM_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 2048 $PSEUDORANDOM_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_COMPILED 4096 $PSEUDORANDOM_NUMBERS

echo "Números pseudo-aleatórios (com Xorshift)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 40   $PSEUDORANDOM_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 56   $PSEUDORANDOM_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 80   $PSEUDORANDOM_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 128  $PSEUDORANDOM_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 168  $PSEUDORANDOM_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 224  $PSEUDORANDOM_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 256  $PSEUDORANDOM_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 512  $PSEUDORANDOM_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 1024 $PSEUDORANDOM_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 2048 $PSEUDORANDOM_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_COMPILED 4096 $PSEUDORANDOM_NUMBERS

echo "Teste de primalidade de Fermat (com LFSR)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 40   $SMALL_PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 56   $SMALL_PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 80   $SMALL_PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 128  $SMALL_PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 168  $SMALL_PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 224  $LARGE_PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 256  $LARGE_PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 512  $LARGE_PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 1024 $LARGE_PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 2048 $LARGE_PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_LFSR_COMPILED 4096 $LARGE_PRIME_NUMBERS

echo "Teste de primalidade de Fermat (com Xorshift)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 40   $SMALL_PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 56   $SMALL_PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 80   $SMALL_PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 128  $SMALL_PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 168  $SMALL_PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 224  $LARGE_PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 256  $LARGE_PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 512  $LARGE_PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 1024 $LARGE_PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 2048 $LARGE_PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $FERMAT_XORSHIFT_COMPILED 4096 $LARGE_PRIME_NUMBERS

echo "Teste de primalidade de Miller-Rabin (com LFSR)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 40   $SMALL_PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 56   $SMALL_PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 80   $SMALL_PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 128  $SMALL_PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 168  $SMALL_PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 224  $LARGE_PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 256  $LARGE_PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 512  $LARGE_PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 1024 $LARGE_PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 2048 $LARGE_PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_LFSR_COMPILED 4096 $LARGE_PRIME_NUMBERS

echo "Teste de primalidade de Miller-Rabin (com Xorshift)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 40   $SMALL_PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 56   $SMALL_PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 80   $SMALL_PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 128  $SMALL_PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 168  $SMALL_PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 224  $LARGE_PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 256  $LARGE_PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 512  $LARGE_PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 1024 $LARGE_PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 2048 $LARGE_PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $MILLER_RABIN_XORSHIFT_COMPILED 4096 $LARGE_PRIME_NUMBERS

echo "$(cat $LOG_FILE)"
