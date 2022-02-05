#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>


// To ensure correct resolution of symbols, add Psapi.lib to TARGETLIBS
// and compile with -DPSAPI_VERSION=1

void PrintProcessNameAndID(DWORD processID, std::string inputProcName)
{
	TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	// Get a handle to the process.
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

	// Get the process name.
	if (NULL != hProcess) {
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
			GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
		}
	}

	// convert to std::string
	std::wstring tmpS(szProcessName);
	std::string procName(tmpS.begin(), tmpS.end());

	// convert string to lowercase
	for (auto& c : procName) { c = std::tolower(c); }
	for (auto& c : inputProcName) { c = std::tolower(c); }
	
	// find substring
	if (procName.find(inputProcName) != std::string::npos) {
		_tprintf(TEXT("PID: %u \t %s\n"), processID, szProcessName);
	}

	// Release the handle to the process.
	CloseHandle(hProcess);
}


int main(int argc, char const* argv[])
{
	if (argc <= 1) {
		printf("Usage: %s <procName>\n", argv[0]);
		return 1;
	}

	// Get the list of process identifiers.
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		return 1;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	// Print the name and process identifier for each process.
	std::string inputProcName(argv[1]);
	for (int i = 0; i < cProcesses; i++) {
		if (aProcesses[i] != 0) {
			PrintProcessNameAndID(aProcesses[i], inputProcName);
		}
	}

	return 0;
}

/*
** - Ref: https://docs.microsoft.com/en-us/windows/win32/psapi/enumerating-all-processes
*/