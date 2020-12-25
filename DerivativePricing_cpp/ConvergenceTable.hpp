//
//  ConvergenceTable.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef ConvergenceTable_hpp
#define ConvergenceTable_hpp

#include "MCStatistics.hpp"
#include "Wrapper.hpp"

class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);
    
    virtual StatisticsMC* clone() const;
    virtual void DumpOneResult(double result);
    virtual std::vector<std::vector<double>> GetResults_curr() const;
    
private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> ResultsSoFar;
    unsigned long StopPoint;
    unsigned long PathsCompleted;
};

#endif /* ConvergenceTable_hpp */
