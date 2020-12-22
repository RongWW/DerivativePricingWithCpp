//
//  main.cpp
//  DerivativePricing_cpp
//
//  Created by Rong Wang on 2020-11-28.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC1.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "\nChapter 1\n";
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nr\n";
    cin >> r;
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    double result = SimpleMonteCarlo1(Strike,
                                      Expiry,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);
    cout << fixed;
    cout <<"the price is " << setprecision(2) << result << "\n";
    
    return 0;
}
