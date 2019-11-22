#include "gtest/gtest.h"
#include "other_func.h"

class MyTest : public ::testing::Test{};

TEST_F(MyTest, other_func1)
{
	other_func();
}

