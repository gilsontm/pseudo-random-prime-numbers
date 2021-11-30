#include <iostream>
#include "lfsr.h"

#define NUMBERS 1000

void init_lfsr(lfsr_t* gen, length_t n) {
    gen->n = n;                                         // Inicializa variáveis.
    mpz_init(gen->tape);                                //
    mpz_init(gen->mask);                                //

    mpz_setbit(gen->tape, n-1);                         // Atribui 1 ao bit mais significativo da fita.
    mpz_setbit(gen->tape, 0);                           // Atribui 1 ao bit menos significativo da fita.

    const int * param = get_lfsr_parameters(n);         // Atribui 1 aos bits da máscara de acordo com os parâmetros.
    mpz_setbit(gen->mask, param[0]-1);                  // Note que os parâmetros dependem do número de bits n.
    mpz_setbit(gen->mask, param[1]-1);                  //
    mpz_setbit(gen->mask, param[2]-1);                  //
    mpz_setbit(gen->mask, param[3]-1);                  //
}

void next_lfsr(lfsr_t* gen, mpz_t res) {
    unsigned int bit;
    mpz_set_ui(res, 0);                                 // Atribui zero ao resultado.
    for (int i = 0; i < gen->n; i++) {                  // Repete n vezes:
        bit = mpz_tstbit(gen->tape, 0);                 //      Atribui ao "bit" o bit menos significativo da fita.
        mpz_mul_2exp(res, res, 1);                      //      Faz um shift-left em "res".
        mpz_fdiv_q_2exp(gen->tape, gen->tape, 1);       //      Faz um shift-right na fita.
        if (bit) {                                      //      Se "bit" for 1:
            mpz_setbit(res, 0);                         //          Atribui 1 ao bit menos significativo de "res".
            mpz_xor(gen->tape, gen->tape, gen->mask);   //          Faz um XOR entre a fita e os bits da máscara.
        }
    }
}

void destroy_lfsr(lfsr_t* gen) {
    mpz_clear(gen->tape);                               // Libera variáveis.
    mpz_clear(gen->mask);                               //
}

int main() {
    mpz_t res;
    mpz_init(res);

    lfsr_t gen;
    init_lfsr(&gen, BITS_4096);

    for (int i = 0; i < NUMBERS; i++) {
        next_lfsr(&gen, res);
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;
    }

    destroy_lfsr(&gen);
    mpz_clear(res);
    return 0;
}
