#ifndef SP_CORE_CORE_H
#define SP_CORE_CORE_H

// ==============================================
//   COMMON SUBSYSTEM
// ==============================================

#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>

#define UNUSED(x) ((void)(x))

int   sp_com_init(void);
int   sp_com_read_args(int argc, char **argv);
int   sp_com_read_conf(const char *filename);
void  sp_com_debug(const char *fmt, ...);
void  sp_com_error(const char *fmt, ...);

// ==============================================
//   EVENT SUBSYSTEM
// ==============================================

int   sp_event_init(void);
void  sp_event_shutdown(void);

#endif // SP_CORE_CORE_H
