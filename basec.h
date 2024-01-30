#ifndef _BASEC_H
#define _BASEC_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_OUTPUT_BUF 1024
#define PREFIX_LEN 2

bool is_uc(char c);
bool is_lc(char c);
bool is_letter(char c);
int str_to_int(uint32_t *dest, char *str, int base);
void int_to_str(uint32_t val, char *str, int base);

#endif /* _BASEC_H */
