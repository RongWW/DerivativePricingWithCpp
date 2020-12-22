//
//  main.cpp
//  Chapter4_3
//
//  Created by Rong Wang on 2020-12-18.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC4.hpp"
#include "Vanilla2.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Spot;
    double Strike;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nChapter4_3\n";
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
    
    PayoffCall3 ThePayoffCall(Strike);
    VanillaOption2 TheCall(ThePayoffCall, Expiry);
    
    double price_call = SimpleMonteCarlo4(TheCall, Spot, r, Vol, NumOfPaths);
    
    PayoffPut3 ThePayoffPut(Strike);
    VanillaOption2 ThePut(ThePayoffPut, Expiry);
    
    double price_put = SimpleMonteCarlo4(ThePut, Spot, r, Vol, NumOfPaths);
    
    cout << "\nThe Call price\n";
    cout << price_call;
    
    cout << "\nThe Put price\n";
    cout << price_put;
    
    double tmp;
    cin >> tmp;
    
    return 0;
}

