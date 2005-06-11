/* DND - a D.N.D. grapher utility
 * Copyright (C) 2005 Georgi D. Sotirov, Boyan D. Sotirov
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/* Title: DND
 * Description: Main programm
 * File: dnd.cpp
 * ---
 * Written by George D. Sotirov <gdsotirov@dir.bg>
 * $Id: dac.cpp,v 1.6 2005/06/11 18:41:10 gsotirov Exp $
 */

#include <vcl.h>

#pragma hdrstop

USEFORM("mainform.cpp", MainForm);
USEFORM("enter_data.cpp", EnterData);
USEFORM("about.cpp", AboutBox);
USEFORM("enter_n.cpp", EnterN);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
  try {
    Application->Initialize();
    Application->Title = "DAC";
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TEnterData), &EnterData);
                 Application->CreateForm(__classid(TEnterN), &EnterN);
                 Application->Run();
  }
  catch (Exception &exception) {
    Application->ShowException(&exception);
  }
  catch (...) {
    try {
      throw Exception("");
    }
    catch (Exception &exception) {
      Application->ShowException(&exception);
    }
  }

  return 0;
}

