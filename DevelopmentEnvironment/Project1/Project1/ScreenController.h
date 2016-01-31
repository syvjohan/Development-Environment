#pragma once

#include <framework.h>

namespace View {
	class CodeView;
}

namespace Model {
	class CodeModel;
}

namespace Controller {
	class EventManager;

	class ScreenController {
		public:
		ScreenController();
		~ScreenController();

		private:
		void RegisterResources();
		void SetWindowParams();
		void ProgramLoop();


		int screenWidth = 1280;
		int screenHeight = 720;

		WindowParams wParams;
		Common common;
		HiResTimer timer;
		EventManager *em;
		Graphics *graphics;

		Model::CodeModel *codeModel;
		View::CodeView *codeView;
	};
}
