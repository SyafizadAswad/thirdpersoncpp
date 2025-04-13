#include "DxLib.h"
#include "GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// Enable 3D
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetUseBackBufferTransColorFlag(FALSE);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetBackgroundColor(255, 30, 30);
	SetDrawScreen(DX_SCREEN_BACK);
	SetCameraNearFar(1.0f, 1000.0f);
	SetLightEnable(TRUE);
	SetLightAmbColor(GetColorF(0.5f, 0.5f, 0.5f, 255));

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

