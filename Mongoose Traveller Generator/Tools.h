#pragma once
#include <string>
#include <algorithm>

namespace Tools
{
    int clamp(int n, int lower, int upper) {
        return std::max(lower, std::min(n, upper));
    }

    bool IsInRange(int target, int low, int high)
    {
        if (target > low - 1 && target < high + 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int RollDice(int dice)
    {
        int result = 0;

        for (int i = 0; i < dice; ++i)
        {
            result += rand() % 6 + 1;
        }

        return result;
    }

    std::string GenerateRandomAlphanum(int len)
    {
        static const char alphanum_options[] = "0123456789ABVDEFGHIJKLMNOPQRSTUVWXYZ";

        std::string generated_alphanum;

        for (int i = 0; i < len; ++i)
        {
            generated_alphanum.push_back(alphanum_options[rand() % sizeof(alphanum_options)]);
        }

        return generated_alphanum;
    }
}