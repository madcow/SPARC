#include "test-cmdline.h"

START_TEST (test_cmdline_read_arguments_empty)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_file_list)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_double_dash)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_options_short)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_options_long)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_number)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_string)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_boolean)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_optional_quotes)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (test_cmdline_read_arguments_optional_equals)
{
	ck_assert(1); // TODO
}
END_TEST

Suite *sp_test_core_cmdline(void)
{
	Suite *s;
	TCase *c;

	s = suite_create("core_cmdline");

	c = tcase_create("read_arguments");
	tcase_add_test(c, test_cmdline_read_arguments_empty);
	tcase_add_test(c, test_cmdline_read_arguments_file_list);
	tcase_add_test(c, test_cmdline_read_arguments_double_dash);
	tcase_add_test(c, test_cmdline_read_arguments_options_short);
	tcase_add_test(c, test_cmdline_read_arguments_options_long);
	tcase_add_test(c, test_cmdline_read_arguments_number);
	tcase_add_test(c, test_cmdline_read_arguments_string);
	tcase_add_test(c, test_cmdline_read_arguments_boolean);
	tcase_add_test(c, test_cmdline_read_arguments_optional_quotes);
	tcase_add_test(c, test_cmdline_read_arguments_optional_equals);
	suite_add_tcase(s, c);

	return s;
}
