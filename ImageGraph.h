#pragma once

#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class ImageGraph {
    public:
        ImageGraph(vector<vector<float>>); //loads points into cartesian and then polar

        void place_on_map(vector<double>, float); //adjusts image to latitude longitude values

        //accessors
        vector<vector<float>> get_cartesian();
        vector<vector<float>> get_polar();
        vector<vector<double>> get_gps();

        string path(); //puts values into snap to roads format
        void set_radius(float); //scales polar coordinates to achieve desired max radius

    private:
        //point systems
        size_t n;
        vector<vector<float>> cartesian_points; //points in terms of x and y
        vector<vector<float>> polar_points; //points in terms of raidus and angle
        vector<vector<double>> gps_points; //cartesian points as latitudes and longitudes
        
        //attributes for map placement
        float max_r;
        vector<double> location; //center point latitude and longitude

        //init helpers
        void recenter(); //finds centroid of input points and sets it to origin
        vector<vector<float>> to_polar(vector<vector<float>>); //converts cartesian points to polar
        vector<vector<float>> to_cartesian(vector<vector<float>>); //converts cartesian points to polar
};
