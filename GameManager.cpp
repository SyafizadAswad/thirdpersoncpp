#include "DxLib.h"
#include "GameManager.h"
#include "Player.h"
#include "CameraManager.h"

namespace GameManager {
	void Init() {
		Player::Init();
		CameraManager::Init();
	}

	void Update() {
		Player::Update();
		CameraManager::Update(Player::GetPosition());
	}

	void Draw() {
		// ground
		SetUseLighting(FALSE);
		DrawCube3D(
			VGet(-100.0f, 0.0f, -100.0f),
			VGet(100.0f, -1.0f, 100.0f),
			GetColor(80, 80, 80),
			GetColor(255, 255, 255),
			TRUE
		);
		SetUseLighting(TRUE);

		Player::Draw();
	}

	void Cleanup() {
		Player::Cleanup();
	}
}