#include "CameraManager.h"
#include "Player.h" // In case you want to get the position here

namespace {
	//VECTOR cameraOffset = VGet(5.0f, 10.0f, -15.0f); // Height and behind player
	VECTOR cameraOffset = VGet(0.0f, 200.0f, -200.0f); // Height and behind player
}

namespace CameraManager {
	void Init() {
		// Empty if not needed
	}

	void Update(VECTOR playerPos) {
		VECTOR targetPos = VAdd(playerPos, VGet(0.0f, 100.0f, 0.0f)); // Look slightly above the player
		VECTOR cameraPos = VAdd(playerPos, cameraOffset);

		SetCameraPositionAndTarget_UpVecY(cameraPos, targetPos);
	}
}
