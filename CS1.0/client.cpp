#include "main.h"

static bool Bunnyhop = false;

int HUD_AddEntity(int type, struct cl_entity_s* ent, const char* modelname)
{
	int iRet = g_Client.HUD_AddEntity(type, ent, modelname);
	return iRet;
}

void HUD_PlayerMove(struct playermove_s* ppmove, int server)
{
	g_Client.HUD_PlayerMove(ppmove, server);
}

void SPR_Set(HSPRITE hPic, int r, int g, int b)
{
	r = 255; g = 0; b = 0;
	return g_Engine.pfnSPR_Set(hPic, r, g, b);
}

void HUD_Frame(double time)
{
	static bool b = true;
	if (b && g_pEngine != NULL)
	{
		g_pEngine->pfnClientCmd("version");
		b = false;
	}
	g_Client.HUD_Frame(time);
}

void CL_CreateMove(float frametime, struct usercmd_s* cmd, int active)
{
	g_Client.CL_CreateMove(frametime, cmd, active);
	if (cmd->buttons & IN_JUMP)
	{
		if (Bunnyhop && K_SPACE)
		{
			cmd->buttons &= ~IN_JUMP;
			Bunnyhop = false;
		}
		else
		{
			Bunnyhop = true;
		}
	}
}

void HookEngine(void)
{
	memcpy(&g_Engine, (LPVOID)g_pEngine, sizeof(cl_enginefunc_t));
	g_pEngine->pfnSPR_Set = SPR_Set;
}

void HookClient(void)
{
	memcpy(&g_Client, (LPVOID)g_pClient, sizeof(cl_clientfunc_t));
	g_pClient->HUD_Frame = HUD_Frame;
	g_pClient->HUD_AddEntity = HUD_AddEntity;
	g_pClient->HUD_PlayerMove = HUD_PlayerMove;
	g_pClient->CL_CreateMove = CL_CreateMove;
}