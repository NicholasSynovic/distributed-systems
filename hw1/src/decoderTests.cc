/* test cases */
#include <gtest/gtest.h>
#include "decoder.h"

// #include <queue>
// #include <string>
// #include <sstream>

// using namespace std;

// class SplitStringTest : public ::testing::Test {
//  protected:
//   void SetUp() override {
//     testString = "this is a test string";
//     expectedWords.push("this");
//     expectedWords.push("is");
//     expectedWords.push("a");
//     expectedWords.push("test");
//     expectedWords.push("string");
//   }

//   string testString;
//   queue<string> expectedWords;
// };

// TEST_F(SplitStringTest, splitStringTest) {
//   queue<string> result = splitString(testString);
//   EXPECT_EQ(result.size(), expectedWords.size());

//   while (!expectedWords.empty()) {
//     EXPECT_EQ(result.front(), expectedWords.front());
//     result.pop();
//     expectedWords.pop();
//   }
// }


// Test function used in attempt to isolate undefined reference issue.

// TEST(DecoderTests, PositiveNos) {
//   ASSERT_EQ(5, do_nothing());
// }

// TEST(DecoderTests, splitString) {
//   string test_string = "test";
//   queue<string> return_q;
//   return_q = splitString(test_string);
//   string func_result = return_q.front();
//   ASSERT_EQ(test_string, func_result);
// }

// TEST(DecoderTests, decode) {
//   pair<int, string> testPair;
//   unordered_set<string> dict;
//   testPair = make_pair(1, "hello");
//   dict.insert("hello");
//   string testString = "Ifmmp";
//   pair<int, string> result = decode(dict, testString);
//   ASSERT_EQ(testPair.first, result.first);
//   ASSERT_EQ(testPair.second, result.second);
// }

// TEST(DecoderTests, setOutputPath) {
//   ASSERT_EQ("stdout", setOutputPath());
//   ASSERT_EQ("test", setOutputPath("test"));
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
