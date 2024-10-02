#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

void gpuSummary()
{
    std::cout << "\n+----------------------------------------------------------------------------------------------------+\n";
    std::cout <<"| NVIDIA-SMI 551.86                 DRIVER VERSION: 551.86             CUDA VERSION: 12.4            |\n";
    std::cout <<"|--------------------------------+---------------------------+---------------------------------------|\n";
    std::cout <<"| GPU   Name                    TCC/WDM       | Bus-Id              Disp.A | Volatile  Uncorr.   ECC |\n";
    std::cout <<"| FAN   Temp     Perf           Pwr:Usage/Cap |               Memory-Usage | GPU-Util  Compute   M.  |\n";
    std::cout <<"|                                             |                            |               MIG   M.  |\n";
    std::cout <<"+================================+===========================+=======================================+\n";
    std::cout <<"|   0   NVIDIA   GeForce GTX 1080       WDDM  |   00000000:26:00.0      On |                     N/A |\n";
    std::cout <<"| 28%    37C      P8              11W /  180W |     701MiB /       8192MiB |      0%         Default |\n";
    std::cout <<"|                                             |                            |                     N/A |\n";
    std::cout <<"+----------------------------------------------------------------------------------------------------+";
    std::cout <<"\n";
}

void dateTime()
{
    // Get the timestamp for the current date and time
    time_t timestamp;
    time(&timestamp);
    std::cout << ctime(&timestamp);
}

void displayProcess()
{
    std::cout << "\n+----------------------------------------------------------------------------------------------------+\n";
    std::cout <<"| Processes:                                                                                         |\n";
    std::cout <<"|  GPU   GI     CI       PID   Type   Process name                                        GPU Memory |\n";
    std::cout <<"|        ID     ID                                                                        Usage      |\n";
    std::cout <<"|----------------------------------------------------------------------------------------------------|\n";
    std::cout <<"|                                                                                                    |\n";
    std::cout <<"|                                                                                                    |\n";
    std::cout <<"|                                                                                                    |\n";
    std::cout <<"+====================================================================================================+\n";
    std::cout <<"\n";
}

int main()
{
    system("cls");
    dateTime();
    gpuSummary();
    displayProcess();
    return 0; 
}