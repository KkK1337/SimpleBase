#include <Windows.h>
#include <vector>
#include <string>
#include <time.h>
#include "hlsdk.h"

extern cl_clientfunc_t* g_pClient;
extern cl_clientfunc_t g_Client;
extern cl_enginefunc_t* g_pEngine;
extern cl_enginefunc_t g_Engine;

void HookClient(void);
void HookEngine(void);