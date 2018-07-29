object frmJail: TfrmJail
  Left = 0
  Top = 0
  Caption = 'frmJail'
  ClientHeight = 286
  ClientWidth = 392
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label11: TLabel
    Left = 8
    Top = 202
    Width = 74
    Height = 13
    Caption = 'kesilecek adet :'
  end
  object GroupBox7: TGroupBox
    Left = 8
    Top = 3
    Width = 233
    Height = 190
    Caption = 'Kesilecek Yaratiklar'
    TabOrder = 0
    object lbJailName: TListBox
      Left = 81
      Top = 18
      Width = 58
      Height = 63
      ItemHeight = 13
      TabOrder = 0
    end
    object clear: TButton
      Left = 81
      Top = 80
      Width = 58
      Height = 25
      Caption = 'clear'
      TabOrder = 1
      OnClick = clearClick
    end
  end
  object chJailActive: TCheckBox
    Left = 8
    Top = 226
    Width = 97
    Height = 17
    Caption = 'chJailActive'
    TabOrder = 1
    OnClick = chJailActiveClick
  end
  object memoJailLog: TMemo
    Left = 247
    Top = 8
    Width = 138
    Height = 185
    TabOrder = 2
  end
  object txtJailMax: TEdit
    Left = 88
    Top = 199
    Width = 33
    Height = 21
    TabOrder = 3
    Text = '10'
  end
  object memJailMonsterCount: TMemo
    Left = 153
    Top = 21
    Width = 40
    Height = 63
    Lines.Strings = (
      '0'
      '0'
      '0'
      '0')
    TabOrder = 4
    OnChange = memJailMonsterCountChange
  end
  object lbJailMonster: TListBox
    Left = 11
    Top = 21
    Width = 75
    Height = 164
    ItemHeight = 13
    Items.Strings = (
      'Worm'
      'Bandicoot'
      'Kecoon'
      'Gloomwing'
      'Gavolt'
      'Bulcan'
      'silan'
      'Bulture'
      'Scorpion'
      'Werewolf'
      'Zombie'
      'Skeleton')
    TabOrder = 5
    OnDblClick = lbJailMonsterDblClick
  end
  object tmJailRefresh: TTimer
    Enabled = False
    OnTimer = tmJailRefreshTimer
    Left = 200
    Top = 8
  end
end
