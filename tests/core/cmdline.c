#include <check.h>

START_TEST (cmd_parse_empty)
{
	ck_assert(0);
}
END_TEST

START_TEST (cmd_parse_file)
{
	ck_assert(0);
}
END_TEST

START_TEST (cmd_parse_file_list)
{
	ck_assert(0);
}
END_TEST

START_TEST (cmd_parse_options)
{
	ck_assert(0);
}
END_TEST

Suite *cmdline_suite(void)
{
	Suite *s;
	TCase *c;

	s = suite_create("cmdline");

	c = tcase_create("parse");
	tcase_add_test(c, cmd_parse_empty);
	tcase_add_test(c, cmd_parse_file);
	tcase_add_test(c, cmd_parse_file_list);
	tcase_add_test(c, cmd_parse_options);
	suite_add_tcase(s, c);

	return s;
}

int main(void)
{
	Suite *s;
	SRunner *r;
	int n;

	s = cmdline_suite();
	r = srunner_create(s);

	srunner_run_all(r, CK_NORMAL);
	n = srunner_ntests_failed(r);

	srunner_free(r);

	return n != 0;
}
