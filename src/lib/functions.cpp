#include <random>
#include <iostream>
#include "functions.h"

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<double> dist(0, 1);

double uniform() { return dist(mt); }