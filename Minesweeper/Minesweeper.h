#pragma once

#include "wx/wx.h"
#include "Main.h"


class Minesweeper: public wxApp
{
public:

	Minesweeper();
	~Minesweeper();



private:
	Main* frame = nullptr;

public:
	virtual bool OnInit();
};

