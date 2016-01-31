#include "ScreenController.h"

#include "CodeModel.h"
#include "CodeView.h"

namespace Controller {
	bool gRunning = true;
	class EventManager : public IEventProcessor {
		public:
		void onWindowClose() { gRunning = false; }
	};

	ScreenController::ScreenController() {
		SetWindowParams();
		if (common.init(wParams)) {
			RegisterResources();

			common.setEventProcessor(em);
			graphics = common.getGraphics();
			graphics->setViewport(0, 0, screenWidth, screenHeight);
			timer.restart();

			codeModel = DBG_NEW Model::CodeModel;
			codeView = DBG_NEW View::CodeView(&common, codeModel);
			codeModel->AddView(codeView);

			int width, height;
			common.getGraphics()->getContextSize(&width, &height);
			codeModel->Init(Vec2(width / 2, height  / 2));

			//Enter Program loop.
			ProgramLoop();

		} else {
			printf("Initializing of Common object failed!");
		}
	}

	ScreenController::~ScreenController() {}

	void ScreenController::RegisterResources() {
		common.registerTextureResource("codeWindow", "image/codeWindow.png");
	}

	void ScreenController::SetWindowParams() {
		wParams.mFullscreen = false;
		wParams.mHeight = screenHeight;
		wParams.mWidth = screenWidth;
		wParams.mTitle = "Development Environment";
		wParams.mPosX = 0;
		wParams.mPosY = 0;
	}

	void ScreenController::ProgramLoop() {
		while (gRunning) {
			timer.tick();

			// Process OS events.
			common.frame();

			graphics->clear(Color::Black, true);

			codeModel->OnUpdate(timer.getDeltaSeconds());

			codeView->OnRender();

			graphics->present();
		}
	}
}