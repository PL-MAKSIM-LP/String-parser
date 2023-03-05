#include "parser.h"
#include <gtest/gtest.h>

TEST(test1, positive) {

    ASSERT_EQ(parser::parse("a3[b3[a]]"), "abaaabaaabaaa");
}
TEST(test2, positive) {

    ASSERT_EQ(parser::parse("a0[b3[a]]"), "a");
}
TEST(test3, positive) {

    ASSERT_EQ(parser::parse("abcd2[a]"), "abcdaa");
}
TEST(test4, positive) {

    ASSERT_EQ(parser::parse("q1[a]2[b]1[c]"), "qabbc");
}
TEST(test5, positive) {

    ASSERT_EQ(parser::parse("20[0[b]]"), "");
}
TEST(test6, positive) {

    ASSERT_EQ(parser::parse("a1[3[]]"), "a");
}
