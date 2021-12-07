#include <gmpxx.h>
#include "lengths.h"

typedef struct {
    length_t n;
    mpz_t tape;
    mpz_t aux;
    unsigned int r;
    unsigned int s;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
} xorshift_t;


int init_xorshift(xorshift_t* gen, length_t n);
void next_xorshift(xorshift_t* gen, mpz_t res);
void destroy_xorshift(xorshift_t* gen);

                                //  r   s   a   b   c   d
const int XORSHIFT_PARAM_128[]  = { 2,  1, 33, 31, 28, 29};
const int XORSHIFT_PARAM_256[]  = { 4,  3, 37, 27, 29, 33};
const int XORSHIFT_PARAM_512[]  = { 8,  1, 37, 26, 29, 34};
const int XORSHIFT_PARAM_1024[] = {16,  7, 34, 29, 25, 31};
const int XORSHIFT_PARAM_2048[] = {32,  1, 35, 27, 26, 37};
const int XORSHIFT_PARAM_4096[] = {64, 53, 33, 26, 27, 29};

/*
 * Função auxiliar de escolha de parâmetros dado o número de bits.
 * Parâmetros:
 *          n = número de bits
 */
const int * get_xorshift_parameters(length_t n) {
    switch (n) {
        case BITS_40:   return XORSHIFT_PARAM_128;
        case BITS_56:   return XORSHIFT_PARAM_128;
        case BITS_80:   return XORSHIFT_PARAM_128;
        case BITS_128:  return XORSHIFT_PARAM_128;
        case BITS_168:  return XORSHIFT_PARAM_256;
        case BITS_224:  return XORSHIFT_PARAM_256;
        case BITS_256:  return XORSHIFT_PARAM_256;
        case BITS_512:  return XORSHIFT_PARAM_512;
        case BITS_1024: return XORSHIFT_PARAM_1024;
        case BITS_2048: return XORSHIFT_PARAM_2048;
        case BITS_4096: return XORSHIFT_PARAM_4096;
        default:        return NULL;
    }
}
