object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'KayitForm'
  ClientHeight = 118
  ClientWidth = 346
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label6: TLabel
    Left = 0
    Top = 105
    Width = 346
    Height = 13
    Align = alBottom
    Caption = 'Pasif'
    ExplicitWidth = 23
  end
  object GroupBox1: TGroupBox
    Left = 3
    Top = 0
    Width = 318
    Height = 89
    Caption = 'Register'
    TabOrder = 0
    object Label5: TLabel
      Left = 10
      Top = 38
      Width = 70
      Height = 13
      Caption = 'Payment Code'
    end
    object Label4: TLabel
      Left = 10
      Top = 14
      Width = 78
      Height = 13
      Caption = 'Character Name'
    end
    object Edit2: TEdit
      Left = 94
      Top = 11
      Width = 219
      Height = 21
      MaxLength = 60
      ReadOnly = True
      TabOrder = 0
    end
    object Edit4: TEdit
      Left = 94
      Top = 35
      Width = 219
      Height = 21
      TabOrder = 1
    end
    object Button1: TButton
      Left = 94
      Top = 56
      Width = 75
      Height = 25
      Caption = 'Load Code'
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object KOSocKay: TClientSocket
    Active = False
    Address = '78.188.80.30'
    ClientType = ctNonBlocking
    Port = 15778
    OnConnect = KOSocKayConnect
    OnRead = KOSocKayRead
    Left = 320
    Top = 24
  end
end
