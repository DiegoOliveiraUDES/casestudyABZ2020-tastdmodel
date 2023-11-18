#include "helper.h"
#include <chrono>
#include <ctime>
#include "inttypes.h"
#include <Windows.h>
#include <psapi.h>  // For memory usage information

std::time_t  current_time = 0;
enum AutState
{
  S0,
  S1
};
struct TState_D
{
  AutState  autState;

};
struct TState_C
{
  int  z;
  std::map<int, TState_D>  f;

};
struct TState_B
{
  int  y;
  std::map<int, TState_C>  f;

};
struct TState_A
{
  int  x;
  std::map<int, TState_B>  f;

};
const std::vector<int>  T_A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
const std::vector<int>  T_B = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
const std::vector<int>  T_C = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};
TState_A  ts_A;
std::time_t  step_time = 1.0E9;
Timer  last_event_time = 0;

int  forall_Cfinal(int&  z)
{
	int  exec = 0;
	for(auto const& c : ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f)
	{
		z = c.first;
		if(0)
		{
			exec = exec + 1;
		
		}else 
		{
			return 0;
		
		}
	
	}
	if(exec == T_C.size())
	{
		return 1;
	
	}else if(exec < T_C.size())
	{
		if(0)
		{
			return 1;
		
		}
	
	}
	return 0;

}

int  forall_Bfinal(int&  y)
{
	int  exec = 0;
	for(auto const& c : ts_A.f[ts_A.x].f)
	{
		y = c.first;
		if((forall_Cfinal(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z) && 0))
		{
			exec = exec + 1;
		
		}else 
		{
			return 0;
		
		}
	
	}
	if(exec == T_B.size())
	{
		return 1;
	
	}else if(exec < T_B.size())
	{
		if(0)
		{
			return 1;
		
		}
	
	}
	return 0;

}

int  forall_Afinal(int&  x)
{
	int  exec = 0;
	for(auto const& c : ts_A.f)
	{
		x = c.first;
		if((forall_Bfinal(ts_A.f[ts_A.x].y) && (forall_Cfinal(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z) && 0)))
		{
			exec = exec + 1;
		
		}else 
		{
			return 0;
		
		}
	
	}
	if(exec == T_A.size())
	{
		return 1;
	
	}else if(exec < T_A.size())
	{
		if(0)
		{
			return 1;
		
		}
	
	}
	return 0;

}

int  exists_Ce_z(int&  z)
{
	for(int c : T_C)
	{
		z = c;
		if(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f.find(z) !=ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f.end())
		{
			if(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f[ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z].autState == S0)
			{
				return 1;
			
			}
		
		}else 
		{
			ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f[ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z].autState = S0;
			if(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f[ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z].autState == S0)
			{
				return 1;
			
			}
		
		}
	
	}
	return 0;

}

int  exists_Be_y(int&  y, int&  z)
{
	for(int c : T_B)
	{
		y = c;
		if(ts_A.f[ts_A.x].f.find(y) !=ts_A.f[ts_A.x].f.end())
		{
			if(exists_Ce_z(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
			{
				return 1;
			
			}
		
		}else 
		{
			ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f.clear();
			if(exists_Ce_z(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
			{
				return 1;
			
			}
		
		}
	
	}
	return 0;

}

int  exists_Ae_x(int&  x, int&  y, int&  z)
{
	for(int c : T_A)
	{
		x = c;
		if(ts_A.f.find(x) !=ts_A.f.end())
		{
			if(exists_Be_y(ts_A.f[ts_A.x].y, ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
			{
				return 1;
			
			}
		
		}else 
		{
			ts_A.f[ts_A.x].f.clear();
			if(exists_Be_y(ts_A.f[ts_A.x].y, ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
			{
				return 1;
			
			}
		
		}
	
	}
	return 0;

}

int    e()
{
	int  exec = 0;
	if(exists_Ae_x(ts_A.x, ts_A.f[ts_A.x].y, ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
	{
		if(exists_Be_y(ts_A.f[ts_A.x].y, ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
		{
			if(exists_Ce_z(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z))
			{
				if(ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f[ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z].autState == S0)
				{
					ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].f[ts_A.f[ts_A.x].f[ts_A.f[ts_A.x].y].z].autState = S1;
					exec = 1;
				
				}
			
			}
		
		}
	
	}
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}

int    Step()
{
	int  exec = 1;
	current_time = step_time+current_time;
	if(exec == 1)
	{
		last_event_time.reset_clock(current_time);
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	// Initialize performance counters
    FILETIME startProcessorTime, endProcessorTime;
    PROCESS_MEMORY_COUNTERS startMemCounters, endMemCounters;
	IO::configInputStream(argc, argv);
	ts_A.f.clear();
	size_t dotPosition = filename.find_last_of('.');
	std::string nameWithoutExtension = filename.substr(0, dotPosition);
	std::ofstream outputFile(nameWithoutExtension+".csv");
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		auto start = std::chrono::high_resolution_clock::now();
		
		// GetProcessTimes(GetCurrentProcess(), &startProcessorTime, nullptr, nullptr, nullptr);
        GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));

		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("e") == 0)
		{
			if(e())
			{
				// GetProcessTimes(GetCurrentProcess(), &endProcessorTime, nullptr, nullptr, nullptr);
				
				auto end = std::chrono::high_resolution_clock::now();
				auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 

				// Calculate CPU usage
				// ULARGE_INTEGER startProcessorTimeUL;
				// startProcessorTimeUL.LowPart = startProcessorTime.dwLowDateTime;
				// startProcessorTimeUL.HighPart = startProcessorTime.dwHighDateTime;

				// ULARGE_INTEGER endProcessorTimeUL;
				// endProcessorTimeUL.LowPart = endProcessorTime.dwLowDateTime;
				// endProcessorTimeUL.HighPart = endProcessorTime.dwHighDateTime;

				// ULONGLONG elapsedTime = (endProcessorTimeUL.QuadPart - startProcessorTimeUL.QuadPart);
                // double cpuUsage = static_cast<double>(elapsedTime) / time1;

				// Print the results to the output file
                GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
                // Calculate RAM memory usage
                SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
				outputFile << _evt.label << "," << time1 << "," << memUsage << std::endl;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("advanceTo") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceToV1(current_time, step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					auto start = std::chrono::high_resolution_clock::now();
					// GetProcessTimes(GetCurrentProcess(), &startProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));
					Step();
					GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
					// GetProcessTimes(GetCurrentProcess(), &endProcessorTime, nullptr, nullptr, nullptr);
					
					auto end = std::chrono::high_resolution_clock::now();
					auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
					// Calculate CPU usage
					// ULARGE_INTEGER startProcessorTimeUL;
					// startProcessorTimeUL.LowPart = startProcessorTime.dwLowDateTime;
					// startProcessorTimeUL.HighPart = startProcessorTime.dwHighDateTime;

					// ULARGE_INTEGER endProcessorTimeUL;
					// endProcessorTimeUL.LowPart = endProcessorTime.dwLowDateTime;
					// endProcessorTimeUL.HighPart = endProcessorTime.dwHighDateTime;

					// ULONGLONG elapsedTime = (endProcessorTimeUL.QuadPart - startProcessorTimeUL.QuadPart);
					// double cpuUsage = static_cast<double>(elapsedTime) / /* convert to nanoseconds */ 1e9;

					// outputFile << ",, Step ," << time1 << "," << cpuUsage << "," << memUsage << std::endl;
					
					// Calculate RAM memory usage
					SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
					outputFile << ",, Step ," << time1 << "," << memUsage << std::endl;
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceToV2(current_time, step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					auto start = std::chrono::high_resolution_clock::now();
					// GetProcessTimes(GetCurrentProcess(), &startProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));

					Step();
					
					// GetProcessTimes(GetCurrentProcess(), &endProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
					auto end = std::chrono::high_resolution_clock::now();
					auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
					// Calculate CPU usage
					// ULARGE_INTEGER startProcessorTimeUL;
					// startProcessorTimeUL.LowPart = startProcessorTime.dwLowDateTime;
					// startProcessorTimeUL.HighPart = startProcessorTime.dwHighDateTime;

					// ULARGE_INTEGER endProcessorTimeUL;
					// endProcessorTimeUL.LowPart = endProcessorTime.dwLowDateTime;
					// endProcessorTimeUL.HighPart = endProcessorTime.dwHighDateTime;

					// ULONGLONG elapsedTime = (endProcessorTimeUL.QuadPart - startProcessorTimeUL.QuadPart);
					// double cpuUsage = static_cast<double>(elapsedTime) / /* convert to nanoseconds */ 1e9;

					// Calculate RAM memory usage
					SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
					
					// outputFile << ",, Step ," << time1 << "," << cpuUsage << "," << memUsage << std::endl;
					outputFile << ",, Step ," << time1 << "," << memUsage << std::endl;
					numberOfSteps--;
				}
			}
		}else if(_evt.label.compare("advanceOf") == 0){
			if(Types::get_str(_evt.params[0]).find(":") != std::string::npos){
				long int numberOfSteps = advanceOfV1(step_time, Types::get_str(_evt.params[0]));
				while (numberOfSteps > 0)
				{
					auto start = std::chrono::high_resolution_clock::now();
					// GetProcessTimes(GetCurrentProcess(), &startProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));

					Step();
					
					// GetProcessTimes(GetCurrentProcess(), &endProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
					auto end = std::chrono::high_resolution_clock::now();
					auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
					// Calculate CPU usage
					// ULARGE_INTEGER startProcessorTimeUL;
					// startProcessorTimeUL.LowPart = startProcessorTime.dwLowDateTime;
					// startProcessorTimeUL.HighPart = startProcessorTime.dwHighDateTime;

					// ULARGE_INTEGER endProcessorTimeUL;
					// endProcessorTimeUL.LowPart = endProcessorTime.dwLowDateTime;
					// endProcessorTimeUL.HighPart = endProcessorTime.dwHighDateTime;

					// ULONGLONG elapsedTime = (endProcessorTimeUL.QuadPart - startProcessorTimeUL.QuadPart);
					// double cpuUsage = static_cast<double>(elapsedTime) / /* convert to nanoseconds */ 1e9;

					// Calculate RAM memory usage
					SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
					
					// outputFile << ",, Step ," << time1 << "," << cpuUsage << "," << memUsage << std::endl;
					outputFile << ",, Step ," << time1 << "," << memUsage << std::endl;
					numberOfSteps--;
				}
			}
			else{
				long int numberOfSteps = advanceOfV2(step_time, Types::get_str(_evt.params[0]), (std::time_t) Types::get_double(_evt.params[1]));
				while (numberOfSteps > 0)
				{
					auto start = std::chrono::high_resolution_clock::now();
					// GetProcessTimes(GetCurrentProcess(), &startProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));

					Step();
					
					// GetProcessTimes(GetCurrentProcess(), &endProcessorTime, nullptr, nullptr, nullptr);
					GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
					auto end = std::chrono::high_resolution_clock::now();
					auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
					// Calculate CPU usage
					// ULARGE_INTEGER startProcessorTimeUL;
					// startProcessorTimeUL.LowPart = startProcessorTime.dwLowDateTime;
					// startProcessorTimeUL.HighPart = startProcessorTime.dwHighDateTime;

					// ULARGE_INTEGER endProcessorTimeUL;
					// endProcessorTimeUL.LowPart = endProcessorTime.dwLowDateTime;
					// endProcessorTimeUL.HighPart = endProcessorTime.dwHighDateTime;

					// ULONGLONG elapsedTime = (endProcessorTimeUL.QuadPart - startProcessorTimeUL.QuadPart);
					// double cpuUsage = static_cast<double>(elapsedTime) / /* convert to nanoseconds */ 1e9;

					// Calculate RAM memory usage
					SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
					
					// outputFile << ",, Step ," << time1 << "," << cpuUsage << "," << memUsage << std::endl;
					outputFile << ",, Step ," << time1 << "," << memUsage << std::endl;
					numberOfSteps--;
				}
			}	
		}
		else 
		{
			ERROR_1;
		
		}
	
	}

	outputFile.close();
	return 0;

}
