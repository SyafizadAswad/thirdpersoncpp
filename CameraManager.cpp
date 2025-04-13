#include "DxLib.h"
#include "CameraManager.h"

namespace {
	VECTOR cameraOffset = VGet(0.0f, 20.0f, -10.0f); //camera behind player
	float cameraSmoothSpeed = 0.15f;
	
	VECTOR currentCameraPos;
	VECTOR currentTargetPos;
}

namespace CameraManager {
	void Init() {
		currentCameraPos = VGet(0.0f, 5.0f, -10.0f);
		currentTargetPos = VGet(0.0f, 0.0f, 0.0f);
	}

	void Update(const VECTOR playerPos) {
		// Desired camera position (behind player)
		VECTOR desiredCameraPos = VAdd(playerPos, cameraOffset);
		VECTOR desiredTarget = playerPos;

		// interpolate smoothly toward the desired camera position
		currentCameraPos.x = currentCameraPos.x + (desiredCameraPos.x - currentCameraPos.x) * cameraSmoothSpeed;
		currentCameraPos.y = currentCameraPos.y + (desiredCameraPos.y - currentCameraPos.y) * cameraSmoothSpeed;
		currentCameraPos.z = currentCameraPos.z + (desiredCameraPos.z - currentCameraPos.z) * cameraSmoothSpeed;

		currentTargetPos.x = currentTargetPos.x + (desiredTarget.x - currentTargetPos.x) * cameraSmoothSpeed;
		currentTargetPos.y = currentTargetPos.y + (desiredTarget.y - currentTargetPos.y) * cameraSmoothSpeed;
		currentTargetPos.z = currentTargetPos.z + (desiredTarget.z - currentTargetPos.z) * cameraSmoothSpeed;

		SetCameraPositionAndTarget_UpVecY(currentCameraPos, currentTargetPos);
	}
}