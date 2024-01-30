#include "basec.h"

#define MAX_INPUT_BUF 1024

#define BIN_PREFIX "0b"
#define HEX_PREFIX "0x"

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

int str_to_int(uint32_t *dest, char *str, int base)
{
	int ret = 0;
	int place_val = 1;

	char *start = str;
	char *end = (str - 1) + strnlen(str, MAX_INPUT_BUF);
	while (start <= end) {
		/* convert char to corresponding int using ASCII math */
		char c = *end;
		int digit;

		if (base == 2 && (c != '0' && c != '1')) {
			ret = -1; /* error */
			goto out;
		}

		if (base == 16 && is_letter(c)) {
			if (!is_hex(c)) {
				ret = -1; /* error */
				goto out;
			}
			digit = convt_hex(c);
		} else {
			digit = c - '0';
		}

		*dest += digit * place_val;
		place_val *= base;
		end--;
	}

out:
	return ret;
}

void int_to_str(char *dest, uint32_t val, int base)
{
	if (base == 2) {
		strncpy(dest, BIN_PREFIX, PREFIX_LEN);
		dest += PREFIX_LEN;
	} else if (base == 16) {
		strncpy(dest, HEX_PREFIX, PREFIX_LEN);
		dest += PREFIX_LEN;
	}

	char o_buf[MAX_OUTPUT_BUF];
	memset(o_buf, 0, sizeof(o_buf));
	char *end = o_buf;
	while (val != 0) {
		int quot = val / base;
		int rem = val % base;
		if (base == 16 && (rem >= 10 && rem <= 15))
			*end = rem + '7'; /* convert to hex characters */
		else
			*end = rem + '0';
		end++;
		val = quot;
	}
	/*
	 * decrement the end pointer to the last character of o_buf string from
	 * the null byte
	 */
	end--;

	while (o_buf - 1 != end) {
		*dest = *end;
		dest++;
		end--;
	}
}
