#ifndef SP_SYSTEM_SYS_LOCAL_H
#define SP_SYSTEM_SYS_LOCAL_H

// ==============================================
//   MEMORY SUBSYSTEM
// ==============================================

int     sp_sys_mem_init(void);
void    sp_sys_mem_shutdown(void);

// ==============================================
//   INPUT SUBSYSTEM
// ==============================================

int     sp_sys_input_init(void);
void    sp_sys_input_shutdown(void);

// ==============================================
//   RENDER SUBSYSTEM
// ==============================================

void    sp_sys_render_shutdown(void);
int     sp_sys_render_init(void);

// ==============================================
//   AUDIO SUBSYSTEM
// ==============================================

int     sp_sys_audio_init(void);
void    sp_sys_audio_shutdown(void);

#endif // SP_SYSTEM_SYS_LOCAL_H
