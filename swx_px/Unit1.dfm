object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 512
  ClientWidth = 727
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Kapat: TButton
    Left = 256
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Kapat'
    TabOrder = 0
    OnClick = KapatClick
  end
  object Ac: TButton
    Left = 175
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Ac'
    TabOrder = 1
    OnClick = AcClick
  end
  object srvList: TCheckListBox
    Left = 8
    Top = 8
    Width = 161
    Height = 329
    ItemHeight = 13
    Items.Strings = (
      '192.168.1.116:15001'
      '192.168.1.116:15002'
      '192.168.1.116:15003')
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 8
    Top = 343
    Width = 711
    Height = 161
    TabOrder = 3
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    Left = 336
    Top = 8
  end
end
