object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 402
  ClientWidth = 670
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 56
    Top = 24
    Width = 505
    Height = 249
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 176
    Top = 281
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 352
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 312
    Top = 312
    Width = 75
    Height = 25
    Caption = 'edit'
    TabOrder = 4
    OnClick = Button4Click
  end
  object HSServer: TServerSocket
    Active = False
    Port = 3322
    ServerType = stNonBlocking
    OnClientError = HSServerClientError
    Left = 568
    Top = 8
  end
  object HSClinet: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctBlocking
    Port = 3322
    OnError = HSClinetError
    Left = 600
    Top = 8
  end
  object Timer1: TTimer
    Left = 568
    Top = 328
  end
end
