/* DAC - Dish Antenna Calculator
 * Copyright (C) 2005 Georgi D. Sotirov, Boayn D. Sotirov
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

/* Title: Form for enter the value of n
 * Description: Implementation of the form
 * File: enter_n.cpp
 * ---
 * Written by Georgi D. Sotirov <gdsotirov@gmail.com>
 */

#include <vcl.h>

#include "enter_n.h"
#include "mainform.h"

#pragma hdrstop
#pragma resource "*.dfm"

TEnterN * EnterN;

__fastcall TEnterN::TEnterN(TComponent * AOwner) : TForm(AOwner) {
}

void __fastcall TEnterN::OKBtnClick(TObject *) {
  int n = EdN->Text.ToInt();

  if ( n >= 1 && n <= 7 ) {
    MainForm->set_n(n);
    Close();
  }
  else
    MessageDlg("The value of n should be between 1 and 7!", mtError, TMsgDlgButtons() << mbOK, 0);
}

void __fastcall TEnterN::FormShow(TObject *) {
  EdN->SetFocus();
}


