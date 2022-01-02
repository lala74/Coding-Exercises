#include <gtest/gtest.h>
#include <iostream>

#include "Vector.h"

using namespace ::testing;
using namespace std;

const int limit = 1e1;

class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override;
    void TearDown() override;
};

void VectorTest::SetUp() {}

void VectorTest::TearDown() {}

TEST_F(VectorTest, PushBack)
{
    Vector<int> vector;
    for (int i = 0; i < limit; i++) {
        cout << "TEST :" << i << endl;
        vector.PushBack(i);
    }
    // ASSERT_EQ(vector[1], 1);
}

// TEST_F(VectorTest, Pop)
// {
//     for (int i = 0; i < limit; i++) {
//         vector.PushBack(i * 2);
//     }
//     ASSERT_EQ(vector[100], 200);
// }
