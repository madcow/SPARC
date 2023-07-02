#include "core/core.h"

// TODO: event system

int sp_event_init(void)
{
	return 0;
}

void sp_event_register(int type)
{
	UNUSED(type);
}

void sp_event_emit(int type, void *todo)
{
	UNUSED(type);
	UNUSED(todo);
}

void sp_event_shutdown(void)
{
}
