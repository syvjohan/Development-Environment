#pragma once

#include <framework.h>

namespace Model {
	enum EntityType {
		ENTITY_CODE_WINDOW = 0
	};

	class CodeModel;

	class Entity {
		public:
			Entity() { mCodeModel = NULL; }
			virtual ~Entity() {};

			virtual void OnInit(CodeModel *m) { mCodeModel = m; }
			virtual void OnUpdate() = 0;

			virtual EntityType Type() = 0;
			CodeModel* GetModel() { return mCodeModel; }

			Vec2 mPos;
			Vec2 mSize;
			Vec2 mScale;
			Vec2 mDir;
			Vec2 mVel;
			Color mColor;
			float mRotation;

		private:
			CodeModel *mCodeModel;
	};

}
