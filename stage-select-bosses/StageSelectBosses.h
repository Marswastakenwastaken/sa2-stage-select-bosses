#pragma once
#include <string>
#include <unordered_map>

DataArray(NJS_TEXLIST, stageSelectTextures, 0xC68B68, 4);
DataPointer(NJS_TEXANIM, stageSelectAnimations, 0xC68C50);
DataPointer(DWORD, StageMapScroll, 0x1A4A964);
DataPointer(float, StageSelectColumnOffset, 0x1AEE764);
DataArray(int, StageMapStageEnabled, 0x1A4A974, 33);
DataPointer(DWORD, CanSelectStage, 0x1D1BEC8);
DataPointer(float, PanelPosX, 0x1A4A968);
DataPointer(float, PanelPosY, 0x1A4A96C);
FunctionPointer(void, DrawLevelPane, (int* a1), 0x676690);
FunctionPointer(void, SaveMenuData, (), 0x673AE0);
DataPointer(DWORD, LastMenuNumber, 0x1A559E8);
DataPointer(DWORD, ShouldDrawStageMenuData, 0x1D1BEF8);
DataPointer(DWORD, dword_1A559E8, 0x1A559E8);
DataPointer(DWORD, dword_1AEE2FC, 0x1AEE2FC);
DataPointer(BYTE, byte_174AFE0, 0x174AFE0);
DataPointer(BYTE, IsInSequence, 0x1DEB31E);
DataPointer(WORD, SequenceNoAndPos, 0x1DEB31F);
DataPointer(BYTE, SequenceEventNo, 0x1DEB321);

class StageSelectBosses {
	public:
		static void Init();
		static void CanDrawLevelPanel();
		static void DrawLevelPanel(int* a1);
		static void DrawMissionSelectPanel(char savedregs);
		static signed int StageSelectMove(int direction);
		static signed int StageSelectMenu();
		static void LoadAssets();
		static void FreeAssets();
		static void ExitHandler();
		static LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static inline bool BossIsSelected = false;
		static inline const void* CAN_DRAW_TRUE_RET = (void*)0x676A7E;
		static inline const void* CAN_DRAW_FALSE_RET = (void*)0x676B64;

	private:
		static void DrawBossSelect();
		static bool IsStageUnlocked(LevelIDs level);
		static const inline size_t BossTexLen = 23;
		static inline NJS_TEXLIST BossTexture = { nullptr, 1 };
		static inline NJS_TEXNAME BossTexName[StageSelectBosses::BossTexLen];
		static inline std::string BossTexFileNames[23] = {
			std::string("stg_stagechr_boss           "),
			std::string("stg_stagechr_boss_name      "),
			std::string("stg_stagechr_boss_bf        "),
			std::string("stg_stagechr_boss_egm1      "),
			std::string("stg_stagechr_boss_sh1       "),
			std::string("stg_stagechr_boss_kbb       "),
			std::string("stg_stagechr_boss_eggs      "),
			std::string("stg_stagechr_boss_rouge     "),
			std::string("stg_stagechr_boss_egm2      "),
			std::string("stg_stagechr_boss_sh2       "),
			std::string("stg_stagechr_boss_hs        "),
			std::string("stg_stagechr_boss_tail1     "),
			std::string("stg_stagechr_boss_fd        "),
			std::string("stg_stagechr_boss_sn1       "),
			std::string("stg_stagechr_boss_egge      "),
			std::string("stg_stagechr_boss_knux      "),
			std::string("stg_stagechr_boss_tail2     "),
			std::string("stg_stagechr_boss_sn2       "),
			std::string("stg_stagechr_boss_bio       "),
			std::string("stg_stagechr_boss_fin       "),
			std::string("stg_plate_boss_btn_m        "),
			std::string("stg_info_boss_spr           "),
			std::string("stg_stagesel_boss_csol      ")
		};
		static inline NJS_TEXANIM BossTextureAnims[41] = {
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 0, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 2, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 3, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 4, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 5, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 6, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 7, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 8, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 9, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 10, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 11, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 12, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 13, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 14, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 15, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 16, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 17, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 18, 0 },
			{ 0x3B, 0x3B, 0x1D, 0x1D, 8, 8, 0xF4, 0xF4, 19, 0 },
			{ 146, 12, 0, 0, 4, 119, 90, 125, 1, 0 },		// boss select
			{ 150, 12, 0, 0, 164, 119, 239, 125, 1, 0 },	// big foot
			{ 172, 12, 0, 0, 4, 127, 90, 133, 1, 0 },		// eggman 1
			{ 175, 12, 0, 0, 94, 127, 182, 133, 1, 0 },		// shadow 1
			{ 155, 12, 0, 0, 4, 135, 94, 141, 1, 0 },		// kbb
			{ 189, 12, 0, 0, 94, 135, 196, 141, 1, 0 },		// egg golem sonic
			{ 161, 12, 0, 0, 4, 143, 84, 149, 1, 0 },		// rouge
			{ 151, 12, 0, 0, 152, 143, 228, 149, 1, 0 },	// eggman 2
			{ 165, 12, 0, 0, 4, 151, 86, 157, 1, 0 },		// shadow 2
			{ 190, 12, 0, 0, 90, 151, 185, 157, 1, 0 },		// hot shot
			{ 191, 12, 0, 0, 4, 159, 100, 165, 1, 0 },		// tails 1
			{ 161, 12, 0, 0, 106, 159, 186, 165, 1, 0 },	// flying dog
			{ 168, 12, 0, 0, 4, 167, 88, 173, 1, 0 },		// sonic 1
			{ 206, 12, 0, 0, 93, 167, 206, 173, 1, 0 },		// egg golem eggman
			{ 141, 12, 0, 0, 4, 175, 74, 181, 1, 0 },		// knuckles
			{ 146, 12, 0, 0, 81, 175, 154, 181, 1, 0 },		// tails 2
			{ 202, 12, 0, 0, 4, 183, 105, 189, 1, 0 },		// sonic 2
			{ 175, 15, 0, 0, 111, 183, 198, 190, 1, 0 },	// biolizard
			{ 154, 12, 0, 0, 4, 191, 81, 197, 1, 0 },		// final hazard
			{ 255, 186, 0, 0, 0, 0, 255, 186, 20, 0 },
			{ 49, 49, 24, 24, 200, 152, 249, 250, 21, 0 },
			{ 76, 76, 38, 38, 0, 0, 152, 152, 22, 0 }
		};

		static inline std::pair<LevelIDs, Characters> BossStageLevelData[18] = {
			{ LevelIDs_BigFoot, Characters_Sonic },
			{ LevelIDs_TailsVsEggman1, Characters_MechTails },
			{ LevelIDs_SonicVsShadow1, Characters_Sonic },
			{ LevelIDs_KingBoomBoo, Characters_Knuckles },
			{ LevelIDs_EggGolemS, Characters_Sonic },
			{ LevelIDs_KnucklesVsRouge, Characters_Knuckles },
			{ LevelIDs_TailsVsEggman2, Characters_MechTails },
			{ LevelIDs_SonicVsShadow2, Characters_Sonic },
			{ LevelIDs_HotShot, Characters_Shadow },
			{ LevelIDs_TailsVsEggman1, Characters_MechEggman },
			{ LevelIDs_FlyingDog, Characters_Rouge },
			{ LevelIDs_SonicVsShadow1, Characters_Shadow },
			{ LevelIDs_EggGolemE, Characters_MechEggman },
			{ LevelIDs_KnucklesVsRouge, Characters_Rouge },
			{ LevelIDs_TailsVsEggman2, Characters_MechEggman },
			{ LevelIDs_SonicVsShadow2, Characters_Shadow },
			{ LevelIDs_Biolizard, Characters_Shadow },
			{ LevelIDs_FinalHazard, Characters_Sonic }
		};

		static inline std::unordered_map<LevelIDs, int> LevelToStageIndex = {
			{ LevelIDs_HiddenBase, 0 },
			{ LevelIDs_PyramidCave, 1 },
			{ LevelIDs_DeathChamber, 2 },
			{ LevelIDs_EggQuarters, 3 },
			{ LevelIDs_SandOcean, 4 },
			{ LevelIDs_DryLagoon, 5 },
			{ LevelIDs_WeaponsBed, 6 },
			{ LevelIDs_PrisonLane, 7 },
			{ LevelIDs_WildCanyon, 8 },
			{ LevelIDs_IronGate, 9 },
			{ LevelIDs_SecurityHall, 10 },
			{ LevelIDs_MetalHarbor, 11 },
			{ LevelIDs_SkyRail, 12 },
			{ LevelIDs_WhiteJungle, 13 },
			{ LevelIDs_GreenForest, 14 },
			{ LevelIDs_PumpkinHill, 15 },
			{ LevelIDs_AquaticMine, 16 },
			{ LevelIDs_GreenHill, 17 },
			{ LevelIDs_RadicalHighway, 19 },
			{ LevelIDs_MissionStreet, 21 },
			{ LevelIDs_ChaoWorld, 22 },
			{ LevelIDs_CityEscape, 23 },
			{ LevelIDs_CrazyGadget, 24 },
			{ LevelIDs_EternalEngine, 25 },
			{ LevelIDs_CosmicWall, 26 },
			{ LevelIDs_MeteorHerd, 27 },
			{ LevelIDs_LostColony, 28 },
			{ LevelIDs_CannonsCoreS, 29 },
			{ LevelIDs_FinalChase, 30 },
			{ LevelIDs_FinalRush, 31 },
			{ LevelIDs_MadSpace, 32 }
		};

		static inline StageSelectLevel BossSelect = { 0, 0, 8, 4 };
		static inline byte BossSelectRow = 0;
		static inline byte BossSelectCol = 0;
		static inline WNDPROC OldWndProc = nullptr;
		static inline bool Exiting = false;

		static inline const byte GREEN_HILL_INDEX = 17;
		static inline const byte MOVE_UP = 0;
		static inline const byte MOVE_DOWN = 1;
		static inline const byte MOVE_LEFT = 2;
		static inline const byte MOVE_RIGHT = 3;
};