#include "lfsr.h"


int init_lfsr(lfsr_t* gen, length_t n) {
    gen->n = n;                                         // Inicializa variáveis.
    mpz_init(gen->tape);                                //
    mpz_init(gen->mask);                                //

    const char * seed = get_seed(n);                    // Atribui seed hexadecimal ao estado da fita.
    if (strlen(seed) == 0) return 1;                    //
    mpz_set_str(gen->tape, seed, 16);                   //

    const int * param = get_lfsr_parameters(n);         // Atribui 1 aos bits da máscara de acordo com os parâmetros.
    if (param == NULL) return 1;                        //
    mpz_setbit(gen->mask, param[0]-1);                  // Note que os parâmetros dependem do número de bits n.
    mpz_setbit(gen->mask, param[1]-1);                  //
    mpz_setbit(gen->mask, param[2]-1);                  //
    mpz_setbit(gen->mask, param[3]-1);                  //
    return 0;
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
