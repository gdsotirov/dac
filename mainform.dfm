object MainForm: TMainForm
  Left = 217
  Top = 330
  Width = 640
  Height = 479
  Caption = 'DND'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  DesignSize = (
    632
    433)
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 414
    Width = 632
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object Pages: TPageControl
    Left = 4
    Top = 4
    Width = 625
    Height = 408
    ActivePage = TabSheet3
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabIndex = 2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Amplitude Distribution'
      DesignSize = (
        617
        380)
      object ChartAD: TChart
        Left = 0
        Top = 4
        Width = 617
        Height = 376
        AnimatedZoom = True
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'Amplitude distribution - f(x)')
        LeftAxis.ExactDateTime = False
        LeftAxis.LabelStyle = talValue
        LeftAxis.TickOnLabelsOnly = False
        LeftAxis.Title.Caption = 'f(x)'
        Legend.LegendStyle = lsSeries
        Legend.TextStyle = ltsXValue
        Legend.Visible = False
        TopAxis.LabelStyle = talValue
        View3D = False
        BevelOuter = bvNone
        TabOrder = 0
        Anchors = [akLeft, akTop, akRight, akBottom]
        object Series1: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'f(x)'
          Dark3D = False
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Phase Distribution'
      ImageIndex = 1
      DesignSize = (
        617
        380)
      object ChartPD: TChart
        Left = 0
        Top = 4
        Width = 617
        Height = 376
        AnimatedZoom = True
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'Phase Distribution - f(Psi)')
        LeftAxis.LabelStyle = talValue
        LeftAxis.Title.Caption = 'Psi, deg'
        Legend.LegendStyle = lsSeries
        Legend.TextStyle = ltsXValue
        Legend.Visible = False
        View3D = False
        BevelOuter = bvNone
        TabOrder = 0
        Anchors = [akLeft, akTop, akRight, akBottom]
        object Series2: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Psi'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Amplitude Distribution Comparison'
      ImageIndex = 2
      DesignSize = (
        617
        380)
      object ChartADC: TChart
        Left = 0
        Top = 8
        Width = 617
        Height = 376
        AnimatedZoom = True
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'Amplitude Distribution Comparison')
        LeftAxis.LabelStyle = talValue
        LeftAxis.Title.Caption = 'cos(Psi)'
        Legend.LegendStyle = lsSeries
        View3D = False
        BevelOuter = bvNone
        TabOrder = 0
        Anchors = [akLeft, akTop, akRight, akBottom]
        object Series3: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'f(x)'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series4: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'cos'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series5: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clOlive
          Title = 'cos^2'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series6: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'cos^3'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series7: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clPurple
          Title = 'cos^4'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series8: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clMaroon
          Title = 'cos^5'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series9: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGray
          Title = 'cos^6'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series10: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clFuchsia
          Title = 'cos^7'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'D.N.D.'
      ImageIndex = 3
      DesignSize = (
        617
        380)
      object ChartDND: TChart
        Left = 0
        Top = 24
        Width = 617
        Height = 356
        AnimatedZoom = True
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        MarginTop = 5
        Title.Text.Strings = (
          'D.N.D.')
        LeftAxis.LabelStyle = talValue
        Legend.LegendStyle = lsSeries
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        TabOrder = 0
        Anchors = [akLeft, akTop, akRight, akBottom]
        object Series11: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'Lambda 0'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series12: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clGreen
          Title = 'Lambda 1'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
        object Series13: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clBlue
          Title = 'Lambda 2'
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          Pointer.Visible = False
          XValues.DateTime = False
          XValues.Name = 'X'
          XValues.Multiplier = 1
          XValues.Order = loAscending
          YValues.DateTime = False
          YValues.Name = 'Y'
          YValues.Multiplier = 1
          YValues.Order = loNone
        end
      end
      object CB_L0: TCheckBox
        Left = 16
        Top = 4
        Width = 109
        Height = 17
        Caption = 'Show Lambda 0'
        Checked = True
        State = cbChecked
        TabOrder = 1
        OnClick = CB_L0Click
      end
      object CB_L1: TCheckBox
        Left = 140
        Top = 4
        Width = 109
        Height = 17
        Caption = 'Show Lambda 1'
        Checked = True
        State = cbChecked
        TabOrder = 2
        OnClick = CB_L1Click
      end
      object CB_L2: TCheckBox
        Left = 264
        Top = 4
        Width = 109
        Height = 17
        Caption = 'Show Lambda 2'
        Checked = True
        State = cbChecked
        TabOrder = 3
        OnClick = CB_L2Click
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Results'
      ImageIndex = 4
      DesignSize = (
        617
        380)
      object REResults: TRichEdit
        Left = 4
        Top = 8
        Width = 609
        Height = 361
        Anchors = [akLeft, akTop, akRight, akBottom]
        BorderStyle = bsNone
        ReadOnly = True
        TabOrder = 0
      end
    end
  end
  object MainMenu: TMainMenu
    Left = 524
    object FileMenu: TMenuItem
      Caption = '&File'
      object FileExit: TMenuItem
        Caption = 'E&xit'
        OnClick = FileExitClick
      end
    end
    object EditMenu: TMenuItem
      Caption = '&Edit'
      object EditEnterData: TMenuItem
        Caption = 'Enter &data...'
        OnClick = EditEnterDataClick
      end
    end
    object HelpMenu: TMenuItem
      Caption = '&Help'
      object HelpAbout: TMenuItem
        Caption = '&About...'
        OnClick = HelpAboutClick
      end
    end
  end
end
