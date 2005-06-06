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

/* Title: AboutBox
 * Description: About box definitions
 * File: about.h
 * ---
 * Written by George D. Sotirov <gdsotirov@dir.bg>
 * $Id: about.h,v 1.4 2005/06/06 17:25:16 gsotirov Exp $
 */

#ifndef aboutH
#define aboutH

#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>

class TAboutBox : public TForm {
__published:
  TPanel *Panel1;
  TImage *ProgramIcon;
  TLabel *ProductName;
  TLabel *Version;
  TLabel *Copyright;
  TLabel *Comments;
  TButton *OKButton;
  void __fastcall OKButtonClick(TObject *Sender);
public:
  virtual __fastcall TAboutBox(TComponent* AOwner);
};

extern PACKAGE TAboutBox *AboutBox;

#endif

