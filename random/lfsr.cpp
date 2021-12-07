#include <iostream>
#include "lfsr.h"


int init_lfsr(lfsr_t* gen, length_t n) {
    gen->n = n;                                         // Inicializa variáveis.
    mpz_init(gen->tape);                                //
    mpz_init(gen->mask);                                //

    mpz_setbit(gen->tape, n-1);                         // Atribui 1 ao bit mais significativo da fita.
    mpz_setbit(gen->tape, 0);                           // Atribui 1 ao bit menos significativo da fita.

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
    lfsr_t gen;                                                 //

    if (argc < 3) return 1;                                     // Verifica os argumentos.
    unsigned int BITS = strtol(argv[1], NULL, 10);              //
    if (errno != 0 || strlen(argv[1]) == 0) return 1;           //
    unsigned int NUMS = strtol(argv[2], NULL, 10);              //
    if (errno != 0 || strlen(argv[2]) == 0) return 1;           //

    if (init_lfsr(&gen, (length_t) BITS) != 0) return 1;        // Inicializa gerador.

    for (int i = 0; i < NUMS; i++) {                            // Gera e imprime "NUMS" números.
        next_lfsr(&gen, res);                                   //
        std::cout << mpz_get_str(NULL, 10, res) << std::endl;   //
    }

    destroy_lfsr(&gen);                                         // Libera variáveis.
    mpz_clear(res);                                             //
    return 0;                                                   //
}
