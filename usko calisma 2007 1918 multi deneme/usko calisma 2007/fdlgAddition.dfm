object dlgAddition: TdlgAddition
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Eklenti'
  ClientHeight = 232
  ClientWidth = 943
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDblClick = FormDblClick
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 216
    Top = 24
    Width = 18
    Height = 13
    Caption = 'ip : '
  end
  object grpbdw: TGroupBox
    Left = 8
    Top = 8
    Width = 193
    Height = 113
    Caption = 'BDW Eklentisi'
    TabOrder = 0
    object lbmonu: TLabel
      Left = 127
      Top = 21
      Width = 53
      Height = 13
      Caption = 'ID Alinmadi'
    end
    object btngetmonuid: TButton
      Left = 3
      Top = 16
      Width = 118
      Height = 25
      Caption = 'Monu ID Al (Secili)'
      TabOrder = 0
      OnClick = btngetmonuidClick
    end
    object btngetmonu: TButton
      Left = 3
      Top = 56
      Width = 118
      Height = 25
      Caption = 'Uzaktan Monu Al'
      TabOrder = 1
      OnClick = btngetmonuClick
    end
    object chautomonu: TCheckBox
      Left = 3
      Top = 87
      Width = 118
      Height = 17
      Caption = 'Otomatik Monu Al'
      TabOrder = 2
      OnClick = chautomonuClick
    end
  end
  object btnclose: TButton
    Left = 8
    Top = 199
    Width = 89
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btncloseClick
  end
  object grpchaos: TGroupBox
    Left = 8
    Top = 127
    Width = 193
    Height = 66
    Caption = 'Chaos Eklentisi'
    TabOrder = 2
    object chdisablesaw: TCheckBox
      Left = 3
      Top = 16
      Width = 134
      Height = 17
      Caption = 'testere damage kapat'
      TabOrder = 0
      OnClick = chdisablesawClick
    end
    object chlootcubes: TCheckBox
      Left = 3
      Top = 39
      Width = 134
      Height = 17
      Caption = 'k'#252'pleri otomatik topla'
      TabOrder = 1
      OnClick = chlootcubesClick
    end
  end
  object Edit1: TEdit
    Left = 140
    Top = 199
    Width = 63
    Height = 21
    TabOrder = 3
    Visible = False
    OnChange = Edit1Change
  end
  object Edit2: TEdit
    Left = 240
    Top = 21
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '127.0.0.1'
  end
  object Button1: TButton
    Left = 240
    Top = 43
    Width = 113
    Height = 16
    Caption = 'Baglan'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 241
    Top = 58
    Width = 113
    Height = 17
    Caption = 'ServerAc'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 241
    Top = 120
    Width = 113
    Height = 104
    TabOrder = 7
  end
  object CheckBox1: TCheckBox
    Left = 264
    Top = 1
    Width = 97
    Height = 17
    Caption = '33-56'
    TabOrder = 8
    OnClick = CheckBox1Click
  end
  object Memo2: TMemo
    Left = 376
    Top = 8
    Width = 89
    Height = 216
    TabOrder = 9
    OnChange = Memo2Change
  end
  object ListBox1: TListBox
    Left = 471
    Top = 8
    Width = 138
    Height = 216
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
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0'
      '0')
    TabOrder = 10
  end
  object CheckBox2: TCheckBox
    Left = 615
    Top = 42
    Width = 97
    Height = 17
    Caption = 'tara'
    TabOrder = 11
    OnClick = CheckBox2Click
  end
  object GroupBox1: TGroupBox
    Left = 241
    Top = 76
    Width = 113
    Height = 41
    Caption = 'git'
    TabOrder = 12
    object Edit3: TEdit
      Left = 0
      Top = 13
      Width = 36
      Height = 21
      TabOrder = 0
      Text = '1000'
    end
    object Edit4: TEdit
      Left = 39
      Top = 13
      Width = 37
      Height = 21
      TabOrder = 1
      Text = '1000'
    end
    object Button3: TButton
      Left = 77
      Top = 11
      Width = 33
      Height = 25
      Caption = 'git'
      TabOrder = 2
    end
  end
  object CheckBox3: TCheckBox
    Left = 615
    Top = 68
    Width = 97
    Height = 17
    Caption = 'CheckBox3'
    TabOrder = 13
    OnClick = CheckBox3Click
  end
  object Edit5: TEdit
    Left = 615
    Top = 89
    Width = 73
    Height = 21
    TabOrder = 14
    Text = '1'
  end
  object Button4: TButton
    Left = 615
    Top = 116
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 15
    OnClick = Button4Click
  end
  object Edit6: TEdit
    Left = 718
    Top = 15
    Width = 121
    Height = 21
    TabOrder = 16
    Text = 'Edit6'
  end
  object Button5: TButton
    Left = 845
    Top = 13
    Width = 75
    Height = 25
    Caption = 'kutuac'
    TabOrder = 17
    OnClick = Button5Click
  end
  object Memo3: TMemo
    Left = 718
    Top = 44
    Width = 139
    Height = 180
    Lines.Strings = (
      'Memo3')
    TabOrder = 18
  end
  object tmmonu: TTimer
    Enabled = False
    OnTimer = tmmonuTimer
    Left = 160
    Top = 72
  end
  object tmlootcubes: TTimer
    Enabled = False
    OnTimer = tmlootcubesTimer
    Left = 152
    Top = 16
  end
  object tmchaoscheck: TTimer
    Enabled = False
    OnTimer = tmchaoscheckTimer
    Left = 160
    Top = 136
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 18333
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientError = ServerSocket1ClientError
    Left = 432
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 18333
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 432
    Top = 32
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 624
    Top = 8
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 250
    OnTimer = Timer2Timer
    Left = 856
    Top = 40
  end
end