object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 115
  ClientWidth = 191
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 177
    Height = 105
    Caption = 'GroupBox1'
    TabOrder = 0
    object Label1: TLabel
      Left = 4
      Top = 19
      Width = 62
      Height = 13
      Caption = 'Kullanici Adi :'
    end
    object Label2: TLabel
      Left = 4
      Top = 41
      Width = 32
      Height = 13
      Caption = 'Sifre : '
    end
    object Edit1: TEdit
      Left = 68
      Top = 16
      Width = 103
      Height = 21
      TabOrder = 0
      Text = 'aaswdd2eer223256'
    end
    object Edit2: TEdit
      Left = 68
      Top = 38
      Width = 103
      Height = 21
      TabOrder = 1
    end
    object Button1: TButton
      Left = 48
      Top = 65
      Width = 75
      Height = 25
      Caption = 'Giris'
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = 'kolebot.com'
    Port = 80
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 144
    Top = 88
  end
end
