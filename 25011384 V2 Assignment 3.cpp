////////////////////////////////////////////////////////////////////////
//              25011384 Jake Isaac Harvey Assignment 3               //
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>

float voltAverage, voltReadArr[6], voltAverageTenPercent, voltAverageFifteenPercent, problemVoltageTenPercent[6], problemVoltageFifteenPercent[6], voltDifference, temp, tempHour;
int i, problemOutputNum, problemHourTenPercent[6], problemHourFifteenPercent[6], totalProblemTenPercent, totalProblemFifteenPercent, nextProblemHour;
bool problemEncounteredBool, problemTenPercentBool, problemFifteenPercentBool;

int main()  {

    problemEncounteredBool = false;
    problemTenPercentBool = false;
    problemFifteenPercentBool = false;
    voltAverage = 0;
    totalProblemTenPercent = 0;
    totalProblemFifteenPercent = 0;
    problemOutputNum = 1;

    ////////////////////////////////////////////////////////////////////////
    //          Read in voltage into the array and data validate          //
    ////////////////////////////////////////////////////////////////////////
    
    for (i = 0; i < 6; i++)  {
        std::cout << "Please enter the voltage at hour " << i + 1 << ": ";
        std::cin >> voltReadArr[i];
        while (voltReadArr[i] < 0)  {   // Entry validation - voltage must be greater than 0, no negative values.
            std::cout << "\nERROR: Voltage must be positive" << "\nPlease enter the voltage at hour " << i + 1 << ": ";
            std::cin >> voltReadArr[i];
        }
        voltAverage = voltAverage + voltReadArr[i];
    }

    ////////////////////////////////////////////////////////////////////////
    //      Calculate the average, 10% difference and 15% difference      //
    ////////////////////////////////////////////////////////////////////////

    voltAverage = voltAverage / 6;
    voltAverageTenPercent = voltAverage / 10;
    voltAverageFifteenPercent = voltAverage * 0.15;

    ////////////////////////////////////////////////////////////////////////
    //                 Check voltages for 10% difference                  //
    ////////////////////////////////////////////////////////////////////////

    for (i = 0; i < 6; i++)  {
        if ((voltReadArr[i] > (voltAverage + voltAverageTenPercent)) || (voltReadArr[i] < (voltAverage - voltAverageTenPercent)))  { // Checks through the voltages to see if they
            temp = voltReadArr[i];                                                                                                   // are bigger than the average + 10% or smaller
            tempHour = i + 1;                                                                                                        // than the average - 10%
            problemHourTenPercent[i] = tempHour;                                                                                            
            problemVoltageTenPercent[i] = temp;                                                                            
            problemEncounteredBool = true;
            problemTenPercentBool = true;
            totalProblemTenPercent++;
        } 
    }
    
    ////////////////////////////////////////////////////////////////////////
    //                 Check voltages for 15% difference                  //
    ////////////////////////////////////////////////////////////////////////

    for (i = 1; i < 6; i++)  {
        if (voltReadArr[i - 1] > (voltReadArr[i] + voltAverageFifteenPercent))  {
            problemEncounteredBool = true;
            problemFifteenPercentBool = true;
            totalProblemFifteenPercent++;
            problemVoltageFifteenPercent[i] = voltReadArr[i - 1] - voltReadArr[i]; 
            problemHourFifteenPercent[i] = i;
        }
    }
   
    ////////////////////////////////////////////////////////////////////////
    //           Final cout statement if there is a problem               //
    ////////////////////////////////////////////////////////////////////////

    if (problemEncounteredBool == true)  {
        std::cout << "\nThe average voltage was ";
        std::cout << std::setprecision(1) << std::fixed << voltAverage << " volts.";
        std::cout << "\n10% = ";
        std::cout << std::setprecision(1) << std::fixed << voltAverageTenPercent << " volts.";
        std::cout << "\n15% = ";
        std::cout << std::setprecision(1) << std::fixed << voltAverageFifteenPercent << " volts.";
        std::cout << std::endl << "\nThe following problems occured:" << std::endl;

        /* Above is for displaying the average, 10% and 15% differences 
           Below is for displaying the problems encountered             */

        if (problemTenPercentBool == true)  {
            for (i = 0; i < 6; i++)  {
                if (problemVoltageTenPercent[i] - voltAverage < 0)  {
                    voltDifference = voltAverage - problemVoltageTenPercent[i];
                } else {
                    voltDifference = problemVoltageTenPercent[i] - voltAverage;
                }
                if ((problemHourTenPercent[i] == 0) || (problemVoltageTenPercent[i] == 0))  {
                    continue;
                }
                std::cout << std::endl << problemOutputNum << ". Voltage at hour " << problemHourTenPercent[i] << " was " << problemVoltageTenPercent[i] << " volts (difference of " << voltDifference << " volts).";
                problemOutputNum++;
            }
        }

        if (problemFifteenPercentBool == true)  {
            for (i = 0; i < 6; i++)  {
                if ((problemHourFifteenPercent[i] == 0) || (problemVoltageFifteenPercent[i] == 0))  {
                    continue;
                }
                nextProblemHour = problemHourFifteenPercent[i] + 1;
                std::cout << std::endl << problemOutputNum <<". Voltage change from hour " << problemHourFifteenPercent[i] << " to hour " << nextProblemHour << " was " << problemVoltageFifteenPercent[i] << " volts.";
                problemOutputNum++;
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////
    //           Final cout statement if there is no problem              //
    ////////////////////////////////////////////////////////////////////////

    if (problemEncounteredBool == false)  {
        std::cout << "\nThe average voltage was ";
        std::cout << std::setprecision(1) << std::fixed << voltAverage << " volts.";
        std::cout << "\n10% = ";
        std::cout << std::setprecision(1) << std::fixed << voltAverageTenPercent << " volts.";
        std::cout << "\n15% = ";
        std::cout << std::setprecision(1) << std::fixed << voltAverageFifteenPercent << " volts.";
        std::cout << "\nNo problems were encountered.";
    }
}