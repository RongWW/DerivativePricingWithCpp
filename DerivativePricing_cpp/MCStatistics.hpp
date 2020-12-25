//
//  MCStatistics.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef MCStatistics_hpp
#define MCStatistics_hpp

#include <vector>

// base class define the interface
class StatisticsMC
{
public:
    StatisticsMC(){};
    
    virtual void DumpOneResult(double result)=0;
    virtual std::vector<std::vector<double>> GetResults_curr() const=0;
    virtual StatisticsMC* clone() const=0;
    virtual ~StatisticsMC(){}
    
private:
};

class StatisticsMean : public StatisticsMC
{
public:
    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResults_curr() const;
    virtual StatisticsMean* clone() const;
    
private:
    double RunningSum;
    unsigned long PathsCompleted;
};

#endif /* MCStatistics_hpp */
