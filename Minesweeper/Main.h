#pragma once
#include "wx/wx.h"


class Main : public wxFrame
{
public:
	Main();
	~Main();

	int mFieldWidth = 10;
	int mFieldHeight = 10;
	wxButton** btn;

	int* mField = nullptr;
	bool mFirstClick = true;
public:
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

