#include "CodeWindow.h"
#include "CodeModel.h"

namespace Model {
	CodeWindow::CodeWindow() {}

	CodeWindow::~CodeWindow() {}

	void CodeWindow::OnInit(CodeModel *m) {
		Entity::OnInit(m);

		mPos = mStartPostion;
		mVel = Vec2(0, 0);
		mDir = Vec2(0, 0);
		mScale = Vec2(1, 1);
		mSize = Vec2(363, 580);
		mRotation = 0;
		mColor = Color::White;
	}

	void CodeWindow::OnUpdate() {
		GetModel()->OnCodeWindowMoved(this);
	}
}