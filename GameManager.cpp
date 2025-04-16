#include "DxLib.h"
#include "GameManager.h"
#include "Player.h"
#include "CameraManager.h"
#include "MapManager.h"

namespace GameManager {
	int floorHandle;
	int floorTexHandle;

	void Init() {
		MapManager::Init("Models/testmap.csv");
		Player::Init();
		CameraManager::Init();
	}

	void Update() {
		MapManager::Update();
		Player::Update();
		CameraManager::Update(Player::GetPosition());
	}

	void Draw() {
		// ground
		/*SetUseLighting(FALSE);
		DrawCube3D(
			VGet(-1000.0f, 0.0f, -1000.0f),
			VGet(1000.0f, -1.0f, 1000.0f),
			GetColor(80, 80, 80),
			GetColor(255, 255, 255),
			TRUE
		);
		SetUseLighting(TRUE);*/
		//SetUseLighting(FALSE);
		MapManager::Draw();
		//SetUseLighting(TRUE);
		Player::Draw();
	}

	void Cleanup() {
		Player::Cleanup();
	}
}