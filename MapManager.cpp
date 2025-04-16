#include "MapManager.h"
#include "DxLib.h"

namespace MapManager {

	void Init(const char* csvPath) {
		// No need to load models or textures anymore
	}

	void Update() {
		// No map-specific updates needed for grid
	}

	void DrawGridFloor(float spacing = 100.0f, int lines = 500, float yHeight = 0.0f) {
		int color = GetColor(128, 0, 128); // Gray color
		float start = -spacing * lines / 2;
		float end   =  spacing * lines / 2;

		// Draw lines parallel to Z-axis
		for (int i = 0; i <= lines; ++i) {
			float x = start + i * spacing;
			DrawLine3D(VGet(x, yHeight, start), VGet(x, yHeight, end), color);
		}

		// Draw lines parallel to X-axis
		for (int i = 0; i <= lines; ++i) {
			float z = start + i * spacing;
			DrawLine3D(VGet(start, yHeight, z), VGet(end, yHeight, z), color);
		}
	}

	void Draw() {
		DrawGridFloor();
	}

	void Cleanup() {
		// Nothing to clean up now
	}
} 
