#include <gtest/gtest.h>
#include "string.h"

TEST(StringTest, SubstringBasic) {
    String s("hello");
    EXPECT_EQ(s[0][4].get(), "hell");
}

TEST(StringTest, SubstringMiddle) {
    String s("hello");
    EXPECT_EQ(s[1][4].get(), "ell");
}

TEST(StringTest, EmptySubstring) {
    String s("hello");
    EXPECT_EQ(s[2][2].get(), "");
}

TEST(StringTest, FullSubstring) {
    String s("hello");
    EXPECT_EQ(s[0][5].get(), "hello");
}

TEST(StringTest, SingleChar) {
    String s("hello");
    EXPECT_EQ(s[1][2].get(), "e");
}
