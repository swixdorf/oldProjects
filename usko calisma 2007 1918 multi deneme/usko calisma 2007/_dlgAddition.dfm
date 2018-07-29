object dlgAddition: TdlgAddition
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Eklenti'
  ClientHeight = 169
  ClientWidth = 211
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
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
      Width = 58
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
    Top = 136
    Width = 89
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = btncloseClick
  end
  object tmmonu: TTimer
    Enabled = False
    OnTimer = tmmonuTimer
    Left = 160
    Top = 72
  end
end
