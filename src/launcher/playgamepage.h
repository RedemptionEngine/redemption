#pragma once

#include <zwidget/core/widget.h>

// #define EXTRAARGS

class LauncherWindow;
class TextLabel;
class ListView;
class LineEdit;
struct WadStuff;

class PlayGamePage : public Widget
{
public:
	PlayGamePage(LauncherWindow* launcher, WadStuff* wads, int numwads, int defaultiwad);
	void UpdateLanguage();

#if defined(EXTRAARGS)
	void SetExtraArgs(const std::string& args);
	std::string GetExtraArgs();
#endif

	int GetSelectedGame();

private:
	void OnGeometryChanged() override;
	void OnSetFocus() override;
	void OnGamesListActivated();

	LauncherWindow* Launcher = nullptr;

	TextLabel* WelcomeLabel = nullptr;
	TextLabel* SelectLabel = nullptr;
#if defined(EXTRAARGS)
	TextLabel* ParametersLabel = nullptr;
#endif
	ListView* GamesList = nullptr;
#if defined(EXTRAARGS)
	LineEdit* ParametersEdit = nullptr;
#endif
};
