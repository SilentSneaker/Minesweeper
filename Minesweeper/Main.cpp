#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_BUTTON(1, OnButtonClicked)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr,wxID_ANY, "Minesweeper")
{
	btn = new wxButton*[mFieldWidth * mFieldHeight];
	wxGridSizer* grid = new wxGridSizer(mFieldWidth, mFieldHeight, 0, 0);

	mField = new int[mFieldWidth * mFieldHeight];
	for (int x = 0; x < mFieldWidth; x++)
	{
		for (int y = 0; y < mFieldHeight; y++)
		{
			btn[y * mFieldWidth + x] = new wxButton(this, 10000 + (y * mFieldWidth + x));
			grid->Add(btn[y * mFieldWidth + x], 1, wxEXPAND | wxALL);
			btn[y * mFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::OnButtonClicked, this);
			mField[y * mFieldWidth + x] = 0;
		
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}

Main::~Main()
{
	delete[]btn;
}

void Main::OnButtonClicked(wxCommandEvent& evt)
{
	// Get coordinate of button in field array
	int x = (evt.GetId() - 10000) % mFieldWidth;
	int y = (evt.GetId() - 10000) / mFieldWidth;

	if (mFirstClick)
	{
		int mines = 30;
		while (mines)
		{
			int rx = rand() % mFieldWidth;
			int ry = rand() % mFieldHeight;
			if (mField[ry * mFieldWidth + rx] == 0 && rx != x && ry != y)
			{
				mField[ry * mFieldWidth + rx] = -1;
				mines--;
			}
			
		}
		mFirstClick = false;
		
	}
	// Disable button preventing it from being pressed again
	btn[y * mFieldWidth + x]->Enable(false);

	if (mField[y * mFieldWidth + x] == -1)
	{
		wxMessageBox("BOOOOMM  !! GAME OVER	!");

		//Reset Game
		mFirstClick = true;
		for (int x = 0; x < mFieldWidth; x++)
		{
			for (int y = 0; y < mFieldHeight; y++)
			{
				mField[y * mFieldWidth + x] = 0;
				btn[y * mFieldWidth + x]->SetLabel("");
				btn[y * mFieldWidth + x]->Enable(true);
			}
		}
	}
	else
	{
		// Count neighboring mines
		int mCount = 0;
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < mFieldWidth && y + j >= 0 && y + j < mFieldHeight)
				{
					if (mField[(y + j) * mFieldWidth + (x + i)] == -1)
					{
						mCount++;
					}
				}
			}
		}

		if (mCount != 0)
		{
			btn[y * mFieldWidth + x]->SetLabel(std::to_string(mCount));
		}

	}

	evt.Skip();
}



