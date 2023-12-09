#include"shooter.h"
#include"point_phase.h"
#include<iostream>
#include<random>
using std::cout;
int main() 
{
	srand(time(0));

	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll;
	roll = shooter.throw_die(die1, die2);
	ComeOutPhase come_out_phase;
	while ( come_out_phase.get_outcome(roll) == natural || come_out_phase.get_outcome(roll) == craps)
	{
		cout<<"Rolled "<< roll->roll_value()<<" roll again\n";
		roll = shooter.throw_die(die1, die2);
	};
	cout<<"Rolled "<<roll->roll_value()<<" start of point phase\nRoll until a "<<roll->roll_value()<<" or 7 is rolled\n";
	int p = roll->roll_value();
	roll = shooter.throw_die(die1, die2);
	PointPhase point_phase(p);

	//main program requirements seem to be contradicting. The output prompts the user to roll UNTIL the point value or a 7 is rolled
	//However, the while loop requirements state to run the loop while get_outcome == point or nopoint
	//If the point value is rolled, then the loop will continue because get_outcome will be point, even though the output implies the loop should exit at this point
	//I dont know how to actually play craps, so I dont know which is right, to continue to loop when the point is rolled or to exit loop
	//I will keep it as-is to match the main function requirements even though the loop contradicts the output

	while(point_phase.get_outcome(roll) == point || point_phase.get_outcome(roll) == nopoint)
	{
		cout<<"Rolled "<<roll->roll_value()<<" roll again\n";
		roll = shooter.throw_die(die1, die2);
	};
	cout<<"Rolled "<<roll->roll_value()<<" end of point phase\n";

	//I couldnt figure out the overload << operator so I am calling the function I wrote to display the roll vector to suffice the main programs output requirements, even though the method is incorrect
	shooter.display_rolls();
	

	return 0;
}