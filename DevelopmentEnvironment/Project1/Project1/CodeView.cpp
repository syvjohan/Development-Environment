#include "CodeView.h"
#include "CodeModel.h"
#include "CodeWindow.h"

namespace View {
	CodeView::CodeView(Common *common, Model::CodeModel *m) {
		mCommon = common;
		mModel = m;
		Graphics *g = common->getGraphics();
		mRenderer = g->createRenderer2D();
	}

	CodeView::~CodeView() {}

	void CodeView::OnUpdate(const float dt) {

	}

	void CodeView::OnRender() {
		mRenderer->begin(Renderer2D::SPRITE_SORT_DEFERRED, Renderer2D::SPRITE_BLEND_ALPHA);
		for (SpriteDef &sprite : mSprites) {
			mRenderer->draw(sprite.mTexture,
							sprite.mPosition,
							sprite.mClip,
							sprite.mOrigin,
							sprite.mRotation,
							sprite.mScale,
							sprite.mTint,
							0.0f);
		}

		mRenderer->end();
	}

	void CodeView::OnCodeWindowInit(Model::CodeWindow *codeWindow) {
		SpriteDef sprite;
		sprite.mEntity = codeWindow;
		sprite.mTexture = mCommon->getTextureResource("codeWindow");
		sprite.mPosition = codeWindow->mPos;
		sprite.mScale = codeWindow->mScale;
		sprite.mOrigin = Vec2(codeWindow->mSize / 2);
		sprite.mClip = { 0, 0, codeWindow->mSize.x, codeWindow->mSize.y };
		sprite.mTint = codeWindow->mColor;
		sprite.mRotation = codeWindow->mRotation;

		mSprites.push_back(sprite);
	}
}