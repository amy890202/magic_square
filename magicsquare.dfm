object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Magic Square by '#29579#26144#32092' 20191015 ver 0.2'
  ClientHeight = 385
  ClientWidth = 651
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 651
    Height = 145
    Align = alTop
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 1
      Top = 141
      Width = 649
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 1
      ExplicitWidth = 143
    end
    object Label1: TLabel
      Left = 24
      Top = 27
      Width = 17
      Height = 13
      Caption = 'n ='
    end
    object Label2: TLabel
      Left = 64
      Top = 51
      Width = 76
      Height = 13
      Caption = 'n should be odd'
    end
    object Edit1: TEdit
      Left = 47
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '3'
    end
    object Button1: TButton
      Left = 65
      Top = 91
      Width = 75
      Height = 25
      Caption = 'Magic Square'
      TabOrder = 1
      OnClick = Button1Click
    end
    object GroupBox1: TGroupBox
      Left = 424
      Top = 24
      Width = 185
      Height = 105
      Caption = 'direction'
      TabOrder = 2
      object RadioButton1: TRadioButton
        Left = 3
        Top = 25
        Width = 113
        Height = 17
        Caption = 'left-top'
        TabOrder = 0
      end
      object RadioButton2: TRadioButton
        Left = 3
        Top = 60
        Width = 113
        Height = 17
        Caption = 'left-down'
        TabOrder = 1
      end
      object RadioButton3: TRadioButton
        Left = 96
        Top = 25
        Width = 113
        Height = 17
        Caption = 'right-top'
        TabOrder = 2
      end
      object RadioButton4: TRadioButton
        Left = 96
        Top = 60
        Width = 113
        Height = 17
        Caption = 'right-down'
        TabOrder = 3
      end
    end
    object GroupBox2: TGroupBox
      Left = 232
      Top = 24
      Width = 185
      Height = 105
      Caption = 'start'
      TabOrder = 3
      object RadioButton5: TRadioButton
        Left = 69
        Top = 23
        Width = 113
        Height = 17
        Caption = #19978
        TabOrder = 0
      end
      object RadioButton6: TRadioButton
        Left = 23
        Top = 48
        Width = 113
        Height = 17
        Caption = #24038
        TabOrder = 1
      end
      object RadioButton7: TRadioButton
        Left = 134
        Top = 48
        Width = 113
        Height = 17
        Caption = #21491
        TabOrder = 2
      end
      object RadioButton8: TRadioButton
        Left = 76
        Top = 83
        Width = 113
        Height = 17
        Caption = #19979
        TabOrder = 3
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 145
    Width = 651
    Height = 240
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 649
      Height = 238
      ActivePage = TabSheet4
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'Memo(align)'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 641
          Height = 210
          Align = alClient
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'ListBox(sum)'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object ListBox1: TListBox
          Left = 0
          Top = 0
          Width = 641
          Height = 210
          Align = alClient
          ItemHeight = 13
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'StringGrid'
        ImageIndex = 2
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object StringGrid1: TStringGrid
          Left = 0
          Top = 0
          Width = 641
          Height = 210
          Align = alClient
          TabOrder = 0
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'memo(no align)'
        ImageIndex = 3
        object Memo2: TMemo
          Left = 0
          Top = 0
          Width = 641
          Height = 210
          Align = alClient
          Lines.Strings = (
            'Memo2')
          TabOrder = 0
        end
      end
    end
  end
end
