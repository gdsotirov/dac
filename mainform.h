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

/* Title: Main form
 * Description: Definitions of the main form
 * File: mainform.h
 * ---
 * Written by Georgi D. Sotirov <gdsotirov@gmail.com>
 */

#ifndef MainFormH
#define MainFormH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>

#define MSG_DATACHANGE (WM_APP + 100)
#define PROGNAME "DAC"

const double b_tbl[] = {-24.6, -30.6, -38.2};
const long b_tbl_len = 3;

class TMainForm : public TForm {
__published: // IDE-managed Components
  TMainMenu *MainMenu;
  TMenuItem *FileMenu;
  TMenuItem *FileExit;
  TMenuItem *EditMenu;
  TMenuItem *EditEnterData;
  TMenuItem *HelpMenu;
  TMenuItem *HelpAbout;
  TStatusBar *StatusBar;
  TPageControl *Pages;
  TTabSheet *TS_AD;
  TTabSheet *TS_PD;
  TTabSheet *TS_ADC;
  TTabSheet *TS_DND;
  TChart *ChartAD;
  TChart *ChartADC;
  TChart *ChartDND;
  TChart *ChartPD;
  TLineSeries *Series1;
  TTabSheet *TS_Results;
  TRichEdit *REResults;
  TLineSeries *Series2;
  TLineSeries *Series3;
  TLineSeries *Series4;
  TLineSeries *Series5;
  TLineSeries *Series6;
  TLineSeries *Series7;
  TLineSeries *Series8;
  TLineSeries *Series9;
  TLineSeries *Series10;
  TLineSeries *Series11;
  TLineSeries *Series12;
  TLineSeries *Series13;
  TCheckBox *CB_L0;
  TCheckBox *CB_L1;
  TCheckBox *CB_L2;
  TTabSheet *TS_ADraw;
  TImage *ImgAntenna;
  TLabel *Lbl_D;
  TLabel *Lbl_R;
  TLabel *Lbl_f;
  TLabel *Lbl_Psi0;
  TTabSheet *TS_TDraw;
  TImage *ImgTolerances;
  TScrollBar *SB_Tlrnce;
  TLabel *Lbl_Da1;
  TTabSheet *TS_FDraw;
  TImage *Image1;
  TLabel *Lbl_Da2;
  TLabel *Lbl_Fd;
  TLabel *Lbl_FR;
  TLabel *Lbl_Dr;
  TLabel *Lbl_Da3;
  TCheckBox *CB_ShowDB;
  TChart *ChartDND_dB;
  TLineSeries *LineSeries1;
  TLineSeries *LineSeries2;
  TLineSeries *LineSeries3;
  TMenuItem *HelpLang;
  TMenuItem *HelpLangENG;
  TMenuItem *HelpLangBG;
  TMenuItem *N1;
  void __fastcall FileExitClick(TObject *Sender);
  void __fastcall EditEnterDataClick(TObject *Sender);
  void __fastcall HelpAboutClick(TObject *Sender);
  void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall CB_L0Click(TObject *Sender);
  void __fastcall CB_L1Click(TObject *Sender);
  void __fastcall CB_L2Click(TObject *Sender);
  void __fastcall PagesChange(TObject *Sender);
  void __fastcall SB_TlrnceScroll(TObject *Sender, TScrollCode ScrollCode, int &ScrollPos);
  void __fastcall TS_TDrawShow(TObject *Sender);
  void __fastcall CB_ShowDBClick(TObject *Sender);
  void __fastcall HelpLangClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
private:
  // Input parameters
  double f1_min;
  double f1_max;
  double Gdb;
  double bi;
  double v;
  // Calculated values
  double Gmax;
  double tita_05;
  double tita_05_rad;
  double l1;
  double l2;
  double l0;
  double D;
  unsigned int p;
  double f;
  int n;
protected:
  void __fastcall OnDataChange(TMessage &Message);
  BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(MSG_DATACHANGE, TMessage, OnDataChange)
  END_MESSAGE_MAP(TControl)
public:
  __fastcall TMainForm(TComponent* Owner);
  inline double get_f1_min(void) const {
    return f1_min;
  }
  inline double get_f1_max(void) const {
    return f1_max;
  }
  inline double get_gdb(void) const {
    return Gdb;
  }
  inline double get_bi(void) const {
    return bi;
  }
  inline double get_v(void) const {
    return v;
  }
  inline int get_n(void) const {
    return n;
  }
  inline void set_freqency_range(double min, double max) {
    f1_min = min;
    f1_max = max;
  }
  inline void set_gdb(double value) {
    Gdb = value;
  }
  inline void set_bi(double value) {
    bi = value;
  }
  inline void set_v(double value) {
    v = value;
  }
  inline void set_n(int value) {
    n = value;
  }

  void ClearPresentation(void);
  void CalculateAndPresentate(void);
};

extern PACKAGE TMainForm * MainForm;

#endif

