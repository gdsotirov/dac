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

/* Title: Enter data frame
 * Description: The definitions of the window for entering input parameters
 * File: enter_data.h
 * ---
 * Written by Georgi D. Sotirov <gdsotirov@gmail.com>
 */

#ifndef enter_dataH
#define enter_dataH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

class TEnterData : public TForm {
__published: // IDE-managed Components
  TGroupBox * GBFreqRange;
  TEdit * f1_min;
  TLabel * Label1;
  TLabel * Label2;
  TEdit * f1_max;
  TLabel * Label3;
  TEdit * gmax;
  TLabel * Label4;
  TEdit * bi;
  TLabel * Label5;
  TEdit * v;
  TButton * BtnApply;
  TButton * BtnCancel;
  TLabel * Label6;
  TLabel * Label7;
  TLabel * Label8;
  TLabel * Label9;
  void __fastcall BtnCancelClick(TObject * Sender);
  void __fastcall BtnApplyClick(TObject * Sender);
  void __fastcall FormShow(TObject * Sender);
public:
  __fastcall TEnterData(TComponent * Owner);
};

extern PACKAGE TEnterData * EnterData;

#endif

