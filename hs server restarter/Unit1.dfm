object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 405
  ClientWidth = 776
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 185
    Height = 201
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object ListBox1: TListBox
    Left = 360
    Top = 8
    Width = 169
    Height = 97
    ItemHeight = 13
    TabOrder = 1
  end
  object ListBox2: TListBox
    Left = 535
    Top = 8
    Width = 66
    Height = 97
    ItemHeight = 13
    TabOrder = 2
  end
  object ListBox3: TListBox
    Left = 607
    Top = 8
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 3
  end
  object Button1: TButton
    Left = 376
    Top = 160
    Width = 75
    Height = 25
    Caption = 'kapa'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Interval = 5000
    OnTimer = Timer1Timer
    Left = 200
    Top = 8
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 30000
    OnTimer = Timer2Timer
    Left = 232
    Top = 8
  end
  object Timer3: TTimer
    Interval = 5000
    OnTimer = Timer3Timer
    Left = 272
    Top = 8
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 15000
    OnTimer = Timer4Timer
    Left = 280
    Top = 104
  end
end
