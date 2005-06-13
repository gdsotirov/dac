object EnterData: TEnterData
  Left = 338
  Top = 536
  BorderStyle = bsDialog
  Caption = 'Input parameters'
  ClientHeight = 253
  ClientWidth = 174
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Microsoft Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 12
    Top = 112
    Width = 30
    Height = 13
    Caption = 'G max'
  end
  object Label4: TLabel
    Left = 12
    Top = 140
    Width = 8
    Height = 13
    Caption = 'bi'
  end
  object Label5: TLabel
    Left = 12
    Top = 168
    Width = 6
    Height = 13
    Caption = 'v'
  end
  object Label8: TLabel
    Left = 132
    Top = 112
    Width = 13
    Height = 13
    Caption = 'dB'
  end
  object Label9: TLabel
    Left = 132
    Top = 140
    Width = 13
    Height = 13
    Caption = 'dB'
  end
  object GBFreqRange: TGroupBox
    Left = 4
    Top = 8
    Width = 165
    Height = 85
    Caption = 'Freqency range'
    TabOrder = 0
    object Label1: TLabel
      Left = 12
      Top = 28
      Width = 17
      Height = 13
      Caption = 'Min'
    end
    object Label2: TLabel
      Left = 12
      Top = 52
      Width = 20
      Height = 13
      Caption = 'Max'
    end
    object Label6: TLabel
      Left = 128
      Top = 28
      Width = 21
      Height = 13
      Caption = 'GHz'
    end
    object Label7: TLabel
      Left = 128
      Top = 52
      Width = 21
      Height = 13
      Caption = 'GHz'
    end
    object f1_min: TEdit
      Left = 48
      Top = 24
      Width = 73
      Height = 21
      TabOrder = 0
    end
    object f1_max: TEdit
      Left = 48
      Top = 48
      Width = 73
      Height = 21
      TabOrder = 1
    end
  end
  object gmax: TEdit
    Left = 52
    Top = 108
    Width = 73
    Height = 21
    TabOrder = 1
  end
  object bi: TEdit
    Left = 52
    Top = 136
    Width = 73
    Height = 21
    TabOrder = 2
  end
  object v: TEdit
    Left = 52
    Top = 164
    Width = 73
    Height = 21
    TabOrder = 3
  end
  object BtnApply: TButton
    Left = 8
    Top = 220
    Width = 75
    Height = 25
    Caption = 'Apply'
    Default = True
    TabOrder = 4
    OnClick = BtnApplyClick
  end
  object BtnCancel: TButton
    Left = 92
    Top = 220
    Width = 75
    Height = 25
    Caption = 'Cancel'
    TabOrder = 5
    OnClick = BtnCancelClick
  end
end
