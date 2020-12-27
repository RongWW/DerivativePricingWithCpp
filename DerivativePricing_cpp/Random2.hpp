//
//  Random2.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-25.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef Random2_hpp
#define Random2_hpp

#include "Arrays.hpp"

class RandomBase
{
public:
    RandomBase(unsigned long Dimensionality);
    
    inline unsigned long GetDimensionality() const; // return dimensionality of the generator
    
    virtual RandomBase* clone() const=0;
    virtual void GetUniforms(MJArray& variates)=0; // reference to an array: save time on copying array
    virtual void Skip(unsigned long numberOfPaths)=0;
    virtual void SetSeed(unsigned long Seed)=0;
    virtual void Reset()=0;
    
    virtual void GetGaussian(MJArray& variates); // transform uniforms into standard Gaussian distributions
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    unsigned long Dimensionality;
};

inline unsigned long RandomBase::GetDimensionality() const
{
    return Dimensionality;
}
#endif /* Random2_hpp */
