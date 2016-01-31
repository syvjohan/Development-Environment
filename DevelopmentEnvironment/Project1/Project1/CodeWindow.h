#pragma once

#include <framework.h>

#include "Entity.h"

namespace Model {
	class CodeModel;

	class CodeWindow : public Entity {
		public:
		CodeWindow();
		~CodeWindow();

		void OnInit(CodeModel *m);
		void OnUpdate();

		inline EntityType Type() { return ENTITY_CODE_WINDOW; }
		 
		Vec2 mStartPostion;
	};
}