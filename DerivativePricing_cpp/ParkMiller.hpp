//
//  ParkMiller.hpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-26.
//  Copyright © 2020 RW. All rights reserved.
//

#ifndef ParkMiller_hpp
#define ParkMiller_hpp

#include "Random2.hpp"

/* Linear Congruential Generator: the minimal standard generator*/

// piece 1: inner class develops a random generator
// that returns one long integer every time it called
class ParkMiller
{
public:
    ParkMiller(long Seed_ = 1);
    void SetSeed(long Seed_);
    long GetOneRandomInteger();
    
    static unsigned long Min(); // static members: have a class scope
    static unsigned long Max(); // static members: have a class scope
    
private:
    long Seed;
};

// piece 2: adapter pattern - larger class that returns output into a vector of uniforms
class RandomParkMiller : public RandomBase
{
public:
    RandomParkMiller(unsigned long Dimensionality,
                     unsigned long InitialSeed=1);
    
    virtual RandomBase* clone() const;
    virtual void GetUniforms(MJArray& variates);
    virtual void Skip(unsigned long numberOfPaths);
    virtual void SetSeed(unsigned long Seed);
    virtual void Reset();
    virtual void ResetDimensionality(unsigned long NewDimensionality);
    
private:
    ParkMiller InnerGenerator;
    unsigned long InitialSeed;
    double Reciprocal;
};


#endif /* ParkMiller_hpp */
