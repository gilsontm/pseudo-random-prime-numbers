#!/bin/bash

LFSR_COMPILED="random/lfsr.out"
LFSR_FERMAT_COMPILED="random/prime/fermat_lfsr.out"
LFSR_MILLER_RABIN_COMPILED="random/prime/miller_rabin_lfsr.out"
XORSHIFT_COMPILED="random/xorshift.out"
XORSHIFT_FERMAT_COMPILED="random/prime/fermat_xorshift.out"
XORSHIFT_MILLER_RABIN_COMPILED="random/prime/miller_rabin_xorshift.out"

PRIME_NUMBERS=100
PSEUDORANDOM_NUMBERS=10000
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
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 40   $PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 56   $PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 80   $PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 128  $PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 168  $PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 224  $PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 256  $PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 512  $PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 1024 $PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 2048 $PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_FERMAT_COMPILED 4096 $PRIME_NUMBERS

echo "Teste de primalidade de Fermat (com Xorshift)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 40   $PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 56   $PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 80   $PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 128  $PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 168  $PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 224  $PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 256  $PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 512  $PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 1024 $PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 2048 $PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_FERMAT_COMPILED 4096 $PRIME_NUMBERS

echo "Teste de primalidade de Miller-Rabin (com LFSR)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 40   $PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 56   $PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 80   $PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 128  $PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 168  $PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 224  $PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 256  $PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 512  $PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 1024 $PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 2048 $PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $LFSR_MILLER_RABIN_COMPILED 4096 $PRIME_NUMBERS

echo "Teste de primalidade de Miller-Rabin (com Xorshift)" >> $LOG_FILE
echo -n "  40 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 40   $PRIME_NUMBERS
echo -n "  56 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 56   $PRIME_NUMBERS
echo -n "  80 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 80   $PRIME_NUMBERS
echo -n " 128 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 128  $PRIME_NUMBERS
echo -n " 168 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 168  $PRIME_NUMBERS
echo -n " 224 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 224  $PRIME_NUMBERS
echo -n " 256 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 256  $PRIME_NUMBERS
echo -n " 512 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 512  $PRIME_NUMBERS
echo -n "1024 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 1024 $PRIME_NUMBERS
echo -n "2048 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 2048 $PRIME_NUMBERS
echo -n "4096 bits ==> " >> $LOG_FILE
/usr/bin/time -f "%es" -a -o $LOG_FILE $XORSHIFT_MILLER_RABIN_COMPILED 4096 $PRIME_NUMBERS

echo "$(cat $LOG_FILE)"