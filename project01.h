#ifndef _PROJECT01_H
#define _PROJECT01_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_OUTPUT_BUF 1024
#define PREFIX_LEN 2

extern int input_err;
bool is_uc(char c);
bool is_lc(char c);
bool is_letter(char c);
uint32_t str_to_int(char *str, int base);
void int_to_str(uint32_t val, char *str, int base);

#endif /* _PROJECT01_H */
