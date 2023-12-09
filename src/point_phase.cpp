#include"point_phase.h"

//ComeOutPhase public functions
RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    int roll_val = roll->roll_value();
    if( roll_val == 7 || roll_val == 11)
    {
        return RollOutcome::natural;
    }
    else if( roll_val == 2 || roll_val == 3 || roll_val == 12 )
    {
        return RollOutcome::craps;
    }
    return RollOutcome::point;
}

//PointPhase public functions
RollOutcome PointPhase::get_outcome(Roll* roll)
{
    int roll_val = roll->roll_value();
    if( roll_val == point )
    {
        return RollOutcome::point;
    }
    else if ( roll_val == 7 )
    {
        return RollOutcome::seven_out;
    }
    return RollOutcome::nopoint;
}