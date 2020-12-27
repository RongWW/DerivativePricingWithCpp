//
//  AntiThetic.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-26.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef AntiThetic_hpp
#define AntiThetic_hpp

#include "Random2.hpp"
#include "Wrapper.hpp"

class AntiThetic : public RandomBase
{
public:
    AntiThetic(const Wrapper<RandomBase>& InnerGenerator);
    
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    Wrapper<RandomBase> InnerGenerator;
    bool OddEven;
    MJArray NextVariates;
};

#endif /* AntiThetic_hpp */
