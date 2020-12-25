//
//  MCStatistics.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#include "MCStatistics.hpp"

StatisticsMean::StatisticsMean() : RunningSum(0), PathsCompleted(0UL)
{}

void StatisticsMean::DumpOneResult(double result)
{
    PathsCompleted++;
    RunningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResults_curr() const
{
    std::vector<std::vector<double>> Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsCompleted;
    
    return Results;
}

StatisticsMean* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
