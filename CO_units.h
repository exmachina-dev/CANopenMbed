#ifndef CO_UNITS_H_
#define CO_UNITS_H_

typedef union {
    uint8_t bytes[4];
    float to_float;
} bfloat;

typedef union {
    uint8_t bytes[4];
    float to_integer;
} bint;

#endif // CO_UNITS_H_
