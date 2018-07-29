object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 522
  ClientWidth = 761
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 162
    Top = 8
    Width = 417
    Height = 233
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Connect: TButton
    Left = 8
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Connect'
    TabOrder = 1
    OnClick = ConnectClick
  end
  object dbs: TMemo
    Left = 8
    Top = 24
    Width = 148
    Height = 217
    Lines.Strings = (
      'bot_program'
      'bot_other')
    TabOrder = 2
  end
  object UserCount: TButton
    Left = 8
    Top = 247
    Width = 75
    Height = 25
    Caption = 'UserCount'
    TabOrder = 3
    OnClick = UserCountClick
  end
  object UnUsedCode: TButton
    Left = 8
    Top = 278
    Width = 75
    Height = 25
    Caption = 'UnUsedCode'
    TabOrder = 4
    OnClick = UnUsedCodeClick
  end
  object Disconnect: TButton
    Left = 81
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Disconnect'
    TabOrder = 5
    OnClick = DisconnectClick
  end
  object Database1: TDatabase
    LoginPrompt = False
    SessionName = 'a'
    Left = 712
    Top = 8
  end
  object Query1: TQuery
    CachedUpdates = True
    SessionName = 's'
    SQL.Strings = (
      'SELECT * FROM users')
    Left = 680
    Top = 8
  end
  object Session1: TSession
    SessionName = 'a'
    Left = 680
    Top = 40
  end
  object Query2: TQuery
    CachedUpdates = True
    SessionName = 's'
    SQL.Strings = (
      'SELECT * FROM users')
    Left = 680
    Top = 96
  end
  object Database2: TDatabase
    LoginPrompt = False
    SessionName = 'a'
    Left = 712
    Top = 96
  end
  object Session2: TSession
    NetFileDir = 'C:\'
    PrivateDir = 'C:\WINDOWS\SYSTEM32'
    SessionName = 's'
    Left = 680
    Top = 128
  end
end
