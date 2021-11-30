# https://datacipy.cz/lfsr_table.pdf
# https://en.wikipedia.org/wiki/Linear-feedback_shift_register#Example_in_Python

# 32, 30, 26, 25
# 16, 14, 13, 11


def linear_feedback_shift_register():
    tape = 1 << 16 | 1

    hash_table = {}

    count = 0
    while True:
        count += 1
        number = 0
        for i in range(16):
            number = (number << 1) | (tape & 1)
            # print(tape & 1, end='')
            # newbit = (tape ^ (tape >> 4096) ^ (tape >> 4095) ^ (tape >> 4081) ^ (tape >> 4069)) & 1
            newbit = (tape ^ (tape >> 16) ^ (tape >> 14) ^ (tape >> 13) ^ (tape >> 11)) & 1
            tape = (newbit << 16) | (tape >> 1)

        number = int(number)
        print(number)
        if number in hash_table:
            print(f"end at {count}")
            break
        hash_table[number] = True

def galois():
    tape = (1 << 4095) | 1
    mask = (1 << 4095) | (1 << 4094) | (1 << 4080) | (1 << 4068)

    count = 0
    while count < 1000:
        count += 1
        number = 0
        for i in range(4096):
            output = tape & 1
            number = (number << 1) | output
            tape >>= 1
            if output:
                tape ^= mask
        number = int(number)
        print(number)

def main():
    galois()

if __name__ == "__main__":
    main()
