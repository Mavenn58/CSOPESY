#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

struct Process {
    int gpuId;
    int graphicsId;
    int computeId;
    int pid;
    std::string type;
    std::string name;
    int gpuMemoryUsage;
};

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

void displayProcess(const std::vector<Process>& processes)
{
    std::cout << "\n+----------------------------------------------------------------------------------------------------+\n";
    std::cout << "| Processes:                                                                                         |\n";
    std::cout << "|  GPU   GI     CI       PID   Type   Process name                                        GPU Memory |\n";
    std::cout << "|        ID     ID                                                                        Usage      |\n";
    std::cout << "|----------------------------------------------------------------------------------------------------|\n";

    for (const auto& process : processes) {
        std::cout << "| " << std::setw(4) << process.gpuId << " " << std::setw(4) << process.graphicsId << " " << std::setw(4) << process.computeId << " " << std::setw(6) << process.pid << " " << std::setw(5) << process.type << " " << std::setw(40) << process.name << " " << std::setw(10) << process.gpuMemoryUsage << "MiB |\n";
    }

    std::cout << "+====================================================================================================+\n";
    std::cout << "\n";
}

int main()
{
    system("cls");
    dateTime();
    gpuSummary();

    std::vector<Process> processes = {
        {0, 1, 2, 1234, "System", "System Process", 100},
        {0, 3, 4, 5678, "User", "User Process", 200},
        {0, 5, 6, 9012, "System", "System Process 2", 300}
    };

    displayProcess(processes);
    return 0; 
}