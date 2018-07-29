object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 469
  ClientWidth = 908
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
    Left = 88
    Top = 72
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 279
    Top = 72
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Memo3: TMemo
    Left = 480
    Top = 72
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object ServerSocket1: TServerSocket
    Active = True
    Port = 18001
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket3ClientConnect
    OnClientDisconnect = ServerSocket3ClientDisconnect
    OnClientRead = ServerSocket3ClientRead
    OnClientError = ServerSocket3ClientError
    Left = 248
    Top = 8
  end
  object ServerSocket2: TServerSocket
    Tag = 1
    Active = True
    Port = 18002
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket3ClientConnect
    OnClientDisconnect = ServerSocket3ClientDisconnect
    OnClientRead = ServerSocket3ClientRead
    OnClientError = ServerSocket3ClientError
    Left = 360
    Top = 8
  end
  object ServerSocket3: TServerSocket
    Tag = 3
    Active = True
    Port = 18003
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket3ClientConnect
    OnClientDisconnect = ServerSocket3ClientDisconnect
    OnClientRead = ServerSocket3ClientRead
    OnClientError = ServerSocket3ClientError
    Left = 496
    Top = 8
  end
end
