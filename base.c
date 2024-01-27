#include "project01.h"

#include <string.h>

#define MAX_INPUT_BUF 1024

bool is_hex(char c)
{
	bool ret = false;
	if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		ret = true;
	return ret;
}

int convt_hex(char c)
{
	int ret;
	if(is_uc(c))
		ret = c - '7';
	else if (is_lc(c))
		ret = c - 'W';
	return ret;
}

uint32_t str_to_int(char *str, int base)
{
	uint32_t ret = 0;
	int place_val = 1;

	char *start = str;
	char *end = (str - 1) + strnlen(str, MAX_INPUT_BUF);
	while (start <= end) {
		/* convert char to corresponding int using ASCII math */
		char c = *end;
		int digit;
		if (base == 16 && is_letter(c)) {
			if (!is_hex(c)) {
				input_err = -1; /* error */
				goto out;
			}
			digit = convt_hex(c);
		} else {
			digit = c - '0';
		}
		ret += digit * place_val;
		place_val *= base;
		end--;
	}

out:
	return ret;
}
