#include "pch.h"

extern "C" {
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions) {
		StageSelectBosses::Init();
	}

	__declspec(dllexport) void __cdecl OnExit() {
		StageSelectBosses::ExitHandler();
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.
}