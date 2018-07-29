object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 470
  ClientWidth = 713
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
    Left = 8
    Top = 8
    Width = 329
    Height = 217
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '31.210.68.131'
    ClientType = ctNonBlocking
    Port = 15333
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnError = ClientSocket1Error
    Left = 384
    Top = 8
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 448
    Top = 8
  end
end
