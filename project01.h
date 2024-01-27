#ifndef _PROJECT01_H
#define _PROJECT01_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

extern int input_err;
bool is_uc(char c);
bool is_lc(char c);
bool is_letter(char c);
uint32_t str_to_int(char *str, int base);

#endif /* _PROJECT01_H */
