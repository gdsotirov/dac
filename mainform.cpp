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
 * $Id: mainform.cpp,v 1.6 2005/06/08 17:09:17 gsotirov Exp $
 */

#include <vcl.h>
#include <cmath>

#include "mainform.h"
#include "enter_data.h"
#include "enter_n.h"
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

void TMainForm::CalculateAndPresentate(void) {
  AnsiString line;

  // Calculate the width of the main lobe
  Gmax = pow(10, Gdb/10);
  line.sprintf("2 * tita 05y = 2 * tita 06x = 2 * tita 05");
  REResults->Lines->Add(line);
  tita_05 = sqrt(8500/Gmax);
  tita_05_rad = deg2rad(tita_05);
  line.sprintf("tita 05 = %f deg = %f rad", tita_05, tita_05_rad);
  REResults->Lines->Add(line);
  l1 = M_C / f1_min;
  l2 = M_C / f1_max;
  l0 = M_C / ((f1_min + f1_max) / 2);
  // Calculate the diameter
  D = 1.47 * (l1/(2*tita_05_rad));
  line.sprintf("D = %f m", D);
  REResults->Lines->Add(line);
  Lbl_D->Caption = line.sprintf("D = %1.2f m", D);

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
  Lbl_f->Caption = line.sprintf("f = %1.2f m", f);

  double psi_0 = 2 * rad2deg(atan((D/2)/2*f));
  line.sprintf("psi 0 = %f deg", psi_0);
  REResults->Lines->Add(line);
  Lbl_Psi0->Caption = line.sprintf("psi 0 = %1.2f deg", psi_0);

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

   REResults->Lines->Add("");
   line.sprintf("Feeder parameters:");
   REResults->Lines->Add(line);

   Pages->ActivePage = TS_ADC;
   PagesChange(this);
   EnterN = new TEnterN(this);
   EnterN->ShowModal();

   double psi_07 = acos(pow(0.707, 1/(double)get_n()));
   double psi_07_deg = rad2deg(psi_07);
   line.sprintf("psi 07 = %f rad = %f deg", psi_07, psi_07_deg);
   REResults->Lines->Add(line);

   double Dr = 60 * l0/psi_07_deg;
   line.sprintf("D rupor = %f m", Dr);
   REResults->Lines->Add(line);

   double R = (Dr*Dr)/(2.4 * l0) - 0.15 * l0;
   line.sprintf("R = %f m", R);
   REResults->Lines->Add(line);
   Lbl_R->Caption = line.sprintf("R = %1.2f m", R);

   double G = 5 * pow(Dr/l0, 2);
   double G_db = 10 * log10(G);
   line.sprintf("G = %1.1f dB", G_db);
   REResults->Lines->Add(line);

   double pcalc = G / (4 * M_PI * f); /* precalculated value */
   double p1 = l1 * pcalc;
   double p0 = l0 * pcalc;
   double p2 = l2 * pcalc;
   line.sprintf("p1 = %f", p1);
   REResults->Lines->Add(line);
   line.sprintf("p0 = %f", p0);
   REResults->Lines->Add(line);
   line.sprintf("p2 = %f", p2);
   REResults->Lines->Add(line);

   double kbv1 = (1 - p1) / (1 + p1);
   double kbv0 = (1 - p0) / (1 + p0);
   double kbv2 = (1 - p2) / (1 + p2);
   line.sprintf("kbv1 = %f", kbv1);
   REResults->Lines->Add(line);
   line.sprintf("kbv0 = %f", kbv0);
   REResults->Lines->Add(line);
   line.sprintf("kbv2 = %f", kbv2);
   REResults->Lines->Add(line);
}

void __fastcall TMainForm::FormShow(TObject *) {
  Pages->ActivePage = TS_AD;
  PagesChange(this);
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
    CalculateAndPresentate();
  }
}

void __fastcall TMainForm::PagesChange(TObject *) {
  MainForm->Caption = "DND - " + Pages->ActivePage->Caption;
}

