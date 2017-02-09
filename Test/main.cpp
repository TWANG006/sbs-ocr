#include <iostream>
#include <vector>
#include "gtest\gtest.h"


using namespace std;

int main(int argc, char** argv)
{
	/* Need to be revised*/

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	return 0;
}