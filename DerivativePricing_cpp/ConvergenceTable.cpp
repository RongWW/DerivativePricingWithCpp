//
//  ConvergenceTable.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#include "ConvergenceTable.hpp"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_) : Inner(Inner_)
{
    StopPoint=2;
    PathsCompleted=0;
}

StatisticsMC* ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result)
{
    Inner->DumpOneResult(result);
    PathsCompleted++;
    
    if (PathsCompleted == StopPoint)
    {
        StopPoint *= 2;
        std::vector<std::vector<double>> thisResult(Inner->GetResults_curr());
        
        for (unsigned long i=0; i<thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsCompleted);
            ResultsSoFar.push_back(thisResult[i]);
        }
    }
    
    return;
}

std::vector<std::vector<double>> ConvergenceTable::GetResults_curr() const
{
    std::vector<std::vector<double>> tmp(ResultsSoFar);
    
    if (PathsCompleted*2 != StopPoint)
    {
        std::vector<std::vector<double>> thisResult(Inner->GetResults_curr());
        
        for (unsigned long i=0; i < thisResult.size(); i++)
        {
            thisResult[i].push_back(PathsCompleted);
            tmp.push_back(thisResult[i]);
        }
    }
    return tmp;
}
