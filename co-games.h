#pragma once
#include<iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <numeric>
bool is_supperadditive(std::map<std::string, int>& map);
bool is_convex(std::map<std::string, int>& map);
int factorial(int number);
std::vector<double> shapley_vector(std::map<std::string, int>& map, int N = 4);
bool check_group_rationalization(std::vector<double> vec);
bool check_individual_rationalization(std::vector<double> vec, int N = 4);
extern std::map<std::string, int> chars;
