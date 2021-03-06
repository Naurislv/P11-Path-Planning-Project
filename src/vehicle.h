#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <math.h>

// Local imports
#include "helpers.h"
#include "map.h"
#include "states.h"

// Spline guarantees that line will go through all points
// where polynomial fit does not guarantee that
#include "external/spline.hpp"

using namespace std;

class Vehicle {
public:

    /**
    * Constructor
    */
    Vehicle(Map input_map);

    /**
    * Destructor
    */
    virtual ~Vehicle();

    Map map;
    States states;
    
    void apply_path(
        vector<double> &next_x_vals,
        vector<double> &next_y_vals
    );
    
    // start in lane 1;
    int lane = 1;
    // Reference velocity
    double ref_vel = 45.9; // mph
    // Goal velocity set by predicting module, starting with 0
    double goal_vel = 0; // mph
};

#endif