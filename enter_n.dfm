object EnterN: TEnterN
  Left = 254
  Top = 614
  BorderStyle = bsDialog
  Caption = 'Enter n'
  ClientHeight = 139
  ClientWidth = 269
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LblHelp: TLabel
    Left = 4
    Top = 4
    Width = 261
    Height = 53
    AutoSize = False
    Caption = 
      'Please, look at the Amplitude Distribution Comparison graph and ' +
      'choose the value of n. The value of n should be the power of the' +
      ' trogonometric function which best aproximates f(x).'
    WordWrap = True
  end
  object LblN: TLabel
    Left = 4
    Top = 72
    Width = 6
    Height = 13
    Caption = 'n'
  end
  object OKBtn: TButton
    Left = 103
    Top = 108
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object EdN: TEdit
    Left = 36
    Top = 68
    Width = 77
    Height = 21
    TabOrder = 1
  end
end
