object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 407
  ClientWidth = 645
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox3: TGroupBox
    Left = 5
    Top = 8
    Width = 182
    Height = 182
    Caption = 'proxy'
    TabOrder = 0
    object Label7: TLabel
      Left = 11
      Top = 18
      Width = 43
      Height = 13
      Caption = 'proxy ip:'
    end
    object Label8: TLabel
      Left = 11
      Top = 39
      Width = 55
      Height = 13
      Caption = 'proxy port:'
    end
    object Edit7: TEdit
      Left = 69
      Top = 15
      Width = 106
      Height = 21
      TabOrder = 0
      Text = '85.153.52.'
    end
    object Edit8: TEdit
      Left = 69
      Top = 36
      Width = 54
      Height = 21
      TabOrder = 1
      Text = '3128'
    end
    object GroupBox4: TGroupBox
      Left = 4
      Top = 116
      Width = 175
      Height = 63
      Caption = 'proxy giris bilgileri'
      TabOrder = 2
      object Label9: TLabel
        Left = 3
        Top = 40
        Width = 25
        Height = 13
        Caption = 'sifre:'
      end
      object Label10: TLabel
        Left = 3
        Top = 19
        Width = 57
        Height = 13
        Caption = 'kullanici adi:'
      end
      object Edit9: TEdit
        Left = 64
        Top = 16
        Width = 106
        Height = 21
        TabOrder = 0
        Text = 'swixdorf'
      end
      object Edit10: TEdit
        Left = 64
        Top = 37
        Width = 106
        Height = 21
        TabOrder = 1
        Text = '201987'
      end
    end
    object CheckBox1: TCheckBox
      Left = 4
      Top = 66
      Width = 153
      Height = 17
      Caption = 'ucretli proxy kullaniyorum'
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
    object Button4: TButton
      Left = 48
      Top = 85
      Width = 75
      Height = 25
      Caption = 'test'
      TabOrder = 4
      OnClick = Button4Click
    end
  end
  object Memo1: TMemo
    Left = 224
    Top = 8
    Width = 289
    Height = 265
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
end