#include "project01.h"

#include <string.h>

#define MAX_INPUT_BUF 1024

uint32_t str_to_int(char *str, int base)
{
	uint32_t ret = 0;
	int place_val = 1;

	char *start = str;
	char *end = (str - 1) + strnlen(str, MAX_INPUT_BUF);
	while (start <= end) {
		int digit = (*end) - '0'; /* convert char to int using ASCII */
		ret += digit * place_val;
		place_val *= base;
		end--;
	}

	return ret;
}
