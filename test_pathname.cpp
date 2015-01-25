#include "gtest/gtest.h"
#include "pathname.h"


TEST(pathname, trim_leading_slash) {
  ASSERT_EQ("one/two/three/", pathname::trim_leading_slash("///one/two/three/"));
  ASSERT_EQ("", pathname::trim_leading_slash("////"));
  ASSERT_EQ("", pathname::trim_leading_slash(""));
}


TEST(pathname, trim_trailing_slash) {
  ASSERT_EQ("/one/two/three", pathname::trim_trailing_slash("/one/two/three///"));
  ASSERT_EQ("", pathname::trim_trailing_slash("//////"));
  ASSERT_EQ("", pathname::trim_trailing_slash(""));
}


TEST(pathname, join) {
  ASSERT_EQ("one/two", pathname::join("one", "two"));
  ASSERT_EQ("one/two/three", pathname::join("one", "two", "three"));
  ASSERT_EQ("one/two/three/four", pathname::join("one", "two", "three", "four"));

  ASSERT_EQ("/one/two/", pathname::join("/one", "two/"));
  ASSERT_EQ("/one/two/", pathname::join("/one/", "/two/"));

  ASSERT_EQ("one", pathname::join("one", ""));
  ASSERT_EQ("one", pathname::join("", "one"));
}


TEST(pathname, base) {
  ASSERT_EQ(".", pathname::base("/one/two/three/"));
  ASSERT_EQ("three", pathname::base("/one/two/three"));
  ASSERT_EQ("one", pathname::base("/one"));
  ASSERT_EQ("/", pathname::base("/"));
  ASSERT_EQ("", pathname::base(""));
}


TEST(pathname, dir) {
  ASSERT_EQ("/one/two/three", pathname::dir("/one/two/three/"));
  ASSERT_EQ("/one/two", pathname::dir("/one/two/three"));
  ASSERT_EQ("/", pathname::dir("/one"));
  ASSERT_EQ("/", pathname::dir("/"));
  ASSERT_EQ("", pathname::dir(""));
}


TEST(pathname, is_absolute) {
  ASSERT_TRUE(pathname::is_absolute("/"));
  ASSERT_TRUE(pathname::is_absolute("/one/two"));
  ASSERT_FALSE(pathname::is_absolute(""));
  ASSERT_FALSE(pathname::is_absolute("one/two/"));
}
