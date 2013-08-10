#pragma once
#include <SFGUI/SFGUI.hpp>
#include "../Core/Build.h"

namespace Goblin
{
	class VideoSettingsPage
	{
	private:
		sfg::Label::Ptr title;
		
		sfg::Table::Ptr mainLayout;

		sfg::Frame::Ptr videoMode;
		sfg::Box::Ptr videoModeLayout;
		sfg::CheckButton::Ptr videoModeFullScreen;
		sfg::Separator::Ptr videoModeSeparator;
		sfg::Label::Ptr videoModeResolutionLabel;
		sfg::ComboBox::Ptr videoModeResolution;

		void setUp();
		
		void temp_populateCombo();

	public:
		VideoSettingsPage(void);
		~VideoSettingsPage(void);

		sfg::Widget::Ptr getTitleWidget();
		sfg::Widget::Ptr getMainWidget();
	};
}