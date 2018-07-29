object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 502
  ClientWidth = 972
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
  object ServerlerListe: TListBox
    Left = 38
    Top = 8
    Width = 121
    Height = 274
    ItemHeight = 13
    TabOrder = 0
    OnClick = ServerlerListeClick
  end
  object ServerlerListeIp: TComboBox
    Left = 8
    Top = 307
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 1
  end
  object Button1: TButton
    Left = 165
    Top = 8
    Width = 75
    Height = 25
    Caption = 'baglan'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 165
    Top = 64
    Width = 75
    Height = 25
    Caption = 'serveral'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 240
    Top = 8
    Width = 177
    Height = 345
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
  object Button3: TButton
    Left = 165
    Top = 95
    Width = 75
    Height = 25
    Caption = '1'
    TabOrder = 5
    OnClick = Button3Click
  end
  object CheckBox1: TCheckBox
    Left = 72
    Top = 335
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    Checked = True
    State = cbChecked
    TabOrder = 6
  end
  object MasaList: TListBox
    Left = 22
    Top = 358
    Width = 355
    Height = 137
    ItemHeight = 13
    TabOrder = 7
    OnDblClick = MasaListDblClick
  end
  object Button4: TButton
    Left = 383
    Top = 389
    Width = 75
    Height = 25
    Caption = 'gir'
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Tag = 6
    Left = 383
    Top = 447
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 9
    OnClick = Button5Click
  end
  object MasaBuy: TEdit
    Left = 383
    Top = 420
    Width = 62
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 10
    Text = '200000'
  end
  object Edit1: TEdit
    Left = 383
    Top = 362
    Width = 75
    Height = 21
    TabOrder = 11
    Text = 'Edit1'
  end
  object Button6: TButton
    Tag = 6
    Left = 464
    Top = 447
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 12
    OnClick = Button6Click
  end
  object Button7: TButton
    Tag = 6
    Left = 545
    Top = 447
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 13
    OnClick = Button7Click
  end
  object Edit2: TEdit
    Left = 609
    Top = 132
    Width = 75
    Height = 21
    TabOrder = 14
    Text = 'Edit2'
  end
  object Button8: TButton
    Tag = 6
    Left = 640
    Top = 447
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 15
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 165
    Top = 257
    Width = 75
    Height = 25
    Caption = 'save'
    TabOrder = 16
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 165
    Top = 226
    Width = 75
    Height = 25
    Caption = 'clear'
    TabOrder = 17
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 640
    Top = 478
    Width = 75
    Height = 25
    Caption = 'Button11'
    TabOrder = 18
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 464
    Top = 478
    Width = 75
    Height = 25
    Caption = 'Button12'
    TabOrder = 19
    OnClick = Button12Click
  end
  object Button13: TButton
    Tag = 1
    Left = 528
    Top = 8
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 20
    OnClick = Button6Click
  end
  object Button14: TButton
    Tag = 1
    Left = 447
    Top = 8
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 21
    OnClick = Button5Click
  end
  object Button15: TButton
    Tag = 1
    Left = 609
    Top = 8
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 22
    OnClick = Button7Click
  end
  object Button16: TButton
    Tag = 1
    Left = 704
    Top = 8
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 23
    OnClick = Button8Click
  end
  object Button17: TButton
    Tag = 2
    Left = 528
    Top = 39
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 24
    OnClick = Button6Click
  end
  object Button18: TButton
    Tag = 2
    Left = 447
    Top = 39
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 25
    OnClick = Button5Click
  end
  object Button19: TButton
    Tag = 2
    Left = 609
    Top = 39
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 26
    OnClick = Button7Click
  end
  object Button20: TButton
    Tag = 2
    Left = 704
    Top = 39
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 27
    OnClick = Button8Click
  end
  object Button21: TButton
    Tag = 3
    Left = 528
    Top = 70
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 28
    OnClick = Button6Click
  end
  object Button22: TButton
    Tag = 3
    Left = 447
    Top = 70
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 29
    OnClick = Button5Click
  end
  object Button23: TButton
    Tag = 3
    Left = 609
    Top = 70
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 30
    OnClick = Button7Click
  end
  object Button24: TButton
    Tag = 3
    Left = 704
    Top = 70
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 31
    OnClick = Button8Click
  end
  object Button25: TButton
    Tag = 4
    Left = 528
    Top = 101
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 32
    OnClick = Button6Click
  end
  object Button26: TButton
    Tag = 4
    Left = 447
    Top = 101
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 33
    OnClick = Button5Click
  end
  object Button27: TButton
    Tag = 4
    Left = 609
    Top = 101
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 34
    OnClick = Button7Click
  end
  object Button28: TButton
    Tag = 4
    Left = 704
    Top = 101
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 35
    OnClick = Button8Click
  end
  object Button29: TButton
    Tag = 5
    Left = 528
    Top = 159
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 36
    OnClick = Button6Click
  end
  object Button30: TButton
    Tag = 5
    Left = 447
    Top = 159
    Width = 75
    Height = 25
    Caption = 'otur'
    TabOrder = 37
    OnClick = Button5Click
  end
  object Button31: TButton
    Tag = 5
    Left = 609
    Top = 159
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 38
    OnClick = Button7Click
  end
  object Button32: TButton
    Tag = 5
    Left = 704
    Top = 159
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 39
    OnClick = Button8Click
  end
  object Button33: TButton
    Left = 165
    Top = 33
    Width = 75
    Height = 25
    Caption = 'cik'
    TabOrder = 40
    OnClick = Button33Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 8
  end
  object ClientSocket2: TClientSocket
    Tag = 1
    Active = False
    ClientType = ctNonBlocking
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 40
  end
  object ClientSocket3: TClientSocket
    Tag = 2
    Active = False
    ClientType = ctNonBlocking
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 72
  end
  object ClientSocket4: TClientSocket
    Tag = 3
    Active = False
    ClientType = ctNonBlocking
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 104
  end
  object ClientSocket5: TClientSocket
    Tag = 4
    Active = False
    ClientType = ctNonBlocking
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    Left = 8
    Top = 136
  end
end
