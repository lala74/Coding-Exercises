//
// Copyright (c) 2022 Axon Enterprise
//
/**
 * @author      : La Minh Duc
 * @file        : Duration.h
 * @created     : Sunday Jan 02, 2022 18:09:20 +07
 */

#ifndef DURATION_H
#define DURATION_H

#include <iostream>

using namespace std::chrono;

class Duration
{
public:
    Duration() { startTime = steady_clock::now(); }
    ~Duration()
    {
        std::cout << "------ FINISH ------" << std::endl;
        auto duration = duration_cast<milliseconds>(steady_clock::now() - startTime).count();
        std::cout << "Runtime: " << duration << " ms" << std::endl;
    }

private:
    steady_clock::time_point startTime;
};

#endif /* DURATION_H */

