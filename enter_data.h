#ifndef enter_dataH
#define enter_dataH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

class TEnterData : public TForm {
__published: // IDE-managed Components
  TGroupBox *GBFreqRange;
  TEdit *f1_min;
  TLabel *Label1;
  TLabel *Label2;
  TEdit *f1_max;
  TLabel *Label3;
  TEdit *gmax;
  TLabel *Label4;
  TEdit *bi;
  TLabel *Label5;
  TEdit *v;
  TButton *BtnApply;
  TButton *BtnCancel;
  TLabel *Label6;
  TLabel *Label7;
  TLabel *Label8;
  TLabel *Label9;
  void __fastcall BtnCancelClick(TObject *Sender);
  void __fastcall BtnApplyClick(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
public:
  __fastcall TEnterData(TComponent* Owner);
};

extern PACKAGE TEnterData *EnterData;

#endif
