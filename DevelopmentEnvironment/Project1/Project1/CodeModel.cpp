#include "CodeModel.h"
#include "CodeWindow.h"
#include "CodeView.h"

namespace Model {
	CodeModel::CodeModel() {}

	CodeModel::~CodeModel() {}

	void CodeModel::Init(Vec2 startPosition) {
		CodeWindow *codeWindow = DBG_NEW CodeWindow();
		codeWindow->mStartPostion = startPosition;
		mEntities.push_back(codeWindow);

		for (Entity *e : mEntities) {
			e->OnInit(this);
			switch (e->Type()) {
				case ENTITY_CODE_WINDOW:
					for (auto *view : mViews) {
						view->OnCodeWindowInit((CodeWindow*)e);
					}
					break;
			}
		}
	}

	void CodeModel::AddView(View::CodeView *v) {
		mViews.push_back(v);
	}

	void CodeModel::RemoveView(View::CodeView *v) {
		for (auto it = mViews.begin(); it != mViews.end(); ++it) {
			if (*it == v) {
				mViews.erase(it);
				return;
			}
		}
	}

	void CodeModel::OnUpdate(const float dt) {

	}

	void CodeModel::OnCodeWindowMoved(Model::CodeWindow *codeModel) {

	}
}