#include <stdio.h>

#define VAR_NAME(v) ((void) v, #v)

/*
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * SUMMARY:
 * This struct is 1 byte large where each parameter takes of 4 bits
 * of space.
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
typedef struct {
    unsigned char top_4_bits : 4;
    unsigned char bot_4_bits : 4;
} struct1_t;

/*
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * SUMMARY:
 * This struct is also 1 byte because 5+3 bits is still 8 bits, which
 * fits into 1 byte.
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
typedef struct {
    unsigned char top_5_bits : 5;
    unsigned char bot_3_bits : 3;
} struct2_t;

/*
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 * SUMMARY:
 * This struct takes up 2 bytes because 5+4 bits is more than can
 * fit into 1 byte.
 * +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
*/
typedef struct {
    unsigned char top_5_bits : 5;
    unsigned char bot_4_bits : 4;
} struct3_t;

void main() {
    
    // -----------------------------------------------------------------------
    struct1_t s1 = {
        .top_4_bits = 15,
        .bot_4_bits = 15
    };
    printf("Size of '%s' in bytes: %ld\n", VAR_NAME(s1), sizeof(struct1_t));

    // -----------------------------------------------------------------------
    struct2_t s2 = {
        .top_5_bits = 31,
        .bot_3_bits = 7
    };
    printf("Size of '%s' in bytes: %ld\n", VAR_NAME(s2), sizeof(struct2_t));

    // -----------------------------------------------------------------------
    struct3_t s3 = {
        .top_5_bits = 31,
        .bot_4_bits = 15
    };
    printf("Size of '%s' in bytes: %ld\n", VAR_NAME(s3), sizeof(struct3_t));
}