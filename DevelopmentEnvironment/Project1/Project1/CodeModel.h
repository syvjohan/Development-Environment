#pragma once

#include <framework.h>
#include <vector>

#include "Defs.h"

namespace View {
	class CodeView;
}

namespace Model {
	class CodeWindow;

	class CodeModel {
		public:
			CodeModel();
			~CodeModel();

			void Init(Vec2 startPosition);
			void AddView(View::CodeView*);
			void RemoveView(View::CodeView*);
			void OnUpdate(const float dt);

			//CodeWindow
			void OnCodeWindowMoved(Model::CodeWindow *codeModel);

		private:
			std::vector<View::CodeView*> mViews;
			std::vector<Entity*> mEntities;
	};

}