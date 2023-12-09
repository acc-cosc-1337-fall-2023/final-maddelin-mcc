#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify roll_die returns a value between 1 and 6")
{
	Die a;
	for( int i = 0; i < 10; i++)
	{
		a.roll();
		REQUIRE((a.rolled_value() < 7 && a.rolled_value() > 0));
	}
}