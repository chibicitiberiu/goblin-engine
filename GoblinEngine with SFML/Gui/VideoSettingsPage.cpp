#include "VideoSettingsPage.h"
#include <sstream>

namespace Goblin
{
	VideoSettingsPage::VideoSettingsPage(void)
	{
		this->setUp();
		this->temp_populateCombo();
	}


	VideoSettingsPage::~VideoSettingsPage(void)
	{
	}

	void VideoSettingsPage::setUp()
	{
		// Set up title label
		title = sfg::Label::Create("Video");
		
		// Set up video mode
		videoModeResolutionLabel = sfg::Label::Create("Resolution:");
		videoModeResolution = sfg::ComboBox::Create();
		videoModeFullScreen = sfg::CheckButton::Create("Full screen");
		videoModeSeparator = sfg::Separator::Create(sfg::Separator::HORIZONTAL);

		// Set up video mode - layout
		videoModeLayout = sfg::Box::Create(sfg::Box::VERTICAL, 2.0f);
		videoModeLayout->Pack(videoModeResolutionLabel);
		videoModeLayout->Pack(videoModeResolution);
		videoModeLayout->Pack(videoModeSeparator);
		videoModeLayout->Pack(videoModeFullScreen);

		// Set up video mode - frame
		videoMode = sfg::Frame::Create("Video mode");
		videoMode->Add(videoModeLayout);

		// Create main layout table
		mainLayout = sfg::Table::Create();
		mainLayout->Attach(videoMode, sf::Rect<sf::Uint32>(0, 0, 1, 1), sfg::Table::FILL | sfg::Table::EXPAND, sfg::Table::FILL, sf::Vector2f(5.0f, 5.0f));
	}

	void VideoSettingsPage::temp_populateCombo()
	{
		auto modes = sf::VideoMode::getFullscreenModes();
		
		for (auto it = modes.begin(); it != modes.end(); it++)
		{
			std::stringstream stream;
			stream<<it->width<<" x "<<it->height<<" x "<<it->bitsPerPixel;

			videoModeResolution->AppendItem(stream.str());
		}
	}

	sfg::Widget::Ptr VideoSettingsPage::getTitleWidget()
	{
		return title;
	}

	sfg::Widget::Ptr VideoSettingsPage::getMainWidget()
	{
		return mainLayout;
	}
}