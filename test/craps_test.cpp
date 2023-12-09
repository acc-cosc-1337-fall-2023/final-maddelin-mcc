#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify Die.roll_die() returns a value between 1 and 6")
{
	Die a;
	for( int i = 0; i < 10; i++)
	{
		a.roll();
		REQUIRE((a.rolled_value() < 7 && a.rolled_value() > 0));
	}
}

TEST_CASE("Verify Roll.roll_die() stores a value between 2 and 12")
{
	Die die1;
	Die die2; 
	Roll roll(die1, die2);
	for( int i = 1; i < 10; i++)
	{
		roll.roll_die();
		REQUIRE( (roll.roll_value() > 1 && roll.roll_value() < 13) );
	}
}