#include "pch.h"
#include "StageSelectBosses.h"

using WndProc_t = LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM);
FunctionHook<void> hCanDrawLevelPanel((intptr_t)0x676A60);
FunctionHook<void, int*> hDrawLevelPanel((intptr_t)0x676690);
FunctionHook<void> hStageMapCreate((intptr_t)0x6779A0);
FunctionHook<void> hStageMapDelete((intptr_t)0x677990);
FunctionHook<signed int> hStageSelectMenu((intptr_t)Menu_StageSelect);
FunctionHook<void> hDrawStageIcons((intptr_t)0x676320);
UsercallFunc(signed int, hStageSelectMove, (int direction), (direction), 0x677BF0, rEAX, rEAX);
UsercallFuncVoid(hDrawMissionSelectPanel, (char savedregs), (savedregs), 0x676B70, rBP);

void StageSelectBosses::Init() {
	hCanDrawLevelPanel.Hook(StageSelectBosses::CanDrawLevelPanel);
	hDrawLevelPanel.Hook(StageSelectBosses::DrawLevelPanel);
	hStageMapCreate.Hook(StageSelectBosses::LoadAssets);
	hStageSelectMenu.Hook(StageSelectBosses::StageSelectMenu);
	hStageMapDelete.Hook(StageSelectBosses::FreeAssets);
	hDrawStageIcons.Hook(StageSelectBosses::DrawBossSelect);
	hStageSelectMove.Hook(StageSelectBosses::StageSelectMove);
	hDrawMissionSelectPanel.Hook(StageSelectBosses::DrawMissionSelectPanel);
	StageSelectBosses::OldWndProc = (WNDPROC)SetWindowLong(GetActiveWindow(), GWLP_WNDPROC, (LONG_PTR)StageSelectBosses::WndProc);
}

void StageSelectBosses::CanDrawLevelPanel() {
	if (StageSelectBosses::BossIsSelected) {
		int a1[3] = {};
		NJS_VECTOR pos = { 0, 0, 0 };
		NJS_SPRITE panelSprite = {};
		pos.x = PanelPosX - 125;
		pos.y = PanelPosY - 70;
		pos.z = 0;

		float argb = 0.5f;
		_constant_attr_or_ = nj_constant_attr_or_;
		nj_constant_material_.a = argb;
		nj_constant_material_.r = argb;
		nj_constant_material_.g = argb;
		nj_constant_material_.b = argb;
		_constant_attr_and_ = nj_constant_attr_and_;

		panelSprite.sx = 1.0;
		panelSprite.sy = 1.0;
		panelSprite.p.x = pos.x;
		panelSprite.p.y = pos.y;
		panelSprite.ang = 0;
		panelSprite.tlist = &stageSelectTextures;
		panelSprite.tanim = &stageSelectAnimations;
		njDrawSprite2D_0(&panelSprite, 92, -95, 0x22u);

		_constant_attr_or_ = nj_constant_attr_or_;
		nj_constant_material_.a = 0;
		nj_constant_material_.r = 0;
		nj_constant_material_.g = 0;
		nj_constant_material_.b = 0;
		_constant_attr_and_ = nj_constant_attr_and_;
		DrawLevelPane(a1);
		return;
	}

	hCanDrawLevelPanel.Original();
}

void StageSelectBosses::DrawLevelPanel(int* a1) {
	if (StageSelectBosses::BossIsSelected) {
		int spritePos = 0x21;
		NJS_VECTOR pos = { 0, 0, 0 };
		NJS_SPRITE sprite = {};

		for (int i = 0; i < 18; ++i) {
			pos.x = (double)(i % 6u) * 38.0 + PanelPosX - 92.5;
			pos.y = (double)(i / 6u) * 35.0 + PanelPosY - 5.0;
			sprite.p.x = pos.x;
			sprite.p.y = pos.y;
			sprite.sx = 0.5f;
			sprite.sy = 0.5f;
			sprite.tlist = &StageSelectBosses::BossTexture;
			sprite.tanim = StageSelectBosses::BossTextureAnims;
			njDrawSprite2D_0(&sprite, i + 1, -89, 0x20u);

			sprite.sx = 0.7f;
			sprite.sy = 0.7f;
			sprite.tlist = &stageSelectTextures;
			sprite.tanim = &stageSelectAnimations;
			njDrawSprite2D_0(&sprite, 88, -90, 0x20u);
		}

		pos.x = PanelPosX - 110.0f;
		pos.y = PanelPosY - 50.0f;
		sprite.sx = 1.0;
		sprite.sy = 1.0;
		sprite.p.x = pos.x;
		sprite.p.y = pos.y;
		sprite.tlist = &StageSelectBosses::BossTexture;
		sprite.tanim = StageSelectBosses::BossTextureAnims;
		njDrawSprite2D_0(&sprite, 19, -93, 0x20u);
		return;
	}

	hDrawLevelPanel.Original(a1);
}

void StageSelectBosses::DrawMissionSelectPanel(char savedregs) {
	if (StageSelectBosses::BossIsSelected) {
		NJS_VECTOR pos = { 0, 0, 0 };
		NJS_SPRITE panelSprite = {};
		NJS_SPRITE sprite = {};
		pos.x = PanelPosX - 125;
		pos.y = PanelPosY - 70;
		pos.z = 0;

		float argb = 0.5f;
		_constant_attr_or_ = nj_constant_attr_or_;
		nj_constant_material_.a = argb;
		nj_constant_material_.r = argb;
		nj_constant_material_.g = argb;
		nj_constant_material_.b = argb;
		_constant_attr_and_ = nj_constant_attr_and_;

		panelSprite.sx = 1.0f;
		panelSprite.sy = 1.0f;
		panelSprite.p.x = pos.x;
		panelSprite.p.y = pos.y;
		panelSprite.ang = 0;
		panelSprite.tlist = &stageSelectTextures;
		panelSprite.tanim = &stageSelectAnimations;
		njDrawSprite2D_0(&panelSprite, 92, -95, 0x22u);

		argb = 1.0f;
		_constant_attr_or_ = nj_constant_attr_or_;
		nj_constant_material_.a = argb;
		nj_constant_material_.r = argb;
		nj_constant_material_.g = argb;
		nj_constant_material_.b = argb;
		_constant_attr_and_ = nj_constant_attr_and_;

		for (int i = 0; i < 18; ++i) {
			pos.x = (double)(i % 6u) * 38.0f + PanelPosX - 92.5f;
			pos.y = (double)(i / 6u) * 35.0f + PanelPosY - 5.0f;
			sprite.p.x = pos.x;
			sprite.p.y = pos.y;
			sprite.sx = 0.5f;
			sprite.sy = 0.5f;
			sprite.tlist = &StageSelectBosses::BossTexture;
			sprite.tanim = StageSelectBosses::BossTextureAnims;
			njDrawSprite2D_0(&sprite, i + 1, -89, 0x20u);

			sprite.sx = 0.7f;
			sprite.sy = 0.7f;
			sprite.tlist = &stageSelectTextures;
			sprite.tanim = &stageSelectAnimations;
			njDrawSprite2D_0(&sprite, 88, -90, 0x20u);
		}

		int index = (StageSelectBosses::BossSelectRow * 6) + StageSelectBosses::BossSelectCol;
		sprite.p.x = (double)(index % 6u) * 38.0f + PanelPosX - 92.5f;
		sprite.p.y = (double)(index / 6u) * 35.0f + PanelPosY - 5.0f;
		sprite.sx = 0.55f;
		sprite.sy = 0.55f;
		njDrawSprite2D_0(&sprite, 90, -88, 0x20u);

		pos.x = PanelPosX - 110.0f;
		pos.y = PanelPosY - 50.0f;
		sprite.sx = 1.0;
		sprite.sy = 1.0;
		sprite.p.x = pos.x;
		sprite.p.y = pos.y;
		sprite.tlist = &StageSelectBosses::BossTexture;
		sprite.tanim = StageSelectBosses::BossTextureAnims;
		njDrawSprite2D_0(&sprite, 20 + index, -93, 0x20u);
		return;
	}

	hDrawMissionSelectPanel.Original(savedregs);
}

bool StageSelectBosses::IsStageUnlocked(LevelIDs level) {
	if (level == LevelIDs_Route101280) {
		return StageMapStageEnabled[18] || StageMapStageEnabled[20];
	}

	if (!StageSelectBosses::LevelToStageIndex.count(level)) {
		return false;
	}

	return StageMapStageEnabled[StageSelectBosses::LevelToStageIndex[level]];
}

signed int StageSelectBosses::StageSelectMove(int direction) {
	StageSelectLevel curSelection = StageSelectLevels[StageSelectLevelSelection];
	if (!StageSelectBosses::BossIsSelected) {
		if (direction == StageSelectBosses::MOVE_UP && curSelection.Level == LevelIDs_GreenHill) {
			StageSelectBosses::BossIsSelected = true;
			return 1;
		}

		if (StageSelectBosses::IsStageUnlocked(LevelIDs_GreenHill)) {
			if (
				direction == StageSelectBosses::MOVE_RIGHT &&
				(
					(curSelection.Level == LevelIDs_KartRace && curSelection.Character == Characters_Rouge) ||
					curSelection.Level == LevelIDs_MissionStreet
				)
			) {
				hStageSelectMove.Original(direction);
				StageSelectBosses::BossIsSelected = true;
				return 1;
			} else if (direction == StageSelectBosses::MOVE_LEFT && curSelection.Level == LevelIDs_AquaticMine) {
				hStageSelectMove.Original(direction);
				StageSelectBosses::BossIsSelected = true;
				return 1;
			}
		}
	} else if (direction == StageSelectBosses::MOVE_DOWN) {
		if (!StageSelectBosses::IsStageUnlocked(LevelIDs_GreenHill)) {
			return 0;
		}

		StageSelectLevelSelection = StageSelectBosses::GREEN_HILL_INDEX;
		StageSelectBosses::BossIsSelected = false;
		return 1;
	} else if (direction == StageSelectBosses::MOVE_UP) {
		return 0;
	} else if (direction == StageSelectBosses::MOVE_RIGHT) {
		StageSelectLevelSelection = StageSelectBosses::GREEN_HILL_INDEX;
		StageSelectBosses::BossIsSelected = false;
		return hStageSelectMove.Original(direction);
	} else if (direction == StageSelectBosses::MOVE_LEFT) {
		StageSelectLevelSelection = StageSelectBosses::GREEN_HILL_INDEX;
		StageSelectBosses::BossIsSelected = false;
		return hStageSelectMove.Original(direction);
	}

	int bossesCol = StageSelectBosses::BossSelect.Column;
	int moveResult = hStageSelectMove.Original(direction);
	StageSelectLevel newSelection = StageSelectLevels[StageSelectLevelSelection];
	if (newSelection.Column > curSelection.Column && bossesCol > curSelection.Column && bossesCol < newSelection.Column) {
		StageSelectBosses::BossIsSelected = true;
		StageSelectLevelSelection = StageSelectBosses::GREEN_HILL_INDEX;
		return 1;
	} else if (newSelection.Column < curSelection.Column && bossesCol < curSelection.Column && bossesCol > newSelection.Column) {
		StageSelectBosses::BossIsSelected = true;
		StageSelectLevelSelection = StageSelectBosses::GREEN_HILL_INDEX;
		return 1;
	}

	return moveResult;
}

void StageSelectBosses::LoadAssets() {
	hStageMapCreate.Original();

	if (StageSelectBosses::BossTexName && StageSelectBosses::BossTexName[0].texaddr) {
		return;
	}

	ResizeTextureList(&StageSelectBosses::BossTexture, StageSelectBosses::BossTexName);
	LoadTextureList("stageMapBoss", &StageSelectBosses::BossTexture);
	njSetTexture(&StageSelectBosses::BossTexture);
}

void StageSelectBosses::FreeAssets() {
	if (!StageSelectBosses::Exiting) {
		hStageMapDelete.Original();
	}

	if (StageSelectBosses::BossTexture.textures && StageSelectBosses::BossTexture.textures[0].texaddr) {
		FreeTexList(&StageSelectBosses::BossTexture);
	}
}

signed int StageSelectBosses::StageSelectMenu() {
	if (StageSelectBosses::BossIsSelected && (CurrentSubMenu == 2 || CurrentSubMenu == 3 || CurrentSubMenu == 5)) {
		if (CurrentSubMenu == 2 && (MenuButtons_Pressed[0] & (Buttons_A | Buttons_Start)) != 0) {
			PlaySoundProbably(32769, 0, 0, 0);
			StageSelectData->EnableLevelWindow = 0;
			StageSelectData->unk0 = 0;
			StageSelectData->currMenu = 1;
			StageSelectData->field_4_2_3 = 1;
			StageSelectData->someChar2 = 0;
			CurrentSubMenu = 3;
			return 0;
		} else if (CurrentSubMenu == 3) {
			if ((MenuButtons_Pressed[0] & Buttons_Left) != 0) {
				StageSelectBosses::BossSelectCol = StageSelectBosses::BossSelectCol > 0 ? StageSelectBosses::BossSelectCol - 1 : 5;
				PlaySoundProbably(32768, 0, 0, 0);
				return 0;
			} else if ((MenuButtons_Pressed[0] & Buttons_Right) != 0) {
				StageSelectBosses::BossSelectCol = StageSelectBosses::BossSelectCol < 5 ? StageSelectBosses::BossSelectCol + 1 : 0;
				PlaySoundProbably(32768, 0, 0, 0);
				return 0;
			} else if ((MenuButtons_Pressed[0] & Buttons_Up) != 0) {
				StageSelectBosses::BossSelectRow = StageSelectBosses::BossSelectRow > 0 ? StageSelectBosses::BossSelectRow - 1 : 2;
				PlaySoundProbably(32768, 0, 0, 0);
				return 0;
			} else if ((MenuButtons_Pressed[0] & Buttons_Down) != 0) {
				StageSelectBosses::BossSelectRow = StageSelectBosses::BossSelectRow < 2 ? StageSelectBosses::BossSelectRow + 1 : 0;
				PlaySoundProbably(32768, 0, 0, 0);
				return 0;
			} else if ((MenuButtons_Pressed[0] & (Buttons_A | Buttons_Start)) != 0) {
				PlaySoundProbably(32769, 0, 0, 0);
				SaveMenuData();
				LastMenuNumber = 3;
				dword_1AEE2FC = 0;
				ShouldDrawStageMenuData = 0;
				StageSelectData->DrawAtAll = 0;
				StageSelectData->field_4 = 0;
				CurrentSubMenu = 5;
				return 0;
			}
		} else if (CurrentSubMenu == 5) {
			int index = (StageSelectBosses::BossSelectRow * 6) + StageSelectBosses::BossSelectCol;
			std::pair<LevelIDs, Characters> selection = StageSelectBosses::BossStageLevelData[index];
			SetCurrentLevel(selection.first);
			if (isFirstStageLoad != 1 || negative_2 == -2) {
				CurrentCharacter = selection.second;
			} else {
				CurrentCharacter = negative_2;
				negative_2 = -2;
			}

			MissionNum = 0;
			byte_174AFE0 = 0;
			TwoPlayerMode = 0;
			CurrentDemoState = DemoState_None;
			NextGameMode = GameMode_StartLevel;
			IsInSequence = 0;
			SequenceNoAndPos = 0;
			SequenceEventNo = 1;
			return 1;
		}
	}

	return hStageSelectMenu.Original();
}

void StageSelectBosses::ExitHandler() {
	StageSelectBosses::Exiting = true;
	StageSelectBosses::FreeAssets();
}

void StageSelectBosses::DrawBossSelect() {
	DWORD originalCanSelectStage = CanSelectStage;
	if (StageSelectBosses::BossIsSelected) {
		CanSelectStage = 0;
	}

	hDrawStageIcons.Original();
	CanSelectStage = originalCanSelectStage;

	NJS_SPRITE bossSprite = {
		{
			(double)(StageMapScroll + 60 * StageSelectBosses::BossSelect.Column + 30) + StageSelectColumnOffset,
			(float)(60 * StageSelectBosses::BossSelect.Row + 30),
			0
		},
		0.7f,
		0.7f,
		0,
		&StageSelectBosses::BossTexture,
		StageSelectBosses::BossTextureAnims
	};

	NJS_SPRITE selectedSprite = {
		{
			(double)(StageMapScroll + 60 * StageSelectBosses::BossSelect.Column + 30) + StageSelectColumnOffset,
			(float)(60 * StageSelectBosses::BossSelect.Row + 30),
			0
		},
		0.7f,
		0.7f,
		0,
		&stageSelectTextures,
		&stageSelectAnimations
	};

	float argb = StageSelectBosses::BossIsSelected ? 1.0f : 0.8f;
	_constant_attr_or_ = nj_constant_attr_or_;
	nj_constant_material_.a = argb;
	nj_constant_material_.r = argb;
	nj_constant_material_.g = argb;
	nj_constant_material_.b = argb;
	_constant_attr_and_ = nj_constant_attr_and_;

	if (StageSelectBosses::BossIsSelected && CurrentSubMenu == 2) {
		float hoverAnim = njCos((int)((double)(unsigned int)(5 * FrameCountIngame) * 182.0444488525391)) * 0.1000000014901161 + 1.100000023841858;
		bossSprite.sx = hoverAnim;
		bossSprite.sy = hoverAnim;
		selectedSprite.sx = hoverAnim;
		selectedSprite.sy = hoverAnim;
		njDrawSprite2D_0(&selectedSprite, 90, -99, 0x20u);
	}

	njDrawSprite2D_0(&bossSprite, 0, -100, 0x22u);
}

LRESULT __stdcall StageSelectBosses::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_QUIT || (uMsg == WM_SYSCOMMAND && (wParam & 0xFFF0) == SC_CLOSE)) {
		StageSelectBosses::ExitHandler();
	}

	return CallWindowProc(StageSelectBosses::OldWndProc, hWnd, uMsg, wParam, lParam);
}
