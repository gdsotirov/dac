//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
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

const double b_tbl[] = {-24.6, -30.6, -38.2};
const long b_tbl_len = 3;

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu;
        TMenuItem *FileMenu;
        TMenuItem *FileExit;
        TMenuItem *EditMenu;
        TMenuItem *EditEnterData;
        TMenuItem *HelpMenu;
        TMenuItem *HelpAbout;
        TStatusBar *StatusBar;
        TPageControl *Pages;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TChart *ChartAD;
        TChart *ChartADC;
        TChart *ChartDND;
        TChart *ChartPD;
        TLineSeries *Series1;
        TTabSheet *TabSheet5;
        TRichEdit *REResults;
        TButton *BtnCalculate;
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
        void __fastcall FileExitClick(TObject *Sender);
        void __fastcall EditEnterDataClick(TObject *Sender);
        void __fastcall HelpAboutClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BtnCalculateClick(TObject *Sender);
        void __fastcall TabSheet5Show(TObject *Sender);
        void __fastcall CB_L0Click(TObject *Sender);
        void __fastcall CB_L1Click(TObject *Sender);
        void __fastcall CB_L2Click(TObject *Sender);
private:
        // Input parameters
        double f1_min;
        double f1_max;
        double Gdb;
        double bi;
        double v;
        // Calculated values
        bool data_ready;
        double Gmax;
        double tita_05;
        double tita_05_rad;
        double l1;
        double l2;
        double l0;
        double D;
        unsigned int p;
        double f;
public:		// User declarations
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
        inline void set_data_ready(bool value) {
          data_ready = value;
        }
        inline bool is_data_ready(void) {
          return data_ready;
        }
        void CalculateAndPlot(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
