#include "core/core.h"
#include "system/sys.h"
#include "system/sys_local.h"

#include <stdlib.h>
#include <stdio.h>

int sp_sys_init(void)
{
	if (sp_sys_mem_init() < 0)
		sp_sys_error(SP_ERR_INIT_MEMORY);
	if (sp_sys_fs_init() < 0)
		sp_sys_error(SP_ERR_INIT_FILES);
	if (sp_sys_input_init() < 0)
		sp_sys_error(SP_ERR_INIT_INPUT);
	if (sp_sys_render_init() < 0)
		sp_sys_error(SP_ERR_INIT_RENDER);
	if (sp_sys_audio_init() < 0)
		sp_sys_error(SP_ERR_INIT_AUDIO);

	return 0;
}

void sp_sys_error(int errno)
{
	sp_com_error(errno);
	sp_sys_shutdown(EXIT_FAILURE);
}

void sp_sys_shutdown(int code)
{
	sp_sys_input_shutdown();
	sp_sys_render_shutdown();
	sp_sys_audio_shutdown();
	sp_sys_mem_shutdown();

	exit(code);
}

int sp_sys_mem_init(void)
{
	return 0;
}

void *sp_sys_mem_alloc(int size)
{
	void *ptr;

	// TODO: Custom memory allocator
	ptr = malloc ((size_t) size);

	if (ptr == NULL)
		sp_sys_error(SP_ERR_NOMEM);

	return ptr;
}

void sp_sys_mem_free(void *ptr)
{
	free(ptr);
}

void sp_sys_mem_shutdown(void)
{
}
