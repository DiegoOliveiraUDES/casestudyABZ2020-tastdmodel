#include "helper.h"
#include <chrono>
#include <ctime>
#include <Windows.h>
#include <psapi.h>  // For memory usage information
enum KleeneState
{
  KLEENE_NOTSTARTED,
  KLEENE_STARTED
};
enum AutState
{
  S0,
  S1,
  S2
};
struct TState_B
{
  AutState  autState;

};
struct TState_A
{
  KleeneState  kleeneState;
  TState_B  ts_B;

};
const std::vector<AutState>  shallow_final_B = {S2};
TState_A  ts_A;

int    a()
{
	int  exec = 0;
	if(((std::find(shallow_final_B.begin(), shallow_final_B.end(), ts_A.ts_B.autState) !=shallow_final_B.end() || KLEENE_NOTSTARTED == ts_A.kleeneState) && S0 == S0))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		ts_A.ts_B.autState = S0;
		if(ts_A.ts_B.autState == S0)
		{
			ts_A.ts_B.autState = S1;
			exec = 1;
		
		}
	
	}else if(ts_A.ts_B.autState == S0)
	{
		ts_A.kleeneState = KLEENE_STARTED;
		if(ts_A.ts_B.autState == S0)
		{
			ts_A.ts_B.autState = S1;
			exec = 1;
		
		}
	
	}
	return exec;

}

int    b()
{
	int  exec = 0;
	if(((std::find(shallow_final_B.begin(), shallow_final_B.end(), ts_A.ts_B.autState) !=shallow_final_B.end() || KLEENE_NOTSTARTED == ts_A.kleeneState) && S0 == S1))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		ts_A.ts_B.autState = S0;
		if(ts_A.ts_B.autState == S1)
		{
			ts_A.ts_B.autState = S1;
			exec = 1;
		
		}
	
	}else if(ts_A.ts_B.autState == S1)
	{
		ts_A.kleeneState = KLEENE_STARTED;
		if(ts_A.ts_B.autState == S1)
		{
			ts_A.ts_B.autState = S1;
			exec = 1;
		
		}
	
	}
	return exec;

}

int    c()
{
	int  exec = 0;
	if(((std::find(shallow_final_B.begin(), shallow_final_B.end(), ts_A.ts_B.autState) !=shallow_final_B.end() || KLEENE_NOTSTARTED == ts_A.kleeneState) && S0 == S1))
	{
		ts_A.kleeneState = KLEENE_STARTED;
		ts_A.ts_B.autState = S0;
		if(ts_A.ts_B.autState == S1)
		{
			ts_A.ts_B.autState = S2;
			exec = 1;
		
		}
	
	}else if(ts_A.ts_B.autState == S1)
	{
		ts_A.kleeneState = KLEENE_STARTED;
		if(ts_A.ts_B.autState == S1)
		{
			ts_A.ts_B.autState = S2;
			exec = 1;
		
		}
	
	}
	return exec;

}
int main(int argc, char** argv)
{
	IO::configInputStream(argc, argv);
	ts_A.kleeneState = KLEENE_NOTSTARTED;
	ts_A.ts_B.autState = S0;
	std::ofstream outputFile("output.csv");
    PROCESS_MEMORY_COUNTERS startMemCounters, endMemCounters;
	while (1)
	{
		Event  _evt = IO::read_event(argc);
		auto start = std::chrono::high_resolution_clock::now();
		GetProcessMemoryInfo(GetCurrentProcess(), &startMemCounters, sizeof(startMemCounters));
		if(_evt.label.empty())
		{
			break;
		
		}else if(_evt.label.compare("a") == 0)
		{
			if(a())
			{
				auto end = std::chrono::high_resolution_clock::now();
				auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
				// Print the results to the output file
                GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
                // Calculate RAM memory usage
                SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
				outputFile << _evt.label << "," << time1 << "," << memUsage << std::endl;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("b") == 0)
		{
			if(b())
			{
				auto end = std::chrono::high_resolution_clock::now();
				auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
				// Print the results to the output file
                GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
                // Calculate RAM memory usage
                SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
				outputFile << _evt.label << "," << time1 << "," << memUsage << std::endl;
			}else 
			{
				ERROR_2;
			
			}
		
		}else if(_evt.label.compare("c") == 0)
		{
			if(c())
			{
				auto end = std::chrono::high_resolution_clock::now();
				auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
				// Print the results to the output file
                GetProcessMemoryInfo(GetCurrentProcess(), &endMemCounters, sizeof(endMemCounters));
                // Calculate RAM memory usage
                SIZE_T memUsage = endMemCounters.WorkingSetSize - startMemCounters.WorkingSetSize;
				outputFile << _evt.label << "," << time1 << "," << memUsage << std::endl;
			}else 
			{
				ERROR_2;
			
			}
		
		}else 
		{
			ERROR_1;
		
		}
	
	}
	return 0;

}
