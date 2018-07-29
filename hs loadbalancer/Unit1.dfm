object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 450
  ClientWidth = 888
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 233
    Top = 8
    Width = 185
    Height = 193
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 152
    Top = 48
    Width = 75
    Height = 25
    Caption = 'kapa'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 152
    Top = 79
    Width = 75
    Height = 25
    Caption = 'kapa'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 440
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button3'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    Left = 521
    Top = 8
    Width = 121
    Height = 193
    ItemHeight = 13
    TabOrder = 4
  end
  object CustomerServer: TServerSocket
    Active = True
    Port = 15000
    ServerType = stNonBlocking
    OnClientConnect = CustomerServerClientConnect
    Left = 16
    Top = 8
  end
  object MinerServer: TServerSocket
    Tag = 1
    Active = True
    Port = 15001
    ServerType = stNonBlocking
    OnClientConnect = MinerServerClientConnect
    Left = 64
    Top = 8
  end
  object ServerSocket3: TServerSocket
    Tag = 2
    Active = True
    Port = 15002
    ServerType = stNonBlocking
    Left = 112
    Top = 8
  end
  object ClientSocket1: TClientSocket
    Active = True
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 15001
    Left = 64
    Top = 40
  end
  object ClientSocket2: TClientSocket
    Active = True
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 15000
    Left = 16
    Top = 40
  end
end
