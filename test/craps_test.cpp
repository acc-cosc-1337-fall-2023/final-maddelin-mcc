#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "point_phase.h"
#include <iostream>
using std::cout; 

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

TEST_CASE("Verify Shooter returns a roll between 2 and 12")
{
	Shooter shooter;
	Die die1;
	Die die2;
	Roll* roll = shooter.throw_die(die1, die2);
	REQUIRE( (roll->roll_value() > 1 && roll->roll_value() < 13) );
}

TEST_CASE("Verify ComeOutPhase.get_outcome() returns natural, craps and point")
{
	//create a shooter instance to pass the roll
	Shooter shooter;
	Die die1;
	Die die2;
	Roll* roll;
	ComeOutPhase phase;

	//check for natural return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() != 7 && roll->roll_value() != 11 );
	REQUIRE( phase.get_outcome(roll) == natural);

	//check for craps return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() != 2 && roll->roll_value() != 3 && roll->roll_value() != 12 );
	REQUIRE( phase.get_outcome(roll) == craps);

	//check for point return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() == 2 || roll->roll_value() == 3 || roll->roll_value() == 7 || roll->roll_value() == 11 || roll->roll_value() == 12);
	REQUIRE( phase.get_outcome(roll) == point);
}

TEST_CASE("Verify PointPhase.get_outcome() returns point, seven_out, and nopoint")
{
	//create a shooter instance to pass the roll
	Shooter shooter;
	Die die1;
	Die die2;
	Roll* roll;
	//set point to 4 (ComeOutPhase.get_outcome() == point)
	int p = 4;
	PointPhase phase(p);

	//check for point return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() != p );
	REQUIRE( phase.get_outcome(roll) == point);
	
	//check for seven_out return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() != 7 );
	REQUIRE( phase.get_outcome(roll) == seven_out);
	
	//check for nopoint return
	do
	{
		roll = shooter.throw_die(die1, die2);
	} while ( roll->roll_value() == 7  || roll->roll_value() == 4);
	REQUIRE( phase.get_outcome(roll) == nopoint);
}