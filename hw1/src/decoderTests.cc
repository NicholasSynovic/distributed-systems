/* test cases */

#include <gtest/gtest.h>
#include "decoder.h"

// TEST(decoderTests, PositiveNos) {
//     ASSERT_EQ(6, square_root(36.0));
//     ASSERT_EQ(18.0, square_root(324.0));
//     ASSERT_EQ(25.4, square_root(645.16));
//     ASSERT_EQ(0, square_root(0.0));
// }

// TEST(SquareRootTest, NegativeNos) {
//     ASSERT_EQ(-1.0, square_root(-15.0));
//     ASSERT_EQ(-1.0, square_root(-0.2));
// }

TEST(DecoderTests, decode) {
  pair<int, string> testPair;
  unordered_set<string> dict;
  testPair = make_pair(1, "hello");
  dict.insert("hello");
  string testString = "Ifmmp";
  pair<int, string> result = decode(dict, testString);
  ASSERT_EQ(testPair.first, result.first);
  ASSERT_EQ(testPair.second, result.second);
}

TEST(DecoderTests, setOutputPath) {
  ASSERT_EQ("stdout", setOutputPath());
  ASSERT_EQ("test", setOutputPath("test"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
