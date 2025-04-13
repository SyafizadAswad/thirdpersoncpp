#include "DxLib.h"
#include "Player.h"

namespace Player {

	// OG RE like movement
	int modelHandle;
	int texHandle;
	VECTOR position = VGet(0.0f, 0.0f, 0.0f);
	float andleY = 0.0f; //Yaw rotation

	void Init() {
		modelHandle = MV1LoadModel("Models/player.mv1");
		texHandle = LoadGraph("Models/police_tex_256.png");
		MV1SetTextureGraphHandle(modelHandle, 0, texHandle, TRUE);
		MV1SetRotationXYZ(modelHandle, VGet(0, 135, 0));
		MV1SetScale(modelHandle, VGet(0.05f, 0.05f, 0.05f));

		MV1SetPosition(modelHandle, position);

		// check texture
		/*int textureCount = MV1GetTextureNum(modelHandle);
		for (int i = 0; i < textureCount; i++) {
			const char* texName = MV1GetTextureName(modelHandle, i);
			printfDx("Texture %d: %s\n", i, texName);
		}*/
	}

	void Update() {
		if (CheckHitKey(KEY_INPUT_W)) position.z += 1;
		if (CheckHitKey(KEY_INPUT_S)) position.z -= 1;
		if (CheckHitKey(KEY_INPUT_A)) position.x -= 1;
		if (CheckHitKey(KEY_INPUT_D)) position.x += 1;
	}

	void Draw() {
		MV1SetPosition(modelHandle, position);
		MV1DrawModel(modelHandle);
	}

	void Cleanup() {
		MV1DeleteModel(modelHandle);
	}

	VECTOR GetPosition() {
		return position;
	}
}