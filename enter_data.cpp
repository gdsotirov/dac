/* DND - a D.N.D. grapher utility
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

/* Title: Enter data frame
 * Description: The implementation of the window for entering input parameters
 * File: enter_data.cpp
 * ---
 * Written by George D. Sotirov <gdsotirov@dir.bg>
 * $Id: enter_data.cpp,v 1.5 2005/06/06 19:53:43 gsotirov Exp $
 */

#include <vcl.h>
#include <stdlib.h>
#include <cmath>
#pragma hdrstop

#include "enter_data.h"
#include "mainform.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TEnterData *EnterData;

__fastcall TEnterData::TEnterData(TComponent * Owner) : TForm(Owner) {
}

void __fastcall TEnterData::BtnCancelClick(TObject *) {
  this->Close();
}

void __fastcall TEnterData::BtnApplyClick(TObject *) {
  double f1_min = this->f1_min->Text.ToDouble();
  double f1_max = this->f1_max->Text.ToDouble();
  double gmax = this->gmax->Text.ToDouble();
  double bi = this->bi->Text.ToDouble();
  double v = this->v->Text.ToDouble();

  if ( f1_max <= f1_min ) {
    MessageDlg("Frequency range maximum is bellow the minimum! Plese, correct the values.", mtError, TMsgDlgButtons() << mbOK, 0);
    this->f1_max->SetFocus();
    return;
  }

  if ( f1_min < 3.9 || f1_min > 18.0 ) {
    MessageDlg("The frequency range minimum is not in the allowed interval from 3.9 GHz to 18 GHz!", mtError, TMsgDlgButtons() << mbOK, 0);
    this->f1_min->SetFocus();
    return;
  }

  if ( f1_max < 3.9 || f1_max > 18.0 ) {
    MessageDlg("The frequency range maximum is not in the allowed interval from 3.9 GHz to 18 GHz!", mtError, TMsgDlgButtons() << mbOK, 0);
    this->f1_max->SetFocus();
    return;
  }

  if ( gmax < 10.0 || gmax > 70.0 ) {
    MessageDlg("The Gmax value is not in the allowed interval from 10 dB to 70 db!", mtError, TMsgDlgButtons() << mbOK, 0);
    this->gmax->SetFocus();
    return;
  }

  if ( bi >= b_tbl[0] ) {
    String msg;
    msg.sprintf("The value of bi must be lower than %f dB!", b_tbl[0]);
    MessageDlg(msg, mtError, TMsgDlgButtons() << mbOK, 0);
    this->bi->SetFocus();
    return;
  }

  if ( v < 0 || v > 1 ) {
    MessageDlg("The value of v is not in the allowed interval from 0 to 1!", mtError, TMsgDlgButtons() << mbOK, 0);
    this->v->SetFocus();
    return;
  }

  MainForm->set_freqency_range(f1_min * 1e9, f1_max * 1e9);
  MainForm->set_gdb(gmax);
  MainForm->set_bi(bi);
  MainForm->set_v(v);

  SendMessage(MainForm->Handle, MSG_DATACHANGE, 0, (int)(this));
  Close();
}

void __fastcall TEnterData::FormShow(TObject *) {
  f1_min->Text = AnsiString(MainForm->get_f1_min()/1e9);
  f1_max->Text = AnsiString(MainForm->get_f1_max()/1e9);
  gmax->Text = AnsiString(MainForm->get_gdb());
  bi->Text = AnsiString(MainForm->get_bi());
  v->Text = AnsiString(MainForm->get_v());
  f1_min->SetFocus();
}

