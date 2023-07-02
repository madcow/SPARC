#ifndef SP_SYSTEM_SYS_H
#define SP_SYSTEM_SYS_H

int     sp_sys_init(void);
void    sp_sys_shutdown(int code);

// ==============================================
//   FILE SUBSYSTEM
// ==============================================

int     sp_sys_fs_open(const char *file, int flags);
int     sp_sys_fs_read(int fd, void *buf, int n);
int     sp_sys_fs_write(int fd, const void *buf, int n);
void    sp_sys_fs_close(int fd);

// ==============================================
//   MEMORY SUBSYSTEM
// ==============================================

void *  sp_sys_mem_alloc(int size);
void    sp_sys_mem_free(void *ptr);

// ==============================================
//   MEMORY SUBSYSTEM
// ==============================================

void    sp_sys_input_update(void);
void    sp_sys_input_show_mouse(bool show);

// ==============================================
//   MEMORY SUBSYSTEM
// ==============================================

void    sp_sys_error(int errno);

// ==============================================
//   MEMORY SUBSYSTEM
// ==============================================

void    sp_sys_render_update(void);

#endif // SP_SYSTEM_SYS_H
