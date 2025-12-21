#pragma once

DataArray(NJS_TEXLIST, stageSelectTextures, 0xC68B68, 4);
DataPointer(NJS_TEXANIM, stageSelectAnimations, 0xC68C50);
DataPointer(DWORD, StageMapScroll, 0x1A4A964);
DataPointer(float, StageSelectColumnOffset, 0x1AEE764);
DataPointer(DWORD, CanSelectStage, 0x1D1BEC8);
DataPointer(float, PanelPosX, 0x1A4A968);
DataPointer(float, PanelPosY, 0x1A4A96C);
FunctionPointer(void, DrawLevelPane, (int* a1), 0x676690);
// DELETE THIS
DataPointer(DWORD, dword_8A0560, 0x8A0560);

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
		static inline NJS_TEXLIST BossTexture = { nullptr, 1 };
		static inline std::string BossTexFileNames[20] = {
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
			std::string("stg_stagechr_boss_fin       ")
		};
		static inline NJS_TEXNAME BossTexName[20] = {
			{ (void*)StageSelectBosses::BossTexFileNames[0].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[1].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[2].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[3].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[4].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[5].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[6].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[7].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[8].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[9].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[10].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[11].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[12].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[13].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[14].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[15].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[16].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[17].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[18].c_str(), 0, 0 },
			{ (void*)StageSelectBosses::BossTexFileNames[19].c_str(), 0, 0 }
		};
		static inline NJS_TEXANIM BossTextureAnims[38] = {
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
			{ 175, 15, 0, 0, 111, 183, 198, 190, 1, 0 },	// biolizard - eq
			{ 154, 12, 0, 0, 4, 191, 81, 197, 1, 0 }		// final hazard (extend a little) - lc
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