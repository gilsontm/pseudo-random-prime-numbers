#include "lengths.h"

/*
 * Seeds aleatórias em hexadecimal, escolhidas empiricamente.
 * Servem para ambos os algoritmos LFSR e Xorshift.
 */
const char* SEED_40   = "49fab441c0";
const char* SEED_56   = "242a1fc8d3850f";
const char* SEED_80   = "c056e937dac140d27c7e";
const char* SEED_128  = "7bb1718dd04e3de7f234352bb37243a2";
const char* SEED_168  = "941c94bbebc399a45918d3481c4f0881bb056f8bd9";
const char* SEED_224  = "ea3d7441618587a257822f5d4ab14a7c3094bd055d63b1cc994afcfc";
const char* SEED_256  = "874f2f610b87a8eb1805de9563b1d99843c9d7b9c549c381155e02517c95df51";
const char* SEED_512  = "c06a972c05099711d702275e1289382830b5ba5d76ac85d34286196b028e378b"
                        "d80e93360e0b88ba83f543316b41e91dc83286829bd21c958c5ca9929cf88f10";
const char* SEED_1024 = "d4a499d29f3aa286febca37dcf98029794d3f5c0f570425dffd9f1ccc6c81675"
                        "22686a549df44d2d1a46dee216b7fa3dc89e740d4d45694335d2de45c2e0697f"
                        "84a2e75da1764a3abd6df1b48fb9e5cb7c3c91b16c16dde7de38152d56a2ee6b"
                        "c587ac46746fe872ad96db89e3b459ecebe8edd9772985b1199f88c6b55ab298";
const char* SEED_2048 = "95adbe2eb075ac3f9dfd0f05495d46c6b6f933e2b399951b6e327c9625b2f55b"
                        "e23361f7fc3fce1b7c2da8360d039c01cbcdda235f07d0c2002622aa8864ebd3"
                        "533a20f0032fda9744979a48c7a6d0aaa4cca81ee2c2b8dfd1330cd69807cc7e"
                        "e4e5e23e5b72b03a6c2ff1666ea5654c90ccf8b3859458ba0f9856e4a7f5f97f"
                        "788300677c935bf84ca2dd8e191cb9403d27581329c8353759cae347123fe565"
                        "73e58cf546c2dbd517cf6fed4c53ac1bf6b92194968004effe0e7d134af108da"
                        "998b9ffbe991c3204ccffc193ef6268cecfad32b48e00168a90917b65f149190"
                        "aafc7fd9987a6ecef5035217d57008eb1f2c5b13478a4312cbfd406c266bd4c5";
const char* SEED_4096 = "578fcce80909f0b07254b84e6708fff21b7de3b7acdb66f214451d793702a23c"
                        "4c1a72bc28d9e68cdf9bc7619dc3ccbfaa9d0a22b7a866a06d1e6dc77e3422a7"
                        "a375da6d08c24df8c6857a44d65eec449a7b6d44b3e79cfd2139561a43794e04"
                        "b6beb1f4946f3fe5ae588f8e5ad86ad39e45629d38bafe0c0dc0ec7143abb717"
                        "9a740e6e87f036de0a57d1f99f7803450361d6b646c132552021f78c47c1cb8a"
                        "f0eeb863b3ac2fb0874b7bcf0044b83002fd0a88a4fcfb15e011276983a05b01"
                        "326cebade79dc6cd46b85fb7c5d30ad417a6595855f86a9d5f9e1877f3ff9a3f"
                        "75958756e9187d70f67a93c5c97f873956d2ddc53ed94d9dd086771980a01d48"
                        "8b3590d57aae4d8aa722e936dd6f0bb35acd6ddbaee0535560ebfe176cf728bc"
                        "26db215ce2d1591c0cd3e1be8efd889944f281b0c38695437a8f993b2747a5d6"
                        "0410d98f8aad95b01cc0288f2098d66b4ea4a8cab07755dacae15fd9487cb9d1"
                        "7ecbb1c92585d4bb2a1b613ae0e9b058fa11e7cfa59a5aa73e389a5f89ef0114"
                        "210e710d06e593895811ad1bc3eed4b945f170bc07f451ba91ce00aedef1c02b"
                        "f6727c43676c9b05b0b89cd279dd9ffc0d3c7359a09994e69a2093955f2bcc11"
                        "0519d546046658cddef2e631d758b62ee16d712fc9d750e5b2c553d0e8801154"
                        "1944054fd33a9fceb811d5ecad3bdc8a9761d8d4977b27761ff7811d6c3ad613";

/*
 * Função auxiliar de escolha da seed dado o número de bits.
 * Parâmetros:
 *          n = número de bits
 * Retorna:
 *          uma seed aleatória escolhida empiricamente.
 */
const char * get_seed(length_t n) {
    switch (n) {
        case BITS_40:   return SEED_40;
        case BITS_56:   return SEED_56;
        case BITS_80:   return SEED_80;
        case BITS_128:  return SEED_128;
        case BITS_168:  return SEED_168;
        case BITS_224:  return SEED_224;
        case BITS_256:  return SEED_256;
        case BITS_512:  return SEED_512;
        case BITS_1024: return SEED_1024;
        case BITS_2048: return SEED_2048;
        case BITS_4096: return SEED_4096;
        default:        return "";
    }
}
