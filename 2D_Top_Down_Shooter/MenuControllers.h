
namespace PredefinedMenus
{

	void MainMenuSetup(Menu * M)
	{
		M->AddMenuItem("Start Game", Types::STATIC_TEXT);
		M->AddMenuItem("Options", Types::OPTION);
		M->AddMenuItem("Quit", Types::STATIC_TEXT);
	}

	void MainMenuController(Menu * M)
	{


	}

};