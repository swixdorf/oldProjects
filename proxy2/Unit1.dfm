object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 429
  ClientWidth = 800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ClientSocket1: TClientSocket
    Active = True
    Address = '85.153.31.132'
    ClientType = ctNonBlocking
    Port = 9999
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 8
  end
end
