#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits> // For std::numeric_limits

class interval {
  public:
    double min, max;

    interval() 
        : min(std::numeric_limits<double>::infinity()), 
          max(-std::numeric_limits<double>::infinity()) {} // Default interval is empty

    interval(double min, double max) : min(min), max(max) {}

    double size() const {
        return max - min;
    }

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }

    static const interval empty, universe;
};

// Define empty and universe intervals using correct infinity constants
const interval interval::empty = interval(
    std::numeric_limits<double>::infinity(), 
    -std::numeric_limits<double>::infinity()
);
const interval interval::universe = interval(
    -std::numeric_limits<double>::infinity(), 
    std::numeric_limits<double>::infinity()
);

#endif
