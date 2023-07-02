#include "core/core.h"
#include <stdio.h>

static char sp_error_msg[][128] = {
// expand error message x-macro
#define E(_, str) str,
#include "core/errors.inc.h"
#undef E
};

int sp_com_init(void)
{
	return 0;
}

int sp_com_read_args(int argc, char **argv)
{
	// TODO: parse command-line

	UNUSED(argc);
	UNUSED(argv);

	return 0;
}

int sp_com_read_conf(const char *filename)
{
	// TODO: parse config file

	UNUSED(filename);

	return 0;
}

void sp_com_debug(const char *fmt, ...)
{
	va_list ap;

	// TODO: different output streams

	va_start(ap, fmt);
	printf("Debug: ");
	vprintf(fmt, ap);
	va_end(ap);
}

// use sp_sys_error for fatal errors
void sp_com_error(int errno)
{
	if (errno < 0 || errno >= SP_MAX_ERRNO)
		errno = SP_ERR_UNKNOWN;

	// TODO: different output streams
	// TODO: take variable arguments

	printf("Error: %s.\n", sp_error_msg[errno]);
}
