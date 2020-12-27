//
//  main.cpp
//  Chapter6_6
//
//  Created by Rong Wang on 2020-12-27.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC8.hpp"
#include "ParkMiller.hpp"
#include "Vanilla3.hpp"
#include "MCStatistics.hpp"
#include "ConvergenceTable.hpp"
#include "AntiThetic.hpp"
#include <iostream>

int main()
{
    double Expiry;
    double Spot;
    double Strike;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nChapter5_4\n";
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
    
    Parameters& rParameter(r);
    Parameters& volParameter(Vol);
    
    PayoffCall3 ThePayoffCall(Expiry);
    VanillaOption3 TheCall(ThePayoffCall, Strike);
    StatisticsMean gatherer_call;
    ConvergenceTable gathererTwo_call(gatherer_call);
    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);
    
    SimpleMonteCarlo8(TheCall, Spot, rParameter, volParameter, NumOfPaths, gathererTwo_call, GenTwo);
    vector<vector<double>> results_call = gathererTwo_call.GetResults_curr();
    
    cout << "\nCall Price Results:\n";
    for (unsigned long i=0; i<results_call.size(); i++)
    {
        for (unsigned long j=0; j<results_call[i].size(); j++)
            cout << results_call[i][j] << " ";
        cout << "\n";
    }
    
    
    PayoffPut3 ThePayoffPut(Expiry);
    VanillaOption3 ThePut(ThePayoffPut, Strike);
    StatisticsMean gatherer_put;
    ConvergenceTable gathererTwo_put(gatherer_put);
    GenTwo.Reset();
    
    SimpleMonteCarlo8(ThePut, Spot, rParameter, volParameter, NumOfPaths, gathererTwo_put, GenTwo);
    vector<vector<double>> results_put = gathererTwo_put.GetResults_curr();
    
    cout << "\nPut Price Results:\n";
    for (unsigned long i=0; i<results_put.size(); i++)
    {
        for (unsigned long j=0; j<results_put[i].size(); j++)
            cout << results_put[i][j] << " ";
        cout << "\n";
    }
    
    double tmp;
    cin >> tmp;
    
    return 0;
}
