//
//  main.cpp
//  Chapter5_3
//
//  Created by Rong Wang on 2020-12-24.
//  Copyright © 2020 RW. All rights reserved.
//

#include "SimpleMC7.hpp"
#include "Vanilla3.hpp"
#include "MCStatistics.hpp"
#include <iostream>
using namespace std;

int main()
{
    double Expiry;
    double Spot;
    double Strike;
    double r, Vol;
    unsigned long NumOfPaths;
    
    cout << "\nChapter5_3\n";
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
    
    ParametersConstant rParameter(r);
    ParametersConstant volParameter(Vol);
    
    PayoffCall3 ThePayoffCall(Strike);
    VanillaOption3 TheCall(ThePayoffCall, Expiry);
    StatisticsMean gatherer_call;
    SimpleMonteCarlo7(TheCall, Spot, rParameter, volParameter, NumOfPaths, gatherer_call);
    vector<vector<double>> results_call = gatherer_call.GetResults_curr();
    
    cout << "\nCall Price Results:\n";
    for (unsigned long i=0; i<results_call.size(); i++)
    {
        for (unsigned long j=0; j<results_call[i].size(); j++)
            cout << results_call[i][j] << " ";
        cout << "\n";
    }
    
    PayoffPut3 ThePayoffPut(Strike);
    VanillaOption3 ThePut(ThePayoffPut, Expiry);
    StatisticsMean gatherer_put;
    SimpleMonteCarlo7(ThePut, Spot, rParameter, volParameter, NumOfPaths, gatherer_put);
    vector<vector<double>> results_put = gatherer_put.GetResults_curr();
    
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
