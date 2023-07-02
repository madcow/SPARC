#include "core/core.h"
#include "system/sys.h"
#include "system/sys_local.h"

int sp_sys_fs_init(void)
{
	return 0;
}

int sp_sys_fs_open(const char *file, int flags)
{
	UNUSED(file);
	UNUSED(flags);

	return 0;
}

int sp_sys_fs_read(int fd, void *buf, int n)
{
	UNUSED(fd);
	UNUSED(buf);
	UNUSED(n);

	return 0;
}

int sp_sys_fs_write(int fd, const void *buf, int n)
{
	UNUSED(fd);
	UNUSED(buf);
	UNUSED(n);

	return 0;
}

void sp_sys_fs_close(int fd)
{
	UNUSED(fd);
}

void sp_sys_fs_shutdown(void)
{
}
