//
//  Normals.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-12-26.
//  Copyright © 2020 RW. All rights reserved.
//

#include "Normals.hpp"
#include <cmath>
using namespace std;

const double OneOverRootTwoPi = 0.398942280401433;

// pdf of standard normal distribution
double StandardNormalPDF(double x)
{
    return OneOverRootTwoPi * exp(-x*x/2);
}

// cdf of standard normal distribution
double StandardNormalCDF(double x)
{
    static double a[5] = { 0.319381530, -0.356563782, 1.781477937,
                           -1.821255978, 1.330274429};
    
    double result;
    if (x<-0.7)
        result = StandardNormalPDF(x) / sqrt(1 + x*x);
    else
    {
        if (x > 0.7)
            result = 1.0 - StandardNormalCDF(-x);
        else
        {
            double tmp = 1.0/(1.0+0.2316419*fabs(x));
            result = 1 - StandardNormalPDF(x) * (tmp*(a[0]+tmp*(a[1]+tmp*(a[2]+tmp*(a[3]+tmp*a[4])))));
            
            if (x<=0.0)
                result = 1.0 - result;
        }
    }
    
    return result;
}

// inverse cdf of standard normal distribution
// Beasley-Springer and Moro approximation : piece-wise approximation
double InverseCDFStandardNormal(double u)
{
    static double a[4]={ 2.50662823884,
                         -18.61500062529,
                         41.39119773534,
                         -25.44106049637};
    static double b[4]={-8.47351093090,
                        23.08336743743,
                        -21.06224101826,
                        3.13082909833};
    static double c[9]={0.3374754822726147,
                        0.9761690190917186,
                        0.1607979714918209,
                        0.0276438810333863,
                        0.0038405729373609,
                        0.0003951896511919,
                        0.0000321767881768,
                        0.0000002888167364,
                        0.0000003960315187};
    double x=u-0.5;
    double r;
    if (fabs(x)<0.42) // Beasley-Springer
    {
        double y=x*x;
        r = x * (((a[3]*y+a[2])*y+a[1])*y+a[0]) / ((((b[3]*y+b[2])*y+b[1])*y+b[0])*y+1.0);
    }
    else // Moro
    {
        r=u;
        if (x>0.0)
            r=1.0-u;
        r=log(-log(r));
        r=c[0]+r*(c[1]+r*(c[2]+r*(c[3]+r*(c[4]+r*(c[5]+r*(c[6]+r*(c[7]+r*c[8])))))));
        if (x<0.0)
            r=-r;
    }
    return r;
}
