object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 501
  ClientWidth = 1400
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
  object Button2: TButton
    Left = 56
    Top = 8
    Width = 75
    Height = 25
    Caption = 'serv'
    TabOrder = 0
    OnClick = Button2Click
  end
  object ServerlerListe: TListBox
    Left = 26
    Top = 39
    Width = 121
    Height = 274
    ItemHeight = 13
    TabOrder = 1
    OnClick = ServerlerListeClick
  end
  object ServerlerListeIp: TComboBox
    Left = 16
    Top = 319
    Width = 161
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    OnChange = ServerlerListeIpChange
  end
  object Button1: TButton
    Left = 137
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 3
    OnClick = gir
  end
  object Memo1: TMemo
    Left = 464
    Top = 8
    Width = 465
    Height = 233
    TabOrder = 4
  end
  object Memo2: TMemo
    Left = 464
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 5
    WordWrap = False
  end
  object MasaList: TListBox
    Left = 8
    Top = 374
    Width = 266
    Height = 137
    ItemHeight = 13
    TabOrder = 6
    OnDblClick = MasaListDblClick
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 346
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object ListBox1: TListBox
    Left = 153
    Top = 39
    Width = 121
    Height = 194
    ItemHeight = 13
    Items.Strings = (
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0')
    TabOrder = 8
  end
  object MasaBuy: TEdit
    Left = 197
    Top = 319
    Width = 62
    Height = 21
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 9
    Text = '200000'
    OnChange = MasaBuyChange
  end
  object Button3: TButton
    Left = 218
    Top = 8
    Width = 41
    Height = 25
    Caption = 'otur'
    TabOrder = 10
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 119
    Top = 347
    Width = 103
    Height = 21
    TabOrder = 11
    Text = 'Edit1'
  end
  object Button4: TButton
    Left = 228
    Top = 346
    Width = 46
    Height = 25
    Caption = 'Button4'
    TabOrder = 12
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 280
    Top = 480
    Width = 75
    Height = 25
    Caption = 'temizle'
    TabOrder = 13
    OnClick = Button5Click
  end
  object Edit2: TEdit
    Left = 153
    Top = 239
    Width = 121
    Height = 21
    TabOrder = 14
    Text = 'Edit2'
  end
  object Button6: TButton
    Left = 168
    Top = 266
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 15
    OnClick = Button6Click
  end
  object CheckListBox1: TCheckListBox
    Left = 280
    Top = 39
    Width = 169
    Height = 194
    ItemHeight = 13
    Items.Strings = (
      '2500'
      '2000'
      '2000'
      '2000'
      '2000'
      '2000'
      '2000'
      '2000'
      '2000')
    TabOrder = 16
  end
  object Button7: TButton
    Left = 312
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Button7'
    TabOrder = 17
    OnClick = Button7Click
  end
  object Edit3: TEdit
    Left = 392
    Top = 247
    Width = 537
    Height = 21
    TabOrder = 18
    Text = 'Edit3'
  end
  object Edit4: TEdit
    Left = 312
    Top = 247
    Width = 43
    Height = 21
    TabOrder = 19
    Text = '0'
  end
  object Button8: TButton
    Left = 361
    Top = 245
    Width = 25
    Height = 25
    Caption = 'Button8'
    TabOrder = 20
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 265
    Top = 8
    Width = 32
    Height = 25
    Caption = 'kalk'
    TabOrder = 21
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 328
    Top = 301
    Width = 75
    Height = 25
    Caption = 'call'
    TabOrder = 22
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 328
    Top = 332
    Width = 75
    Height = 25
    Caption = 'fold'
    TabOrder = 23
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 328
    Top = 400
    Width = 75
    Height = 25
    Caption = 'raise'
    TabOrder = 24
    OnClick = Button12Click
  end
  object Edit5: TEdit
    Left = 328
    Top = 373
    Width = 75
    Height = 21
    TabOrder = 25
    Text = '5000'
  end
  object Button13: TButton
    Left = 328
    Top = 431
    Width = 75
    Height = 25
    Caption = 'call1'
    TabOrder = 26
    OnClick = Button13Click
  end
  object Memo3: TMemo
    Left = 564
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 27
    WordWrap = False
  end
  object Memo4: TMemo
    Left = 664
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 28
    WordWrap = False
  end
  object Memo5: TMemo
    Left = 764
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 29
    WordWrap = False
  end
  object Memo6: TMemo
    Left = 963
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 30
    WordWrap = False
  end
  object Memo7: TMemo
    Left = 863
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 31
    WordWrap = False
  end
  object Memo8: TMemo
    Left = 1063
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 32
    WordWrap = False
  end
  object Memo9: TMemo
    Left = 1157
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 33
    WordWrap = False
  end
  object Memo10: TMemo
    Left = 1263
    Top = 268
    Width = 100
    Height = 233
    ScrollBars = ssVertical
    TabOrder = 34
    WordWrap = False
  end
  object Button14: TButton
    Left = 418
    Top = 431
    Width = 40
    Height = 25
    Caption = 'Button14'
    TabOrder = 35
    OnClick = Button14Click
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '184.75.174.127'
    Port = 9339
    OnConnect = ClientSocket1Connect
    OnRead = ClientSocket1Read
    Left = 16
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = Timer1Timer
    Top = 256
  end
end