object Form2: TForm2
  Left = 914
  Top = 0
  Caption = 'hshs :)'
  ClientHeight = 407
  ClientWidth = 526
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 87
    Width = 513
    Height = 211
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 193
    Height = 81
    Caption = 'EmuServer'
    TabOrder = 1
    object Label11: TLabel
      Left = 7
      Top = 16
      Width = 24
      Height = 13
      Caption = 'Port:'
    end
    object Label12: TLabel
      Left = 32
      Top = 40
      Width = 40
      Height = 13
      Caption = 'DURUM:'
    end
    object Shape1: TShape
      Left = 78
      Top = 37
      Width = 19
      Height = 22
      Brush.Color = clRed
      Pen.Color = clTeal
      Shape = stCircle
    end
    object Label13: TLabel
      Left = 60
      Top = 59
      Width = 37
      Height = 13
      Caption = 'Label13'
    end
    object Edit2: TEdit
      Left = 36
      Top = 13
      Width = 38
      Height = 21
      TabOrder = 0
      Text = '16600'
      OnChange = Edit2Change
    end
    object Button1: TButton
      Left = 78
      Top = 11
      Width = 75
      Height = 25
      Caption = 'OPEN server'
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 331
    Width = 193
    Height = 81
    Caption = 'EmuServer'
    TabOrder = 2
    object Label10: TLabel
      Left = 4
      Top = 16
      Width = 17
      Height = 13
      Caption = 'IP: '
    end
    object Label1: TLabel
      Left = 115
      Top = 16
      Width = 24
      Height = 13
      Caption = 'Port:'
    end
    object Label2: TLabel
      Left = 32
      Top = 40
      Width = 40
      Height = 13
      Caption = 'DURUM:'
    end
    object Shape2: TShape
      Left = 78
      Top = 37
      Width = 19
      Height = 22
      Brush.Color = clRed
      Pen.Color = clTeal
      Shape = stCircle
    end
    object Label3: TLabel
      Left = 60
      Top = 59
      Width = 37
      Height = 13
      Caption = 'Label13'
    end
    object Edit1: TEdit
      Left = 20
      Top = 13
      Width = 92
      Height = 21
      TabOrder = 0
      Text = '127.0.0.1'
      OnChange = Edit1Change
    end
    object Edit3: TEdit
      Left = 142
      Top = 13
      Width = 38
      Height = 21
      TabOrder = 1
      Text = '16600'
      OnChange = Edit3Change
    end
    object Button2: TButton
      Left = 118
      Top = 40
      Width = 58
      Height = 25
      Caption = 'Baglan'
      TabOrder = 2
      OnClick = Button2Click
    end
  end
  object Button3: TButton
    Left = 0
    Top = 304
    Width = 75
    Height = 25
    Caption = 'emuhs'
    TabOrder = 3
  end
  object Button4: TButton
    Left = 328
    Top = 28
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Memo2: TMemo
    Left = 218
    Top = 0
    Width = 185
    Height = 29
    Lines.Strings = (
      'Memo2')
    TabOrder = 5
  end
  object Timer1: TTimer
    Left = 568
    Top = 328
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 16600
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientError = ServerSocket1ClientError
    Left = 280
    Top = 8
  end
  object ClientSocket1: TClientSocket
    Active = False
    Address = '127.0.0.1'
    ClientType = ctNonBlocking
    Port = 16600
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 280
    Top = 40
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 1500
    OnTimer = Timer2Timer
    Left = 224
    Top = 16
  end
  object Timer3: TTimer
    OnTimer = Timer3Timer
    Left = 224
    Top = 48
  end
end
