object dlgMaden: TdlgMaden
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'maden'
  ClientHeight = 522
  ClientWidth = 717
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 8
    Width = 65
    Height = 17
    AutoSize = False
    Caption = 'banka koy'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 136
    Top = 8
    Width = 73
    Height = 17
    AutoSize = False
    Caption = 'sundries sat '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 263
    Top = 8
    Width = 50
    Height = 17
    AutoSize = False
    Caption = #231#246'pe at'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 374
    Top = 8
    Width = 43
    Height = 17
    AutoSize = False
    Caption = 'biriktir'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsUnderline]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 103
    Top = 464
    Width = 212
    Height = 13
    Caption = '(Maden i'#351'lemi bot ba'#351'latarak devreye girer.)'
  end
  object Label5: TLabel
    Left = 112
    Top = 440
    Width = 124
    Height = 13
    Caption = 'Ta'#351' k'#305'rd'#305'rma bekleme(ms):'
  end
  object lstinn: TCheckListBox
    Left = 8
    Top = 31
    Width = 105
    Height = 402
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 13
    Items.Strings = (
      'HP Pot(45)'
      'HP Pot(90)'
      'HP Pot(180)'
      'HP Pot(360)'
      'HP Pot(720)'
      'MP Pot(120)'
      'MP Pot(240)'
      'MP Pot(480)'
      'MP Pot(960)'
      'MP Pot(1920)'
      'Sling'
      'Acid potion'
      'Bezoar'
      'Glutinous'
      'Firecracker'
      'Flower Firecracker'
      'Low scroll'
      'Crystal'
      'Opal'
      'Sapphire'
      'Calling Friend Sc'
      'TS'
      'BUS'
      'Upgrade Scroll'
      'Abyss Gem'
      'MP Rice Cake'
      'Monster Stone'
      'Mavi kutu'
      'Yesil kutu'
      'Kirmizi kutu'
      'Bronze coin'
      'Silver coin'
      'Gold coin'
      'Dc Flash'
      'Rainworm')
    ParentFont = False
    TabOrder = 0
    OnClick = lstinnClick
  end
  object lstsund: TCheckListBox
    Left = 119
    Top = 31
    Width = 105
    Height = 402
    ItemHeight = 13
    Items.Strings = (
      'HP Pot(45)'
      'HP Pot(90)'
      'HP Pot(180)'
      'HP Pot(360)'
      'HP Pot(720)'
      'MP Pot(120)'
      'MP Pot(240)'
      'MP Pot(480)'
      'MP Pot(960)'
      'MP Pot(1920)'
      'Sling'
      'Acid potion'
      'Bezoar'
      'Glutinous'
      'Firecracker'
      'Flower Firecracker'
      'Low scroll'
      'Crystal'
      'Opal'
      'Sapphire'
      'Calling Friend Sc'
      'TS'
      'BUS'
      'Upgrade Scroll'
      'Abyss Gem'
      'MP Rice Cake'
      'Monster Stone'
      'Mavi kutu'
      'Yesil kutu'
      'Kirmizi kutu'
      'Bronze coin'
      'Silver coin'
      'Gold coin'
      'Dc Flash'
      'Rainworm')
    TabOrder = 1
    OnClick = lstsundClick
  end
  object lstremove: TCheckListBox
    Left = 230
    Top = 31
    Width = 105
    Height = 402
    ItemHeight = 13
    Items.Strings = (
      'HP Pot(45)'
      'HP Pot(90)'
      'HP Pot(180)'
      'HP Pot(360)'
      'HP Pot(720)'
      'MP Pot(120)'
      'MP Pot(240)'
      'MP Pot(480)'
      'MP Pot(960)'
      'MP Pot(1920)'
      'Sling'
      'Acid potion'
      'Bezoar'
      'Glutinous'
      'Firecracker'
      'Flower Firecracker'
      'Low scroll'
      'Crystal'
      'Opal'
      'Sapphire'
      'Calling Friend Sc'
      'TS'
      'BUS'
      'Upgrade Scroll'
      'Abyss Gem'
      'MP Rice Cake'
      'Monster Stone'
      'Mavi kutu'
      'Yesil kutu'
      'Kirmizi kutu'
      'Bronze coin'
      'Silver coin'
      'Gold coin'
      'Dc Flash'
      'Rainworm')
    TabOrder = 2
    OnClick = lstremoveClick
  end
  object lstnop: TCheckListBox
    Left = 341
    Top = 31
    Width = 105
    Height = 402
    ItemHeight = 13
    Items.Strings = (
      'HP Pot(45)'
      'HP Pot(90)'
      'HP Pot(180)'
      'HP Pot(360)'
      'HP Pot(720)'
      'MP Pot(120)'
      'MP Pot(240)'
      'MP Pot(480)'
      'MP Pot(960)'
      'MP Pot(1920)'
      'Sling'
      'Acid potion'
      'Bezoar'
      'Glutinous'
      'Firecracker'
      'Flower Firecracker'
      'Low scroll'
      'Crystal'
      'Opal'
      'Sapphire'
      'Calling Friend Sc'
      'TS'
      'BUS'
      'Upgrade Scroll'
      'Abyss Gem'
      'MP Rice Cake'
      'Monster Stone'
      'Mavi kutu'
      'Yesil kutu'
      'Kirmizi kutu'
      'Bronze coin'
      'Silver coin'
      'Gold coin'
      'Dc Flash'
      'Rainworm')
    TabOrder = 3
    OnClick = lstnopClick
  end
  object btnclose: TButton
    Left = 356
    Top = 489
    Width = 92
    Height = 25
    Caption = 'Kapat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = btncloseClick
  end
  object chmaden: TCheckBox
    Left = 8
    Top = 464
    Width = 89
    Height = 17
    Caption = 'Maden aktif'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = chmadenClick
  end
  object btnabyss: TButton
    Left = 8
    Top = 489
    Width = 81
    Height = 25
    Caption = 'Abyssleri k'#305'r'
    TabOrder = 6
    OnClick = btnabyssClick
  end
  object btnblue: TButton
    Left = 95
    Top = 489
    Width = 81
    Height = 25
    Caption = 'Mavi kutu k'#305'r'
    TabOrder = 7
    OnClick = btnblueClick
  end
  object btngreen: TButton
    Left = 182
    Top = 489
    Width = 81
    Height = 25
    Caption = 'Yesil kutu k'#305'r'
    TabOrder = 8
    OnClick = btngreenClick
  end
  object btnred: TButton
    Left = 269
    Top = 489
    Width = 81
    Height = 25
    Caption = 'K'#305'rm'#305'z'#305' kutu k'#305'r'
    TabOrder = 9
    OnClick = btnredClick
  end
  object chmadensh: TCheckBox
    Left = 8
    Top = 441
    Width = 89
    Height = 17
    Caption = 'SpeedHack'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 10
    OnClick = chmadenshClick
  end
  object txtoredelay: TEdit
    Left = 242
    Top = 437
    Width = 39
    Height = 21
    TabOrder = 11
    Text = '100'
  end
  object CheckBox1: TCheckBox
    Left = 321
    Top = 466
    Width = 97
    Height = 17
    Caption = 'islemcidusur'
    TabOrder = 12
    OnClick = CheckBox1Click
  end
  object GroupBox1: TGroupBox
    Left = 452
    Top = 31
    Width = 81
    Height = 138
    Caption = 'Madene Gidis'
    TabOrder = 13
    object lstmdncoord: TListBox
      Left = 1
      Top = 15
      Width = 77
      Height = 97
      ItemHeight = 13
      Items.Strings = (
        '(817,451):5'
        '(776,433):5'
        '(667,423):5'
        '(640,375):15')
      TabOrder = 0
    end
  end
  object tmmaden: TTimer
    Enabled = False
    Interval = 100
    OnTimer = tmmadenTimer
    Left = 336
    Top = 416
  end
  object tmrpr: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = tmrprTimer
    Left = 368
    Top = 416
  end
  object tmsundgo: TTimer
    Enabled = False
    Interval = 100
    OnTimer = tmsundgoTimer
    Left = 416
    Top = 408
  end
end
