#include <iostream>
#include <errno.h>
#include "xorshift.h"


int init_xorshift(xorshift_t* gen, length_t n) {
    gen->n = n;                                         // Inicializa variáveis.
    mpz_init(gen->tape);                                //
    mpz_init(gen->aux);                                 //

    const int * param = get_xorshift_parameters(n);     // Atribui os parâmetros do gerador.
    if (param == NULL) return 1;                        //
    gen->r = param[0];                                  //
    gen->s = param[1];                                  //
    gen->a = param[2];                                  //
    gen->b = param[3];                                  //
    gen->c = param[4];                                  //
    gen->d = param[5];                                  //

    mpz_setbit(gen->tape, n-1);                         // Atribui 1 ao bit mais significativo da fita.
    mpz_setbit(gen->tape, 0);                           // Atribui 1 ao bit menos significativo da fita.
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

/*
 * A função main espera dois inteiros:
 *          BITS = número de bits dos números que serão gerados
 *          NUMS = quantidade de números que será gerada
 * Retorna:
 *          0    = sucesso                     => imprime os números no terminal
 *          1    = erro (parâmetros inválidos) => não imprime nada
 */
int main(int argc, char* argv[]) {
    mpz_t res;                                                  // Inicializa variáveis.
    mpz_init(res);                                              //
    xorshift_t gen;                                             //

    if (argc < 3) return 1;                                     // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);              //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;           //
    unsigned int NUMS = strtol(argv[2], NULL, 10);              //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;           //

    if (init_xorshift(&gen, (length_t) BITS) != 0) return 1;    // Inicializa gerador.

    for (int i = 0; i < NUMS; i++) {                            // Gera e imprime "NUMS" números.
        next_xorshift(&gen, res);                               //
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;   //
    }                                                           //

    destroy_xorshift(&gen);                                     // Libera variáveis.
    mpz_clear(res);                                             //
    return 0;                                                   //
}
