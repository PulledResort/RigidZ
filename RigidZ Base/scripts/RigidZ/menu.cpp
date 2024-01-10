// RigidZ Menu 2017
// Created by: Tarack
// All rights reserved!

#include "menu.h"
#include "keyboard.h"
#include "drawings.h"
#include "functions.h"
#include "config.h"

#include <string>
#include <ctime>
#include <fstream>
#include <iostream>


#pragma region Options
// You can change theese options :)

// Menu open key
DWORD main_key = 0x51;// Q
// Nav down key
DWORD down_key = VK_NUMPAD2;
// Nav up key
DWORD up_key = VK_NUMPAD8;
// Nav left key
DWORD left_key = VK_NUMPAD4;
// Nav right key
DWORD right_key = VK_NUMPAD6;
// Nav back key
DWORD back_key = VK_NUMPAD0;

// Menu Sizes
float MenuX = 165;
float MenuY = 95;
float menuScrollRectY = 0.0;
float MenuWidth = 289;
float MinusCatagoryHeight = 6;
float SpriteCatagoryHeading = 0;
float MinusCatagoryWidth = 6;
float MenuHeight = 27;

// Menu Colors [ R G B A ]
int MenuColors[3][4] = { 

// Menu background color
{ 0, 0, 0, 145 }, 

// Menu lines color
{ 110, 0, 0, 255 },

// Menu text color
{ 255, 255, 255, 255 }

};
#pragma endregion

#pragma region Variables
// Dont change this :)
char* submenuArrowsX[] = { "helicopterhud", "mparrow" };
int selectionArrowID = 1;
char* submenuArrowsY[] = { "hudarrow", "mp_arrowxlarge" };
char* MenuCaptions;
int CurrentMenu;
char* LatestMenu;
int MenuLines;
int CurrentLine[256] = { 0 };
int loopLock = 0;
int selectedPlayer = 0;
int x;
int y;

int CurrentModel = 0;
int Time = 0;
int CurrentWeather = 0;
int MoneyDropAmount = 1500;
int CurrentDesign = 1;
int CurrentTitleFont = 1;
int CategoryFont = 2;

char UserID[32];
char Name[32];
char Position[64];
char Angle[32];

DWORD timer;

bool CategoryPressed;
#pragma endregion

#pragma region Features with Toggle
bool featureGOD;
bool featureVanish;
bool featureNeverWanted;
bool featureNoRagdoll;
bool featureInfinityAbility;
bool featureSuperJump;
bool featureExplosiveMelee;
bool featureTinyPlayer;
bool featureFastRun;

bool featureVehicleGOD;
bool featureVehicleStickToGround;
bool featureVehicleVanish;
bool featureVehicleRainbow;

bool FIBNumberPlate_;
int Start = 1;
std::string storedNumberPlate = "...bush did 911 and Hitler would have done a better job than the monkey we have now. donald trump is the only hope we've got.";
int bPlate = 1;

bool featureVehicleWarp;

bool featureWeaponInfinityAmmo;
bool featureWeaponExplosiveAmmo;
bool featureWeaponVehicleGun;

bool featureTimeFreeze;
bool featureWeatherFreeze;

bool featureLoadNorthYankton;

bool featureMiscExpandedRadar;
bool featureMiscThermalVision;
bool featureMiscNightVision;
bool featureMiscMobileRadio;
bool featureMiscChaosMode;
bool featureMiscPedBox;
bool autoRefillHP = 0;
int randomExchange = 1;
float ScaleX = 14;

bool featureDropMoney;
bool weEvenSpectating;
bool checkSpectator;
bool featureNameESP = false;
float ScaleESP = 0.4010f;
float ClientESP = 0.3970f;
float ESPWidth = 0.0780f;

float ESPWidth2 = 0.0780f;
float ESPWidth3 = 0.0780f;
float ESPWidth4 = 0.0780f;
float ESPWidth5 = 0.0780f;

float ESPWidth6 = 0.0780f;
float ESPWidth7 = 0.0780f;
float ESPWidth8 = 0.0780f;


float BlackX2 = 0.0390f;
float WhiteX2 = 0.0390f;

float BlackX3 = 0.0390f;
float WhiteX3 = 0.0390f;

float BlackX4 = 0.0390f;
float WhiteX4 = 0.0390f;

float BlackX5 = 0.0390f;
float WhiteX5 = 0.0390f;


float BlackX6 = 0.0390f;
float WhiteX6 = 0.0390f;
float BlackX7 = 0.0390f;
float WhiteX7 = 0.0390f;
float BlackX8 = 0.0390f;
float WhiteX8 = 0.0390f;

float BlackX = 0.0390f;
float WhiteX = 0.0390f;
float UIDWidth = 0.0370;

float RockstarX = -0.0110;
float RockstarY = -0.1829;
float RockstarWidth = 0.0370;
float RockstarHeight = 0.0700;
float UIDX = 0.0190f;
float UIDY = 0.1770f;

/*
Wanted elveing
*/

float OneStarX = 0.0010f;
float OneStarY = 0.1650f;

float TwoStarX = 0.0060f;
float TwoStarY = 0.1650f;

float ThreeStarX = 0.0050f;
float ThreeStarY = 0.1630f;

float FourStarX = 0.0150f;
float FourStarY = 0.1620f;

float FiveStarX = 0.0280f;
float FiveStarY = 0.1630f;

float OneStarWidth = 0.0010f;
float OneStarHeight = 0.0220f;

float TwoStarWidth = 0.0280f;
float TwoStarHeight = 0.0200f;

float ThreeStarWidth = 0.0370f;
float ThreeStarHeight = 0.0200f;

float FourStarWidth = 0.0440f;
float FourStarHeight = 0.0200f;

float FiveStarWidth = 0.0562f;
float FiveStarHeight = 0.0190f;

float OneNewStarX = -0.0000f;
float OneNewStarY = 0.1630f;

float TwoNewStarX = 0.0130f;
float TwoNewStarY = 0.1650f;

float ThreeNewStarX = 0.0170f;
float ThreeNewStarY = 0.1630f;

float FourNewStarX = 0.0090f;
float FourNewStarY = 0.1620f;

float FiveNewStarX = 0.0050f;
float FiveNewStarY = 0.1630f;

float OneNewStarWidth = 0.0290f;
float OneNewStarHeight = 0.0510f;

float TwoNewStarWidth = 0.0360f;
float TwoNewStarHeight = 0.0500f;

float ThreeNewStarWidth = 0.0240f;
float ThreeNewStarHeight = 0.0500f;

float FourNewStarWidth = 0.0290f;
float FourNewStarHeight = 0.0510f;

float FiveNewStarWidth = 0.0290f;
float FiveNewStarHeight = 0.0510f;

float TwoNewStar2X = -0.0010f;
float TwoNewStar2Y = 0.1650f;

float ThreeNewStar2X = 0.0050f;
float ThreeNewStar2Y = 0.1630f;

float ThreeNewStar3X = -0.0080f;
float ThreeNewStar3Y = 0.1630f;

float FourNewStar2X = 0.0200f;
float FourNewStar2Y = 0.1620f;

float FourNewStar3X = 0.0310f;
float FourNewStar3Y = 0.1610f;

float FourNewStar4X = -0.0020f;
float FourNewStar4Y = 0.1620f;

float FiveNewStar2X = 0.0500f;
float FiveNewStar2Y = 0.1630f;

float FiveNewStar3X = 0.0380f;
float FiveNewStar3Y = 0.1630f;

float FiveNewStar4X = 0.0270f;
float FiveNewStar4Y = 0.1630f;

float FiveNewStar5X = 0.0160f;
float FiveNewStar5Y = 0.1630f;


////////

float UIDHeight = 0.0200;
float ESPHeight = 0.0200;
float YBlack = -0.1720;
float YWhite = -0.1920;

float DevInfoY = 0.1620;
float DevInfoX = -0.0000;
float DevESP = 0.4020;
float ClanInfoX = 0.0010f;
float ClientInfoY = 0.1320f;
float ClientInfoX = 0.0010f;
float ClanInfoY = -0.1860f;
float FriendInfoY = 0.0300f;
float FriendInfoX = 0.0300;
float yMainText = -0.2080f;
float AWidth = 0.088851f;
float BWidth = 0.105838f;
float CWidth = 0.135417f;
float DWidth = 0.164996;
float EWidth = 0.194575;

float FWidth = 0.224154;
float GWidth = 0.253733;
float HWidth = 0.312891;
int maxDistance = 200;
bool CenterText = 0;

bool featureFuncEffectChopVision;
bool featureFuncEffectTazer;
bool featureFuncEffectRampage;
bool featureFuncRaceTurbo;
typedef struct
{
	int netHandle, //main network handle
		unk1, unk2, unk3, unk4, unk5, unk6, unk7, unk8, unk9, unk10, unk11, unk12;
} networkHandleMgr;
typedef struct
{
	int clanHandle, //main clan handle
		unk1, unk2, unk3, unk4, unk5, unk6, unk7, unk8, unk9, unk10, unk11, unk12, unk13,
		unk14, unk15, unk16, unk17, unk18, unk19, unk20,
		unk21; //isCrewActive
	int unk22; //char *crewRole
	int unk23; //char *creaTag
	int unk24, unk25, unk26, unk27, unk28, unk29,
		unk30, //isLeader
		unk31, //crewId
		unk32, unk33, unk34;
} networkClanMgr;
typedef struct
{
	int memHandle;
	char* unk1;
} networkMembershipMgr;

networkClanMgr clanM, clanP;

BOOL IsPlayerInClan(Player player)
{
	if (NETWORK::NETWORK_IS_SESSION_ACTIVE())
	{
		networkHandleMgr net, net2;
		NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &net.netHandle, 13); NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::PLAYER_ID(), &net2.netHandle, 13);
		if (NETWORK::_NETWORK_PLAYER_IS_IN_CLAN())
		{
			if (NETWORK::NETWORK_CLAN_PLAYER_IS_ACTIVE(&net2.netHandle) && NETWORK::NETWORK_CLAN_PLAYER_IS_ACTIVE(&net.netHandle))
			{
				if (NETWORK::NETWORK_CLAN_PLAYER_GET_DESC(&clanM.clanHandle, 35, &net2.netHandle) && NETWORK::NETWORK_CLAN_PLAYER_GET_DESC(&clanP.clanHandle, 35, &net.netHandle))
				{
					if (clanP.clanHandle == clanM.clanHandle)
					{
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

void drawNow(char* text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	//UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_COLOUR(r, g, b, a); // <- was 200
	//snprintf(opt, sizeof(opt), "~h~s", text);		// added ~h~ so it highlights selected text -_- hopefully
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void DRAW_TEXTURE(char* Streamedtexture, char* textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
	{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	}
	else
	{
		GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
	}
}

#pragma region Is Friend

int wantedlevel;
bool IsPlayerFriend(Player player)
{
	bool BplayerFriend = false;
	bool bplayerFriend = false;
	int handle[76];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, &handle[0], 13);
	if (NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
	{
		BplayerFriend = NETWORK::NETWORK_IS_FRIEND(&handle[0]);
	}
	if (BplayerFriend)
		bplayerFriend = true;
	else
		bplayerFriend = false;
	return bplayerFriend;
}

#pragma endregion

#pragma region Arrays / Structs
char* Vehicles[400] = {
	 "NINEF", "NINEF2", "BLISTA", "ASEA", "ASEA2", "BOATTRAILER", "BUS", "ARMYTANKER", "ARMYTRAILER", "ARMYTRAILER2" ,
	 "SUNTRAP", "COACH", "AIRBUS", "ASTEROPE", "AIRTUG", "AMBULANCE", "BARRACKS", "BARRACKS2", "BALLER", "BALLER2" ,
	 "BJXL", "BANSHEE", "BENSON", "BFINJECTION", "BIFF", "BLAZER", "BLAZER2", "BLAZER3", "BISON", "BISON2" ,
	 "BISON3", "BOXVILLE", "BOXVILLE2", "BOXVILLE3", "BOBCATXL", "BODHI2", "BUCCANEER", "BUFFALO", "BUFFALO2", "BULLDOZER" ,
	 "BULLET", "BLIMP", "BURRITO", "BURRITO2", "BURRITO3", "BURRITO4", "BURRITO5", "CAVALCADE", "CAVALCADE2", "POLICET" ,
	 "GBURRITO", "CABLECAR", "CADDY", "CADDY2", "CAMPER", "CARBONIZZARE", "CHEETAH", "COMET2", "COGCABRIO", "COQUETTE" ,
	 "CUTTER", "GRESLEY", "DILETTANTE", "DILETTANTE2", "DUNE", "DUNE2", "HOTKNIFE", "DLOADER", "DUBSTA", "DUBSTA2" ,
	 "DUMP", "RUBBLE", "DOCKTUG", "DOMINATOR", "EMPEROR", "EMPEROR2", "EMPEROR3", "ENTITYXF", "EXEMPLAR", "ELEGY2" ,
	 "F620", "FBI", "FBI2", "FELON", "FELON2", "FELTZER2", "FIRETRUK", "FLATBED", "FORKLIFT", "FQ2" ,
	 "FUSILADE", "FUGITIVE", "FUTO", "GRANGER", "GAUNTLET", "HABANERO", "HAULER", "HANDLER", "INFERNUS", "INGOT" ,
	 "INTRUDER", "ISSI2", "JACKAL", "JOURNEY", "JB700", "KHAMELION", "LANDSTALKER", "LGUARD", "MANANA", "MESA" ,
	 "MESA2", "MESA3", "CRUSADER", "MINIVAN", "MIXER", "MIXER2", "MONROE", "MOWER", "MULE", "MULE2" ,
	 "ORACLE", "ORACLE2", "PACKER", "PATRIOT", "PBUS", "PENUMBRA", "PEYOTE", "PHANTOM", "PHOENIX", "PICADOR" ,
	 "POUNDER", "POLICE", "POLICE4", "POLICE2", "POLICE3", "POLICEOLD1", "POLICEOLD2", "PONY", "PONY2", "PRAIRIE" ,
	 "PRANGER", "PREMIER", "PRIMO", "PROPTRAILER", "RANCHERXL", "RANCHERXL2", "RAPIDGT", "RAPIDGT2", "RADI", "RATLOADER" ,
	 "REBEL", "REGINA", "REBEL2", "RENTALBUS", "RUINER", "RUMPO", "RUMPO2", "RHINO", "RIOT", "RIPLEY" ,
	 "ROCOTO", "ROMERO", "SABREGT", "SADLER", "SADLER2", "SANDKING", "SANDKING2", "SCHAFTER2", "SCHWARZER", "SCRAP" ,
	 "SEMINOLE", "SENTINEL", "SENTINEL2", "ZION", "ZION2", "SERRANO", "SHERIFF", "SHERIFF2", "SPEEDO", "SPEEDO2" ,
	 "STANIER", "STINGER", "STINGERGT", "STOCKADE", "STOCKADE3", "STRATUM", "SULTAN", "SUPERD", "SURANO", "SURFER" ,
	 "SURFER2", "SURGE", "TACO", "TAILGATER", "TAXI", "TRASH", "TRACTOR", "TRACTOR2", "TRACTOR3", "GRAINTRAILER" ,
	 "BALETRAILER", "TIPTRUCK", "TIPTRUCK2", "TORNADO", "TORNADO2", "TORNADO3", "TORNADO4", "TOURBUS", "TOWTRUCK", "TOWTRUCK2" ,
	 "UTILLITRUCK", "UTILLITRUCK2", "UTILLITRUCK3", "VOODOO2", "WASHINGTON", "STRETCH", "YOUGA", "ZTYPE", "SANCHEZ", "SANCHEZ2" ,
	 "SCORCHER", "TRIBIKE", "TRIBIKE2", "TRIBIKE3", "FIXTER", "CRUISER", "BMX", "POLICEB", "AKUMA", "CARBONRS" ,
	 "BAGGER", "BATI", "BATI2", "RUFFIAN", "DAEMON", "DOUBLE", "PCJ", "VADER", "VIGERO", "FAGGIO2" ,
	 "HEXER", "ANNIHILATOR", "BUZZARD", "BUZZARD2", "CARGOBOB", "CARGOBOB2", "CARGOBOB3", "SKYLIFT", "POLMAV", "MAVERICK" ,
	 "NEMESIS", "FROGGER", "FROGGER2", "CUBAN800", "DUSTER", "STUNT", "MAMMATUS", "JET", "SHAMAL", "LUXOR" ,
	 "TITAN", "LAZER", "CARGOPLANE", "SQUALO", "MARQUIS", "DINGHY", "DINGHY2", "JETMAX", "PREDATOR", "TROPIC" ,
	 "SEASHARK", "SEASHARK2", "SUBMERSIBLE", "TRAILERS", "TRAILERS2", "TRAILERS3", "TVTRAILER", "RAKETRAILER", "TANKER", "TRAILERLOGS" ,
	 "TR2", "TR3", "TR4", "TRFLAT", "TRAILERSMALL", "VELUM", "ADDER", "VOLTIC", "VACCA", "BIFTA" ,
	 "SPEEDER", "PARADISE", "KALAHARI", "JESTER", "TURISMOR", "VESTRA", "ALPHA", "HUNTLEY", "THRUST", "MASSACRO" ,
	 "MASSACRO2", "ZENTORNO", "BLADE", "GLENDALE", "PANTO", "PIGALLE", "WARRENER", "RHAPSODY", "DUBSTA3", "MONSTER" ,
	 "SOVEREIGN", "INNOVATION", "HAKUCHOU", "FUROREGT", "MILJET", "COQUETTE2", "BTYPE", "BUFFALO3", "DOMINATOR2", "GAUNTLET2" ,
	 "MARSHALL", "DUKES", "DUKES2", "STALION", "STALION2", "BLISTA2", "BLISTA3", "DODO", "SUBMERSIBLE2", "HYDRA" ,
	 "INSURGENT", "INSURGENT2", "TECHNICAL", "SAVAGE", "VALKYRIE", "KURUMA", "KURUMA2", "JESTER2", "CASCO", "VELUM2" ,
	 "GUARDIAN", "ENDURO", "LECTRO", "SLAMVAN", "SLAMVAN2", "RATLOADER2", "SWIFT2", "LUXOR2", "FELTZER3", "OSIRIS" ,
	 "VIRGO", "WINDSOR", "BESRA", "SWIFT", "BLIMP2", "VINDICATOR", "TORO", "T20", "COQUETTE3", "CHINO" ,
	 "BRAWLER", "BUCCANEER2", "CHINO2", "FACTION", "FACTION2", "MOONBEAM", "MOONBEAM2", "PRIMO2", "VOODOO", "LURCHER" ,
	 "BTYPE2", "BALLER3", "BALLER4", "BALLER5", "BALLER6", "CARGOBOB4", "COG55", "COG552", "COGNOSCENTI", "COGNOSCENTI2" ,
	 "DINGHY4", "LIMO2", "MAMBA", "NIGHTSHADE", "SCHAFTER3", "SCHAFTER4", "SCHAFTER5", "SCHAFTER6", "SEASHARK3", "SPEEDER2" ,
	 "SUPERVOLITO", "SUPERVOLITO2", "TORO2", "TROPIC2", "VALKYRIE2", "VERLIERER2", "TAMPA", "BANSHEE2", "SULTANRS", "BTYPE3",
};

char* Weathers[8] = { "RAIN", "THUNDER", "SNOW", "SMOG", "FOGGY", "CLEAR", "EXTRASUNNY", "XMAS" };

char* WeatherNames[8] = { "Rainy", "Thunder", "Snow", "Smog", "Foggy", "Clear", "Sunny", "Xmas" };

const int Teleports = 15; // Number of elements in the teleport struct array.
static struct {
	char*  text;
	float x;
	float y;
	float z;
} lines[Teleports] = {
	{ "Waypoint" },
	{ "LS Customs (Los Santos #1)" ,-368, -134, 38.5 },
	{ "LS Airport", -1336.0f, -3044.0f, 13.9f },
	{ "Chilliad", 425.4f, 5614.3f, 766.5f },
	{ "LS Stripclub", 127.4f, -1307.7f, 29.2f },
	{ "Sandy Shores Airfield", 1741.3f, 3279.4f, 41.0f},
	{ "Elburro Heights", 1384.0f, -2057.1f, 52.0f },
	{ "Ferris Wheel", -1670.7f, -1125.0f, 13.0f },
	{ "North Chumash", -3192.6f, 1100.0f, 20.2f },
	{ "Windfarm", 2354.0f, 1830.3f, 101.1f },
	{ "Military Base", -2047.4f, 3132.1f, 32.8f },
	{ "IAA Office", 113.568f, -619.001f, 206.25f },
	{ "Humane Labs", 3614.394f, 3744.803f, 28.9f},
	{ "Fort Zancudo Tower", -2358.132f, 3249.754f, 101.65f },
	{ "North Yankton", 3360.19, -4849.67, 111.8 },
	//{"Sandy Shores Airfield", 1741.3f, 3279.4f, 41.0f },
};
#pragma endregion

void ScriptMain()
{//%s ~m~[%i/%i]
	notifyAboveMap("betaTrainer");

	generate_config("betaTrainer.ini");

	config cfg("betaTrainer.ini");
	section* usersection = cfg.get_section("interface");

	if (usersection != NULL) 
	{
		GAMEPLAY::STRING_TO_INT(strdup(cfg.get_value("interface", "headbg").c_str()), &CurrentDesign);
		GAMEPLAY::STRING_TO_INT(strdup(cfg.get_value("interface", "currenttitlefont").c_str()), &CurrentTitleFont);
	}
	while (true)
	{
		Menu::UpdateMenu();
		if (IsKeyJustUp(main_key))
		{
			char saves[256];
			sprintf_s(saves, "[interface]\nheadbg = %i\ncurrenttitlefont = %i", CurrentDesign, CurrentTitleFont);

			std::ofstream ostrm;
			ostrm.open("betaTrainer.ini");
			if (ostrm) {
				ostrm << saves;
			}

			GRAPHICS::GET_SCREEN_RESOLUTION(&x, &y);
			Menu::InitializeMenu(MainOptions);
		}
		
		WAIT(0);
	}
}

void generate_config(const std::string& filename) 
{
	if (!is_exists(filename))
	{
		std::ofstream ostrm;
		ostrm.open(filename);
		if (ostrm) {
			ostrm << "[interface]\nheadbg = 2\ncurrenttitlefont = 1";
		}
	}
}

inline bool is_exists(const std::string& name) 
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

float byAdd = 0.010;
namespace Menu
{ // themes
	#pragma region Main Menu Draw & Functions
	void MenuMainDraw()
	{
		// [Lines]
		for (int i = 0; i < MenuLines; i++)
		{
			MenuY = 95 + i * 27;
			Draw::Rectangle(MenuX / (float)x, MenuY / (float)y + (0.00278f), MenuWidth / (float)x, MenuHeight / (float)y, MenuColors[0][0], MenuColors[0][1], MenuColors[0][2], MenuColors[0][3]);
		}

		Draw::Rectangle(MenuX / (float)x, (95 + CurrentLine[CurrentMenu] * 27) / (float)y + (0.00278f), MenuWidth / (float)x, MenuHeight / (float)y, MenuColors[1][0], MenuColors[1][1], MenuColors[1][2], 150);
		//
		Draw::Sprite("mpentry", "birdsandbees_flat", MenuX / (float)x, (95 + CurrentLine[CurrentMenu] * 27) / (float)y + (0.00278f), MenuWidth / (float)x, MenuHeight / (float)y, 0, MenuColors[1][0], MenuColors[1][1], MenuColors[1][2], 150);

		// [Captions]
		if (CurrentDesign == 1)
			Draw::Rectangle(140 / (float)x, 50 / (float)y, 250 / (float)x, 60 / (float)y, MenuColors[1][0], MenuColors[1][1], MenuColors[1][2], MenuColors[1][3]);
			//Draw::Sprite("Spacey", "header_interaction_bdg", 165 / (float)x, 50 / (float)y, 289 / (float)x, 70 / (float)y, 0, 255, 255, 255, MenuColors[1][3]);
		else if (CurrentDesign == 2)
			Draw::Sprite("darts", "xj_v_blackboard01", 165 / (float)x, 50 / (float)y, 289 / (float)x, 70 / (float)y, 0, 255, 255, 255, MenuColors[1][3]);
		else if (CurrentDesign == 3)
			Draw::Sprite("CommonMenu", "interaction_bgd", 165 / (float)x, 50 / (float)y, 290 / (float)x, 60 / (float)y, 0, 255, 255, 255, MenuColors[1][3]);

		if (CurrentTitleFont == 1)
			Draw::Text(MenuCaptions, 165 / (float)x, 40 / (float)y, MenuX / (float)x, (MenuWidth + 90) / (float)x, 0.65, 7, 0, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		else if (CurrentTitleFont == 2)
			Draw::Text(MenuCaptions, 165 / (float)x, 40 / (float)y, MenuX / (float)x, (MenuWidth + 90) / (float)x, 0.65, 1, 0, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		// [Navigation]
		if (timer == NULL)
			timer = GetTickCount();

		if (IsKeyDown(down_key) || IsKeyDown(VK_DOWN))
		{
			if (GetTickCount() > 100 + timer)
			{
				if (CurrentLine[CurrentMenu] < MenuLines)
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					CurrentLine[CurrentMenu]++;
					if (CurrentLine[CurrentMenu] == MenuLines)
						CurrentLine[CurrentMenu] = 0;
					timer = NULL;
				}
			}
		}
		else if (IsKeyDown(up_key) || IsKeyDown(VK_UP))
		{
			if (GetTickCount() > 100 + timer)
			{
				if (CurrentLine[CurrentMenu] >= 0)
				{
					if (GetTickCount() > 100 + timer)
					{
						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
						CurrentLine[CurrentMenu]--;
						if (CurrentLine[CurrentMenu] == -1)
							CurrentLine[CurrentMenu] = MenuLines - 1;
						timer = NULL;
					}
				}
			}
		}
	}
	#pragma endregion

	void UpdateMenu()
	{
#pragma region Updated features
		if (loopLock <= 8)
			loopLock++;

		if (featureNeverWanted)
		{
			PLAYER::SET_PLAYER_WANTED_LEVEL(PLAYER::GET_PLAYER_INDEX(), 0, false);
			PLAYER::SET_PLAYER_WANTED_LEVEL_NOW(PLAYER::GET_PLAYER_INDEX(), false);
		}
		if (featureExplosiveMelee)
		{
			GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::GET_PLAYER_INDEX());
		}
		if (featureSuperJump)
		{
			GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::GET_PLAYER_INDEX());
		}
		if (featureInfinityAbility)
		{
			PLAYER::SPECIAL_ABILITY_FILL_METER(PLAYER::GET_PLAYER_INDEX(), true);
		}

		if (featureVehicleStickToGround)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()), false))
			{
				VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX())));
			}
		}
		if (featureVehicleRainbow)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()), false))
			{
				if (loopLock > 8)
				{
					VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX())), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 160), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 160));
					loopLock = 0;
				}
			}
		}

		if (featureWeaponInfinityAmmo)
		{
			Hash CurrentWeapon;
			Ped playerPed = PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX());
			if (WEAPON::GET_CURRENT_PED_WEAPON(playerPed, &CurrentWeapon, 1))
			{
				if (WEAPON::IS_WEAPON_VALID(CurrentWeapon))
				{
					int maxAmmo;
					if (WEAPON::GET_MAX_AMMO(playerPed, CurrentWeapon, &maxAmmo))
					{
						WEAPON::SET_PED_AMMO(playerPed, CurrentWeapon, maxAmmo);

						maxAmmo = WEAPON::GET_MAX_AMMO_IN_CLIP(playerPed, CurrentWeapon, 1);
						if (maxAmmo > 0)
							WEAPON::SET_AMMO_IN_CLIP(playerPed, CurrentWeapon, maxAmmo);
					}
				}
			}
		}
		if (featureWeaponExplosiveAmmo)
		{
			GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::GET_PLAYER_INDEX());
		}
		if (featureWeaponVehicleGun)
		{
			if (loopLock > 8)
			{
				Ped playerPed = PLAYER::PLAYER_PED_ID();
				if (PED::IS_PED_SHOOTING(playerPed))
				{
					Vector3 coords;
					if (WEAPON::GET_PED_LAST_WEAPON_IMPACT_COORD(playerPed, &coords))
					{
						VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(Vehicles[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, sizeof(Vehicles) / sizeof(Vehicles[0]))]), coords.x, coords.y, coords.z, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 360), true, false);
					}
					loopLock = 0;
				}
			}
			else
			{
				loopLock++;
			}
		}

		if (featureTimeFreeze)
		{
			TIME::SET_CLOCK_TIME(Time, 0, 0);
		}
		if (featureWeatherFreeze)
		{
			GAMEPLAY::SET_WEATHER_TYPE_NOW(Weathers[CurrentWeather]);
		}

		if (featureMiscChaosMode)
		{
			const int numElements = 15;
			const int arrSize = numElements * 2 + 2;
			Ped peds[arrSize];
			peds[0] = numElements;
			int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			// Nearby Peds
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]) && peds[offsettedID] != PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()))
				{
					ENTITY::SET_ENTITY_HAS_GRAVITY(peds[offsettedID], false);
					Vector3 velocity = ENTITY::GET_ENTITY_VELOCITY(peds[offsettedID]);
					velocity.z = 2.f;
					if (ENTITY::IS_ENTITY_A_PED(peds[offsettedID]) && !PED::IS_PED_RAGDOLL(peds[offsettedID]))
					{
						PED::SET_PED_TO_RAGDOLL(peds[offsettedID], 2000, 0, 2, false, false, false);
						velocity.z = 5.f;
						ENTITY::APPLY_FORCE_TO_ENTITY(peds[offsettedID], 1, 0, 0, ENTITY::IS_ENTITY_A_PED(peds[offsettedID]) ? 10.f : 5.f, 0, 0, 0, 1, 1, 1, 1, 1, 1);
					}
					ENTITY::SET_ENTITY_VELOCITY(peds[offsettedID], velocity.x, velocity.y, velocity.z);
				}
			}

			// Nearby Vehicles
			const int numElements2 = 15;
			const int arrSize2 = numElements2 * 2 + 2;
			Vehicle veh[arrSize2];
			veh[0] = numElements2;
			int count2 = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

			if (veh != NULL)
			{
				for (int i = 0; i < count2; i++)
				{
					int offsettedID = i * 2 + 2;
					if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]) && veh[offsettedID] != PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX())))
					{
						ENTITY::SET_ENTITY_HAS_GRAVITY(veh[offsettedID], false);
						Vector3 velocity = ENTITY::GET_ENTITY_VELOCITY(veh[offsettedID]);
						velocity.z = 2.f;
						ENTITY::SET_ENTITY_VELOCITY(veh[offsettedID], velocity.x, velocity.y, velocity.z);
						ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, ENTITY::IS_ENTITY_A_PED(veh[offsettedID]) ? 10.f : 5.f, 0, 0, 0, 1, 1, 1, 1, 1, 1);
					}
				}
			}
		}
		if (FIBNumberPlate_)
		{
			int Length = storedNumberPlate.size();
			Vehicle curVeh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1))
			{
				if (GAMEPLAY::GET_GAME_TIMER() > bPlate)
				{
					if (Start > Length)
					{
						Start = 1;
					}

					std::string subText = storedNumberPlate.substr(Start);

					if (subText.size() < 8)
					{
						int Remaining = 7 - subText.size();
						subText = subText + storedNumberPlate.substr(1, Remaining);
					}
					char* plateText = (strcpy((char*)malloc(subText.length() + 1), subText.c_str()));
					VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(curVeh, plateText);
					Start = Start + 1;
					bPlate = GAMEPLAY::GET_GAME_TIMER() + 131;
				}
			}
		}
		if (featureDropMoney)
		{
			Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()), true);

			OBJECT::CREATE_AMBIENT_PICKUP(0x711D02A4, pos.x + 0.5, pos.y + 0.5, pos.z, 0, MoneyDropAmount, 0x711D02A4, true, true);
		}

		if (featureMiscPedBox)
		{
			const int numElements = 15;
			const int arrSize = numElements * 2 + 2;
			Ped peds[arrSize];
			peds[0] = numElements;
			int count = PED::GET_PED_NEARBY_PEDS(PLAYER::PLAYER_PED_ID(), peds, -1);

			// Nearby Peds
			for (int i = 0; i < count; ++i)
			{
				int offsettedID = i * 2 + 2;
				if (ENTITY::DOES_ENTITY_EXIST(peds[offsettedID]) && peds[offsettedID] != PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()))
				{
					char hpText[64];

					Vector3 pos = ENTITY::GET_ENTITY_COORDS(peds[offsettedID], true);
					float sx;
					float sy;

					GRAPHICS::DRAW_LINE(pos.x + 1, pos.y, pos.z, pos.x - 1, pos.y, pos.z, 255, 0, 0, 255);
					GRAPHICS::DRAW_LINE(pos.x, pos.y + 1, pos.z, pos.x, pos.y - 1, pos.z, 255, 0, 0, 255);
					GRAPHICS::DRAW_LINE(pos.x, pos.y, pos.z + 1, pos.x, pos.y, pos.z - 1, 255, 0, 0, 255);

					GRAPHICS::GET_SCREEN_COORD_FROM_WORLD_COORD(pos.x, pos.y, pos.z, &sx, &sy);

					sprintf_s(hpText, "Health: %i", ENTITY::GET_ENTITY_HEALTH(peds[offsettedID]));
					Draw::Text(hpText, sx, sy, NULL, NULL, 0.25, 0, NULL, 255, 255, 255, 200);
				}
			}
		}
		if (autoRefillHP)
		{
			Ped ped = PLAYER::PLAYER_PED_ID();
			//RequestControlOfEnt(ped);
			int health = ENTITY::GET_ENTITY_HEALTH(ped);
			int maxHealth = ENTITY::GET_ENTITY_MAX_HEALTH(ped);
			int healthPercent = health * 100 / maxHealth;
			int armor = PED::GET_PED_ARMOUR(ped);
			int maxArmor = PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID());
			int armorPercent = armor * 100 / maxArmor;
			bool alive = !PED::IS_PED_DEAD_OR_DYING(ped, 1);
			char* aliveStatus;
			if (alive) aliveStatus = "Yes"; else aliveStatus = "No";
			bool inVehicle = PED::IS_PED_IN_ANY_VEHICLE(ped, 0);
			if (inVehicle) {
			}
			else
			{
				if (alive)
				{
					if (healthPercent < 99)
					{
						Ped selectedplayer = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos1 = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						pos1.z += randomExchange;
						Vector3 pos;
						pos.x = pos1.x;
						pos.y = pos1.y;
						pos.z = pos1.z;
						OBJECT::CREATE_AMBIENT_PICKUP(-1888453608, pos.x, pos.y, pos.z, 0, 100000, 1, 0, 1);
					}
					if (armorPercent < 99)
					{
						Ped selectedplayer = PLAYER::PLAYER_PED_ID();
						if (!ENTITY::DOES_ENTITY_EXIST(selectedplayer)) return;
						Vector3 pos1 = ENTITY::GET_ENTITY_COORDS(selectedplayer, 1);
						pos1.z += randomExchange;
						Vector3 pos;
						pos.x = pos1.x;
						pos.y = pos1.y;
						pos.z = pos1.z;
						OBJECT::CREATE_AMBIENT_PICKUP(1274757841, pos.x, pos.y, pos.z, 0, 100000, 1, 0, 1);
					}
				}
			}
		}
		if (featureNameESP)
		{
			//TODO:Infamous esp
		}
		#pragma endregion
	}

	void InitializeMenu(Menus menu)
	{
		timer = NULL;
		CurrentMenu = menu;
		//notifyAboveMap((char*)CurrentMenu);
		AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);

		switch (menu)
		{

		case MainOptions:
			while (true)
			{
#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
#pragma endregion

				Menu::SetValues(7, "xPloitz", MainOptions);

				Menu::Category("Player Options", SelfOptions, 0);
				Menu::Category("Vehicle Options", VehicleOptions, 1);
				Menu::Category("Weapon Options", WeaponOptions, 2);
				Menu::Category("Network Options", TimeOptions, 3);
				Menu::Category("Teleportation", TeleportOptions, 4);
				Menu::Category("Customization", MenuOptions, 5);
				Menu::Category("Miscellaneous", MiscOptions, 6);

				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case SelfOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(12, "Player", SelfOptions);

				Menu::ToggleFunction("Invincilbility", FEATURE_FUNC_TOG_GOD, &featureGOD, 0);
				Menu::Category("Health Options", Heal, 1);
				Menu::ToggleFunction("Invisible", FEATURE_FUNC_TOG_VANISH, &featureVanish, 2);
				Menu::Toggle("Cops Turn Blind Eye", &featureNeverWanted, 3);
				Menu::ToggleFunction("No Ragdoll", FEATURE_FUNC_TOG_NO_RAGDOLL, &featureNoRagdoll, 4);
				Menu::Toggle("Special Ability", &featureInfinityAbility, 5);
				Menu::Toggle("Super Jump", &featureSuperJump, 6);
				Menu::ToggleFunction("Super Run", FEATURE_FUNC_TOG_FASTRUN, &featureFastRun, 7);
				Menu::Toggle("Explosive Melee", &featureExplosiveMelee, 8);
				Menu::ToggleFunction("Shrink", FEATURE_FUNC_TINY_PLAYER, &featureTinyPlayer, 9);
				Menu::Category("Money Options", MoneyOptions, 10);
				Menu::Category("Informations", InformationOptions, 11);



				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				WAIT(0);
			}

			break;

		case Heal:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion	

				Menu::SetValues(5, "Health", Heal);

				Menu::Function("Increase Health", FEATURE_FUNC_FILL_HEALTH, 0);
				Menu::Function("Increase Armor", FEATURE_FUNC_FILL_ARMOR, 1);
				Menu::Function("No Wanted Level", FEATURE_FUNC_CLEAR_WANTED, 2);
				Menu::Function("No Blood Stains", FEATURE_FUNC_CLEAR_BLOOD, 3);
				Menu::Toggle("Auto Refill Esstentials", &autoRefillHP, 4);

				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				WAIT(0);
			}
			break;

		case MoneyOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(2, "$tealth", MoneyOptions);

				Menu::IntList("Amount", 100, 2000, MoneyDropAmount, 0);
				Menu::Toggle("Establish", &featureDropMoney, 1);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				WAIT(0);
			}
			break;

		case InformationOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(5, "Player Info", InformationOptions);

				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX()), true);
				int userID[76];
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::PLAYER_ID(), &userID[0], 13);
				char* producedResult = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&userID[0]);
				sprintf_s(Name, "SC ID: %s", PLAYER::GET_PLAYER_NAME(PLAYER::GET_PLAYER_INDEX()));
				sprintf_s(UserID, "SC UID: %s", producedResult);
				sprintf_s(Position, "District: %.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
				sprintf_s(Angle, "Heading: %.3f", ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED(PLAYER::GET_PLAYER_INDEX())));


				Menu::Label(Name, 0);
				Menu::Label(UserID, 1);
				Menu::Label(Position, 2);
				Menu::Label(Angle, 3);
				Menu::Category("Players", OnlinePlayers, 4);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case OnlinePlayerSub:
			while (true)
			{
#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
#pragma endregion
				Menu::SetValues(5, PLAYER::GET_PLAYER_NAME(selectedPlayer), OnlinePlayerSub);

				Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
				int userID[76];
				NETWORK::NETWORK_HANDLE_FROM_PLAYER(selectedPlayer, &userID[0], 13);
				char* producedResult = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&userID[0]);
				sprintf_s(Name, "SC ID: %s", PLAYER::GET_PLAYER_NAME(selectedPlayer));
				sprintf_s(UserID, "SC UID: %s", producedResult);
				sprintf_s(Position, "District: %.3f, %.3f, %.3f", pos.x, pos.y, pos.z);
				sprintf_s(Angle, "Heading: %.3f", ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED(selectedPlayer)));

				Menu::Label(Name, 0);
				Menu::Label(UserID, 1);
				Menu::Label(Position, 2);
				Menu::Label(Angle, 3);
				Menu::Toggle("Spectate", &weEvenSpectating, 4);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;
		case OnlinePlayers:
			while (true)
			{
#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
#pragma endregion

				for (int i = 0; i < 32; i++)
				{
					if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
					{
						Menu::SetValues(PLAYER::GET_NUMBER_OF_PLAYERS(), "Players", OnlinePlayers);
						Menu::Category(PLAYER::GET_PLAYER_NAME(i), OnlinePlayerSub, i);
					}
				}
				if (IsKeyDown(VK_NUMPAD5) && PLAYER::IS_PLAYER_PLAYING(CurrentLine[CurrentMenu] - 1))
				{
					selectedPlayer = CurrentLine[CurrentMenu] - 1;
				}


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;
		case VehicleOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(9, "xPloitz", VehicleOptions);

				Menu::Category("Vehicle Spawner", VehicleSpawnOptions, 0);
				Menu::ToggleFunction("Invincible Loop", FEATURE_FUNC_TOG_VEH_GOD, &featureVehicleGOD, 1);
				Menu::ToggleFunction("Invisible", FEATURE_FUNC_TOG_VEH_VANISH, &featureVehicleVanish, 2);
				Menu::Toggle("Stick to Ground", &featureVehicleStickToGround, 3);
				Menu::Toggle("Painter ~g~[RigidZ]", &featureVehicleRainbow, 4);
				Menu::Function("Plate Text", FEATURE_FUNC_VEH_CHANGELICENSE, 5);
				Menu::Function("Repair", FEATURE_FUNC_VEH_REPAIR, 6);
				Menu::Function("Unflip", FEATURE_FUNC_VEH_UNFLIP, 7);
				Menu::Toggle("Scrolling Plate Text", &FIBNumberPlate_, 8);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case VehicleSpawnOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(2, "Vehicles", VehicleSpawnOptions);

				Menu::CharList("~c~Vehicle~w~ ", Vehicles, Vehicles, &CurrentModel, 400, 0);
				Menu::FunctionArgs("Warp", FEATURE_FUNC_VEH_SPAWN, Vehicles[CurrentModel], NULL, 1);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case WeaponOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(5, "Weapon", WeaponOptions);

				Menu::Toggle("No Reload", &featureWeaponInfinityAmmo, 0);
				Menu::Toggle("Explosive Ammo", &featureWeaponExplosiveAmmo, 1);
				Menu::Toggle("Vehicle Gun", &featureWeaponVehicleGun, 2);
				Menu::Function("Give All Weapon", FEATURE_FUNC_WEAPON_GIVE_ALL, 3);
				Menu::Function("Remove All Weapon", FEATURE_FUNC_WEAPON_REMOVE_ALL, 4);

				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case TeleportOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(Teleports + 1, "Locations", TeleportOptions);

				Menu::ToggleFunction("Load North Yankton", FEATURE_FUNC_ENABLE_YANKTON, &featureLoadNorthYankton, 0);
				for (int i = 0; i < Teleports; i++)
				{
					float TeleportCoords[] = { lines[i].x, lines[i].y, lines[i].z };
					Menu::FunctionArgs(lines[i].text, FEATURE_FUNC_TELEPORT, "", TeleportCoords, i + 1);
				}


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case TimeOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(4, "Experience", TimeOptions);
				Menu::Toggle("Freeze Time", &featureTimeFreeze, 0);
				Menu::Toggle("Freeze Weather", &featureWeatherFreeze, 1);
				Menu::IntListFunction("Set Time", 0, 23, Time, FEATURE_FUNC_TIME_SET, 2);
				Menu::CharListFunction("Set Weather", WeatherNames, Weathers, &CurrentWeather, 8, FEATURE_FUNC_WEATHER_SET, 3);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case MenuOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(9, "Customizer", MenuOptions);

				Menu::IntList("Title Design", 1, 3, CurrentDesign, 0);
				Menu::IntList("Title Font", 1, 8, CurrentTitleFont, 1);
				Menu::IntList("Catagory Font", 1, 8, CategoryFont, 2);
				Menu::IntList("[R]olors", 1, 8, MenuColors[0][3], 3);
				Menu::IntList("Selection arrowFont", 0, 2, selectionArrowID, 4);
				Menu::FloatList("Catagory arrowWidth", -69.0, 169.0, MinusCatagoryWidth, 5);
				Menu::FloatList("Catagory arrowWidth", -69.0, 169.0, MinusCatagoryHeight, 6);
				Menu::FloatList("byAdd [bgd%^]", -129.0, 169.0, byAdd, 6);
				//Menu::FloatList("Catagory ~", -69.0, 169.0, ~, 6);
				//Menu::Category("Credits", EffectOptions, 3);

				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case MiscOptions:
			while (true)
			{
				#pragma region BackKey

				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(10, "xPloitz", MiscOptions);

				Menu::ToggleFunction("Enlarge Radar", FEATURE_FUNC_MISC_EXPANDEDRADAR, &featureMiscExpandedRadar, 0);
				Menu::ToggleFunction("Night Vision", FEATURE_FUNC_MISC_NIGHTVISION, &featureMiscNightVision, 1);
				Menu::ToggleFunction("Thermal Vision", FEATURE_FUNC_MISC_THERMALVISION, &featureMiscThermalVision, 2);
				Menu:ToggleFunction("R.O.F", FEATURE_FUNC_MISC_MOBILERADIO, &featureMiscMobileRadio, 3);
				Menu::Toggle("Chaos Mode", &featureMiscChaosMode, 4);
				Menu::Toggle("Ped ESP", &featureMiscPedBox, 5);
				Menu::Toggle("Player ESP", &featureNameESP, 6);
				Menu::Function("Unlock all Achievements", FEATURE_FUNC_MISC_ACHIEVEMENT_UNLOCK, 7);
				Menu::Category("Vision Effects", EffectOptions, 8);
				Menu::FloatList("Sprite Scale", -337.7, 337.7, ScaleX, 9);
				


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;

		case EffectOptions:
			while (true)
			{
				#pragma region BackKey
				Menu::MenuMainDraw();
				Menu::UpdateMenu();
				#pragma endregion

				Menu::SetValues(4, "Visions", EffectOptions);

				Menu::ToggleFunctionArgs("Chop Effect", FEATURE_FUNC_CAM_EFFECT, &featureFuncEffectChopVision, "ChopVision", NULL, 0);
				Menu::ToggleFunctionArgs("Rampage Effect", FEATURE_FUNC_CAM_EFFECT, &featureFuncEffectRampage, "Rampage", NULL, 1);
				Menu::ToggleFunctionArgs("Tazed Effect", FEATURE_FUNC_CAM_EFFECT, &featureFuncEffectTazer, "Dont_tazeme_bro", NULL, 2);
				Menu::ToggleFunctionArgs("Boost Effect", FEATURE_FUNC_CAM_EFFECT, &featureFuncRaceTurbo, "RaceTurbo", NULL, 3);


				if (IsKeyJustUp(main_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Crash", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;
				}
				if (IsKeyJustUp(back_key))
				{
					AUDIO::PLAY_SOUND_FRONTEND(-1, "Power_Down", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
					break;

				}
				WAIT(0);
			}
			break;
		}
	}

	void SetValues(int linesC, char* MenuCaption, Menus Menu)
	{
		MenuLines = linesC;
		MenuCaptions = MenuCaption;	
		if (CurrentMenu != Menu)
			CurrentMenu = Menu;
	}

	#pragma region Line Types
	void Label(char* DisplayName, int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
	}

	void CharList(char* DisplayName, char* Names[], char* Datas[], int* CurrentData, int DataSize, int Index) // Data size required because sizeof() is return false data.
	{
		char Data[128];
		MenuY = 85 + Index * 27;
		sprintf_s(Data, "%s ~m~[%i/%i]", Names[*CurrentData], *CurrentData, DataSize);

		Draw::Text(DisplayName, (MenuX - 120) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(Data, (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (CurrentLine[CurrentMenu] == Index)
		{
			if (GetTickCount() > 100 + timer)
			{
				if (IsKeyDown(left_key))
				{
					if (*CurrentData > 1)
					{
						*CurrentData = *CurrentData - 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(right_key))
				{
					if (*CurrentData < DataSize)
					{
						*CurrentData = *CurrentData + 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
			}
		}
	}

	void IntList(char* DisplayName, int MinValue, int MaxValue, int& ToModify, int Index)
	{
		char Data[128];
		sprintf_s(Data, "~p~[%i]", ToModify);
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 120) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(Data, (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (CurrentLine[CurrentMenu] == Index)
		{
			if (GetTickCount() > 100 + timer)
			{
				if (IsKeyDown(left_key))
				{
					if (ToModify > MinValue)
					{
						ToModify = ToModify - 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(right_key))
				{
					if (ToModify < MaxValue)
					{
						ToModify = ToModify + 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
			}
		}
	}

	void FloatList(char* DisplayName, float MinValue, float MaxValue, float& ToModify, int Index)
	{
		char Data[128];
		sprintf_s(Data, "~p~[%f]", ToModify);
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 120) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(Data, (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (CurrentLine[CurrentMenu] == Index)
		{
			if (GetTickCount() > 100 + timer)
			{
				if (IsKeyDown(left_key))
				{
					if (ToModify > MinValue)
					{
						ToModify = ToModify - 0.001;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(right_key))
				{
					if (ToModify < MaxValue)
					{
						ToModify = ToModify + 0.001;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
			}
		}
	}

	void Category(char* DisplayName, Menus RedirectTo, int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.40, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(">", (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 14) / (float)x, 0.40, CategoryFont, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Sprite(submenuArrowsX[selectionArrowID], submenuArrowsY[selectionArrowID], (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuWidth - MinusCatagoryWidth, MenuHeight - MinusCatagoryHeight, SpriteCatagoryHeading, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		// add some better catagory arrows..
		if (GetTickCount() > 100 + timer)
		{ //int CurrentLine[256] = { 0 };
			if (IsKeyDown(VK_NUMPAD5) && CurrentLine[CurrentMenu] == Index)
			{
				InitializeMenu(RedirectTo);
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
				timer = NULL;
			}
		}
	}

	void Toggle(char* DisplayName, bool* Toggle, int Index)
	{
		MenuY = 85 + Index * 27;
		if (*Toggle)
			Draw::Sprite("commonmenu", "shop_box_tick", (MenuX + 134) / (float)x, (MenuY + 9) / (float)y + (0.00278f), /*[0.028f, 0.045f] */0.045f, 0.045f, 0, 255, 255, 255, 185);
		else
			Draw::Sprite("commonmenu", "shop_box_blank", (MenuX + 134) / (float)x, (MenuY + 9) / (float)y + (0.00278f), /*14 / (float)x, ScaleX / (float)y*/0.045f, 0.045f, 0, 255, 255, 255, 185);

		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		//Draw::Text(GetOptionSwitch(Toggle), (MenuX + 95) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		if (GetTickCount() > 100 + timer)
		{
			if (IsKeyDown(VK_NUMPAD5) && CurrentLine[CurrentMenu] == Index)
			{
				*Toggle = !*Toggle;
				timer = NULL;
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
			}
		}
	}

	void IntListFunction(char* DisplayName, int MinValue, int MaxValue, int& ToModify, FEATURE_FUNCS features, int Index)
	{
		char Data[128];
		sprintf_s(Data, "~p~[%i]", ToModify);
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(Data, (MenuX + 80) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (CurrentLine[CurrentMenu] == Index)
		{
			if (GetTickCount() > 100 + timer)
			{
				if (IsKeyDown(left_key))
				{
					if (ToModify > MinValue)
					{
						ToModify = ToModify - 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(right_key))
				{
					if (ToModify < MaxValue)
					{
						ToModify = ToModify + 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(VK_NUMPAD5))
				{
					MenuFunctions(features, false, "", NULL, ToModify);
					timer = NULL;

					AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
				}
			}
		}
	}

	void CharListFunction(char* DisplayName, char* Names[], char* Datas[], int* CurrentData, int DataSize, FEATURE_FUNCS features, int Index)
	{
		char Data[128];
		sprintf_s(Data, "~r~[%s]", Names[*CurrentData]);
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		Draw::Text(Data, (MenuX + 80) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, (MenuWidth + 6) / (float)x, 0.35, 0, 2, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (CurrentLine[CurrentMenu] == Index)
		{
			if (GetTickCount() > 100 + timer)
			{
				if (IsKeyDown(left_key))
				{
					if (*CurrentData > 1)
					{
						*CurrentData = *CurrentData - 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(right_key))
				{
					if (*CurrentData < DataSize)
					{
						*CurrentData = *CurrentData + 1;
						timer = NULL;

						AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
					}
				}
				else if (IsKeyDown(VK_NUMPAD5))
				{
					MenuFunctions(features, false, Datas[*CurrentData], NULL, NULL);
					timer = NULL;

					AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
				}
			}
		}
	}

	void Function(char* DisplayName, FEATURE_FUNCS features, int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (GetTickCount() > 100 + timer)
		{
			if (IsKeyDown(VK_NUMPAD5) && CurrentLine[CurrentMenu] == Index)
			{
				MenuFunctions(features, false, "", NULL, NULL);
				timer = NULL;
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
			}
		}
	}

	void FunctionArgs(char* DisplayName, FEATURE_FUNCS features, char* CharArg, float FloatArg[], int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);

		if (GetTickCount() > 100 + timer)
		{
			if (IsKeyDown(VK_NUMPAD5) &&  CurrentLine[CurrentMenu] == Index)
			{
				MenuFunctions(features, false, CharArg, FloatArg, NULL);
				timer = NULL;
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
			}
		}
	}

	void ToggleFunction(char* DisplayName, FEATURE_FUNCS features, bool* Toggle, int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		
		if (*Toggle)
			Draw::Sprite("commonmenu", "shop_box_tickb", (MenuX + 134) / (float)x, (MenuY + 9) / (float)y + (0.00278f), 14 / (float)x, ScaleX / (float)y, 0, 255, 255, 255, 185);
		else
			Draw::Sprite("commonmenu", "shop_box_blankb", (MenuX + 134) / (float)x, (MenuY + 9) / (float)y + (0.00278f), 14 / (float)x, ScaleX / (float)y, 0, 255, 51, 51, 185);

		if (GetTickCount() > 100 + timer)
		{
			if (IsKeyDown(VK_NUMPAD5) && CurrentLine[CurrentMenu] == Index)
			{
				*Toggle = !*Toggle;
				MenuFunctions(features, *Toggle, "", NULL, NULL);
				timer = NULL;
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
			}
		}
	}

	void ToggleFunctionArgs(char* DisplayName, FEATURE_FUNCS features, bool* Toggle, char* CharArg, float FloatArg[], int Index)
	{
		MenuY = 85 + Index * 27;
		Draw::Text(DisplayName, (MenuX - 140) / (float)x, MenuY / (float)y + (0.00278f), MenuX / (float)x, MenuWidth / (float)x, 0.35, 0, 1, MenuColors[2][0], MenuColors[2][1], MenuColors[2][2], MenuColors[2][3]);
		
		if (*Toggle)
			Draw::Sprite("commonmenu", "shop_box_tickb", (MenuX + 110) / (float)x, (MenuY + 9) / (float)y + (0.00278f), 14 / (float)x, 14 / (float)y, 0, 255, 255, 255, 185);
		else
			Draw::Sprite("commonmenu", "shop_box_blankb", (MenuX + 110) / (float)x, (MenuY + 9) / (float)y + (0.00278f), 14 / (float)x, 14 / (float)y, 0, 255, 51, 51, 185);

		if (GetTickCount() > 100 + timer)
		{
			if (IsKeyDown(VK_NUMPAD5) && CurrentLine[CurrentMenu] == Index)
			{
				*Toggle = !*Toggle;
				MenuFunctions(features, *Toggle, CharArg, FloatArg, NULL);
				timer = NULL;
				AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
			}
		}
	}
	#pragma endregion
}