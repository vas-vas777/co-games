#include "co-games.h"


std::map<std::string, int> chars = {
    {"0",0},
    {"1",4},
    {"2",3},
    {"3",2},
    {"4",2},
    {"12",7},
    {"13",7},
    {"14",6},
    {"23",6},
    {"24",6},
    {"34",4},
    {"123",11},
    {"124",10},
    {"134",11},
    {"234",10},
    {"1234",14},
};

bool is_supperadditive(std::map<std::string, int>& map)
{
    std::string vec;
    std::string  key_union = "";

    for (auto i : map)
    {
        for (auto j : map)
        {
            std::set_intersection(i.first.begin(), i.first.end(), j.first.begin(), j.first.end(), std::back_inserter(vec));
            /* std::cout << "vec1" << std::endl;*/
            if (i.first == "0" || j.first == "0")
            {
                vec.clear();
                continue;
            }
            /*for (auto z : vec)
            {
                std::cout << z << std::endl;
            }*/
            if (vec.empty() == true)
            {
                vec.clear();

                key_union = i.first + j.first;
                std::sort(key_union.begin(), key_union.end());
                if (map[key_union] < (map[i.first] + map[j.first]))
                {
                    std::cout << map[key_union] << " < " << map[i.first] << " + " << map[j.first] << std::endl;
                    return false;
                }
            }
            vec.clear();

        }
        vec.clear();
    }
    return true;
}

bool is_convex(std::map<std::string, int>& map)
{

    std::string vec;
    std::string key_union = "";
    std::string key_intersect = "";

    for (auto i : map)
    {
        for (auto j : map)
        {
            std::set_intersection(i.first.begin(), i.first.end(), j.first.begin(), j.first.end(), std::back_inserter(vec));
            if (i.first == "0" || j.first == "0" || i.first == j.first)
            {
                vec.clear();
                continue;
            }

            if (vec.empty() == false)
            {
                for (auto i : vec)
                {
                    key_intersect += i;
                }
                //std::cout << key_intersect << std::endl;
            }
            std::sort(key_intersect.begin(), key_intersect.end());

            std::set_union(i.first.begin(), i.first.end(), j.first.begin(), j.first.end(), std::back_inserter(key_union));
            //key_union = i.first + j.first;
            std::sort(key_union.begin(), key_union.end());
            //std::cout << key_union << std::endl;
            //std::cout << map[] << std::endl;
           // std::cout << key_union << " " << key_intersect << " " << i.first << " " << j.first << std::endl;
           // std::cout << map[key_union] << "+" << map[key_intersect] << " >= " << map[i.first] << " + " << map[j.first] << std::endl;
            if ((map[key_union] + map[key_intersect]) < (map[i.first] + map[j.first]))
            {
                // std::cout << i.first + j.first << " " << i.first << " " << j.first << std::endl;
                std::cout << key_union << " " << key_intersect << " " << i.first << " " << j.first << std::endl;
                std::cout << map[key_union] << "+" << map[key_intersect] << " < " << map[i.first] << " + " << map[j.first] << std::endl;
                return false;
            }
            key_union.clear();
            key_intersect.clear();
            vec.clear();
        }
        key_union.clear();
        key_intersect.clear();
        vec.clear();
    }
    return true;
}

int factorial(int number)
{
    int result = 1;
    for (auto i = 1; i <= number; i++) {
        result = result * i;
    }
    return result;
}

std::vector<double> shapley_vector(std::map<std::string, int>& map, int N)
{
    std::vector<double> result;
    std::string coal;
    std::string result_symmetric_difference;
    double res = 0.0;
    for (auto i = 0; i < N; ++i)
    {
        res = 0.0;
        coal = std::to_string(i + 1);
        for (auto coals : map)
        {
            /* if (coals.first == "0")
             {
                 continue;
             }*/
            if (coals.first.find(coal) != std::string::npos)
            {
                std::set_symmetric_difference(coals.first.begin(), coals.first.end(), coal.begin(), coal.end(), std::back_inserter(result_symmetric_difference));
                //std::cout << i << " " <<coals.first<<" "<<result_symmetric_difference<<" "<< map[coals.first] << " " << map[result_symmetric_difference] << std::endl;
                res += double(factorial(coals.first.size() - 1)) * double(factorial(N - coals.first.size())) *
                    double((map[coals.first] - map[result_symmetric_difference]));
                //std::cout << res << std::endl;
                result_symmetric_difference.clear();
            }
            else
            {
                result_symmetric_difference.clear();
                continue;
            }
        }
        res /= factorial(N);
        result.push_back(res);
        result_symmetric_difference.clear();
    }
    return result;
}

bool check_group_rationalization(std::vector<double> vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0);
}

bool check_individual_rationalization(std::vector<double> vec, int N)
{
    for (auto i = 0; i < N; ++i)
    {
        if (vec[i] < chars[std::to_string(powl(i, 2))])
        {
            return false;
        }
    }
    return true;
}