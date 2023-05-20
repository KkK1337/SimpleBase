// CONSTANTS
#include <cstddef>
#include <rpcndr.h>

#define MAXSTUDIOBONES		128		// total bones actually used

#define IN_ATTACK	(1 << 0)
#define IN_JUMP		(1 << 1)
#define IN_DUCK		(1 << 2)
#define IN_FORWARD	(1 << 3)
#define IN_BACK		(1 << 4)
#define IN_USE		(1 << 5)
#define IN_CANCEL	(1 << 6)
#define IN_LEFT		(1 << 7)
#define IN_RIGHT	(1 << 8)
#define IN_MOVELEFT	(1 << 9)
#define IN_MOVERIGHT (1 << 10)
#define IN_ATTACK2	(1 << 11)
#define IN_RUN      (1 << 12)
#define IN_RELOAD	(1 << 13)
#define IN_ALT1		(1 << 14)
#define IN_SCORE	(1 << 15)   // Used by client.dll for when scoreboard is held down

#define	FL_ONGROUND	(1<<9)

#define MAX_PHYSENTS 			600
#define MAX_MOVEENTS 			64
#define MAX_PHYSINFO_STRING		256
#define MAX_ENT_LEAFS			48
#define HISTORY_MAX 				64
#define MAX_INFO_STRING			256
#define MAX_SCOREBOARDNAME		32
#define MAX_QPATH 				64

#define	K_TAB			9
#define	K_ENTER			13
#define	K_ESCAPE		27
#define	K_SPACE			32
#define	K_BACKSPACE		127
#define	K_UPARROW		128
#define	K_DOWNARROW		129
#define	K_LEFTARROW		130
#define	K_RIGHTARROW	131
#define	K_ALT			132
#define	K_CTRL			133
#define	K_SHIFT			134
#define	K_F1			135
#define	K_F2			136
#define	K_F3			137
#define	K_F4			138
#define	K_F5			139
#define	K_F6			140
#define	K_F7			141
#define	K_F8			142
#define	K_F9			143
#define	K_F10			144
#define	K_F11			145
#define	K_F12			146
#define	K_INS			147
#define	K_DEL			148
#define	K_PGDN			149
#define	K_PGUP			150
#define	K_HOME			151
#define	K_END			152
#define K_KP_HOME		160
#define K_KP_UPARROW	161
#define K_KP_PGUP		162
#define	K_KP_LEFTARROW	163
#define K_KP_5			164
#define K_KP_RIGHTARROW	165
#define K_KP_END		166
#define K_KP_DOWNARROW	167
#define K_KP_PGDN		168
#define	K_KP_ENTER		169
#define K_KP_INS   		170
#define	K_KP_DEL		171
#define K_KP_SLASH		172
#define K_KP_MINUS		173
#define K_KP_PLUS		174
#define K_CAPSLOCK		175
#define K_KP_MUL		176
#define K_WIN			177
#define	K_MOUSE1		241
#define	K_MOUSE2		242
#define	K_MOUSE3		243
#define K_MOUSE4		244
#define K_MOUSE5		245

#define MAX_MAP_HULLS		4
#define	MIPLEVELS			4
#define MAX_MODEL_NAME		64

// TYPE
typedef int	  qboolean;
typedef int	  func_t;
typedef int	  string_t;
typedef float vec_t;
typedef float TransformMatrix[MAXSTUDIOBONES][3][4];

// FUNC
typedef void(__cdecl* StartReading_t)     (DWORD* buf);
typedef void(__cdecl* EndReading_t)       (DWORD* buf);
typedef int(__cdecl* ReadBits_t)         (int count);
typedef void(__cdecl* ReadOrigin_t)       (float* origin);
typedef int(__cdecl* UserMsg_t)          (const char* name, int size, void* buf);
typedef void(__cdecl* Event_t)            (struct event_args_s* args);
typedef void(__cdecl* EngineMsg_t)        (void);
typedef void(__cdecl* StudioEntityLight_t)(struct alight_s* plight);
typedef int(__cdecl* StudioCheckBBox_t)  (void);

// ENUM
typedef enum
{
	mod_brush,
	mod_sprite,
	mod_alias,
	mod_studio
} modtype_t;

typedef enum
{
	ST_SYNC = 0,
	ST_RAND
} synctype_t;

enum
{
	kRenderFxNone = 0,
	kRenderFxPulseSlow,
	kRenderFxPulseFast,
	kRenderFxPulseSlowWide,
	kRenderFxPulseFastWide,
	kRenderFxFadeSlow,
	kRenderFxFadeFast,
	kRenderFxSolidSlow,
	kRenderFxSolidFast,
	kRenderFxStrobeSlow,
	kRenderFxStrobeFast,
	kRenderFxStrobeFaster,
	kRenderFxFlickerSlow,
	kRenderFxFlickerFast,
	kRenderFxNoDissipation,
	kRenderFxDistort,			// Distort/scale/translate flicker
	kRenderFxHologram,			// kRenderFxDistort + distance fade
	kRenderFxDeadPlayer,		// kRenderAmt is the player index
	kRenderFxExplode,			// Scale up really big!
	kRenderFxGlowShell,			// Glowing Shell
	kRenderFxClampMinScale,		// Keep this sprite from getting very small (SPRITES only!)
	kRenderFxLightMultiplier,   //CTM !!!CZERO added to tell the studiorender that the value in iuser2 is a lightmultiplier
};

enum
{
	kRenderNormal,			// src
	kRenderTransColor,		// c*a+dest*(1-a)
	kRenderTransTexture,	// src*a+dest*(1-a)
	kRenderGlow,			// src*a+dest -- No Z buffer checks
	kRenderTransAlpha,		// src*srca+dest*(1-srca)
	kRenderTransAdd,		// src*a+dest
};

typedef enum {
	TRI_FRONT = 0,
	TRI_NONE = 1,
} TRICULLSTYLE;

typedef enum {
	NA_UNUSED,
	NA_LOOPBACK,
	NA_BROADCAST,
	NA_IP,
	NA_IPX,
	NA_BROADCAST_IPX,
} netadrtype_t;

typedef enum {
	t_sound = 0,
	t_skin,
	t_model,
	t_decal,
	t_generic,
	t_eventscript,
	t_world,
} resourcetype_t;

typedef enum {
	MicrophoneVolume = 0,
	OtherSpeakerScale
} VoiceTweakControl;

// STRUCT
typedef struct rect_s {
	int	left, right, top, bottom;
} wrect_t;

typedef struct {
	unsigned r, g, b, a;
} colorVec;

typedef struct {
	vec_t x, y, z;
} vec3_t;

typedef struct {
	int		iSize;
	int		iWidth;
	int		iHeight;
	int		iFlags;
	int		iCharHeight;
	short	charWidths[256];
} SCREENINFO;

typedef struct client_data_s {
	vec3_t	origin;
	vec3_t	viewangles;
	int		iWeaponBits;
	float		fov;
} client_data_t;

typedef struct client_sprite_s {
	char		szName[64];
	char		szSprite[64];
	int		hspr;
	int		iRes;
	wrect_t	rc;
} client_sprite_t;

typedef struct {
	int			effect;
	byte			r1, g1, b1, a1;
	byte			r2, g2, b2, a2;
	float			x;
	float			y;
	float			fadein;
	float			fadeout;
	float			holdtime;
	float			fxtime;
	const char* pName;
	const char* pMessage;
} client_textmessage_t;

typedef struct {
	char* name;
	short 	ping;
	byte 	thisplayer;
	byte 	spectator;
	byte 	packetloss;
	char* model;
	short 	topcolor;
	short 	bottomcolor;
} hud_player_info_t;

typedef struct {
	float		animtime;
	vec3_t	origin;
	vec3_t	angles;
} position_history_t;

typedef struct {
	byte r, g, b;
} color24;

typedef struct cvar_s {
	char* name;
	char* string;
	int		flags;
	float		value;
	struct cvar_s* next;
} cvar_t;

typedef struct link_s {
	struct link_s* prev, * next;
} link_t;

typedef struct {
	byte	mouthopen;
	byte	sndcount;
	int 	sndavg;
} mouth_t;

typedef struct {
	vec3_t	normal;
	float		dist;
} pmplane_t;

typedef struct {
	float		prevanimtime;
	float		sequencetime;
	byte		prevseqblending[2];
	vec3_t	prevorigin;
	vec3_t	prevangles;
	int 		prevsequence;
	float		prevframe;
	byte		prevcontroller[4];
	byte		prevblending[2];
} latchedvars_t;

typedef struct usercmd_s {
	short			lerp_msec;
	byte				msec;
	vec3_t			viewangles;
	float				forwardmove;
	float				sidemove;
	float				upmove;
	byte				lightlevel;
	unsigned short  	buttons;
	byte   			impulse;
	byte				weaponselect;
	int				impact_index;
	vec3_t			impact_position;
} usercmd_t;

typedef struct {
	vec3_t	normal;
	float		dist;
} plane_t;

typedef struct weapon_data_s {
	int	m_iId;
	int	m_iClip;
	float	m_flNextPrimaryAttack;
	float	m_flNextSecondaryAttack;
	float	m_flTimeWeaponIdle;
	int	m_fInReload;
	int	m_fInSpecialReload;
	float	m_flNextReload;
	float	m_flPumpTime;
	float	m_fReloadTime;
	float	m_fAimedDamage;
	float	m_fNextAimBonus;
	int	m_fInZoom;
	int	m_iWeaponState;
	int	iuser1;
	int	iuser2;
	int	iuser3;
	int	iuser4;
	float	fuser1;
	float	fuser2;
	float	fuser3;
	float	fuser4;
} weapon_data_t;

typedef struct screenfade_s {
	float		fadeSpeed;
	float		fadeEnd;
	float		fadeTotalEnd;
	float		fadeReset;
	byte		fader, fadeg, fadeb, fadealpha;
	int		fadeFlags;
} screenfade_t;

typedef struct kbutton_s {
	int		down[2];		// key nums holding it down
	int		state;			// low bit is down state
} kbutton_t;

typedef struct con_nprint_s {
	int	index;
	float	time_to_live;
	float	color[3];
} con_nprint_t;

typedef struct event_args_s {
	int	flags;
	int	entindex;
	float	origin[3];
	float	angles[3];
	float	velocity[3];
	int	ducking;
	float	fparam1;
	float	fparam2;
	int	iparam1;
	int	iparam2;
	int	bparam1;
	int	bparam2;
} event_args_t;

typedef struct movevars_s {
	float		gravity;
	float		stopspeed;
	float		maxspeed;
	float		spectatormaxspeed;
	float		accelerate;
	float		airaccelerate;
	float		wateraccelerate;
	float		friction;
	float   	edgefriction;
	float		waterfriction;
	float		entgravity;
	float   	bounce;
	float   	stepsize;
	float  	maxvelocity;
	float		zmax;
	float		waveHeight;
	qboolean footsteps;
	char		skyName[32];
	float		rollangle;
	float		rollspeed;
	float		skycolor_r;
	float		skycolor_g;
	float		skycolor_b;
	float		skyvec_x;
	float		skyvec_y;
	float		skyvec_z;
} movevars_t;

typedef struct alight_s {
	int		ambientlight;
	int		shadelight;
	vec3_t	color;
	float* plightvec;
} alight_t;

typedef struct mplane_s {
	vec3_t	normal;
	float		dist;
	byte		type;
	byte		signbits;
	byte		pad[2];
} mplane_t;

typedef struct mstudioevent_s {
	int 	frame;
	int	event;
	int	type;
	char	options[64];
} mstudioevent_t;

typedef struct demo_api_s {
	int(*IsRecording)	(void);
	int(*IsPlayingback)	(void);
	int(*IsTimeDemo)	(void);
	void(*WriteBuffer)	(int size, unsigned char* buffer);
} demo_api_t;

typedef struct cache_user_s {
	void* data;
} cache_user_t;




// структуры Возможны "пересечения"

typedef struct triangleapi_s {
	int	version;
	void(*RenderMode)	(int mode);
	void(*Begin)			(int primitiveCode);
	void(*End) 			(void);
	void(*Color4f)		(float r, float g, float b, float a);
	void(*Color4ub) 		(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void(*TexCoord2f) 	(float u, float v);
	void(*Vertex3fv)		(float* worldPnt);
	void(*Vertex3f) 		(float x, float y, float z);
	void(*Brightness)		(float brightness);
	void(*CullFace) 		(TRICULLSTYLE style);
	int(*SpriteTexture) 	(struct model_s* pSpriteModel, int frame);
	int(*WorldToScreen) 	(float* world, float* screen);
} triangleapi_t;

typedef struct entity_state_s {
	int 		entityType;
	int 		number;
	float		msg_time;
	int 		messagenum;
	vec3_t	origin;
	vec3_t	angles;
	int 		modelindex;
	int 		sequence;
	float		frame;
	int 		colormap;
	short	skin;
	short	solid;
	int 		effects;
	float		scale;
	byte		eflags;
	int 		rendermode;
	int 		renderamt;
	color24	rendercolor;
	int 		renderfx;
	int 		movetype;
	float		animtime;
	float		framerate;
	int 		body;
	byte		controller[4];
	byte		blending[4];
	vec3_t	velocity;
	vec3_t	mins;
	vec3_t	maxs;
	int 		aiment;
	int 		owner;
	float		friction;
	float		gravity;
	int 		team;
	int 		playerclass;
	int 		health;
	qboolean	spectator;
	int         	weaponmodel;
	int 		gaitsequence;
	vec3_t	basevelocity;
	int 		usehull;
	int 		oldbuttons;
	int 		onground;
	int 		iStepLeft;
	float		flFallVelocity;
	float		fov;
	int 		weaponanim;
	vec3_t	startpos;
	vec3_t	endpos;
	float		impacttime;
	float		starttime;
	int 		iuser1;
	int 		iuser2;
	int 		iuser3;
	int 		iuser4;
	float		fuser1;
	float		fuser2;
	float		fuser3;
	float		fuser4;
	vec3_t	vuser1;
	vec3_t	vuser2;
	vec3_t	vuser3;
	vec3_t	vuser4;
} entity_state_t;

typedef struct edict_s edict_t; // передопределение by kaktyz92

typedef struct entvars_s {
	string_t	classname;
	string_t	globalname;
	vec3_t	origin;
	vec3_t	oldorigin;
	vec3_t	velocity;
	vec3_t	basevelocity;
	vec3_t     clbasevelocity;
	vec3_t	movedir;
	vec3_t	angles;
	vec3_t	avelocity;
	vec3_t	punchangle;
	vec3_t	v_angle;
	vec3_t	endpos;
	vec3_t	startpos;
	float		impacttime;
	float		starttime;
	int 		fixangle;
	float		idealpitch;
	float		pitch_speed;
	float		ideal_yaw;
	float		yaw_speed;
	int 		modelindex;
	string_t	model;
	int 		viewmodel;
	int 		weaponmodel;
	vec3_t	absmin;
	vec3_t	absmax;
	vec3_t	mins;
	vec3_t	maxs;
	vec3_t	size;
	float		ltime;
	float		nextthink;
	int 		movetype;
	int 		solid;
	int 		skin;
	int 		body;
	int 		effects;
	float		gravity;
	float		friction;
	int 		light_level;
	int 		sequence;
	int 		gaitsequence;
	float		frame;
	float		animtime;
	float		framerate;
	byte		controller[4];
	byte		blending[2];
	float		scale;
	int 		rendermode;
	float		renderamt;
	vec3_t	rendercolor;
	int 		renderfx;
	float		health;
	float		frags;
	int 		weapons;
	float		takedamage;
	int 		deadflag;
	vec3_t	view_ofs;
	int 		button;
	int 		impulse;
	edict_t* chain;
	edict_t* dmg_inflictor;
	edict_t* enemy;
	edict_t* aiment;
	edict_t* owner;
	edict_t* groundentity;
	int 		spawnflags;
	int 		flags;
	int 		colormap;
	int 		team;
	float		max_health;
	float		teleport_time;
	float		armortype;
	float		armorvalue;
	int 		waterlevel;
	int 		watertype;
	string_t	target;
	string_t	targetname;
	string_t	netname;
	string_t	message;
	float		dmg_take;
	float		dmg_save;
	float		dmg;
	float		dmgtime;
	string_t	noise;
	string_t	noise1;
	string_t	noise2;
	string_t	noise3;
	float		speed;
	float		air_finished;
	float		pain_finished;
	float		radsuit_finished;
	edict_t* pContainingEntity;
	int 		playerclass;
	float		maxspeed;
	float		fov;
	int 		weaponanim;
	int 		pushmsec;
	int 		bInDuck;
	int 		flTimeStepSound;
	int 		flSwimTime;
	int 		flDuckTime;
	int 		iStepLeft;
	float		flFallVelocity;
	int 		gamestate;
	int 		oldbuttons;
	int 		groupinfo;
	int 		iuser1;
	int 		iuser2;
	int 		iuser3;
	int 		iuser4;
	float		fuser1;
	float		fuser2;
	float		fuser3;
	float		fuser4;
	vec3_t	vuser1;
	vec3_t	vuser2;
	vec3_t	vuser3;
	vec3_t	vuser4;
	edict_t* euser1;
	edict_t* euser2;
	edict_t* euser3;
	edict_t* euser4;
} entvars_t;

typedef struct edict_s {
	qboolean	free;
	int 		serialnumber;
	link_t	area;
	int 		headnode;
	int 		num_leafs;
	short	leafnums[MAX_ENT_LEAFS];
	float		freetime;
	void* pvPrivateData;
	entvars_t	v;
} edict_t;

typedef struct {
	qboolean	allsolid;
	qboolean	startsolid;
	qboolean	inopen, inwater;
	float		fraction;
	vec3_t	endpos;
	plane_t	plane;
	edict_t* ent;
	int		hitgroup;
} trace_t;

typedef struct pmtrace_s {
	qboolean		allsolid;
	qboolean		startsolid;
	qboolean		inopen, inwater;
	float			fraction;
	vec3_t		endpos;
	pmplane_t	plane;
	int 			ent;
	vec3_t      	deltavelocity;
	int         		hitgroup;
} pmtrace_t;

typedef struct physent_s {
	char 	name[32];
	int		player;
	vec3_t 	origin;
	struct model_s* model;
	struct model_s* studiomodel;
	vec3_t 	mins, maxs;
	int		info;
	vec3_t 	angles;
	int		solid;
	int		skin;
	int		rendermode;
	float 	frame;
	int		sequence;
	byte 	controller[4];
	byte 	blending[2];
	int		movetype;
	int		takedamage;
	int		blooddecal;
	int		team;
	int		classnumber;
	int		iuser1;
	int		iuser2;
	int		iuser3;
	int		iuser4;
	float 	fuser1;
	float 	fuser2;
	float 	fuser3;
	float 	fuser4;
	vec3_t 	vuser1;
	vec3_t 	vuser2;
	vec3_t 	vuser3;
	vec3_t 	vuser4;
} physent_t;

typedef struct mnode_s {
	int				contents;
	int				visframe;
	short			minmaxs[6];
	struct mnode_s* parent;
	mplane_t* plane;
	struct mnode_s* children[2];
	unsigned short	firstsurface;
	unsigned short	numsurfaces;
} mnode_t;

typedef struct cl_entity_s {
	int 				index;
	qboolean			player;
	entity_state_t		baseline;
	entity_state_t 		prevstate;
	entity_state_t 		curstate;
	int 				current_position;
	position_history_t	ph[HISTORY_MAX];
	mouth_t			mouth;
	latchedvars_t 		latched;
	float				lastmove;
	vec3_t			origin;
	vec3_t			angles;
	vec3_t			attachment[4];
	int 				trivial_accept;
	struct model_s* model;
	struct efrag_s* efrag;
	struct mnode_s* topnode;
	float				syncbase;
	int 				visframe;
	colorVec			cvFloorColor;
} cl_entity_t;

typedef struct netadr_s {
	netadrtype_t		type;
	unsigned char		ip[4];
	unsigned char		ipx[10];
	unsigned short	port;
} netadr_t;

typedef HSPRITE(*PFNSPR_LOAD)					(const char* szPicName);
typedef int(*PFNSPR_FRAMES)				(HSPRITE hPic);
typedef int(*PFNSPR_HEIGHT)				(HSPRITE hPic, int frame);
typedef int(*PFNSPR_WIDTH)				(HSPRITE hPic, int frame);
typedef void(*PFNSPR_SET)					(HSPRITE hPic, int r, int g, int b);
typedef void(*PFNSPR_DRAW)					(int frame, int x, int y, const wrect_t* prc);
typedef void(*PFNSPR_DRAWHOLES)			(int frame, int x, int y, const wrect_t* prc);
typedef void(*PFNSPR_DRAWADDITIVE)			(int frame, int x, int y, const wrect_t* prc);
typedef void(*PFNSPR_ENABLESCISSOR)		(int x, int y, int width, int height);
typedef void(*PFNSPR_DISABLESCISSOR)		(void);
typedef client_sprite_t* (*PFNSPR_GETLIST)				(char* psz, int* piCount);
typedef void(*PFNFILLRGBA)					(int x, int y, int width, int height, int r, int g, int b, int a);
typedef int(*PFNGETSCREENINFO)			(SCREENINFO* pscrinfo);
typedef void(*PFNSETCROSSHAIR)				(HSPRITE hspr, wrect_t rc, int r, int g, int b);
typedef struct cvar_s* (*PFNREGISTERVARIABLE)			(char* szName, char* szValue, int flags);
typedef float(*PFNGETCVARFLOAT)				(char* szName);
typedef char* (*PFNGETCVARSTRING)			(char* szName);
typedef int(*PFNADDCOMMAND)				(char* cmd_name, void(*function)(void));
typedef int(*PFNHOOKUSERMSG)				(char* szMsgName, UserMsg_t pfn);
typedef int(*PFNSERVERCMD)				(char* szCmdString);
typedef int(*PFNCLIENTCMD)				(char* szCmdString);
typedef void(*PFNGETPLAYERINFO)			(int ent_num, hud_player_info_t* pinfo);
typedef void(*PFNPLAYSOUNDBYNAME)		(char* szSound, float volume);
typedef void(*PFNPLAYSOUNDBYINDEX)		(int iSound, float volume);
typedef void(*PFNANGLEVECTORS)				(const float* vecAngles, float* forward, float* right, float* up);
typedef client_textmessage_t* (*PFNTEXTMESSAGEGET)			(const char* pName);
typedef int(*PFNDRAWCHARACTER)			(int x, int y, int number, int r, int g, int b);
typedef int(*PFNDRAWCONSOLESTRING)		(int x, int y, char* string);
typedef void(*PFNDRAWSETTEXTCOLOR)		(float r, float g, float b);
typedef void(*PFNDRAWCONSOLESTRINGLEN)	(const char* string, int* length, int* height);
typedef void(*PFNCONSOLEPRINT)				(const char* string);
typedef void(*PFNCENTERPRINT)				(const char* string);
typedef int(*GETWINDOWCENTERX)			(void);
typedef int(*GETWINDOWCENTERY)			(void);
typedef void(*GETVIEWANGLES)				(float*);
typedef void(*SETVIEWANGLES)				(float*);
typedef int(*GETMAXCLIENTS)				(void);
typedef void(*CVAR_SETVALUE)				(char* cvar, float value);
typedef int(*CMD_ARGC)					(void);
typedef char* (*CMD_ARGV)					(int arg);
typedef void(*CON_PRINTF)					(char* fmt, ...);
typedef void(*CON_DPRINTF)					(char* fmt, ...);
typedef void(*CON_NPRINTF)					(int pos, char* fmt, ...);
typedef void(*CON_NXPRINTF)					(struct con_nprint_s* info, char* fmt, ...);
typedef const char* (*PHYSINFO_VALUEFORKEY)		(const char* key);
typedef const char* (*SERVERINFO_VALUEFORKEY)		(const char* key);
typedef float(*GETCLIENTMAXSPEED)			(void);
typedef int(*CHECKPARM)					(char* parm, char** ppnext);
typedef void(*KEY__EVENT)					(int key, int down);
typedef void(*GETMOUSEPOSITION)			(int* mx, int* my);
typedef int(*ISNOCLIPPING)					(void);
typedef struct cl_entity_s* (*GETLOCALPLAYER)				(void);
typedef struct cl_entity_s* (*GETVIEWMODEL)				(void);
typedef struct cl_entity_s* (*GETENTITYBYINDEX)			(int idx);
typedef float(*GETCLIENTTIME)				(void);
typedef void(*V_CALCSHAKE)					(void);
typedef void(*V_APPLYSHAKE)					(float* origin, float* angles, float factor);
typedef int(*PM_POINTCONTENTS)			(float* point, int* truecontents);
typedef int(*PM_WATERENTITY)				(float* p);
typedef struct pmtrace_s* (*PM_TRACELINE)					(float* start, float* end, int flags, int usehull, int ignore_pe);
typedef struct model_s* (*CL_LOADMODEL)				(const char* modelname, int* index);
typedef int(*CL_CREATEVISIBLEENTITY)		(int type, struct cl_entity_s* ent);
typedef const struct model_s* (*GETSPRITEPOINTER)				(HSPRITE hSprite);
typedef void(*PFNPLAYSOUNDBYNAMEATLOCATION)	(char* szSound, float volume, float* origin);
typedef unsigned short(*PFNPRECACHEEVENT)			(int type, const char* psz);
typedef void(*PFNPLAYBACKEVENT)			(int flags, const struct edict_s* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
typedef void(*PFNWEAPONANIM)				(int iAnim, int body);
typedef float(*PFNRANDOMFLOAT)				(float flLow, float flHigh);
typedef long(*PFNRANDOMLONG)				(long lLow, long lHigh);
typedef void(*PFNHOOKEVENT)				(char* name, void(*pfnEvent)(struct event_args_s* args));
typedef int(*CON_ISVISIBLE)					(void);
typedef const char* (*PFNGETGAMEDIRECTORY)		(void);
typedef struct cvar_s* (*PFNGETCVARPOINTER)			(const char* szName);
typedef const char* (*KEY_LOOKUPBINDING)			(const char* pBinding);
typedef const char* (*PFNGETLEVELNAME)				(void);
typedef void(*PFNGETSCREENFADE)			(struct screenfade_s* fade);
typedef void(*PFNSETSCREENFADE)			(struct screenfade_s* fade);
typedef void* (*VGUI_GETPANEL)				(void);
typedef void(*VGUI_VIEWPORTPAINTBACKGROUND)	(int extents[4]);
typedef byte* (*COM_LOADFILE)					(char* path, int usehunk, int* pLength);
typedef char* (*COM_PARSEFILE)				(char* data, char* token);
typedef void(*COM_FREEFILE)					(void* buffer);
typedef int(*ISSPECTATEONLY)				(void);
typedef struct model_s* (*LOADMAPSPRITE)				(const char* filename);
typedef void(*COM_ADDAPPDIRECTORYTOSEARCHPATH)	(const char* pszBaseDir, const char* appName);
typedef int(*COM_EXPANDFILENAME)			(const char* fileName, char* nameOutBuffer, int nameOutBufferSize);
typedef const char* (*PLAYERINFO_VALUEFORKEY)		(int playerNum, const char* key);
typedef void(*PLAYERINFO_SETVALUEFORKEY)	(const char* key, const char* value);
typedef qboolean(*GETPLAYERUNIQUEID)			(int iPlayer, char playerID[16]);
typedef int(*GETTRACKERIDFORPLAYER)		(int playerSlot);
typedef int(*GETPLAYERFORTRACKERID)		(int trackerID);
typedef int(*PFNSERVERCMDUNRELIABLE)		(char* szCmdString);

typedef struct playermove_s {
	int				player_index;
	qboolean			server;
	qboolean			multiplayer;
	float 			time;
	float 			frametime;
	vec3_t 			forward, right, up;
	vec3_t 			origin;
	vec3_t 			angles;
	vec3_t 			oldangles;
	vec3_t 			velocity;
	vec3_t 			movedir;
	vec3_t 			basevelocity;
	vec3_t 			view_ofs;
	float 			flDuckTime;
	qboolean			bInDuck;
	int				flTimeStepSound;
	int				iStepLeft;
	float				flFallVelocity;
	vec3_t 			punchangle;
	float 			flSwimTime;
	float 			flNextPrimaryAttack;
	int				effects;
	int				flags;
	int				usehull;
	float 			gravity;
	float 			friction;
	int				oldbuttons;
	float 			waterjumptime;
	qboolean			dead;
	int				deadflag;
	int				spectator;
	int				movetype;
	int				onground;
	int				waterlevel;
	int				watertype;
	int				oldwaterlevel;
	char 			sztexturename[256];
	char 			chtexturetype;
	float				maxspeed;
	float 			clientmaxspeed;
	int				iuser1;
	int				iuser2;
	int				iuser3;
	int				iuser4;
	float 			fuser1;
	float 			fuser2;
	float 			fuser3;
	float 			fuser4;
	vec3_t			vuser1;
	vec3_t 			vuser2;
	vec3_t			vuser3;
	vec3_t 			vuser4;
	int				numphysent;
	physent_t		physents[MAX_PHYSENTS];
	int				nummoveent;
	physent_t		moveents[MAX_MOVEENTS];
	int				numvisent;
	physent_t		visents[MAX_PHYSENTS];
	usercmd_t		cmd;
	int				numtouch;
	pmtrace_t		touchindex[MAX_PHYSENTS];
	char 			physinfo[MAX_PHYSINFO_STRING];
	struct movevars_s* movevars;
	vec3_t 			player_mins[4];
	vec3_t 			player_maxs[4];
	const char* (*PM_Info_ValueForKey) 	(const char* s, const char* key);
	void(*PM_Particle)				(vec3_t origin, int color, float life, int zpos, int zvel);
	int(*PM_TestPlayerPosition)	(vec3_t pos, pmtrace_t* ptrace);
	void(*Con_NPrintf)				(int idx, char* fmt, ...);
	void(*Con_DPrintf)				(char* fmt, ...);
	void(*Con_Printf)				(char* fmt, ...);
	double(*Sys_FloatTime)			(void);
	void(*PM_StuckTouch)			(int hitent, pmtrace_t* ptraceresult);
	int(*PM_PointContents) 		(vec3_t p, int* truecontents /*filled in if this is non-null*/);
	int(*PM_TruePointContents)	(vec3_t p);
	int(*PM_HullPointContents) 	(struct hull_s* hull, int num, vec3_t p);
	pmtrace_t(*PM_PlayerTrace) 			(vec3_t start, vec3_t end, int traceFlags, int ignore_pe);
	PM_TRACELINE 	PM_TraceLine;
	long(*RandomLong)			(long lLow, long lHigh);
	float(*RandomFloat)			(float flLow, float flHigh);
	int(*PM_GetModelType)		(struct model_s* mod);
	void(*PM_GetModelBounds)		(struct model_s* mod, vec3_t mins, vec3_t maxs);
	void* (*PM_HullForBsp)			(physent_t* pe, vec3_t offset);
	float(*PM_TraceModel)			(physent_t* pEnt, vec3_t start, vec3_t end, trace_t* trace);
	int(*COM_FileSize)			(char* filename);
	byte* (*COM_LoadFile)			(char* path, int usehunk, int* pLength);
	void(*COM_FreeFile) 			(void* buffer);
	char* (*memfgets)				(byte* pMemFile, int fileSize, int* pFilePos, char* pBuffer, int bufferSize);
	qboolean			runfuncs;
	void(*PM_PlaySound) 			(int channel, const char* sample, float volume, float attenuation, int fFlags, int pitch);
	const char* (*PM_TraceTexture)		(int ground, vec3_t vstart, vec3_t vend);
	void(*PM_PlaybackEventFull) 	(int flags, int clientindex, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
} playermove_t;

typedef struct event_api_s {
	int			version;
	void(*EV_PlaySound) 				(int ent, float* origin, int channel, const char* sample, float volume, float attenuation, int fFlags, int pitch);
	void(*EV_StopSound)				(int ent, int channel, const char* sample);
	int(*EV_FindModelIndex)			(const char* pmodel);
	int(*EV_IsLocal) 				(int playernum);
	int(*EV_LocalPlayerDucking) 		(void);
	void(*EV_LocalPlayerViewheight) 	(float*);
	void(*EV_LocalPlayerBounds) 		(int hull, float* mins, float* maxs);
	int(*EV_IndexFromTrace) 			(struct pmtrace_s* pTrace);
	struct physent_s* (*EV_GetPhysent)				(int idx);
	void(*EV_SetUpPlayerPrediction)	(int dopred, int bIncludeLocalClient);
	void(*EV_PushPMStates)			(void);
	void(*EV_PopPMStates) 			(void);
	void(*EV_SetSolidPlayers)			(int playernum);
	void(*EV_SetTraceHull) 			(int hull);
	void(*EV_PlayerTrace) 			(float* start, float* end, int traceFlags, int ignore_pe, struct pmtrace_s* tr);
	void(*EV_WeaponAnimation) 		(int sequence, int body);
	unsigned short(*EV_PrecacheEvent) 			(int type, const char* psz);
	void(*EV_PlaybackEvent) 			(int flags, const struct  edict_s* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2);
	const char* (*EV_TraceTexture) 			(int ground, float* vstart, float* vend);
	void(*EV_StopAllSounds) 			(int entnum, int entchannel);
	void(*EV_KillEvents) 				(int entnum, const char* eventname);
} event_api_t;

typedef struct net_response_s {
	int		error;
	int		context;
	int		type;
	netadr_t	remote_address;
	double	ping;
	void* response;
} net_response_t;

typedef void(*net_api_response_func_t)	(struct net_response_s* response);

typedef struct net_adrlist_s {
	struct net_adrlist_s* next;
	netadr_t		remote_address;
} net_adrlist_t;

typedef struct net_status_s {
	int		connected;
	netadr_t	local_address;
	netadr_t	remote_address;
	int		packet_loss;
	double	latency;
	double	connection_time;
	double	rate;
} net_status_t;

typedef struct net_api_s {
	void(*InitNetworking)		(void);
	void(*Status) 			(struct net_status_s* status);
	void(*SendRequest) 		(int context, int request, int flags, double timeout, struct netadr_s* remote_address, net_api_response_func_t response);
	void(*CancelRequest) 		(int context);
	void(*CancelAllRequests) 	(void);
	char* (*AdrToString)		(struct netadr_s* a);
	int(*CompareAdr) 		(struct netadr_s* a, struct netadr_s* b);
	int(*StringToAdr) 		(char* s, struct netadr_s* a);
	const char* (*ValueForKey)		(const char* s, const char* key);
	void(*RemoveKey) 		(char* s, const char* key);
	void(*SetValueForKey) 	(char* s, const char* key, const char* value, int maxsize);
} net_api_t;

typedef struct ref_params_s {
	float			vieworg[3];
	float			viewangles[3];
	float			forward[3];
	float			right[3];
	float			up[3];
	float			frametime;
	float			time;
	int			intermission;
	int			paused;
	int			spectator;
	int			onground;
	int			waterlevel;
	float			simvel[3];
	float			simorg[3];
	float			viewheight[3];
	float			idealpitch;
	float			cl_viewangles[3];
	int			health;
	float			crosshairangle[3];
	float			viewsize;
	float			punchangle[3];
	int			maxclients;
	int			viewentity;
	int			playernum;
	int			max_entities;
	int			demoplayback;
	int			hardware;
	int			smoothing;
	struct usercmd_s* cmd;
	struct movevars_s* movevars;
	int			viewport[4];
	int			nextView;
	int			onlyClientDraw;
} ref_params_t;

typedef struct clientdata_s {
	vec3_t	origin;
	vec3_t	velocity;
	int		viewmodel;
	vec3_t	punchangle;
	int		flags;
	int		waterlevel;
	int		watertype;
	vec3_t	view_ofs;
	float		health;
	int		bInDuck;
	int		weapons;
	int		flTimeStepSound;
	int		flDuckTime;
	int		flSwimTime;
	int		waterjumptime;
	float		maxspeed;
	float		fov;
	int		weaponanim;
	int		m_iId;
	int		ammo_shells;
	int		ammo_nails;
	int		ammo_cells;
	int		ammo_rockets;
	float		m_flNextAttack;
	int		tfstate;
	int		pushmsec;
	int		deadflag;
	char		physinfo[MAX_PHYSINFO_STRING];
	int		iuser1;
	int		iuser2;
	int		iuser3;
	int		iuser4;
	float		fuser1;
	float		fuser2;
	float		fuser3;
	float		fuser4;
	vec3_t	vuser1;
	vec3_t	vuser2;
	vec3_t	vuser3;
	vec3_t	vuser4;
} clientdata_t;

typedef struct local_state_s {
	entity_state_t		playerstate;
	clientdata_t		client;
	weapon_data_t	weapondata[32];
} local_state_t;

typedef struct resource_s {
	char              		szFileName[MAX_QPATH];
	resourcetype_t	type;
	int               		nIndex;
	int               		nDownloadSize;
	unsigned char		ucFlags;
	unsigned char		rgucMD5_hash[16];
	unsigned char		playernum;
	unsigned char		rguc_reserved[32];
	struct resource_s* pNext;
	struct resource_s* pPrev;
} resource_t;

typedef struct customization_s {
	qboolean 			bInUse;
	resource_t			resource;
	qboolean				bTranslated;
	int        				nUserData1;
	int        				nUserData2;
	void* pInfo;
	void* pBuffer;
	struct customization_s* pNext;
} customization_t;

typedef struct player_info_s {
	int				userid;
	char				userinfo[MAX_INFO_STRING];
	char				name[MAX_SCOREBOARDNAME];
	int				spectator;
	int				ping;
	int				packet_loss;
	char				model[MAX_QPATH];
	int				topcolor;
	int				bottomcolor;
	int				renderframe;
	int				gaitsequence;
	float				gaitframe;
	float				gaityaw;
	vec3_t			prevgaitorigin;
	customization_t 	customdata;
} player_info_t;

typedef struct r_studio_interface_s {
	int	version;
	int(*StudioDrawModel)	(int flags);
	int(*StudioDrawPlayer)	(int flags, struct entity_state_s* pplayer);
} r_studio_interface_t;

typedef struct tempent_s	TEMPENTITY;
typedef struct tempent_s {
	int			flags;
	float			die;
	float			frameMax;
	float			x;
	float			y;
	float			z;
	float			fadeSpeed;
	float			bounceFactor;
	int			hitSound;
	void(*hitcallback)	(struct tempent_s* ent, struct pmtrace_s* ptr);
	void(*callback)	(struct tempent_s* ent, float frametime, float currenttime);
	TEMPENTITY* next;
	int			priority;
	short		clientIndex;
	vec3_t		tentOffset;
	cl_entity_t	entity;
} TEMPENTITY;

typedef struct IVoiceTweak_s {
	int(*StartVoiceTweakMode)	(void);
	void(*EndVoiceTweakMode)	(void);
	void(*SetControlFloat)		(VoiceTweakControl iControl, float value);
	float(*GetControlFloat)		(VoiceTweakControl iControl);
} IVoiceTweak;

struct efx_api_s
{
	struct particle_t* (*R_AllocParticle)			(void(*callback) (struct particle_s* particle, float frametime));
	void(*R_BlobExplosion)			(float* org);
	void(*R_Blood)					(float* org, float* dir, int pcolor, int speed);
	void(*R_BloodSprite)				(float* org, int colorindex, int modelIndex, int modelIndex2, float size);
	void(*R_BloodStream)				(float* org, float* dir, int pcolor, int speed);
	void(*R_BreakModel)				(float* pos, float* size, float* dir, float random, float life, int count, int modelIndex, char flags);
	void(*R_Bubbles)					(float* mins, float* maxs, float height, int modelIndex, int count, float speed);
	void(*R_BubbleTrail)				(float* start, float* end, float height, int modelIndex, int count, float speed);
	void(*R_BulletImpactParticles)	(float* pos);
	void(*R_EntityParticles)			(struct cl_entity_s* ent);
	void(*R_Explosion)				(float* pos, int model, float scale, float framerate, int flags);
	void(*R_FizzEffect)				(struct cl_entity_s* pent, int modelIndex, int density);
	void(*R_FireField) 				(float* org, int radius, int modelIndex, int count, int flags, float life);
	void(*R_FlickerParticles)			(float* org);
	void(*R_FunnelSprite)				(float* org, int modelIndex, int reverse);
	void(*R_Implosion)				(float* end, float radius, int count, float life);
	void(*R_LargeFunnel)				(float* org, int reverse);
	void(*R_LavaSplash)				(float* org);
	void(*R_MultiGunshot)				(float* org, float* dir, float* noise, int count, int decalCount, int* decalIndices);
	void(*R_MuzzleFlash)				(float* pos1, int type);
	void(*R_ParticleBox)				(float* mins, float* maxs, unsigned char r, unsigned char g, unsigned char b, float life);
	void(*R_ParticleBurst)			(float* pos, int size, int color, float life);
	void(*R_ParticleExplosion)		(float* org);
	void(*R_ParticleExplosion2)		(float* org, int colorStart, int colorLength);
	void(*R_ParticleLine)				(float* start, float* end, unsigned char r, unsigned char g, unsigned char b, float life);
	void(*R_PlayerSprites)			(int client, int modelIndex, int count, int size);
	void(*R_Projectile)				(float* origin, float* velocity, int modelIndex, int life, int owner, void(*hitcallback)(struct tempent_s* ent, struct pmtrace_s* ptr));
	void(*R_RicochetSound)			(float* pos);
	void(*R_RicochetSprite)			(float* pos, struct model_s* pmodel, float duration, float scale);
	void(*R_RocketFlare)				(float* pos);
	void(*R_RocketTrail)				(float* start, float* end, int type);
	void(*R_RunParticleEffect)		(float* org, float* dir, int color, int count);
	void(*R_ShowLine)					(float* start, float* end);
	void(*R_SparkEffect)				(float* pos, int count, int velocityMin, int velocityMax);
	void(*R_SparkShower)				(float* pos);
	void(*R_SparkStreaks)				(float* pos, int count, int velocityMin, int velocityMax);
	void(*R_Spray)					(float* pos, float* dir, int modelIndex, int count, int speed, int spread, int rendermode);
	void(*R_Sprite_Explode)			(TEMPENTITY* pTemp, float scale, int flags);
	void(*R_Sprite_Smoke)				(TEMPENTITY* pTemp, float scale);
	void(*R_Sprite_Spray)				(float* pos, float* dir, int modelIndex, int count, int speed, int iRand);
	void(*R_Sprite_Trail)				(int type, float* start, float* end, int modelIndex, int count, float life, float size, float amplitude, int renderamt, float speed);
	void(*R_Sprite_WallPuff)			(TEMPENTITY* pTemp, float scale);
	void(*R_StreakSplash)				(float* pos, float* dir, int color, int count, float speed, int velocityMin, int velocityMax);
	void(*R_TracerEffect)				(float* start, float* end);
	void(*R_UserTracerParticle)		(float* org, float* vel, float life, int colorIndex, float length, unsigned char deathcontext, void(*deathfunc)(struct particle_s* particle));
	struct particle_t* (*R_TracerParticles)			(float* org, float* vel, float life);
	void(*R_TeleportSplash)			(float* org);
	void(*R_TempSphereModel)			(float* pos, float speed, float life, int count, int modelIndex);
	TEMPENTITY* (*R_TempModel)				(float* pos, float* dir, float* angles, float life, int modelIndex, int soundtype);
	TEMPENTITY* (*R_DefaultSprite)			(float* pos, int spriteIndex, float framerate);
	TEMPENTITY* (*R_TempSprite)				(float* pos, float* dir, float scale, int modelIndex, int rendermode, int renderfx, float a, float life, int flags);
	int(*Draw_DecalIndex)			(int id);
	int(*Draw_DecalIndexFromName)	(char* name);
	void(*R_DecalShoot)				(int textureIndex, int entity, int modelIndex, float* position, int flags);
	void(*R_AttachTentToPlayer)		(int client, int modelIndex, float zoffset, float life);
	void(*R_KillAttachedTents)		(int client);
	struct BEAM* (*R_BeamCirclePoints)		(int type, float* start, float* end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	struct BEAM* (*R_BeamEntPoint)			(int startEnt, float* end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	struct BEAM* (*R_BeamEnts)				(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	struct BEAM* (*R_BeamFollow)				(int startEnt, int modelIndex, float life, float width, float r, float g, float b, float brightness);
	void(*R_BeamKill)					(int deadEntity);
	struct BEAM* (*R_BeamLightning)			(float* start, float* end, int modelIndex, float life, float width, float amplitude, float brightness, float speed);
	struct BEAM* (*R_BeamPoints)				(float* start, float* end, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	struct BEAM* (*R_BeamRing)				(int startEnt, int endEnt, int modelIndex, float life, float width, float amplitude, float brightness, float speed, int startFrame, float framerate, float r, float g, float b);
	struct dlight_t* (*CL_AllocDlight)			(int key);
	struct dlight_t* (*CL_AllocElight)			(int key);
	TEMPENTITY* (*CL_TempEntAlloc)			(float* org, struct model_s* model);
	TEMPENTITY* (*CL_TempEntAllocNoModel)	(float* org);
	TEMPENTITY* (*CL_TempEntAllocHigh)		(float* org, struct model_s* model);
	TEMPENTITY* (*CL_TentEntAllocCustom)		(float* origin, struct model_s* model, int high, void(*callback) (struct tempent_s* ent, float frametime, float currenttime));
	void(*R_GetPackedColor)			(short* packed, short color);
	short(*R_LookupColor)				(unsigned char r, unsigned char g, unsigned char b);
	void(*R_DecalRemoveAll)			(int textureIndex); //textureIndex points to the decal index in the array, not the actual texture index.
};


typedef struct
{
	float		mins[3], maxs[3];
	float		origin[3];
	int			headnode[MAX_MAP_HULLS];
	int			visleafs;		// not including the solid leaf 0
	int			firstface, numfaces;
} dmodel_t;

typedef struct texture_s
{
	char		name[16];
	unsigned	width, height;
	int			anim_total;				// total tenths in sequence ( 0 = no)
	int			anim_min, anim_max;		// time for this frame min <=time< max
	struct texture_s* anim_next;		// in the animation sequence
	struct texture_s* alternate_anims;	// bmodels in frame 1 use these
	unsigned	offsets[MIPLEVELS];		// four mip maps stored
	unsigned	paloffset;
} texture_t;

typedef struct
{
	int			planenum;
	short		children[2];	// negative numbers are contents
} dclipnode_t;

typedef struct hull_s
{
	dclipnode_t* clipnodes;
	mplane_t* planes;
	int			firstclipnode;
	int			lastclipnode;
	vec3_t		clip_mins;
	vec3_t		clip_maxs;
} hull_t;

typedef struct
{
	vec3_t		position;
} mvertex_t;

typedef struct
{
	unsigned short	v[2];
	unsigned int	cachededgeoffset;
} medge_t;

typedef struct
{
	float		vecs[2][4];		// [s/t] unit vectors in world space. 
	// [i][3] is the s/t offset relative to the origin.
	// s or t = dot(3Dpoint,vecs[i])+vecs[i][3]
	float		mipadjust;		// ?? mipmap limits for very small surfaces
	texture_t* texture;
	int			flags;			// sky or slime, no lightmap or 256 subdivision
} mtexinfo_t;

typedef struct model_s
{
	char		name[MAX_MODEL_NAME];
	qboolean	needload;		// bmodels and sprites don't cache normally

	modtype_t	type;
	int			numframes;
	synctype_t	synctype;

	int			flags;

	//
	// volume occupied by the model
	//		
	vec3_t		mins, maxs;
	float		radius;

	//
	// brush model
	//
	int			firstmodelsurface, nummodelsurfaces;

	int			numsubmodels;
	dmodel_t* submodels;

	int			numplanes;
	mplane_t* planes;

	int			numleafs;		// number of visible leafs, not counting 0
	struct mleaf_s* leafs;

	int			numvertexes;
	mvertex_t* vertexes;

	int			numedges;
	medge_t* edges;

	int			numnodes;
	mnode_t* nodes;

	int			numtexinfo;
	mtexinfo_t* texinfo;

	int			numsurfaces;
	struct msurface_s* surfaces;

	int			numsurfedges;
	int* surfedges;

	int			numclipnodes;
	dclipnode_t* clipnodes;

	int			nummarksurfaces;
	struct msurface_s** marksurfaces;

	hull_t		hulls[MAX_MAP_HULLS];

	int			numtextures;
	texture_t** textures;

	byte* visdata;

	color24* lightdata;

	char* entities;

	//
	// additional model data
	//
	cache_user_t	cache;		// only access through Mod_Extradata

} model_t;

typedef struct
{
	int					id;
	int					version;

	char				name[64];
	int					length;

	vec3_t				eyeposition;	// ideal eye position
	vec3_t				min;			// ideal movement hull size
	vec3_t				max;

	vec3_t				bbmin;			// clipping bounding box
	vec3_t				bbmax;

	int					flags;

	int					numbones;			// bones
	int					boneindex;

	int					numbonecontrollers;		// bone controllers
	int					bonecontrollerindex;

	int					numhitboxes;			// complex bounding boxes
	int					hitboxindex;

	int					numseq;				// animation sequences
	int					seqindex;

	int					numseqgroups;		// demand loaded sequences
	int					seqgroupindex;

	int					numtextures;		// raw textures
	int					textureindex;
	int					texturedataindex;

	int					numskinref;			// replaceable textures
	int					numskinfamilies;
	int					skinindex;

	int					numbodyparts;
	int					bodypartindex;

	int					numattachments;		// queryable attachable points
	int					attachmentindex;

	int					soundtable;
	int					soundindex;
	int					soundgroups;
	int					soundgroupindex;

	int					numtransitions;		// animation node to animation node transition graph
	int					transitionindex;
} studiohdr_t;

// EngFuncs
typedef struct cl_enginefuncs_s {
	PFNSPR_LOAD 				pfnSPR_Load;
	PFNSPR_FRAMES 				pfnSPR_Frames;
	PFNSPR_HEIGHT 				pfnSPR_Height;
	PFNSPR_WIDTH 				pfnSPR_Width;
	PFNSPR_SET 					pfnSPR_Set;
	PFNSPR_DRAW 				pfnSPR_Draw;
	PFNSPR_DRAWHOLES 			pfnSPR_DrawHoles;
	PFNSPR_DRAWADDITIVE 		pfnSPR_DrawAdditive;
	PFNSPR_ENABLESCISSOR 		pfnSPR_EnableScissor;
	PFNSPR_DISABLESCISSOR 		pfnSPR_DisableScissor;
	PFNSPR_GETLIST 				pfnSPR_GetList;
	PFNFILLRGBA 				pfnFillRGBA;
	PFNGETSCREENINFO 			pfnGetScreenInfo;
	PFNSETCROSSHAIR 			pfnSetCrosshair;
	PFNREGISTERVARIABLE 		pfnRegisterVariable;
	PFNGETCVARFLOAT 			pfnGetCvarFloat;
	PFNGETCVARSTRING 			pfnGetCvarString;
	PFNADDCOMMAND 			pfnAddCommand;
	PFNHOOKUSERMSG			pfnHookUserMsg;
	PFNSERVERCMD 				pfnServerCmd;
	PFNCLIENTCMD 				pfnClientCmd;
	PFNGETPLAYERINFO 			pfnGetPlayerInfo;
	PFNPLAYSOUNDBYNAME 		pfnPlaySoundByName;
	PFNPLAYSOUNDBYINDEX 		pfnPlaySoundByIndex;
	PFNANGLEVECTORS 			pfnAngleVectors;
	PFNTEXTMESSAGEGET 			pfnTextMessageGet;
	PFNDRAWCHARACTER 			pfnDrawCharacter;
	PFNDRAWCONSOLESTRING 		pfnDrawConsoleString;
	PFNDRAWSETTEXTCOLOR 		pfnDrawSetTextColor;
	PFNDRAWCONSOLESTRINGLEN 	pfnDrawConsoleStringLen;
	PFNCONSOLEPRINT 			pfnConsolePrint;
	PFNCENTERPRINT 				pfnCenterPrint;
	GETWINDOWCENTERX 			GetWindowCenterX;
	GETWINDOWCENTERY 			GetWindowCenterY;
	GETVIEWANGLES 				GetViewAngles;
	SETVIEWANGLES 				SetViewAngles;
	GETMAXCLIENTS 				GetMaxClients;
	CVAR_SETVALUE 				Cvar_SetValue;
	CMD_ARGC 					Cmd_Argc;
	CMD_ARGV 					Cmd_Argv;
	CON_PRINTF 					Con_Printf;
	CON_DPRINTF				Con_DPrintf;
	CON_NPRINTF				Con_NPrintf;
	CON_NXPRINTF 				Con_NXPrintf;
	PHYSINFO_VALUEFORKEY 		PhysInfo_ValueForKey;
	SERVERINFO_VALUEFORKEY 	ServerInfo_ValueForKey;
	GETCLIENTMAXSPEED 			GetClientMaxspeed;
	CHECKPARM 					CheckParm;
	KEY__EVENT 					Key_Event;
	GETMOUSEPOSITION 			GetMousePosition;
	ISNOCLIPPING 				IsNoClipping;
	GETLOCALPLAYER 			GetLocalPlayer;
	GETVIEWMODEL 				GetViewModel;
	GETENTITYBYINDEX 			GetEntityByIndex;
	GETCLIENTTIME 				GetClientTime;
	V_CALCSHAKE 				V_CalcShake;
	V_APPLYSHAKE 				V_ApplyShake;
	PM_POINTCONTENTS 			PM_PointContents;
	PM_WATERENTITY 			PM_WaterEntity;
	PM_TRACELINE 				PM_TraceLine;
	CL_LOADMODEL 				CL_LoadModel;
	CL_CREATEVISIBLEENTITY 		CL_CreateVisibleEntity;
	GETSPRITEPOINTER 			GetSpritePointer;
	PFNPLAYSOUNDBYNAMEATLOCATION pfnPlaySoundByNameAtLocation;
	PFNPRECACHEEVENT 			pfnPrecacheEvent;
	PFNPLAYBACKEVENT 			pfnPlaybackEvent;
	PFNWEAPONANIM 				pfnWeaponAnim;
	PFNRANDOMFLOAT 			pfnRandomFloat;
	PFNRANDOMLONG 			pfnRandomLong;
	PFNHOOKEVENT 				pfnHookEvent;
	CON_ISVISIBLE 				Con_IsVisible;
	PFNGETGAMEDIRECTORY 		pfnGetGameDirectory;
	PFNGETCVARPOINTER 			pfnGetCvarPointer;
	KEY_LOOKUPBINDING 			Key_LookupBinding;
	PFNGETLEVELNAME 			pfnGetLevelName;
	PFNGETSCREENFADE 			pfnGetScreenFade;
	PFNSETSCREENFADE 			pfnSetScreenFade;
	VGUI_GETPANEL 				VGui_GetPanel;
	VGUI_VIEWPORTPAINTBACKGROUND VGui_ViewportPaintBackground;
	COM_LOADFILE 				COM_LoadFile;
	COM_PARSEFILE 				COM_ParseFile;
	COM_FREEFILE 				COM_FreeFile;
	struct triangleapi_s* pTriAPI;
	struct efx_api_s* pEfxAPI;
	struct event_api_s* pEventAPI;
	struct demo_api_s* pDemoAPI;
	struct net_api_s* pNetAPI;
	struct IVoiceTweak_s* pVoiceTweak;
	ISSPECTATEONLY				IsSpectateOnly;
	LOADMAPSPRITE 				LoadMapSprite;
	COM_ADDAPPDIRECTORYTOSEARCHPATH COM_AddAppDirectoryToSearchPath;
	COM_EXPANDFILENAME 		COM_ExpandFilename;
	PLAYERINFO_VALUEFORKEY 	PlayerInfo_ValueForKey;
	PLAYERINFO_SETVALUEFORKEY PlayerInfo_SetValueForKey;
	GETPLAYERUNIQUEID 			GetPlayerUniqueID;
	GETTRACKERIDFORPLAYER 		GetTrackerIDForPlayer;
	GETPLAYERFORTRACKERID 		GetPlayerForTrackerID;
	PFNSERVERCMDUNRELIABLE	pfnServerCmdUnreliable;
} cl_enginefunc_t;

typedef struct cl_clientfuncs_s
{
	int(*Initialize) (cl_enginefunc_t* pEnginefuncs, int iVersion);
	int(*HUD_Init) (void);
	int(*HUD_VidInit) (void);
	void(*HUD_Redraw) (float time, int intermission);
	int(*HUD_UpdateClientData) (client_data_t* pcldata, float flTime);
	int(*HUD_Reset) (void);
	void(*HUD_PlayerMove) (struct playermove_s* ppmove, int server);
	void(*HUD_PlayerMoveInit) (struct playermove_s* ppmove);
	char(*HUD_PlayerMoveTexture) (char* name);
	void(*IN_ActivateMouse) (void);
	void(*IN_DeactivateMouse) (void);
	void(*IN_MouseEvent) (int mstate);
	void(*IN_ClearStates) (void);
	void(*IN_Accumulate) (void);
	void(*CL_CreateMove) (float frametime, struct usercmd_s* cmd, int active);
	int(*CL_IsThirdPerson) (void);
	void(*CL_CameraOffset) (float* ofs);
	struct kbutton_s* (*KB_Find) (const char* name);
	void(*CAM_Think) (void);
	void(*V_CalcRefdef) (struct ref_params_s* pparams);
	int(*HUD_AddEntity) (int type, struct cl_entity_s* ent, const char* modelname);
	void(*HUD_CreateEntities) (void);
	void(*HUD_DrawNormalTriangles) (void);
	void(*HUD_DrawTransparentTriangles) (void);
	void(*HUD_StudioEvent) (const struct mstudioevent_s* event, const struct cl_entity_s* entity);
	void(*HUD_PostRunCmd) (struct local_state_s* from, struct local_state_s* to, struct usercmd_s* cmd, int runfuncs, double time, unsigned int random_seed);
	void(*HUD_Shutdown) (void);
	void(*HUD_TxferLocalOverrides) (struct entity_state_s* state, const struct clientdata_s* client);
	void(*HUD_ProcessPlayerState) (struct entity_state_s* dst, const struct entity_state_s* src);
	void(*HUD_TxferPredictionData) (struct entity_state_s* ps, const struct entity_state_s* pps, struct clientdata_s* pcd, const struct clientdata_s* ppcd, struct weapon_data_s* wd, const struct weapon_data_s* pwd);
	void(*Demo_ReadBuffer) (int size, unsigned char* buffer);
	int(*HUD_ConnectionlessPacket) (struct netadr_s* net_from, const char* args, char* response_buffer, int* response_buffer_size);
	int(*HUD_GetHullBounds) (int hullnumber, float* mins, float* maxs);
	void(*HUD_Frame) (double time);
	int(*HUD_Key_Event) (int down, int keynum, const char* pszCurrentBinding);
	void(*HUD_TempEntUpdate) (double frametime, double client_time, double cl_gravity, struct tempent_s** ppTempEntFree, struct tempent_s** ppTempEntActive, int(*Callback_AddVisibleEntity)(struct cl_entity_s* pEntity), void(*Callback_TempEntPlaySound)(struct tempent_s* pTemp, float damp));
	struct cl_entity_s* (*HUD_GetUserEntity) (int index);
	int(*HUD_VoiceStatus) (int entindex, qboolean bTalking);
	int(*HUD_DirectorMessage) (unsigned char command, unsigned int firstObject, unsigned int secondObject, unsigned int flags);
	int(*HUD_GetStudioModelInterface) (int version, struct r_studio_interface_s** ppinterface, struct engine_studio_api_s* pstudio);
	void(*HUD_CHATINPUTPOSITION_FUNCTION) (int* x, int* y);
	int(*HUD_GETPLAYERTEAM_FUNCTION) (int iplayer);
	void(*CLIENTFACTORY) (void);
} cl_clientfunc_t;

typedef struct engine_studio_api_s
{
	// Allocate number*size bytes and zero it
	void* (*Mem_Calloc)				(int number, size_t size);
	// Check to see if pointer is in the cache
	void* (*Cache_Check)				(struct cache_user_s* c);
	// Load file into cache ( can be swapped out on demand )
	void(*LoadCacheFile)				(char* path, struct cache_user_s* cu);
	// Retrieve model pointer for the named model
	struct model_s* (*Mod_ForName)				(const char* name, int crash_if_missing);
	// Retrieve pointer to studio model data block from a model
	void* (*Mod_Extradata)				(struct model_s* mod);
	// Retrieve indexed model from client side model precache list
	struct model_s* (*GetModelByIndex)			(int index);
	// Get entity that is set for rendering
	struct cl_entity_s* (*GetCurrentEntity)		(void);
	// Get referenced player_info_t
	struct player_info_s* (*PlayerInfo)			(int index);
	// Get most recently received player state data from network system
	struct entity_state_s* (*GetPlayerState)		(int index);
	// Get viewentity
	struct cl_entity_s* (*GetViewEntity)			(void);
	// Get current frame count, and last two timestampes on client
	void(*GetTimes)					(int* framecount, double* current, double* old);
	// Get a pointer to a cvar by name
	struct cvar_s* (*GetCvar)					(const char* name);
	// Get current render origin and view vectors ( up, right and vpn )
	void(*GetViewInfo)				(float* origin, float* upv, float* rightv, float* vpnv);
	// Get sprite model used for applying chrome effect
	struct model_s* (*GetChromeSprite)			(void);
	// Get model counters so we can incement instrumentation
	void(*GetModelCounters)			(int** s, int** a);
	// Get software scaling coefficients
	void(*GetAliasScale)				(float* x, float* y);

	// Get bone, light, alias, and rotation matrices
	float**** (*StudioGetBoneTransform) (void);
	float**** (*StudioGetLightTransform)(void);
	float*** (*StudioGetAliasTransform) (void);
	float*** (*StudioGetRotationMatrix) (void);

	// Set up body part, and get submodel pointers
	void(*StudioSetupModel)			(int bodypart, void** ppbodypart, void** ppsubmodel);
	// Check if entity's bbox is in the view frustum
	int(*StudioCheckBBox)			(void);
	// Apply lighting effects to model
	void(*StudioDynamicLight)			(struct cl_entity_s* ent, struct alight_s* plight);
	void(*StudioEntityLight)			(struct alight_s* plight);
	void(*StudioSetupLighting)		(struct alight_s* plighting);

	// Draw mesh vertices
	void(*StudioDrawPoints)			(void);

	// Draw hulls around bones
	void(*StudioDrawHulls)			(void);
	// Draw bbox around studio models
	void(*StudioDrawAbsBBox)			(void);
	// Draws bones
	void(*StudioDrawBones)			(void);
	// Loads in appropriate texture for model
	void(*StudioSetupSkin)			(void* ptexturehdr, int index);
	// Sets up for remapped colors
	void(*StudioSetRemapColors)		(int top, int bottom);
	// Set's player model and returns model pointer
	struct model_s* (*SetupPlayerModel)			(int index);
	// Fires any events embedded in animation
	void(*StudioClientEvents)			(void);
	// Retrieve/set forced render effects flags
	int(*GetForceFaceFlags)			(void);
	void(*SetForceFaceFlags)			(int flags);
	// Tell engine the value of the studio model header
	void(*StudioSetHeader)			(void* header);
	// Tell engine which model_t * is being renderered
	void(*SetRenderModel)				(struct model_s* model);

	// Final state setup and restore for rendering
	void(*SetupRenderer)				(int rendermode);
	void(*RestoreRenderer)			(void);

	// Set render origin for applying chrome effect
	void(*SetChromeOrigin)			(void);

	// True if using D3D/OpenGL
	int(*IsHardware)					(void);

	// Only called by hardware interface
	void(*GL_StudioDrawShadow)		(void);
	void(*GL_SetRenderMode)			(int mode);

	void(*StudioSetRenderamt)			(int iRenderamt); 	//!!!CZERO added for rendering glass on viewmodels
	void(*StudioSetCullState)			(int iCull);
	void(*StudioRenderShadow)			(int iSprite, float* p1, float* p2, float* p3, float* p4);
} engine_studio_api_t;