#include "core/core.h"
#include "system/sys.h"

int main(int argc, char **argv)
{
	sp_com_init();
	sp_sys_init();

	sp_com_read_args(argc, argv);
	sp_com_read_config("gas.cfg");
	sp_com_exec_script("gasrc");

	sp_com_error(SP_ERR_NOT_TOASTER);
	sp_sys_shutdown(0);

	return 0;
}
