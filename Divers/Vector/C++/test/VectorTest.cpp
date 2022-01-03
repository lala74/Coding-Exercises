#include <gtest/gtest.h>
#include <iostream>

#include "Vector.h"

using namespace ::testing;
using namespace std;

const int limit = 1e4;

class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override;
    void TearDown() override;

    Vector<int> vector;
};

void VectorTest::SetUp() {}

void VectorTest::TearDown() {}

TEST_F(VectorTest, PushBack)
{
    for (int i = 0; i < 100; i++) {
        vector.PushBack(i * 2);
    }
    ASSERT_EQ(vector[30], 60);
}

TEST_F(VectorTest, PushBackBig)
{
    for (int i = 0; i < limit; i++) {
        vector.PushBack(i * 2);
    }
    ASSERT_EQ(vector[100], 200);
    vector.Clear();
    ASSERT_EQ(vector.Size(), 0);
}

TEST_F(VectorTest, PopBack)
{
    for (int i = 0; i < 100; i++) {
        vector.PushBack(i * 2);
    }
    for (int i = 0; i < 100; i++) {
        vector.PopBack();
    }
    ASSERT_EQ(vector.Size(), 0);
}

