#include "project01.h"

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

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

	return 0;

err:
	exit(-1);
}
