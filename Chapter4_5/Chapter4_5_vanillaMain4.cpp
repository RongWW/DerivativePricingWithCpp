//
//  main.cpp
//  Chapter4_5
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC6.hpp"
#include "Vanilla3.hpp"
#include "Parameters.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Spot;
    double Strike;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nChapter4_4\n";
    cout << "\nExpiry\n";
    cin >> Expiry;
    cout << "\nSpot\n";
    cin >> Spot;
    cout << "\nStrike\n";
    cin >> Strike;
    cout << "\nr\n";
    cin >> r;
    cout << "\nVol\n";
    cin >> Vol;
    cout << "\nNumber of Paths\n";
    cin >> NumOfPaths;
    
    rParameter = ParametersConstant(r);
    volParameter = ParametersConstant(Vol);
    
    PayoffCall3 ThePayoffCall(Strike);
    VanillaOption3 TheCall(ThePayoffCall, Expiry);
    
    double price_call = SimpleMonteCarlo6(TheCall, Spot, rParameter, volParameter, NumOfPaths);
    
    PayoffPut3 ThePayoffPut(Strike);
    VanillaOption3 ThePut(ThePayoffPut, Expiry);
    
    double price_put = SimpleMonteCarlo6(ThePut, Spot, rParameter, volParameter, NumOfPaths);
    
    cout << "\nThe Call price\n";
    cout << price_call;
    
    cout << "\nThe Put price\n";
    cout << price_put;
    
    double tmp;
    cin >> tmp;
    
    return 0;
}

