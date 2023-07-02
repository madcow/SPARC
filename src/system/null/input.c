#include "core/core.h"
#include "system/sys.h"
#include "system/sys_local.h"

static struct sp_keyboard_s {
	int keymap[255];
} _keyboard;

static struct sp_mouse_pointer_s {
	float xpos, ypos;
} _mouse_pointer;

int sp_sys_input_init(void)
{
	UNUSED(_keyboard);
	UNUSED(_mouse_pointer);

	return 0;
}

void sp_sys_input_update(void)
{
	// Poll mouse and key state
	// Generate new input event
}

void sp_sys_input_show_mouse(bool show)
{
	// Set pointer visibility

	UNUSED(show);
}

void sp_sys_input_shutdown(void)
{
}
