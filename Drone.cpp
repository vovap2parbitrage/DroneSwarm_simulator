#include "Drone.h"

double root(double num) {
    double left = 0;
    double right = num;
    double mid = num/2.0;

    while(right - left > 0.01) {
        mid = (right + left)/2.0;

        if(mid > num/mid) {
            right = mid;
        }
        else left = mid;
    }

    return mid;
}