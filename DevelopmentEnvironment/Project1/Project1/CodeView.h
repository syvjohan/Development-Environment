#pragma once

#include <framework.h>

#include "Defs.h"

namespace Model {
	class CodeModel;
	class CodeWindow;
}

namespace View {
	class CodeView {
		public:
		CodeView(Common*, Model::CodeModel*);
		~CodeView();
		void OnUpdate(const float dt);

		void OnRender();

		void OnCodeWindowInit(Model::CodeWindow*);

		private:
		Common *mCommon;
		Model::CodeModel *mModel;
		Renderer2D *mRenderer;

		std::vector<SpriteDef> mSprites;
	};

}