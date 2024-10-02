#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

struct Process {
    int gpuId;
    std::string graphicsId;
    std::string computeId;
    int pid;
    std::string type;
    std::string name;
    std::string gpuMemoryUsage;
};

void gpuSummary()
{
    std::cout << "\n+------------------------------------------------------------------------------------------+\n";
    std::cout << "| NVIDIA-SMI 551.86             DRIVER VERSION: 551.86             CUDA VERSION: 12.4      |\n";
    std::cout << "|---------------------------------------------+------------------------+-------------------|\n";
    std::cout << "| GPU   Name                 TCC/WDM    | Bus-Id          Disp.A | Volatile  Uncorr.   ECC |\n";
    std::cout << "| FAN   Temp     Perf     Pwr:Usage/Cap |           Memory-Usage | GPU-Util  Compute   M.  |\n";
    std::cout << "|                                       |                        |               MIG   M.  |\n";
    std::cout << "+=======================================+========================+=========================+\n";
    std::cout << "|   0  NVIDIA GeForce GTX 1080     WDDM |   00000000:26:00.0  On |                     N/A |\n";
    std::cout << "| 28%   37C     P8          11W /  180W |     701MiB /   8192MiB |      0%         Default |\n";
    std::cout << "|                                       |                        |                     N/A |\n";
    std::cout << "+---------------------------------------+------------------------+-------------------------+\n";
    std::cout << "\n";
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
    std::cout << "\n+------------------------------------------------------------------------------------------+\n";
    std::cout << "| Processes:                                                                               |\n";
    std::cout << "|  GPU   GI       CI       PID   Type   Process name                            GPU Memory |\n";
    std::cout << "|        ID       ID                                                            Usage      |\n";
    std::cout << "|------------------------------------------------------------------------------------------|\n";

    for (const auto& process : processes) {
        std::string name = process.name;
        std::string gpuMemoryUsage = process.gpuMemoryUsage;

        // Limit the process name to 30 characters
        if (name.length() > 30) {
            name = name.substr(0, 30) + "...";
        }

        // Limit the GPU memory usage to 10 characters
        if (gpuMemoryUsage.length() > 10) {
            gpuMemoryUsage = gpuMemoryUsage.substr(0, 10) + "...";
        }

        std::cout << "|" << std::setw(4) << process.gpuId << " " << std::setw(8) << process.graphicsId << " " << std::setw(8) << process.computeId << " " << std::setw(6) << process.pid << " " << std::setw(5) << process.type << "    " << std::setw(40) << std::left << name << " " << std::setw(6) << std::right << gpuMemoryUsage << "    |\n";
    }

    std::cout << "+==========================================================================================+\n";
    std::cout << "\n";
}

int main()
{
    system("cls");
    dateTime();
    gpuSummary();

    std::vector<Process> processes = {
        {0, "N/A", "N/A", 1368, "C+G", "C:\\Program Files\\DataSync\\DataSyncService.exe", "N/A"},
        {0, "N/A", "N/A", 2166, "C+G", "C:\\Program Files\\ImageProcessing\\AdvancedImageProcessingDaemonWithBatchSupport.exe", "N/A"},
        {0, "N/A", "N/A", 4244, "C+G", "C:\\Program Files\\NetworkMonitor\\NetworkMonitorAgent.exe", "N/A"},
        {0, "N/A", "N/A", 5684, "C+G", "C:\\Program Files\\UserAuth\\UserAuthManager.exe", "N/A"},
        {0, "N/A", "N/A", 6676, "C+G", "C:\\Program Files\\SystemCleanup\\ThoroughSystemCleanupTaskWithSchedulingOptions.exe", "N/A"},
    };

    displayProcess(processes);
    return 0; 
}