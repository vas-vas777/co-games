// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "co-games.h"
#include <iostream>


int main()
{
    for (auto i : chars) {
        std::cout << i.first << " = " << i.second << "; ";
        std::cout << std::endl;
    }
    //std::vector<int> vec;
    //std::cout << std::set_union(0b0001, 0b0010, std::back_inserter(vec)) << std::endl;
    if (is_supperadditive(chars) == true)
    {
        std::cout << "super_additive" << std::endl;
    }
    else
    {
        std::cout << "not_super_additive" << std::endl;
    }

    if (is_convex(chars) == true)
    {
        std::cout << "game is convex" << std::endl;
    }
    else
    {
        std::cout << "game is not convex" << std::endl;
    }
    std::vector<double> vector = shapley_vector(chars);
    for (auto i : vector)
    {
        std::cout << roundl(i*100)/100 << " ";
    }
    std::cout << std::endl;
    if (check_group_rationalization(vector) == true)
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }

    if (check_individual_rationalization(vector) == true)
    {
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }
}


