#include "core/test-cmd.h"

#include <check.h>

int main(void)
{
	Suite *s;
	SRunner *r;
	int n;

	s = sp_test_cmd();
	r = srunner_create(s);

	srunner_run_all(r, CK_NORMAL);
	n = srunner_ntests_failed(r);

	srunner_free(r);

	return n != 0;
}
