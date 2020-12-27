//
//  ParkMiller.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-26.
//  Copyright © 2020 RW. All rights reserved.
//

#include "ParkMiller.hpp"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_) : Seed(Seed_)
{
    // 0 seed yields a chain of zeros
    if (Seed == 0)
        Seed = 1;
}

void ParkMiller::SetSeed(long Seed_)
{
    Seed = Seed_;
    if (Seed == 0)
        Seed = 1;
}

unsigned long ParkMiller::Min()
{
    return 1;
}

unsigned long ParkMiller::Max()
{
    return m-1;
}

long ParkMiller::GetOneRandomInteger()
{
    long k = Seed / q;
    
    Seed=a*(Seed-k*q)-r*k;
    if (Seed < 0)
        Seed += m;
    
    return Seed;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality_, unsigned long InitialSeed_) :
RandomBase(Dimensionality_), InnerGenerator(InitialSeed_), InitialSeed(InitialSeed_)
// note that RandomBase does not have default constructor, therefore must be explicitly initialized.
{
    Reciprocal = 1 / (1 + InnerGenerator.Max()); // add 1 to obtained random number in an open interval (0, 1), not [0, 1]
}

RandomBase* RandomParkMiller::clone() const
{
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(MJArray &variates)
{
    for (unsigned long i=0; i<GetDimensionality(); i++)
        variates[i] = InnerGenerator.GetOneRandomInteger() * Reciprocal;
}

void RandomParkMiller::Skip(unsigned long numberOfPaths)
{
    MJArray tmp(GetDimensionality());
    for (unsigned i=0; i<numberOfPaths; i++)
        GetUniforms(tmp);
}

void RandomParkMiller::SetSeed(unsigned long Seed)
{
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset()
{
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality)
{
    RandomBase::ResetDimensionality(NewDimensionality);
    // need to reset the seed when dimensionality changed.
    Reset();
}
