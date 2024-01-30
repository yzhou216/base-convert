#include "basec.h"

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

bool is_uc(char c)
{
	bool ret = false;
	if (c >= 'A' && c <= 'Z')
		ret = true;
	return ret;
}

bool is_lc(char c)
{
	bool ret = false;
	if (c >= 'a' && c <= 'z')
		ret = true;
	return ret;
}

bool is_letter(char c)
{
	bool ret = false;
	if (is_uc(c) || is_lc(c))
		ret = true;
	return ret;
}

int parse_base(char **str)
{
	/* pointer arithmetic used to truncate prefixes bytes */
	int base;
	if (is_letter(**str)) {
		base = -1; /* error */
		goto out;
	}

	if (**str == '0') {
		(*str)++; /* truncate '0' */
		switch (**str) {
		case 'B':
		case 'b':
			base = 2;
			(*str)++; /* truncate 'b' */
			break;
		case 'X':
		case 'x':
			base = 16;
			(*str)++; /* truncate 'x' */
			break;
		default:
			base = -1; /* error */
			goto out;
		}
	} else {
		base = 10;
	}

out:
	return base;
}

int main(int argc, char **argv)
{
	char *i_str; /* input string */
	int o_base; /* output base */

	bool o_flag = false;
	int c;
	while ((c = getopt(argc, argv, "o:")) != -1) {
		switch (c) {
		case 'o':
			o_base = atoi(optarg);
			o_flag = true;
			break;
		case '?':
			if (optopt == 'o')
				printf("Option -%c requires an argument.\n",
				       optopt);
			else if (isprint(optopt))
				printf("Unknown option `-%c'.\n", optopt);
			else
				printf("Unknown option character `\\x%x'.\n",
				       optopt);
			goto err;
		default:
			abort();
		}
	}

	if (!o_flag) {
		printf("Option -o is required.\n");
		goto err;
	}

	if (optind >= argc) {
		printf("No input number provided.\n");
		goto err;
	}

	i_str = argv[optind];

	int i_base = parse_base(&i_str);
	if (i_base == -1)
		goto input_err;

	uint32_t res;
	if (str_to_int(&res, i_str, i_base) == -1)
		goto input_err;

	char o_str[MAX_OUTPUT_BUF + PREFIX_LEN];
	memset(o_str, 0, sizeof(o_str));
	int_to_str(o_str, res, o_base);
	printf("%s\n", o_str);

	return 0;

input_err:
	printf("Bad input\n");
err:
	exit(-1);
}
