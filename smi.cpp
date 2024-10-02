#include <stdio.h>
#include <vector>
#include <iostream>
#include <ctime>

void gpuSummary()
{
    std::cout << "\n+-----------------------------------------------------------------------------------+\n";
    std::cout <<"| NVIDIA-SMI 551.86           DRIVER VERSION: 551.86       CUDA VERSION: 12.4       |\n";
    std::cout <<"|--------------------------------+---------------------------+----------------------|\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"+================================+===========================+======================+\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"|                                |                           |                      |\n";
    std::cout <<"+-----------------------------------------------------------------------------------+";
    std::cout <<"\n";
}

void dateTime()
{
    // Get the timestamp for the current date and time
    time_t timestamp;
    time(&timestamp);
    std::cout << ctime(&timestamp);
}

int main()
{
    system("cls");
    dateTime();
    gpuSummary();
    return 0; 
}