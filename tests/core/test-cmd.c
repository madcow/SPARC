#include "test-cmd.h"

START_TEST (cmd_parse_empty)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (cmd_parse_file)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (cmd_parse_file_list)
{
	ck_assert(1); // TODO
}
END_TEST

START_TEST (cmd_parse_options)
{
	ck_assert(1); // TODO
}
END_TEST

Suite *sp_test_cmd(void)
{
	Suite *s;
	TCase *c;

	s = suite_create("cmd");
	c = tcase_create("parse");

	tcase_add_test(c, cmd_parse_empty);
	tcase_add_test(c, cmd_parse_file);
	tcase_add_test(c, cmd_parse_file_list);
	tcase_add_test(c, cmd_parse_options);

	suite_add_tcase(s, c);

	return s;
}
