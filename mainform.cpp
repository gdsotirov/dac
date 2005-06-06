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

/* Title: Main form
 * Description: Implementation of the main form
 * File: mainform.cpp
 * ---
 * Written by George D. Sotirov <gdsotirov@dir.bg>
 * $Id: mainform.cpp,v 1.4 2005/06/06 17:25:16 gsotirov Exp $
 */

#include <vcl.h>
#include <math.h>

#include "mainform.h"
#include "enter_data.h"
#include "about.h"
#include "func.h"

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent * Owner) : p(1), TForm(Owner) {

}
void __fastcall TMainForm::FileExitClick(TObject *) {
  if ( MessageDlg("Are you sure you want to exit?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes ) {
    this->Close();
  }
}

void __fastcall TMainForm::EditEnterDataClick(TObject *) {
  EnterData = new TEnterData(this);
  EnterData->ShowModal();
}

void __fastcall TMainForm::HelpAboutClick(TObject *) {
  AboutBox = new TAboutBox(this);
  AboutBox->ShowModal();
}

void __fastcall TMainForm::FormCloseQuery(TObject *, bool &CanClose) {
  CanClose = MessageDlg("Are you sure you want to exit?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes;
}

void TMainForm::ClearPresentation(void) {
  REResults->Lines->Clear();
  ChartAD->Series[0]->Clear();
  ChartPD->Series[0]->Clear();
  for ( int i = 0; i < ChartADC->SeriesCount(); ++i)
    ChartADC->Series[i]->Clear();
  for ( int i = 0; i < ChartDND->SeriesCount(); ++i)
    ChartDND->Series[i]->Clear();
}

void TMainForm::CalculateAndPlot(void) {
  AnsiString line;

  // Calculate the width of the main lobe
  Gmax = pow(10, Gdb/10);
  line.sprintf("2 * tita_05_y = 2 * tita_06_x = 2 * tita_05");
  REResults->Lines->Add(line);
  tita_05 = sqrt(8500/Gmax);
  tita_05_rad = deg2rad(tita_05);
  line.sprintf("tita_05 = %f deg = %f rad", tita_05, tita_05_rad);
  REResults->Lines->Add(line);
  l1 = M_C / f1_min;
  l2 = M_C / f1_max;
  l0 = M_C / ((f1_min + f1_max) / 2);
  // Calculate the diameter
  D = 1.47 * (l1/(2*tita_05_rad));
  line.sprintf("D = %f m", D);
  REResults->Lines->Add(line);

  unsigned int i = 0;
  p = 1;
  while ( bi <= b_tbl[i] && i < b_tbl_len ) {
    p += 1;
    ++i;
  }

  line.sprintf("p = %d", p);
  REResults->Lines->Add(line);

  // Create Amplitude Distribution chart
  // Determine focal distance
  f = D/2;
  double n = (f/2)/(l0/2);
  f = ceil(n) * l0;
  line.sprintf("f = %f m", f);
  REResults->Lines->Add(line);
  double psi_0 = 2 * rad2deg(atan((D/2)/2*f));
  line.sprintf("psi_0 = %f deg", psi_0);
  REResults->Lines->Add(line);

  double step = 0.5*D/10;
  for ( int i = 0; i <= 10; ++i ) {
    double x = i * step;
    double y = f_x(x, D, p);
    double psi = f_psi(x, f);
    double psi_deg = rad2deg(psi);
    AnsiString lbl;
    lbl.sprintf("%1.2f", x);
    ChartAD->Series[0]->AddXY(x, y, lbl, clRed);
    ChartPD->Series[0]->AddXY(x, psi_deg, lbl, clBlue);
    lbl.sprintf("%1.2f", psi_deg);
    ChartADC->Series[0]->AddXY(psi_deg, y, lbl);
    for ( int j = 1; j < 8; ++j ) {
      double res = pow(cos(psi), j);
      ChartADC->Series[j]->AddXY(psi_deg, res, lbl);
    }
  }

  step = 0.05;
  for ( int i = 0; i < 3; ++i ) {
    double tita = step;
    while ( tita <= 90.0 ) {
      double l = 0.0;
      double y = 0.0;
      AnsiString lbl;

      switch ( i ) {
        case 0: l = l0; break;
        case 1: l = l1; break;
        case 2: l = l2; break;
      }
      double U = (M_PI * D * sin(deg2rad(tita))) / l;
      if ( U > 10 )
        y = fabs(f_tita_2(tita, U));
      else
        y = fabs(f_tita_1(U));
      tita += step;

      lbl.sprintf("%1.2f", tita);
       ChartDND->Series[i]->AddXY(U, y, lbl);
     }
   }
}

void __fastcall TMainForm::FormShow(TObject *) {
  Pages->ActivePage = TabSheet1;
}

void __fastcall TMainForm::CB_L0Click(TObject *) {
  ChartDND->Series[0]->Active = CB_L0->Checked;
}

void __fastcall TMainForm::CB_L1Click(TObject *) {
  ChartDND->Series[1]->Active = CB_L1->Checked;
}

void __fastcall TMainForm::CB_L2Click(TObject *) {
  ChartDND->Series[2]->Active = CB_L2->Checked;
}

void __fastcall TMainForm::OnDataChange(TMessage & Message) {
  if ( Message.Msg == MSG_DATACHANGE ) {
    ClearPresentation();
    CalculateAndPlot();
  }
}

