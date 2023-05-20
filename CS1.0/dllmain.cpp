// dllmain.cpp : Defines the entry point for the DLL application.
#include "main.h"

cl_clientfunc_t* g_pClient = NULL;
cl_clientfunc_t g_Client;
cl_enginefunc_t* g_pEngine = NULL;
cl_enginefunc_t g_Engine;

bool bDataCompare(const BYTE* pData, const BYTE* bMask, char* szMask)
{
    for (; *szMask; ++szMask, ++pData, ++bMask)
    {
        if (*szMask == 'x' && *pData != *bMask)
        {
            return false;
        }
    }
    return (*szMask) == NULL;
}

DWORD dwFindPattern(DWORD dwAddress, DWORD dwSize, BYTE* pbMask, char* szMask)
{
    for (DWORD i = NULL; i < dwSize; i++)
    {
        if (bDataCompare((BYTE*)(dwAddress + i), pbMask, szMask))
        {
            return (DWORD)(dwAddress + i);
        }
    }
    return 0;
}

void Thread(void)
{
    while (true)
    {
        if (g_pClient == NULL && GetModuleHandle("hw.dll"))
        {
            DWORD dwClient = dwFindPattern((DWORD)GetModuleHandle("hw.dll"), 0x0122A000, (BYTE*)"\x8B\x44\x24\x04\x6A\x00\x68\x00\x00\x00\x00\x68", "xxxxxxx????x");
            if (dwClient != NULL)
            {
                g_pClient = (cl_clientfunc_t*)*(DWORD*)(dwClient + 0x7);
                if (g_pClient->Initialize != NULL)
                {
                    HookClient();
                }
                else { g_pClient = NULL; }
            }
        }
        if (g_pEngine == NULL && GetModuleHandle("client.dll"))
        {
            DWORD dwEngine = *(DWORD*)((DWORD)GetProcAddress(GetModuleHandle("client.dll"), "Initialize") + 0x1C);
            if (dwEngine != NULL)
            {
                g_pEngine = (cl_enginefunc_t*)(dwEngine);
                if (g_pEngine->pfnSPR_Load != NULL)
                {
                    HookEngine();
                }
                else { g_pEngine = NULL; }
            }
        }
        Sleep(50);
    }

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Thread, NULL, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
