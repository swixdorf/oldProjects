object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 230
  ClientWidth = 432
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
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'Edit1'
    OnKeyPress = Edit1KeyPress
  end
  object Memo1: TMemo
    Left = 8
    Top = 35
    Width = 145
    Height = 190
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ListBox1: TListBox
    Left = 159
    Top = 35
    Width = 121
    Height = 190
    ItemHeight = 13
    TabOrder = 2
    OnClick = ListBox1Click
  end
  object ComboBox1: TComboBox
    Left = 159
    Top = 8
    Width = 121
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Text = 'ComboBox1'
    OnChange = ComboBox1Change
    Items.Strings = (
      'ares'
      'dies'
      'xigenon'
      'beramus'
      'cypher'
      'olympia'
      'edana'
      'manes'
      'patos'
      'logos'
      'ronark'
      'girakon'
      'akara'
      'c-e'
      'c-w'
      'io'
      'kro')
  end
  object Button1: TButton
    Left = 286
    Top = 120
    Width = 75
    Height = 25
    Caption = 'ekle'
    TabOrder = 4
    OnClick = Button1Click
  end
end