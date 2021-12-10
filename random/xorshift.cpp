#include "xorshift.h"


int init_xorshift(xorshift_t* gen, length_t n) {
    gen->n = n;                                         // Inicializa variáveis.
    mpz_init(gen->tape);                                //
    mpz_init(gen->aux);                                 //

    const char * seed = get_seed(n);                    // Atribui seed hexadecimal ao estado da fita.
    if (strlen(seed) == 0) return 1;                    //
    mpz_set_str(gen->tape, seed, 16);                   //

    const int * param = get_xorshift_parameters(n);     // Atribui os parâmetros do gerador.
    if (param == NULL) return 1;                        //
    gen->r = param[0];                                  //
    gen->s = param[1];                                  //
    gen->a = param[2];                                  //
    gen->b = param[3];                                  //
    gen->c = param[4];                                  //
    gen->d = param[5];                                  //
    return 0;
}

void next_xorshift(xorshift_t* gen, mpz_t res) {
    unsigned long number1, number2;                     // Declara variáveis.
    unsigned int offset = (gen->r - gen->s) * 64;       //

    mpz_set_ui(res, 0);                                 // Atribui zero ao "res".

    while (mpz_sizeinbase(res, 2) < gen->n) {           // Enquanto "res" não tiver "n" bits, faça:
        number1 = mpz_get_ui(gen->tape);                // Extrai os 64 bits menos significativos da fita.
        mpz_fdiv_q_2exp(gen->aux, gen->tape, offset);   // Extrai outros 64 bits da fita de acordo com o offset.
        number2 = mpz_get_ui(gen->aux);                 //

        number1 ^= number1 << gen->a;                   // Aplica shifts e ou-exclusivo segundo os parâmetros.
        number1 ^= number1 >> gen->b;                   //
        number2 ^= number2 << gen->c;                   //
        number2 ^= number2 >> gen->d;                   //
        number2 ^= number1;                             //

        mpz_set_ui(gen->aux, number2);                  // Atribui "number2" ao "aux".
        mpz_mul_2exp(res, res, 64);                     // Desloca "res" 64 bits à esquerda.
        mpz_ior(res, res, gen->aux);                    // Coloca "aux" nos 64 bits menos significativos de "res".
        mpz_mul_2exp(gen->aux, gen->aux, offset);       // Desloca "aux" um total de "offset" bits à esquerda.
        mpz_fdiv_q_2exp(gen->tape, gen->tape, 64);      // Desloca a fita 64 bits à direita.
        mpz_ior(gen->tape, gen->tape, gen->aux);        // Coloca "aux" nos 64 bits mais significativos da fita.
    }

    mpz_set_ui(gen->aux, 1);                            // Por fim, trunca "res" para "n" bits.
    mpz_mul_2exp(gen->aux, gen->aux, gen->n);           //
    mpz_sub_ui(gen->aux, gen->aux, 1);                  //
    mpz_and(res, res, gen->aux);                        //
}

void destroy_xorshift(xorshift_t* gen) {
    mpz_clear(gen->tape);                               // Libera variáveis.
    mpz_clear(gen->aux);                                //
}
