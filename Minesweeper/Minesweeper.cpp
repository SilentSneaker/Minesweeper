#include "Minesweeper.h"


wxIMPLEMENT_APP(Minesweeper);

Minesweeper::Minesweeper()
{

}
Minesweeper::~Minesweeper()
{

}
bool Minesweeper::OnInit()
{
	frame = new Main();
	frame->Show();
	return true;
}