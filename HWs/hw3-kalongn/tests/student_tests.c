#include "unit_tests.h"

TestSuite(student_suite, .timeout = TEST_TIMEOUT);

/*
Test(student_suite, name_of_test, .description="description of test") {
    // Steps of unit test go here
}
*/
// Test cases for strglen
Test(student_suite, strglen_str_one)
{
    char *plaintext = "Stony Brook";
    int key_act = strgLen(plaintext);
    int key_exp = 11;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_two)
{
    char *plaintext = "CSE 220";
    int key_act = strgLen(plaintext);
    int key_exp = 7;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_three)
{
    char *plaintext = "C";
    int key_act = strgLen(plaintext);
    int key_exp = 1;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_four)
{
    char *plaintext = "System Fundamental";
    int key_act = strgLen(plaintext);
    int key_exp = 18;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_five)
{
    char *plaintext = "1";
    int key_act = strgLen(plaintext);
    int key_exp = 1;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_six)
{
    char *plaintext = "";
    int key_act = strgLen(plaintext);
    int key_exp = 0;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

Test(student_suite, strglen_str_seven)
{
    char *plaintext = NULL;
    int key_act = strgLen(plaintext);
    int key_exp = -1;
    cr_expect_eq(key_act, key_exp, "Return value was %d, but it should have been %d.\n", key_act, key_exp);
}

// Test cases for strgCopy
Test(student_suite, strgCopy_one)
{
    char source[] = "Computer Science";
    char destination[50] = "*I can store any message!*";
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}

Test(student_suite, strgCopy_two)
{
    char source[] = "CSE-220";
    char destination[50] = "*I can store any message!*";
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}

Test(student_suite, strgCopy_three)
{
    char source[] = "System Fundamental";
    char destination[50] = "*I can store any message!*";
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}

Test(student_suite, strgCopy_four)
{
    char source[] = "1";
    char destination[50] = "*I can store any message!*";
    strgCopy(source, destination);
    cr_expect_str_eq(destination, source, "Expected: \"%s\", Actual: \"%s\"\n", source, destination);
}

Test(student_suite, strgCopy_five)
{
    char *source = "";
    char destination[50] = "*I can store any message!*";
    strgCopy(source, destination);
    cr_expect_str_empty(destination, "Expected: \"\", Actual: \"%s\"\n", destination);
}
Test(student_suite, strgCopy_six)
{
    char source[] = "System Fundamental";
    char destination[12] = "HiHiHiHiHiH";
    strgCopy(source, destination);
    char expect[] = "System Fund";
    cr_expect_str_eq(destination, expect, "Expected: \"%s\", Actual: \"%s\"\n", expect, destination);
}

// Test cases for strgChangeCase
Test(student_suite, strgChangeCase_one)
{
    char str[] = "Stony Brook";
    char expected[] = "sTONY bROOK";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

Test(student_suite, strgChangeCase_two)
{
    char str[] = "CSE220";
    char expected[] = "cse220";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

Test(student_suite, strgChangeCase_three)
{
    char str[] = "C";
    char expected[] = "c";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

Test(student_suite, strgChangeCase_four)
{
    char str[] = "System Fundamental";
    char expected[] = "sYSTEM fUNDAMENTAL";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

Test(student_suite, strgChangeCase_five)
{
    char str[] = "1";
    char expected[] = "1";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

Test(student_suite, strgChangeCase_six)
{
    char str[] = "";
    char expected[] = "";
    strgChangeCase(str);
    cr_expect_str_eq(str, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, str);
}

// Test cases for strgDiff
Test(student_suite, strgDiff_one)
{
    char *s1 = "Hello";
    char *s2 = "Hello";
    int diff = strgDiff(s1, s2);
    cr_expect_eq(diff, -1, "Expected: -1, Actual: %d\n", diff);
}

Test(student_suite, strgDiff_two)
{
    char *s1 = "CSE-220";
    char *s2 = "CSE220";
    int diff = strgDiff(s1, s2);
    int expected = 3;
    cr_expect_eq(diff, expected, "Expected: %d, Actual: %d\n", expected, diff);
}

Test(student_suite, strgDiff_three)
{
    char *s1 = "CSE220";
    char *s2 = "SE220";
    int diff = strgDiff(s1, s2);
    int expected = 0;
    cr_expect_eq(diff, expected, "Expected: %d, Actual: %d\n", expected, diff);
}

Test(student_suite, strgDiff_four)
{
    char *s1 = "";
    char *s2 = "";
    int diff = strgDiff(s1, s2);
    int expected = -2;
    cr_expect_eq(diff, expected, "Expected: %d, Actual: %d\n", expected, diff);
}

// Test cases for strgInterleave
Test(student_suite, strgInterleave_one)
{
    char *s1 = "abc";
    char *s2 = "123";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "a1b2c3";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(student_suite, strgInterleave_two)
{
    char *s1 = "abcdef";
    char *s2 = "123";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "a1b2c3def";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(student_suite, strgInterleave_three)
{
    char *s1 = "cse";
    char *s2 = "12345";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "c1s2e345";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(student_suite, strgInterleave_four)
{
    char *s1 = "1234";
    char *s2 = "cs";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "1c2s34";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(student_suite, strgInterleave_five)
{
    char *s1 = "";
    char *s2 = "";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}

Test(student_suite, strgInterleave_six)
{
    char *s1 = "";
    char *s2 = "123";
    char d[50] = "*I can store any message!*";
    strgInterleave(s1, s2, d);
    char *expected = "123";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}
Test(student_suite, strgInterleave_)
{
    char *s1 = "abc";
    char *s2 = "123";
    char d[5] = "Hell";
    strgInterleave(s1, s2, d);
    char *expected = "a1b2";
    cr_expect_str_eq(d, expected, "Expected: \"%s\", Actual: \"%s\"\n", expected, d);
}
// encrypt
Test(student_suite, encrypt_one)
{
    const char *plaintext = "abc";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 2);
    char *ciphertext_exp = "cde__EOM__";
    int count_exp = 3;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_two)
{
    const char *plaintext = "Ayb";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 3);
    char *ciphertext_exp = "Dbe__EOM__";
    int count_exp = 3;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_three)
{
    const char *plaintext = "Cse220";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 1);
    char *ciphertext_exp = "Dtf331__EOM__";
    int count_exp = 6;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_four)
{
    const char *plaintext = "CS";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 0);
    char *ciphertext_exp = "CS__EOM__";
    int count_exp = 2;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_five)
{
    const char *plaintext = "";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 0);
    char *ciphertext_exp = "undefined__EOM__";
    int count_exp = 0;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_six)
{
    const char *plaintext = "Hei";
    char ciphertext_act[] = "testing12";
    int count_act = encryptModified(plaintext, ciphertext_act, 0);
    char *ciphertext_exp = "testing12";
    int count_exp = -1;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_seven)
{
    const char *plaintext = "Hei";
    char ciphertext_act[] = "y";
    int count_act = encryptModified(plaintext, ciphertext_act, 0);
    int count_exp = -1;
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_eight)
{
    const char *plaintext = "System Fundamentals";
    char ciphertext_act[] = "***I can store any message!***";
    int count_act = encryptModified(plaintext, ciphertext_act, 1);
    char *ciphertext_exp = "Tztufn Gvoebnfoubmt__EOM__";
    int count_exp = 18;
    cr_expect_str_eq(ciphertext_act, ciphertext_exp, "ciphertext was: %s\nbut it should have been: %s", ciphertext_act, ciphertext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, encrypt_nine)
{
    const char *plaintext = NULL;
    char *ciphertext_act = NULL;
    int count_act = encryptModified(plaintext, ciphertext_act, 0);
    int count_exp = -1;
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

// decrypt
Test(student_suite, decrypt_one)
{
    const char *ciphertext = "Tztufn Gvoebnfoubmt__EOM__";
    char plaintext_act[] = "***I can store any message!***";
    int count_act = decrypt(ciphertext, plaintext_act, 1);
    char *plaintext_exp = "System Fundamentals";
    int count_exp = 18;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_two)
{
    const char *ciphertext = "cde__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 2);
    char *plaintext_exp = "abc";
    int count_exp = 3;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_three)
{
    const char *ciphertext = "Dbe__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 3);
    char *plaintext_exp = "Ayb";
    int count_exp = 3;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_four)
{
    const char *ciphertext = "Dtf331__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 26);
    char *plaintext_exp = "Dtf775";
    int count_exp = 6;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_five)
{
    const char *ciphertext = "CS__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 0);
    char *plaintext_exp = "CS";
    int count_exp = 2;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_six)
{
    const char *ciphertext = "__EOM__";
    char plaintext_act[] = "I can store any message!";
    int count_act = decrypt(ciphertext, plaintext_act, 0);
    char *plaintext_exp = "undefined";
    int count_exp = 0;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_seven)
{
    const char *ciphertext = "test__EOM__";
    char plaintext_act[] = "";
    int count_act = decrypt(ciphertext, plaintext_act, 0);
    char *plaintext_exp = "";
    int count_exp = 0;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_eight)
{
    const char *ciphertext = "test__EOM_";
    char plaintext_act[] = "test";
    int count_act = decrypt(ciphertext, plaintext_act, 0);
    char *plaintext_exp = "test";
    int count_exp = -1;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}

Test(student_suite, decrypt_ninth)
{
    const char *ciphertext = "test__EOM__";
    char plaintext_act[] = "tes";
    int count_act = decrypt(ciphertext, plaintext_act, 1);
    char *plaintext_exp = "sdr";
    int count_exp = 3;
    cr_expect_str_eq(plaintext_act, plaintext_exp, "ciphertext was: %s\nbut it should have been: %s", plaintext_act, plaintext_exp);
    cr_expect_eq(count_act, count_exp, "Return value was %d, but it should have been %d.\n", count_act, count_exp);
}
