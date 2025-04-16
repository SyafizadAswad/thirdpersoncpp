#include "DxLib.h"
#include "Player.h"
#include <math.h>

namespace {
	int modelHandle;
	int texHandle;
	VECTOR position = VGet(0.0f, 0.0f, 0.0f);
	VECTOR velocity = VGet(0.0f, 0.0f, 0.0f);
	float moveSpeed = 10.0f;
	float currentRotationY = 0.0f;

	int currentAnimHandle = -1;
	int currentAnimIndex = -1;

	int animIndex_Tpose = 0;
	int animIndex_Hands_Hit = 1;
	int animIndex_Hands_Run = 2;
	int animIndex_Hands_Punch2 = 3;
	int animIndex_Hands_Punch1 = 4;
	int animIndex_Hands_Idle = 5;
	int animIndex_Hands_Punch3 = 6;
	int animIndex_Hands_Death = 7;
	

	// For frame control
	float animSpeed = 1.0f; // You can change this to speed up/down animation
}

namespace Player {

	void PlayAnimation(int animIndex) {
		if (currentAnimIndex == animIndex) return; // Already playing

		// Detach old animation
		if (currentAnimHandle != -1) {
			MV1DetachAnim(modelHandle, currentAnimHandle);
		}

		// Attach and blend
		currentAnimHandle = MV1AttachAnim(modelHandle, animIndex);
		MV1SetAttachAnimBlendRate(modelHandle, currentAnimHandle, 1.0f);

		// DonÅft reset the animation timer here!
		currentAnimIndex = animIndex;
	}

	void Init() {
		modelHandle = MV1LoadModel("Models/player.mv1");
		texHandle = LoadGraph("Models/police_tex_256.png");
		MV1SetTextureGraphHandle(modelHandle, 0, texHandle, TRUE);
		MV1SetRotationXYZ(modelHandle, VGet(0, 135, 0));
		//MV1SetScale(modelHandle, VGet(0.05f, 0.05f, 0.05f));
		MV1SetPosition(modelHandle, position);

		PlayAnimation(animIndex_Hands_Idle);

		// Optional: Print all available animations
		/*
		int animNum = MV1GetAnimNum(modelHandle);
		for (int i = 0; i < animNum; i++) {
			const char* animName = MV1GetAnimName(modelHandle, i);
			printfDx("Anim %d: %s\n", i, animName);
		}
		*/
	}

	void Update() {
		velocity = VGet(0.0f, 0.0f, 0.0f);

		if (CheckHitKey(KEY_INPUT_W)) velocity.z += 1.0f;
		if (CheckHitKey(KEY_INPUT_S)) velocity.z -= 1.0f;
		if (CheckHitKey(KEY_INPUT_A)) velocity.x -= 1.0f;
		if (CheckHitKey(KEY_INPUT_D)) velocity.x += 1.0f;

		bool isMoving = (VSize(velocity) > 0.01f);

		// Movement
		if (isMoving) {
			velocity = VNorm(velocity);
			position = VAdd(position, VScale(velocity, moveSpeed));
			currentRotationY = atan2f(velocity.x, velocity.z) + DX_PI;
		}

		MV1SetPosition(modelHandle, position);
		MV1SetRotationXYZ(modelHandle, VGet(0.0f, currentRotationY, 0.0f));

		// Animation Switching
		int desiredAnimIndex = isMoving ? animIndex_Hands_Run: animIndex_Hands_Idle;

		if (desiredAnimIndex != currentAnimIndex) {
			PlayAnimation(desiredAnimIndex);
		}

		// Frame time control + loop
		float nowTime = MV1GetAttachAnimTime(modelHandle, currentAnimHandle);
		float totalTime = MV1GetAttachAnimTotalTime(modelHandle, currentAnimHandle);

		nowTime += animSpeed;

		if (nowTime >= totalTime) {
			nowTime = 0.0f; // Loop back to beginning
		}

		MV1SetAttachAnimTime(modelHandle, currentAnimHandle, nowTime);
	}

	void Draw() {
		MV1DrawModel(modelHandle);
	}

	void Cleanup() {
		MV1DeleteModel(modelHandle);
	}

	VECTOR GetPosition() {
		return position;
	}
}
