#include "DxLib.h"
#include "GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// Enable 3D
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetUseBackBufferTransColorFlag(FALSE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetGraphMode(1280, 720, 32);
	SetWindowSize(1280, 720);
	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);
	SetCameraNearFar(1.0f, 10000.0f);
	SetLightEnable(TRUE);
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 1.0f));

	GameManager::Init();
	GameManager::Draw();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		GameManager::Update();
		GameManager::Draw();
	}

	GameManager::Cleanup();
	DxLib_End();
	return 0;
}

