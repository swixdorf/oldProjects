object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 243
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'create'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 176
    Top = 8
    Width = 185
    Height = 227
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object post: TButton
    Left = 8
    Top = 80
    Width = 75
    Height = 25
    Caption = 'post'
    TabOrder = 2
    OnClick = postClick
  end
end