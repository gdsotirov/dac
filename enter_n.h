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

/* Title: Form for enter the value of n
 * Description: Definitions of the form
 * File: enter_n.h
 * ---
 * Written by George D. Sotirov <gdsotirov@dir.bg>
 * $Id: enter_n.h,v 1.1 2005/06/06 19:53:43 gsotirov Exp $
 */

#ifndef enter_nH
#define enter_nH

#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>

class TEnterN : public TForm {
__published:        
  TButton *OKBtn;
  TLabel *LblHelp;
  TLabel *LblN;
  TEdit *EdN;
  void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
public:
  virtual __fastcall TEnterN(TComponent* AOwner);
};

extern PACKAGE TEnterN * EnterN;

#endif

