object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 858
  ClientWidth = 1089
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object log: TListBox
    Left = 0
    Top = 804
    Width = 1089
    Height = 54
    Align = alBottom
    ItemHeight = 13
    TabOrder = 0
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 1089
    Height = 804
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 1
    object TabSheet3: TTabSheet
      Caption = 'Login'
      ImageIndex = 2
      object GroupBox3: TGroupBox
        Left = 10
        Top = 3
        Width = 207
        Height = 245
        Caption = 'LetterFonksiyonlari'
        TabOrder = 0
        Visible = False
        object LetterItem: TListBox
          Left = 94
          Top = 16
          Width = 86
          Height = 172
          ItemHeight = 13
          TabOrder = 0
        end
        object LetterAdet: TListBox
          Left = 53
          Top = 16
          Width = 42
          Height = 172
          ItemHeight = 13
          TabOrder = 1
        end
        object LetterId: TListBox
          Left = 5
          Top = 16
          Width = 49
          Height = 172
          ItemHeight = 13
          TabOrder = 2
        end
        object LetterKontrol: TButton
          Left = 43
          Top = 194
          Width = 75
          Height = 25
          Caption = 'LetterKontrol'
          TabOrder = 3
        end
        object SeciliLCek: TButton
          Left = 124
          Top = 194
          Width = 75
          Height = 25
          Caption = 'SeciliLCek'
          TabOrder = 4
          OnClick = SeciliLCekClick
        end
        object OtoLetterCek: TCheckBox
          Left = 3
          Top = 225
          Width = 86
          Height = 17
          Caption = 'OtoLetterCek'
          Checked = True
          State = cbChecked
          TabOrder = 5
        end
        object TradeAc: TCheckBox
          Left = 94
          Top = 225
          Width = 76
          Height = 17
          Caption = 'OtoTrade'
          TabOrder = 6
          Visible = False
        end
        object Edit3: TEdit
          Left = 4
          Top = 198
          Width = 33
          Height = 21
          TabOrder = 7
          Text = 'Edit3'
        end
      end
      object GroupBox1: TGroupBox
        Left = 368
        Top = 11
        Width = 281
        Height = 43
        Caption = 'Login'
        TabOrder = 1
        object Label1: TLabel
          Left = 18
          Top = 46
          Width = 73
          Height = 13
          Caption = 'AccountName :'
        end
        object Label2: TLabel
          Left = 18
          Top = 73
          Width = 53
          Height = 13
          Caption = 'Password :'
        end
        object Edit1: TEdit
          Left = 96
          Top = 43
          Width = 121
          Height = 21
          TabOrder = 0
          Text = 'Username'
          OnChange = EditSave
        end
        object Edit2: TEdit
          Left = 96
          Top = 70
          Width = 121
          Height = 21
          TabOrder = 1
          Text = 'Password'
          OnChange = EditSave
        end
        object Button5: TButton
          Left = 103
          Top = 12
          Width = 75
          Height = 25
          Caption = 'Login'
          TabOrder = 2
          OnClick = Button5Click
        end
      end
      object ototo: TCheckBox
        Left = 422
        Top = 60
        Width = 193
        Height = 17
        Caption = 'AutoLoginCreatePartyStartAtack'
        TabOrder = 2
      end
      object GroupBox43: TGroupBox
        Left = 14
        Top = 263
        Width = 230
        Height = 206
        Caption = 'Create Account'
        TabOrder = 3
        object cMail: TEdit
          Left = 43
          Top = 21
          Width = 121
          Height = 21
          TabOrder = 0
          Text = 'cMail'
        end
        object cPassword: TEdit
          Left = 43
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 1
          Text = 'cPassword'
        end
        object cUsername: TEdit
          Left = 43
          Top = 75
          Width = 121
          Height = 21
          TabOrder = 2
          Text = 'cUsername'
        end
        object cNick: TEdit
          Left = 43
          Top = 102
          Width = 121
          Height = 21
          TabOrder = 3
          Text = 'cNick'
        end
        object Register: TButton
          Left = 67
          Top = 129
          Width = 75
          Height = 25
          Caption = 'Register'
          TabOrder = 4
          OnClick = RegisterClick
        end
      end
      object Button185: TButton
        Left = 789
        Top = 49
        Width = 75
        Height = 25
        Caption = 'Button185'
        TabOrder = 4
        OnClick = Button185Click
      end
      object allsrv: TComboBox
        Left = 789
        Top = -1
        Width = 92
        Height = 21
        ItemHeight = 13
        TabOrder = 5
        Text = 'All Server'
        OnChange = allsrvChange
      end
      object allloc: TComboBox
        Left = 789
        Top = 22
        Width = 92
        Height = 21
        ItemHeight = 13
        TabOrder = 6
        Text = 'All Loc'
        OnChange = alllocChange
        Items.Strings = (
          'Center'
          'Left'
          'Right')
      end
      object Memo1: TMemo
        Left = 797
        Top = 111
        Width = 281
        Height = 368
        TabOrder = 7
        OnChange = Memo1Change
      end
      object AutoExp: TCheckBox
        Left = 892
        Top = 3
        Width = 97
        Height = 16
        Caption = 'Oto Karakter Ac'
        Checked = True
        State = cbChecked
        TabOrder = 8
      end
      object CheckBox14: TCheckBox
        Left = 892
        Top = 15
        Width = 97
        Height = 17
        Caption = 'Oto Relog'
        TabOrder = 9
        OnClick = CheckBox14Click
      end
      object CheckBox15: TCheckBox
        Left = 892
        Top = 28
        Width = 97
        Height = 17
        Caption = 'maden'
        TabOrder = 10
        OnClick = CheckBox15Click
      end
      object proxy: TCheckBox
        Left = 892
        Top = 56
        Width = 97
        Height = 17
        Caption = 'proxy'
        TabOrder = 11
        OnClick = proxyClick
      end
      object CheckBox16: TCheckBox
        Left = 892
        Top = 41
        Width = 97
        Height = 17
        Caption = 'otopresok'
        TabOrder = 12
        OnClick = CheckBox16Click
      end
      object RadioButton1: TRadioButton
        Left = 944
        Top = 57
        Width = 45
        Height = 17
        Caption = 'srv1'
        Checked = True
        TabOrder = 13
        TabStop = True
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 994
        Top = 57
        Width = 55
        Height = 17
        Caption = 'srv2'
        TabOrder = 14
        OnClick = RadioButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 995
        Top = 41
        Width = 55
        Height = 17
        Caption = 'srv3'
        TabOrder = 15
        OnClick = RadioButton3Click
      end
      object Memo3: TMemo
        Left = 797
        Top = 485
        Width = 124
        Height = 201
        Lines.Strings = (
          'Memo3')
        TabOrder = 16
      end
      object Button204: TButton
        Left = 927
        Top = 485
        Width = 75
        Height = 25
        Caption = 'SetAcc'
        TabOrder = 17
        OnClick = Button204Click
      end
      object RadioButton4: TRadioButton
        Left = 995
        Top = 25
        Width = 68
        Height = 17
        Caption = 'srv4'
        TabOrder = 18
        OnClick = RadioButton4Click
      end
      object RadioButton5: TRadioButton
        Left = 995
        Top = 11
        Width = 113
        Height = 17
        Caption = 'srv5'
        TabOrder = 19
        OnClick = RadioButton5Click
      end
      object RadioButton6: TRadioButton
        Left = 995
        Top = -2
        Width = 113
        Height = 17
        Caption = 'srv6'
        TabOrder = 20
        OnClick = RadioButton6Click
      end
      object CheckBox20: TCheckBox
        Left = 892
        Top = 72
        Width = 97
        Height = 17
        Caption = 'fastlogin'
        TabOrder = 21
        OnClick = CheckBox20Click
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Settings'
      object Button79: TButton
        Left = 429
        Top = 737
        Width = 75
        Height = 25
        Caption = 'Button79'
        TabOrder = 0
        OnClick = Button79Click
      end
      object AllPressOk: TButton
        Left = 5
        Top = 522
        Width = 75
        Height = 25
        Caption = 'AllPressOk'
        TabOrder = 1
        OnClick = AllPressOkClick
      end
      object Button184: TButton
        Left = 98
        Top = 522
        Width = 75
        Height = 25
        Caption = 'nova'
        TabOrder = 2
        OnClick = Button184Click
      end
      object Edit9: TEdit
        Left = 83
        Top = 524
        Width = 14
        Height = 21
        TabOrder = 3
        Text = '0'
      end
      object Button183: TButton
        Left = 179
        Top = 522
        Width = 75
        Height = 25
        Caption = 'AllChaosMap'
        TabOrder = 4
        OnClick = Button183Click
      end
      object Edit10: TEdit
        Left = 83
        Top = 551
        Width = 14
        Height = 21
        TabOrder = 5
        Text = '0'
      end
      object Button186: TButton
        Left = 98
        Top = 549
        Width = 75
        Height = 25
        Caption = 'potion ic'
        TabOrder = 6
        OnClick = Button186Click
      end
      object CheckBox13: TCheckBox
        Left = 179
        Top = 553
        Width = 72
        Height = 17
        Caption = 'chaosgiris'
        TabOrder = 7
        OnClick = CheckBox13Click
      end
      object CheckBox18: TCheckBox
        Left = 456
        Top = 674
        Width = 97
        Height = 17
        Caption = 'surekli vur 2'
        TabOrder = 8
        OnClick = CheckBox18Click
      end
      object Button181: TButton
        Left = 318
        Top = 522
        Width = 75
        Height = 25
        Caption = 'allhapisgorev'
        TabOrder = 9
        OnClick = Button181Click
      end
      object Button188: TButton
        Left = 318
        Top = 585
        Width = 75
        Height = 25
        Caption = 'all otur'
        TabOrder = 10
        OnClick = Button188Click
      end
      object Button189: TButton
        Left = 318
        Top = 616
        Width = 75
        Height = 25
        Caption = 'all kalk'
        TabOrder = 11
        OnClick = Button189Click
      end
      object Edit13: TEdit
        Left = 440
        Top = 524
        Width = 49
        Height = 21
        TabOrder = 12
        Text = 'Edit13'
      end
      object Edit14: TEdit
        Left = 440
        Top = 551
        Width = 49
        Height = 21
        TabOrder = 13
        Text = 'Edit14'
      end
      object Button190: TButton
        Left = 504
        Top = 549
        Width = 75
        Height = 25
        Caption = 'vur'
        TabOrder = 14
        OnClick = Button190Click
      end
      object Button191: TButton
        Left = 318
        Top = 554
        Width = 75
        Height = 25
        Caption = 'all sopa'
        TabOrder = 15
        OnClick = Button191Click
      end
      object CheckBox17: TCheckBox
        Left = 440
        Top = 580
        Width = 97
        Height = 17
        Caption = 'surekli vur'
        TabOrder = 16
        OnClick = CheckBox17Click
      end
      object Button192: TButton
        Left = 504
        Top = 616
        Width = 75
        Height = 25
        Caption = 'vur'
        TabOrder = 17
        OnClick = Button192Click
      end
      object Edit15: TEdit
        Left = 440
        Top = 618
        Width = 49
        Height = 21
        TabOrder = 18
        Text = '0'
      end
      object Button193: TButton
        Left = 810
        Top = 522
        Width = 75
        Height = 25
        Caption = 'worm'
        TabOrder = 19
        OnClick = Button193Click
      end
      object Button194: TButton
        Left = 318
        Top = 647
        Width = 75
        Height = 25
        Caption = 'all hapis ver'
        TabOrder = 20
        OnClick = Button194Click
      end
      object Button198: TButton
        Left = 237
        Top = 585
        Width = 75
        Height = 25
        Caption = 'gorevci git'
        TabOrder = 21
        OnClick = Button198Click
      end
      object Button199: TButton
        Left = 237
        Top = 616
        Width = 75
        Height = 25
        Caption = 'all zopa giy'
        TabOrder = 22
        OnClick = Button199Click
      end
      object Memo2: TMemo
        Left = 589
        Top = 547
        Width = 92
        Height = 149
        Lines.Strings = (
          'Memo2')
        TabOrder = 23
      end
      object ListBox45: TListBox
        Left = 687
        Top = 547
        Width = 121
        Height = 149
        ItemHeight = 13
        Items.Strings = (
          '0'
          '0'
          '0'
          '0'
          '0')
        TabOrder = 24
      end
      object Button195: TButton
        Left = 814
        Top = 577
        Width = 75
        Height = 25
        Caption = 'bandicot'
        TabOrder = 25
        OnClick = Button195Click
      end
      object Button196: TButton
        Left = 814
        Top = 608
        Width = 75
        Height = 25
        Caption = 'kecoon'
        TabOrder = 26
        OnClick = Button196Click
      end
      object Button197: TButton
        Left = 814
        Top = 639
        Width = 75
        Height = 25
        Caption = 'bulcan'
        TabOrder = 27
        OnClick = Button197Click
      end
      object Edit16: TEdit
        Left = 440
        Top = 647
        Width = 49
        Height = 21
        TabOrder = 28
        Text = 'Edit16'
      end
      object Button200: TButton
        Left = 93
        Top = 578
        Width = 75
        Height = 25
        Caption = 'all go 125'
        TabOrder = 29
        OnClick = Button200Click
      end
      object CheckBox19: TCheckBox
        Left = 179
        Top = 569
        Width = 97
        Height = 17
        Caption = 'mekan'
        TabOrder = 30
      end
      object Button207: TButton
        Left = 179
        Top = 641
        Width = 75
        Height = 25
        Caption = 'AllgoInn'
        TabOrder = 31
        OnClick = Button207Click
      end
      object Button208: TButton
        Left = 179
        Top = 669
        Width = 75
        Height = 25
        Caption = 'indenkutual'
        TabOrder = 32
        OnClick = Button208Click
      end
      object Button209: TButton
        Left = 179
        Top = 700
        Width = 75
        Height = 25
        Caption = 'inekutukoy'
        TabOrder = 33
        OnClick = Button209Click
      end
      object GroupBox24: TGroupBox
        Left = 16
        Top = 609
        Width = 84
        Height = 44
        Caption = 'Chaos Loc'
        TabOrder = 34
        object Edit18: TEdit
          Left = 3
          Top = 13
          Width = 32
          Height = 21
          TabOrder = 0
          Text = '955'
          OnChange = Edit18Change
        end
        object Edit19: TEdit
          Left = 41
          Top = 13
          Width = 35
          Height = 21
          TabOrder = 1
          Text = '502'
          OnChange = Edit19Change
        end
      end
      object mapal: TCheckBox
        Left = 179
        Top = 593
        Width = 52
        Height = 17
        Caption = 'mapal'
        TabOrder = 35
        OnClick = mapalClick
      end
      object matokal: TCheckBox
        Left = 179
        Top = 612
        Width = 62
        Height = 17
        Caption = 'matokal'
        TabOrder = 36
      end
      object Button211: TButton
        Left = 38
        Top = 679
        Width = 75
        Height = 25
        Caption = 'next server'
        TabOrder = 37
        OnClick = Button211Click
      end
      object Button212: TButton
        Left = 106
        Top = 630
        Width = 75
        Height = 25
        Caption = 'test'
        TabOrder = 38
        OnClick = Button212Click
      end
      object will_time_m: TEdit
        Left = 119
        Top = 732
        Width = 26
        Height = 21
        TabOrder = 39
        Text = 'nowl_time_m'
      end
      object will_time_h: TEdit
        Left = 85
        Top = 732
        Width = 28
        Height = 21
        TabOrder = 40
        Text = 'will_time_h'
      end
      object now_time_h: TEdit
        Left = 4
        Top = 710
        Width = 28
        Height = 21
        TabOrder = 41
        Text = 'now_time_h'
      end
      object now_time_m: TEdit
        Left = 38
        Top = 710
        Width = 26
        Height = 21
        TabOrder = 42
        Text = 'now_time_m'
      end
      object will2_time_h: TEdit
        Left = 85
        Top = 752
        Width = 28
        Height = 21
        TabOrder = 43
        Text = 'will_time_h'
      end
      object will2_time_m: TEdit
        Left = 119
        Top = 752
        Width = 26
        Height = 21
        TabOrder = 44
        Text = 'nowl_time_m'
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'Inventory'
      ImageIndex = 5
      object Image1: TImage
        Left = 1046
        Top = 542
        Width = 33
        Height = 39
        Picture.Data = {
          0A544A504547496D61676520040000FFD8FFE000104A46494600010100000100
          010000FFDB00430006040506050406060506070706080A100A0A09090A140E0F
          0C1017141818171416161A1D251F1A1B231C1616202C20232627292A29191F2D
          302D283025282928FFDB0043010707070A080A130A0A13281A161A2828282828
          2828282828282828282828282828282828282828282828282828282828282828
          28282828282828282828282828FFC00011080020002003012200021101031101
          FFC4001F0000010501010101010100000000000000000102030405060708090A
          0BFFC400B5100002010303020403050504040000017D01020300041105122131
          410613516107227114328191A1082342B1C11552D1F02433627282090A161718
          191A25262728292A3435363738393A434445464748494A535455565758595A63
          6465666768696A737475767778797A838485868788898A92939495969798999A
          A2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4D5D6
          D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FAFFC4001F01000301
          01010101010101010000000000000102030405060708090A0BFFC400B5110002
          0102040403040705040400010277000102031104052131061241510761711322
          328108144291A1B1C109233352F0156272D10A162434E125F11718191A262728
          292A35363738393A434445464748494A535455565758595A636465666768696A
          737475767778797A82838485868788898A92939495969798999AA2A3A4A5A6A7
          A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4D5D6D7D8D9DAE2E3
          E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002110311003F00F9F6
          1431DAC5BE08B0541DCC80F6AB163E1FD4B570ADA769CD246C7894A044F7E6BA
          9960B46F0F59B08D4C8D6F1A8C9039283FAFF3AE974BF8896C5A3B4BED2CC508
          1B527B73940001D13D3A9C0AE0C1D5A351B755D8F35B9A7A2392B5F85D7F247B
          EF6FED2DC0E582A93803DF8A8750F0C786F4ED2AEA53A9BDDCE2263114718DF8
          38E80E79FA57B35A8B7D52C1A58944D68E0A9DE842BFA8E7AFF2AE73C5DE0ED1
          DBC3DA9DE4560D6D3C76D248AF6F232025149E5790457B9185274F9E8A4FD6E6
          5EDE4E5693367C1FF09E2D5F44D2EF753D48B58DCD94321B7863C320689470C7
          A67BD779A67C37F0AE992192DF494BAB80817CCBA91A5031FECF083A0EB50782
          BC59E1983C1BA04375E21D25258B4FB7478E4BC8C1561128208CF041C8AD97F1
          BF84C300DE23D21CE3200BD8FF00C6BCEA787A34F646CF996E3A4D32DF2A250D
          295E1628D70ABEC303007D2B95F89405A7843570624512595C46BCFDD6F2C9C6
          07B03D38181935B775E3DF0C2473B1F10E94914637109748D9E3B004B31F6C57
          8EFC4FF891A6EB3A75D5968D246215574964908CB96465C20072DC81CF400D69
          5F15C90F7756F630517295923FFFD9}
      end
      object Button3: TButton
        Left = 166
        Top = 652
        Width = 75
        Height = 25
        Caption = 'save'
        TabOrder = 0
        OnClick = Button3Click
      end
      object GroupBox4: TGroupBox
        Left = 31
        Top = 522
        Width = 129
        Height = 124
        Caption = 'Sell'
        TabOrder = 1
        object SellList: TListBox
          Left = 3
          Top = 16
          Width = 121
          Height = 97
          ItemHeight = 13
          TabOrder = 0
          OnKeyDown = SellListKeyDown
        end
      end
      object GroupBox5: TGroupBox
        Left = 166
        Top = 522
        Width = 129
        Height = 124
        Caption = 'Crash'
        TabOrder = 2
        object CrashList: TListBox
          Left = 3
          Top = 16
          Width = 121
          Height = 97
          ItemHeight = 13
          TabOrder = 0
          OnKeyDown = CrashListKeyDown
        end
      end
      object GroupBox6: TGroupBox
        Left = 301
        Top = 522
        Width = 129
        Height = 124
        Caption = 'Trade'
        TabOrder = 3
        object TradeList: TListBox
          Left = 3
          Top = 16
          Width = 121
          Height = 97
          ItemHeight = 13
          TabOrder = 0
          OnKeyDown = TradeListKeyDown
        end
      end
      object Button6: TButton
        Left = 85
        Top = 652
        Width = 75
        Height = 25
        Caption = 'inv getir'
        TabOrder = 4
        OnClick = Button6Click
      end
      object Button11: TButton
        Left = 247
        Top = 652
        Width = 75
        Height = 25
        Caption = 'ref'
        TabOrder = 5
        OnClick = Button11Click
      end
      object Button88: TButton
        Left = 887
        Top = 628
        Width = 75
        Height = 25
        Caption = 'inn'
        TabOrder = 6
        OnClick = Button88Click
      end
      object Edit11: TEdit
        Left = 29
        Top = 652
        Width = 50
        Height = 21
        TabOrder = 7
        Text = '0'
      end
      object Button206: TButton
        Left = 400
        Top = 652
        Width = 75
        Height = 25
        Caption = 'buy birak'
        TabOrder = 8
        OnClick = Button206Click
      end
      object Edit17: TEdit
        Left = 344
        Top = 652
        Width = 50
        Height = 21
        TabOrder = 9
        Text = 'Edit17'
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Skill/Stats'
      ImageIndex = 4
      object GroupBox7: TGroupBox
        Left = 3
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 0
        object Label10: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label11: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label12: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label13: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label14: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label15: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button4: TButton
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button7: TButton
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button8: TButton
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button9: TButton
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button10: TButton
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button141: TButton
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button142: TButton
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button143: TButton
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button144: TButton
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button145: TButton
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox8: TGroupBox
        Left = 106
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 1
        object Label16: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label17: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label18: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label19: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label20: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label21: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button12: TButton
          Tag = 1
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button13: TButton
          Tag = 1
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button14: TButton
          Tag = 1
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button15: TButton
          Tag = 1
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button16: TButton
          Tag = 1
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button146: TButton
          Tag = 1
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button147: TButton
          Tag = 1
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button148: TButton
          Tag = 1
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button149: TButton
          Tag = 1
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button150: TButton
          Tag = 1
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox9: TGroupBox
        Left = 209
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 2
        object Label22: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label23: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label24: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label25: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label26: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label27: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button17: TButton
          Tag = 2
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button18: TButton
          Tag = 2
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button19: TButton
          Tag = 2
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button20: TButton
          Tag = 2
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button21: TButton
          Tag = 2
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button151: TButton
          Tag = 2
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button152: TButton
          Tag = 2
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button153: TButton
          Tag = 2
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button154: TButton
          Tag = 2
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button155: TButton
          Tag = 2
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox10: TGroupBox
        Left = 312
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 3
        object Label28: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label29: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label30: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label31: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label32: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label33: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button22: TButton
          Tag = 3
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button23: TButton
          Tag = 3
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button24: TButton
          Tag = 3
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button25: TButton
          Tag = 3
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button26: TButton
          Tag = 3
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button156: TButton
          Tag = 3
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button157: TButton
          Tag = 3
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button158: TButton
          Tag = 3
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button159: TButton
          Tag = 3
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button160: TButton
          Tag = 3
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox11: TGroupBox
        Left = 415
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 4
        object Label34: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label35: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label36: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label37: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label38: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label39: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button27: TButton
          Tag = 4
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button28: TButton
          Tag = 4
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button29: TButton
          Tag = 4
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button30: TButton
          Tag = 4
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button31: TButton
          Tag = 4
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button161: TButton
          Tag = 4
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button162: TButton
          Tag = 4
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button163: TButton
          Tag = 4
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button164: TButton
          Tag = 4
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button165: TButton
          Tag = 4
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox12: TGroupBox
        Left = 518
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 5
        object Label40: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label41: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label42: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label43: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label44: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label45: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button32: TButton
          Tag = 5
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button33: TButton
          Tag = 5
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button34: TButton
          Tag = 5
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button35: TButton
          Tag = 5
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button36: TButton
          Tag = 5
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button166: TButton
          Tag = 5
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button167: TButton
          Tag = 5
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button168: TButton
          Tag = 5
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button169: TButton
          Tag = 5
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button170: TButton
          Tag = 5
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox13: TGroupBox
        Left = 621
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 6
        object Label46: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label47: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label48: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label49: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label50: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label51: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button37: TButton
          Tag = 6
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button38: TButton
          Tag = 6
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button39: TButton
          Tag = 6
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button40: TButton
          Tag = 6
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button41: TButton
          Tag = 6
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button171: TButton
          Tag = 6
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button172: TButton
          Tag = 6
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button173: TButton
          Tag = 6
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button174: TButton
          Tag = 6
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button175: TButton
          Tag = 6
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox14: TGroupBox
        Left = 724
        Top = 0
        Width = 97
        Height = 126
        Caption = 'Stats'
        TabOrder = 7
        object Label52: TLabel
          Left = 16
          Top = 16
          Width = 14
          Height = 13
          Caption = 'Str'
        end
        object Label53: TLabel
          Left = 16
          Top = 31
          Width = 19
          Height = 13
          Caption = 'Dex'
        end
        object Label54: TLabel
          Left = 16
          Top = 46
          Width = 13
          Height = 13
          Caption = 'Hp'
        end
        object Label55: TLabel
          Left = 16
          Top = 61
          Width = 14
          Height = 13
          Caption = 'Mp'
        end
        object Label56: TLabel
          Left = 16
          Top = 76
          Width = 14
          Height = 13
          Caption = 'Int'
        end
        object Label57: TLabel
          Left = 26
          Top = 97
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button42: TButton
          Tag = 7
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = '+'
          TabOrder = 0
          OnClick = givestat
        end
        object Button43: TButton
          Tag = 7
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = '+'
          TabOrder = 1
          OnClick = givestat
        end
        object Button44: TButton
          Tag = 7
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = '+'
          TabOrder = 2
          OnClick = givestat
        end
        object Button45: TButton
          Tag = 7
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 3
          OnClick = givestat
        end
        object Button46: TButton
          Tag = 7
          Left = 69
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = '+'
          TabOrder = 4
          OnClick = givestat
        end
        object Button176: TButton
          Tag = 7
          Left = 52
          Top = 16
          Width = 15
          Height = 15
          Hint = '1'
          Caption = 'A'
          TabOrder = 5
          OnClick = givestatall
        end
        object Button177: TButton
          Tag = 7
          Left = 52
          Top = 31
          Width = 15
          Height = 15
          Hint = '2'
          Caption = 'A'
          TabOrder = 6
          OnClick = givestatall
        end
        object Button178: TButton
          Tag = 7
          Left = 52
          Top = 46
          Width = 15
          Height = 15
          Hint = '3'
          Caption = 'A'
          TabOrder = 7
          OnClick = givestatall
        end
        object Button179: TButton
          Tag = 7
          Left = 52
          Top = 61
          Width = 15
          Height = 15
          Hint = '5'
          Caption = 'A'
          TabOrder = 8
          OnClick = givestatall
        end
        object Button180: TButton
          Tag = 7
          Left = 52
          Top = 76
          Width = 15
          Height = 15
          Hint = '4'
          Caption = 'A'
          TabOrder = 9
          OnClick = givestatall
        end
      end
      object GroupBox15: TGroupBox
        Left = 3
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 8
        object Label58: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label59: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label60: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label61: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label62: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button47: TButton
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button48: TButton
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button49: TButton
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button50: TButton
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox16: TGroupBox
        Left = 106
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 9
        object Label63: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label64: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label65: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label66: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label67: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button51: TButton
          Tag = 1
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button52: TButton
          Tag = 1
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button53: TButton
          Tag = 1
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button54: TButton
          Tag = 1
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox17: TGroupBox
        Left = 209
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 10
        object Label68: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label69: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label70: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label71: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label72: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button55: TButton
          Tag = 2
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button56: TButton
          Tag = 2
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button57: TButton
          Tag = 2
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button58: TButton
          Tag = 2
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox18: TGroupBox
        Left = 312
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 11
        object Label73: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label74: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label75: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label76: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label77: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button59: TButton
          Tag = 3
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button60: TButton
          Tag = 3
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button61: TButton
          Tag = 3
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button62: TButton
          Tag = 3
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox19: TGroupBox
        Left = 415
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 12
        object Label78: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label79: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label80: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label81: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label82: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button63: TButton
          Tag = 4
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button64: TButton
          Tag = 4
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button65: TButton
          Tag = 4
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button66: TButton
          Tag = 4
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox20: TGroupBox
        Left = 518
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 13
        object Label83: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label84: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label85: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label86: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label87: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button67: TButton
          Tag = 5
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button68: TButton
          Tag = 5
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button69: TButton
          Tag = 5
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button70: TButton
          Tag = 5
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox21: TGroupBox
        Left = 621
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 14
        object Label88: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label89: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label90: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label91: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label92: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
        end
        object Button71: TButton
          Tag = 6
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button72: TButton
          Tag = 6
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button73: TButton
          Tag = 6
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button74: TButton
          Tag = 6
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object GroupBox22: TGroupBox
        Left = 724
        Top = 132
        Width = 97
        Height = 101
        Caption = 'Skills'
        TabOrder = 15
        object Label93: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Skill0'
        end
        object Label94: TLabel
          Left = 16
          Top = 31
          Width = 23
          Height = 13
          Caption = 'Skill1'
        end
        object Label95: TLabel
          Left = 16
          Top = 46
          Width = 23
          Height = 13
          Caption = 'Skill2'
        end
        object Label96: TLabel
          Left = 16
          Top = 61
          Width = 23
          Height = 13
          Caption = 'Skill3'
        end
        object Label97: TLabel
          Left = 34
          Top = 80
          Width = 24
          Height = 13
          Caption = 'Point'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
        end
        object Button75: TButton
          Tag = 7
          Left = 69
          Top = 16
          Width = 15
          Height = 15
          Hint = '5'
          Caption = '+'
          TabOrder = 0
          OnClick = giveskill
        end
        object Button76: TButton
          Tag = 7
          Left = 69
          Top = 31
          Width = 15
          Height = 15
          Hint = '6'
          Caption = '+'
          TabOrder = 1
          OnClick = giveskill
        end
        object Button77: TButton
          Tag = 7
          Left = 69
          Top = 46
          Width = 15
          Height = 15
          Hint = '7'
          Caption = '+'
          TabOrder = 2
          OnClick = giveskill
        end
        object Button78: TButton
          Tag = 7
          Left = 69
          Top = 61
          Width = 15
          Height = 15
          Hint = '8'
          Caption = '+'
          TabOrder = 3
          OnClick = giveskill
        end
      end
      object st1job: TButton
        Left = 827
        Top = 132
        Width = 75
        Height = 25
        Caption = '1stjob'
        TabOrder = 16
        OnClick = st1jobClick
      end
      object GroupBox23: TGroupBox
        Left = 3
        Top = 263
        Width = 97
        Height = 282
        Caption = 'Dolas Koordinatlar'
        TabOrder = 17
        object ListBox1: TListBox
          Left = 3
          Top = 14
          Width = 45
          Height = 105
          ItemHeight = 13
          TabOrder = 0
        end
        object Edit4: TEdit
          Left = 3
          Top = 122
          Width = 47
          Height = 21
          TabOrder = 1
          Text = 'X'
        end
        object Edit5: TEdit
          Left = 3
          Top = 145
          Width = 47
          Height = 21
          TabOrder = 2
          Text = 'Y'
        end
        object Button2: TButton
          Left = 54
          Top = 122
          Width = 39
          Height = 44
          Caption = 'Add'
          TabOrder = 3
        end
        object ListBox2: TListBox
          Left = 49
          Top = 14
          Width = 45
          Height = 105
          ItemHeight = 13
          TabOrder = 4
        end
        object CheckBox1: TCheckBox
          Left = 3
          Top = 172
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 5
          OnClick = CheckBox1Click
        end
        object CheckBox2: TCheckBox
          Tag = 1
          Left = 3
          Top = 185
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 6
          OnClick = CheckBox1Click
        end
        object CheckBox3: TCheckBox
          Tag = 2
          Left = 3
          Top = 197
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 7
          OnClick = CheckBox1Click
        end
        object CheckBox4: TCheckBox
          Tag = 3
          Left = 3
          Top = 210
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 8
          OnClick = CheckBox1Click
        end
        object CheckBox5: TCheckBox
          Tag = 4
          Left = 3
          Top = 223
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 9
          OnClick = CheckBox1Click
        end
        object CheckBox6: TCheckBox
          Tag = 5
          Left = 3
          Top = 236
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 10
          OnClick = CheckBox1Click
        end
        object CheckBox7: TCheckBox
          Tag = 6
          Left = 3
          Top = 249
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 11
          OnClick = CheckBox1Click
        end
        object CheckBox8: TCheckBox
          Tag = 7
          Left = 3
          Top = 262
          Width = 64
          Height = 17
          Hint = '9'
          Caption = 'Dolas'
          TabOrder = 12
          OnClick = CheckBox1Click
        end
      end
      object GroupBox31: TGroupBox
        Left = 3
        Top = 548
        Width = 97
        Height = 76
        Caption = 'DolasCalculate'
        TabOrder = 18
        object Label98: TLabel
          Left = 11
          Top = 20
          Width = 32
          Height = 13
          Caption = 'Radius'
        end
        object Edit20: TEdit
          Left = 49
          Top = 17
          Width = 41
          Height = 21
          TabOrder = 0
          Text = '30'
        end
        object Button86: TButton
          Left = 16
          Top = 43
          Width = 75
          Height = 25
          Caption = 'Set'
          TabOrder = 1
          OnClick = Button86Click
        end
      end
      object Dolas: TButton
        Left = 0
        Top = 651
        Width = 75
        Height = 25
        Caption = 'DolasBasla'
        TabOrder = 19
        OnClick = DolasClick
      end
      object Button82: TButton
        Left = 414
        Top = 336
        Width = 75
        Height = 25
        Caption = 'Refresh'
        TabOrder = 20
        OnClick = Button82Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'SkillUse'
      ImageIndex = 4
      object BuffSkillList: TCheckListBox
        Left = 960
        Top = 226
        Width = 75
        Height = 223
        OnClickCheck = BuffSkillListClickCheck
        ItemHeight = 13
        Items.Strings = (
          'ac40'
          'buf240'
          'ac80'
          'buf360'
          'ac120'
          'buf720'
          'ac160'
          'buf960'
          'ac200'
          'undying'
          'buf1200'
          'buf1500'
          'ac300'
          'buf2000'
          'ac350'
          'buf2500')
        TabOrder = 0
      end
      object HealList: TCheckListBox
        Left = 960
        Top = 455
        Width = 75
        Height = 86
        OnClickCheck = HealListClickCheck
        ItemHeight = 13
        Items.Strings = (
          '240'
          '360'
          '720'
          '960'
          '1920')
        TabOrder = 1
      end
      object AtackType: TRadioGroup
        Left = 914
        Top = 566
        Width = 121
        Height = 99
        Caption = 'AtackType'
        ItemIndex = 2
        Items.Strings = (
          'All'
          'Only Player'
          'Only Npc')
        TabOrder = 2
        OnClick = AtackTypeClick
      end
      object GroupBox46: TGroupBox
        Left = 5
        Top = 3
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 3
        object ListBox4: TListBox
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox5: TListBox
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox6: TListBox
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox7: TListBox
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo9: TMemo
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox8: TListBox
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button94: TButton
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button95: TButton
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button96: TButton
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button97: TButton
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button98: TButton
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox45: TGroupBox
        Left = 223
        Top = 0
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 4
        object ListBox9: TListBox
          Tag = 1
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox10: TListBox
          Tag = 1
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox11: TListBox
          Tag = 1
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox12: TListBox
          Tag = 1
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo10: TMemo
          Tag = 1
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox13: TListBox
          Tag = 1
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button99: TButton
          Tag = 1
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button100: TButton
          Tag = 1
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button101: TButton
          Tag = 1
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button102: TButton
          Tag = 1
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button103: TButton
          Tag = 1
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox47: TGroupBox
        Left = 445
        Top = 3
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 5
        object ListBox14: TListBox
          Tag = 2
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox15: TListBox
          Tag = 2
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox16: TListBox
          Tag = 2
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox17: TListBox
          Tag = 2
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo11: TMemo
          Tag = 2
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox18: TListBox
          Tag = 2
          Left = 141
          Top = 59
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button104: TButton
          Tag = 2
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button105: TButton
          Tag = 2
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button106: TButton
          Tag = 2
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button107: TButton
          Tag = 2
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button108: TButton
          Tag = 2
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox48: TGroupBox
        Left = 672
        Top = 9
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 6
        object ListBox19: TListBox
          Tag = 3
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox20: TListBox
          Tag = 3
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox21: TListBox
          Tag = 3
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox22: TListBox
          Tag = 3
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo12: TMemo
          Tag = 3
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox23: TListBox
          Tag = 3
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button109: TButton
          Tag = 3
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button110: TButton
          Tag = 3
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button111: TButton
          Tag = 3
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button112: TButton
          Tag = 3
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button113: TButton
          Tag = 3
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox49: TGroupBox
        Left = 3
        Top = 274
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 7
        object ListBox24: TListBox
          Tag = 4
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox25: TListBox
          Tag = 4
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox26: TListBox
          Tag = 4
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox27: TListBox
          Tag = 4
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo13: TMemo
          Tag = 4
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox28: TListBox
          Tag = 4
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button114: TButton
          Tag = 4
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button115: TButton
          Tag = 4
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button116: TButton
          Tag = 4
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button117: TButton
          Tag = 4
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button118: TButton
          Tag = 4
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox50: TGroupBox
        Left = 219
        Top = 274
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 8
        object ListBox29: TListBox
          Tag = 5
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox30: TListBox
          Tag = 5
          Left = 6
          Top = 18
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox31: TListBox
          Tag = 5
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox32: TListBox
          Tag = 5
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo14: TMemo
          Tag = 5
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox33: TListBox
          Tag = 5
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button119: TButton
          Tag = 5
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button120: TButton
          Tag = 5
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button121: TButton
          Tag = 5
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button122: TButton
          Tag = 5
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button123: TButton
          Tag = 5
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox51: TGroupBox
        Left = 443
        Top = 277
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 9
        object ListBox34: TListBox
          Tag = 6
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox35: TListBox
          Tag = 6
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox36: TListBox
          Tag = 6
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox37: TListBox
          Tag = 6
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo15: TMemo
          Tag = 6
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox38: TListBox
          Tag = 6
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button124: TButton
          Tag = 6
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button125: TButton
          Tag = 6
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button126: TButton
          Tag = 6
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button127: TButton
          Tag = 6
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button128: TButton
          Tag = 6
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object GroupBox52: TGroupBox
        Left = 667
        Top = 277
        Width = 214
        Height = 268
        Caption = 'GroupBox45'
        TabOrder = 10
        object ListBox39: TListBox
          Tag = 7
          Left = -5
          Top = 129
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 0
          Visible = False
        end
        object ListBox40: TListBox
          Tag = 7
          Left = 6
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 1
          OnDblClick = SkillListDblClick
        end
        object ListBox41: TListBox
          Tag = 7
          Left = 33
          Top = 64
          Width = 57
          Height = 73
          ItemHeight = 13
          TabOrder = 2
          Visible = False
        end
        object ListBox42: TListBox
          Tag = 7
          Left = 77
          Top = 17
          Width = 71
          Height = 206
          ItemHeight = 13
          TabOrder = 3
          OnDblClick = SelectedSkillsDblClick
        end
        object Memo16: TMemo
          Tag = 7
          Left = 147
          Top = 17
          Width = 51
          Height = 206
          TabOrder = 4
          OnChange = SkillTimeChange
        end
        object ListBox43: TListBox
          Tag = 7
          Left = 106
          Top = 38
          Width = 55
          Height = 73
          ItemHeight = 13
          TabOrder = 5
          Visible = False
        end
        object Button129: TButton
          Tag = 7
          Left = 43
          Top = 229
          Width = 40
          Height = 25
          Caption = '0'
          TabOrder = 6
          OnClick = skill5Click
        end
        object Button130: TButton
          Tag = 7
          Left = 3
          Top = 229
          Width = 40
          Height = 25
          Caption = 'Basic'
          TabOrder = 7
          OnClick = skill0Click
        end
        object Button131: TButton
          Tag = 7
          Left = 83
          Top = 229
          Width = 40
          Height = 25
          Caption = '1'
          TabOrder = 8
          OnClick = skill6Click
        end
        object Button132: TButton
          Tag = 7
          Left = 123
          Top = 229
          Width = 40
          Height = 25
          Caption = '2'
          TabOrder = 9
          OnClick = skill7Click
        end
        object Button133: TButton
          Tag = 7
          Left = 163
          Top = 229
          Width = 40
          Height = 25
          Caption = '3'
          TabOrder = 10
          OnClick = skill8Click
        end
      end
      object AllSameSkill: TCheckBox
        Left = 199
        Top = 592
        Width = 97
        Height = 17
        Caption = 'AllSameSkill'
        TabOrder = 11
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'deneme'
      ImageIndex = 5
      object ListBoxtt: TListBox
        Left = 368
        Top = 3
        Width = 121
        Height = 414
        ItemHeight = 13
        TabOrder = 0
        OnDblClick = ListBoxttDblClick
      end
      object HealSkillKod: TListBox
        Left = 520
        Top = 232
        Width = 54
        Height = 86
        ItemHeight = 13
        Items.Strings = (
          '112509'
          '112518'
          '112527'
          '112536'
          '112545')
        TabOrder = 1
        Visible = False
      end
      object BuffSkillKod: TListBox
        Left = 523
        Top = 3
        Width = 57
        Height = 223
        ItemHeight = 13
        Items.Strings = (
          '112612'
          '112615'
          '112621'
          '112624'
          '112630'
          '112633'
          '112639'
          '112642'
          '112651'
          '112654'
          '112655'
          '112657'
          '112660'
          '112670'
          '112674'
          '112675')
        TabOrder = 2
        Visible = False
      end
      object RadioGroup2: TRadioGroup
        Left = 494
        Top = 199
        Width = 85
        Height = 159
        Caption = 'RadioGroup2'
        ItemIndex = 0
        Items.Strings = (
          'socket0'
          'socket1'
          'socket2'
          'socket3'
          'socket4'
          'socket5'
          'socket6'
          'socket7')
        TabOrder = 3
      end
      object CheckBox9: TCheckBox
        Left = 29
        Top = 593
        Width = 97
        Height = 17
        Caption = 'Upgrade'
        TabOrder = 4
        OnClick = CheckBox9Click
      end
      object Button85: TButton
        Left = 128
        Top = 589
        Width = 75
        Height = 25
        Caption = 'gobuy'
        TabOrder = 5
        OnClick = Button85Click
      end
      object Edit6: TEdit
        Left = 45
        Top = 535
        Width = 121
        Height = 21
        TabOrder = 6
        Text = '262001001'
      end
      object Edit7: TEdit
        Left = 45
        Top = 562
        Width = 121
        Height = 21
        TabOrder = 7
        Text = '12'
      end
      object Button87: TButton
        Left = 172
        Top = 554
        Width = 75
        Height = 25
        Caption = 'Inn'
        TabOrder = 8
        OnClick = Button87Click
      end
      object ListBox3: TListBox
        Left = 241
        Top = 3
        Width = 121
        Height = 414
        ItemHeight = 13
        TabOrder = 9
        OnDblClick = ListBox3DblClick
      end
      object Button1: TButton
        Left = 266
        Top = 423
        Width = 75
        Height = 25
        Caption = 'NearestGate'
        TabOrder = 10
        OnClick = Button1Click
      end
      object RadioGroup4: TRadioGroup
        Left = 229
        Top = 648
        Width = 76
        Height = 105
        Caption = 'RadioGroup4'
        ItemIndex = 0
        Items.Strings = (
          'Paldron'
          'Pad'
          'helmet'
          'gauntlet'
          'bot')
        TabOrder = 11
        OnClick = RadioGroup4Click
      end
      object RadioGroup5: TRadioGroup
        Left = 144
        Top = 648
        Width = 79
        Height = 105
        Caption = 'RadioGroup5'
        ItemIndex = 0
        Items.Strings = (
          'paper'
          'linen'
          'plate')
        TabOrder = 12
        OnClick = RadioGroup5Click
      end
      object RadioGroup6: TRadioGroup
        Left = 60
        Top = 648
        Width = 78
        Height = 105
        Caption = 'RadioGroup6'
        ItemIndex = 0
        Items.Strings = (
          'warrior'
          'rogue'
          'mage'
          'priest')
        TabOrder = 13
        OnClick = RadioGroup6Click
      end
      object Button92: TButton
        Left = 344
        Top = 656
        Width = 75
        Height = 25
        Caption = 'Button92'
        TabOrder = 14
        OnClick = Button92Click
      end
      object Button93: TButton
        Left = 400
        Top = 768
        Width = 75
        Height = 25
        Caption = 'Button93'
        TabOrder = 15
        OnClick = Button93Click
      end
      object buybow: TRadioGroup
        Left = 593
        Top = 440
        Width = 185
        Height = 105
        Caption = 'buybow'
        Items.Strings = (
          'Bow(321)'
          'Short Bow(767)'
          'Rapt Bow(3.392)'
          'Composite Bow(20.812)'
          'Crossbow(92.466)'
          'Horncrossbow(164.032)')
        TabOrder = 16
        OnClick = buybowClick
      end
      object Button134: TButton
        Left = 800
        Top = 562
        Width = 75
        Height = 25
        Caption = 'Button134'
        TabOrder = 17
        OnClick = Button134Click
      end
      object BuyBowSocks: TCheckListBox
        Left = 784
        Top = 448
        Width = 121
        Height = 108
        ItemHeight = 13
        Items.Strings = (
          'Socket0'
          'Socket1'
          'Socket2'
          'Socket3'
          'Socket4'
          'Socket5'
          'Socket6'
          'Socket7')
        TabOrder = 18
      end
      object ListBox44: TListBox
        Left = 651
        Top = 35
        Width = 121
        Height = 300
        ItemHeight = 13
        TabOrder = 19
      end
      object Button135: TButton
        Left = 663
        Top = 341
        Width = 92
        Height = 25
        Caption = 'listnearplayers'
        TabOrder = 20
        OnClick = Button135Click
      end
      object GroupBox53: TGroupBox
        Left = 544
        Top = 616
        Width = 418
        Height = 137
        Caption = 'Chat'
        TabOrder = 21
        object Label8: TLabel
          Left = 4
          Top = 76
          Width = 57
          Height = 13
          Caption = 'Zaman(ms):'
        end
        object Button182: TButton
          Left = 113
          Top = 100
          Width = 164
          Height = 25
          Caption = 'Basla'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Mesaj: TMemo
          Left = 101
          Top = 21
          Width = 187
          Height = 49
          Lines.Strings = (
            'www,farmersbot,com For Best bot '
            'Solution for KnightOnLine [[FREE for '
            'a while]][maden][atack][merchant]')
          TabOrder = 1
          OnChange = MesajChange
        end
        object Edit8: TEdit
          Left = 67
          Top = 73
          Width = 40
          Height = 21
          TabOrder = 2
          Text = '500'
          OnChange = Edit8Change
        end
        object ChatTipi: TRadioGroup
          Left = 4
          Top = 13
          Width = 91
          Height = 57
          Caption = 'ChatTipi'
          ItemIndex = 0
          Items.Strings = (
            'AllChat'
            'Shout'
            'Merchant')
          TabOrder = 3
          OnClick = ChatTipiClick
        end
        object PM: TCheckBox
          Left = 186
          Top = 76
          Width = 41
          Height = 17
          Caption = 'PM'
          TabOrder = 4
        end
        object ChatList: TCheckListBox
          Left = 294
          Top = 21
          Width = 121
          Height = 108
          ItemHeight = 13
          Items.Strings = (
            'Socket0'
            'Socket1'
            'Socket2'
            'Socket3'
            'Socket4'
            'Socket5'
            'Socket6'
            'Socket7')
          TabOrder = 5
          OnClick = ChatListClick
        end
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'TabSheet7'
      ImageIndex = 6
      object inngetir: TButton
        Left = 564
        Top = 146
        Width = 75
        Height = 25
        Caption = 'i'
        TabOrder = 0
        OnClick = inngetirClick
      end
      object innpage: TEdit
        Left = 437
        Top = 148
        Width = 121
        Height = 21
        TabOrder = 1
        Text = 'innpage'
      end
    end
    object TabSheet8: TTabSheet
      Caption = 'TabSheet8'
      ImageIndex = 7
      object spdlbl: TLabel
        Left = 673
        Top = 572
        Width = 12
        Height = 13
        Caption = '10'
      end
      object AllPtOk: TButton
        Left = 467
        Top = 427
        Width = 75
        Height = 25
        Caption = 'AllPtOk'
        TabOrder = 0
        OnClick = AllPtOkClick
      end
      object AllPtQuit: TButton
        Left = 548
        Top = 427
        Width = 75
        Height = 25
        Caption = 'AllPtQuit'
        TabOrder = 1
        OnClick = AllPtQuitClick
      end
      object AllTown: TButton
        Left = 710
        Top = 427
        Width = 75
        Height = 25
        Caption = 'AllTown'
        TabOrder = 2
        OnClick = AllTownClick
      end
      object KazBasla: TButton
        Left = 298
        Top = 426
        Width = 75
        Height = 25
        Caption = 'KazBasla'
        TabOrder = 3
        OnClick = KazBaslaClick
      end
      object KazDur: TButton
        Left = 379
        Top = 426
        Width = 75
        Height = 25
        Caption = 'KazDur'
        TabOrder = 4
        OnClick = KazDurClick
      end
      object Trade: TRadioGroup
        Left = 107
        Top = 403
        Width = 69
        Height = 87
        Caption = 'Trade'
        ItemIndex = 2
        Items.Strings = (
          'Nothing'
          'Accept'
          'Decline'
          'only ok')
        TabOrder = 5
      end
      object GroupBox32: TGroupBox
        Left = 29
        Top = 401
        Width = 75
        Height = 42
        Caption = 'Special Code'
        TabOrder = 6
        object spcode: TEdit
          Left = 3
          Top = 18
          Width = 69
          Height = 21
          TabOrder = 0
          Text = 'TTT'
        end
      end
      object RunToMob: TCheckBox
        Left = 182
        Top = 429
        Width = 97
        Height = 17
        Caption = 'RunToMob'
        TabOrder = 7
        OnClick = RunToMobClick
      end
      object AutoClan: TRadioGroup
        Left = 29
        Top = 442
        Width = 72
        Height = 50
        Caption = 'AutoClan'
        ItemIndex = 1
        Items.Strings = (
          'Accept'
          'Decline')
        TabOrder = 8
      end
      object GroupBox2: TGroupBox
        Left = 224
        Top = 551
        Width = 149
        Height = 42
        Caption = 'Mine Settings'
        TabOrder = 9
        object Label3: TLabel
          Left = 3
          Top = 16
          Width = 49
          Height = 13
          Caption = 'Mining Loc'
        end
        object MineY: TEdit
          Left = 100
          Top = 13
          Width = 44
          Height = 21
          TabOrder = 0
          Text = '369'
          OnChange = MineYChange
        end
        object MineX: TEdit
          Left = 62
          Top = 13
          Width = 38
          Height = 21
          TabOrder = 1
          Text = '629'
          OnChange = MineXChange
        end
      end
      object Button81: TButton
        Left = 36
        Top = 522
        Width = 84
        Height = 25
        Caption = 'doda55gorevlerial'
        TabOrder = 10
      end
      object RAtack: TCheckBox
        Left = 298
        Top = 403
        Width = 97
        Height = 17
        Caption = 'RAtack'
        TabOrder = 11
        OnClick = RAtackClick
      end
      object CheckBox10: TCheckBox
        Left = 182
        Top = 452
        Width = 97
        Height = 17
        BiDiMode = bdRightToLeftNoAlign
        Caption = 'Buy Potions'
        ParentBiDiMode = False
        TabOrder = 12
        OnClick = CheckBox10Click
      end
      object CheckBox11: TCheckBox
        Left = 182
        Top = 475
        Width = 97
        Height = 17
        Caption = 'AutoParty'
        TabOrder = 13
        OnClick = CheckBox11Click
      end
      object GroupBox30: TGroupBox
        Left = 176
        Top = 498
        Width = 241
        Height = 42
        Caption = 'AtackLocation'
        TabOrder = 14
        object Label4: TLabel
          Left = 3
          Top = 16
          Width = 43
          Height = 13
          Caption = 'AtackLoc'
        end
        object Label5: TLabel
          Left = 150
          Top = 16
          Width = 41
          Height = 13
          Caption = 'Distance'
        end
        object AtackY: TEdit
          Left = 100
          Top = 13
          Width = 44
          Height = 21
          TabOrder = 0
          Text = '369'
          OnChange = AtackYChange
        end
        object AtackX: TEdit
          Left = 62
          Top = 13
          Width = 38
          Height = 21
          TabOrder = 1
          Text = '629'
          OnChange = AtackXChange
        end
        object distance: TEdit
          Left = 197
          Top = 13
          Width = 36
          Height = 21
          TabOrder = 2
          Text = '30'
          OnChange = distanceChange
        end
      end
      object GroupBox44: TGroupBox
        Left = 32
        Top = 577
        Width = 107
        Height = 64
        Caption = 'PotBuy'
        TabOrder = 15
        object Label6: TLabel
          Left = 3
          Top = 16
          Width = 52
          Height = 13
          Caption = 'Hp Count :'
        end
        object Label7: TLabel
          Left = 3
          Top = 37
          Width = 53
          Height = 13
          Caption = 'Mp Count :'
        end
        object hpcount: TEdit
          Left = 60
          Top = 13
          Width = 35
          Height = 21
          TabOrder = 0
          Text = '5'
          OnChange = hpcountChange
        end
        object mpcount: TEdit
          Left = 60
          Top = 34
          Width = 35
          Height = 21
          TabOrder = 1
          Text = '250'
          OnChange = mpcountChange
        end
      end
      object Button90: TButton
        Left = 441
        Top = 604
        Width = 75
        Height = 25
        Caption = 'Move'
        TabOrder = 16
        OnClick = Button90Click
      end
      object Button89: TButton
        Left = 686
        Top = 471
        Width = 75
        Height = 25
        Caption = 'AllBif'
        TabOrder = 17
        OnClick = Button89Click
      end
      object SpeedSet: TScrollBar
        Left = 548
        Top = 568
        Width = 121
        Height = 17
        Max = 30
        PageSize = 10
        Position = 10
        TabOrder = 18
        OnChange = SpeedSetChange
      end
      object Button91: TButton
        Left = 686
        Top = 502
        Width = 75
        Height = 25
        Caption = 'AllMatockAl'
        TabOrder = 19
        OnClick = Button91Click
      end
      object Button80: TButton
        Left = 441
        Top = 573
        Width = 75
        Height = 25
        Caption = 'Nearplay'
        TabOrder = 20
      end
      object Button83: TButton
        Left = 686
        Top = 533
        Width = 75
        Height = 25
        Caption = 'Trade Modu'
        TabOrder = 21
        OnClick = Button83Click
      end
      object CheckBox12: TCheckBox
        Left = 285
        Top = 475
        Width = 97
        Height = 17
        Caption = 'NoJail'
        TabOrder = 22
        OnClick = CheckBox12Click
      end
      object Button84: TButton
        Left = 587
        Top = 502
        Width = 75
        Height = 25
        Caption = 'inn 1m koy'
        TabOrder = 23
        OnClick = Button84Click
      end
      object Button136: TButton
        Left = 691
        Top = 564
        Width = 75
        Height = 25
        Caption = 'heppa9staff'
        TabOrder = 24
        OnClick = Button136Click
      end
      object Button137: TButton
        Left = 691
        Top = 595
        Width = 89
        Height = 25
        Caption = 'buy dagger to 0'
        TabOrder = 25
        OnClick = Button137Click
      end
      object Button138: TButton
        Left = 691
        Top = 626
        Width = 90
        Height = 25
        Caption = 'buy scroll to 1'
        TabOrder = 26
        OnClick = Button138Click
      end
      object paraver: TCheckBox
        Left = 110
        Top = 491
        Width = 66
        Height = 17
        Caption = 'paraver'
        TabOrder = 27
      end
      object Button187: TButton
        Left = 385
        Top = 470
        Width = 75
        Height = 25
        Caption = 'chaos zone'
        TabOrder = 28
        OnClick = Button187Click
      end
      object Button139: TButton
        Left = 691
        Top = 651
        Width = 90
        Height = 25
        Caption = 'up dagger'
        TabOrder = 29
        OnClick = Button139Click
      end
      object Button140: TButton
        Left = 692
        Top = 336
        Width = 75
        Height = 25
        Caption = 'givelist'
        TabOrder = 30
        OnClick = Button140Click
      end
      object Edit12: TEdit
        Left = 565
        Top = 338
        Width = 121
        Height = 21
        TabOrder = 31
        Text = 'Edit12'
      end
      object Button205: TButton
        Left = 767
        Top = 502
        Width = 75
        Height = 25
        Caption = 'matok giy'
        TabOrder = 32
        OnClick = Button205Click
      end
    end
    object TabSheet9: TTabSheet
      Caption = 'TabSheet9'
      ImageIndex = 8
      object WebBrowser1: TWebBrowser
        Left = 5
        Top = 3
        Width = 924
        Height = 711
        TabOrder = 0
        ControlData = {
          4C000000805F00007C4900000000000000000000000000000000000000000000
          000000004C000000000000000000000001000000E0D057007335CF11AE690800
          2B2E126208000000000000004C0000000114020000000000C000000000000046
          8000000000000000000000000000000000000000000000000000000000000000
          00000000000000000100000000000000000000000000000000000000}
      end
      object Button201: TButton
        Left = 993
        Top = 3
        Width = 75
        Height = 25
        Caption = 'pus'
        TabOrder = 1
        OnClick = Button201Click
      end
      object Serverlar: TComboBox
        Left = 993
        Top = 93
        Width = 86
        Height = 19
        Style = csOwnerDrawFixed
        BiDiMode = bdLeftToRight
        ItemHeight = 13
        ParentBiDiMode = False
        TabOrder = 2
        Items.Strings = (
          'ARES'
          'DIES'
          'XIGENON'
          'BERAMUS'
          'CYPHER'
          'OLYMPIA'
          'EDANA'
          'MANES'
          'PATHOS'
          'LOGOS'
          'RONARK'
          'GIRAKON'
          'AKARA'
          'C-EAST'
          'C-WEST'
          'IONIA'
          'KRONOS'
          'HELYOS')
      end
      object Karakter: TRadioGroup
        Left = 1005
        Top = 118
        Width = 57
        Height = 65
        Caption = 'Karakter'
        Items.Strings = (
          'Orta'
          'Sol'
          'Sag')
        TabOrder = 3
      end
      object Button202: TButton
        Left = 993
        Top = 34
        Width = 75
        Height = 25
        Caption = 'cash'
        TabOrder = 4
        OnClick = Button202Click
      end
      object RadioGroup1: TRadioGroup
        Left = 935
        Top = 3
        Width = 52
        Height = 270
        Caption = 'RadioGroup1'
        Items.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19')
        TabOrder = 5
      end
      object Button203: TButton
        Left = 993
        Top = 216
        Width = 75
        Height = 25
        Caption = 'Button203'
        TabOrder = 6
        OnClick = Button203Click
      end
    end
  end
  object Button210: TButton
    Left = 485
    Top = 674
    Width = 75
    Height = 25
    Caption = 'nbuykur'
    TabOrder = 2
    OnClick = Button210Click
  end
  object PopupMenu2: TPopupMenu
    Left = 904
    Top = 240
    object Sell1: TMenuItem
      Caption = 'Sell'
      object SellItem1: TMenuItem
        Caption = 'Goto Sell Location'
        OnClick = SellItem1Click
      end
      object SellItem2: TMenuItem
        Caption = 'Sell Item'
        OnClick = SellItem2Click
      end
      object SellAll1: TMenuItem
        Caption = 'Sell All with filter'
        OnClick = SellAll1Click
      end
      object Deneme1: TMenuItem
        Caption = 'Deneme'
      end
    end
    object Crash1: TMenuItem
      Caption = 'Crash'
      object CrashItem1: TMenuItem
        Caption = 'Crash Item'
        OnClick = CrashItem1Click
      end
    end
    object Wear1: TMenuItem
      Caption = 'Wear'
      object RightHand1: TMenuItem
        Caption = 'Right Hand'
        OnClick = RightHandClick
      end
      object LeftHand1: TMenuItem
        Caption = 'Left Hand'
        OnClick = LeftHandClick
      end
      object Helmet1: TMenuItem
        Caption = 'Helmet'
        OnClick = Helmet1Click
      end
      object Pauldron1: TMenuItem
        Caption = 'Pauldron'
        OnClick = Pauldron1Click
      end
      object Pads1: TMenuItem
        Caption = 'Pads'
        OnClick = Pads1Click
      end
      object Bots1: TMenuItem
        Caption = 'Gauntlets'
        OnClick = Bots1Click
      end
      object Bots2: TMenuItem
        Caption = 'Bots'
        OnClick = Bots2Click
      end
      object Earring01: TMenuItem
        Caption = 'Earring0'
        OnClick = Earring01Click
      end
      object Earring11: TMenuItem
        Caption = 'Earring1'
        OnClick = Earring11Click
      end
      object Pendant1: TMenuItem
        Caption = 'Pendant'
        OnClick = Pendant1Click
      end
      object Belt1: TMenuItem
        Caption = 'Belt'
        OnClick = Belt1Click
      end
      object Ring01: TMenuItem
        Caption = 'Ring0'
        OnClick = Ring01Click
      end
      object Ring1: TMenuItem
        Caption = 'Ring1'
        OnClick = Ring1Click
      end
    end
    object Move10: TMenuItem
      Caption = 'Move'
    end
    object Merchant1: TMenuItem
      Caption = 'Merchant'
      object OpenBuy1: TMenuItem
        Caption = 'OpenBuy'
        OnClick = OpenBuy1Click
      end
      object OpenSell1: TMenuItem
        Caption = 'OpenSell'
        OnClick = OpenSell1Click
      end
      object AddToSell1: TMenuItem
        Caption = 'AddToSell'
        OnClick = AddToSell1Click
      end
    end
    object rade1: TMenuItem
      Caption = 'Trade'
      object radeAll1: TMenuItem
        Caption = 'TradeAll'
        object toSocket11: TMenuItem
          Caption = 'toSocket1'
          OnClick = toSocketClick
        end
        object toSocket1: TMenuItem
          Tag = 1
          Caption = 'toSocket2'
          OnClick = toSocketClick
        end
        object toSocket31: TMenuItem
          Tag = 2
          Caption = 'toSocket3'
          OnClick = toSocketClick
        end
        object toSocket32: TMenuItem
          Tag = 3
          Caption = 'toSocket4'
          OnClick = toSocketClick
        end
        object toSocket41: TMenuItem
          Tag = 4
          Caption = 'toSocket5'
          OnClick = toSocketClick
        end
        object toSocket51: TMenuItem
          Tag = 5
          Caption = 'toSocket6'
          OnClick = toSocketClick
        end
        object toSocket61: TMenuItem
          Tag = 6
          Caption = 'toSocket7'
          OnClick = toSocketClick
        end
        object toSocket71: TMenuItem
          Tag = 7
          Caption = 'toSocket8'
          OnClick = toSocketClick
        end
      end
      object T1: TMenuItem
        Caption = 'TradeReq'
      end
      object radeAccept1: TMenuItem
        Caption = 'TradeAccept'
      end
      object radeConfirm1: TMenuItem
        Caption = 'TradeConfirm'
        OnClick = radeConfirm1Click
      end
      object AddThisItem1: TMenuItem
        Caption = 'AddThisItem'
        OnClick = AddThisItem1Click
      end
      object AddMoney1: TMenuItem
        Caption = 'AddMoney'
        OnClick = AddMoney1Click
      end
      object GiveList1: TMenuItem
        Caption = 'GiveList'
        OnClick = GiveList1Click
      end
      object radeCancel1: TMenuItem
        Caption = 'TradeCancel'
      end
    end
    object Inn1: TMenuItem
      Caption = 'Inn'
      object SendToInn01: TMenuItem
        Caption = 'SendToInn0'
        OnClick = SendToInn01Click
      end
    end
    object AddList1: TMenuItem
      Caption = 'AddList'
      object Sell2: TMenuItem
        Caption = 'Sell'
        OnClick = Sell2Click
      end
      object Crash2: TMenuItem
        Caption = 'Crash'
        OnClick = Crash2Click
      end
      object rade2: TMenuItem
        Caption = 'Trade'
        OnClick = rade2Click
      end
    end
    object N20yever1: TMenuItem
      Caption = '20 ye ver'
      OnClick = N20yever1Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 832
    Top = 240
    object check1: TMenuItem
      Caption = 'Unlock'
      OnClick = check1Click
    end
    object Menuu: TMenuItem
      Caption = 'Connection'
      object ConnectAll1: TMenuItem
        Bitmap.Data = {
          360C0000424D360C000000000000360000002800000020000000200000000100
          180000000000000C0000232E0000232E00000000000000000001654B3D240D00
          210E001504001C06002608003505043D00044E04044E0200581000490F005631
          00715E00494A002B1E00430C004A0A09341000281800373400635E212A160051
          342D9573664A2719310800391D003E39005C6405333D011923008766633C1C17
          2F12092407002C0900390B03480B09540A0A580000690E07741E085E13006934
          00B3932FC0B3398F7F0E6235005725005F3F003929004340009692448C8058E4
          CDB7D4B79C4422006A48136D500D6454014D4400221A00130C00A477884C1D2D
          3B0915370006460606530903670D0676100B7F0C0F81090D8B1415821906711D
          00A96D13F3CE4EF3DB41BCA300D1B90DE2CC19BDAE04A59F106F7002484A04C3
          BD88AF9B627B620CF1D852F0D24F5931003C0D00330603230004B0759153152D
          4300104700045E09076B0A00780A00880F0695101289030989050C971F197C18
          007C2C00C38626E6B93AE4C425E4CB1DFCE335FAE543BDB0267F7C02727B0C36
          3C007D7014E4CA5EE3C62FA378005B1B00570F0740000C40041CB872915D142A
          55050A6208017B15038310008707008F07018D03049C15179113129F2C22A63F
          309C3F2AAA543EAE5F3EC07C47B67C3BBB8E4AC19F53A58B379E9222DFE844B1
          BC12938B08AF9426875700550F00721900660F0D561318350004C57A8A6F202B
          6D131278130A8E1C0F91150A920D09920E0E951618B0393AA9413CAF5047C56D
          67C16E6CBD6870BE6E75BC7272B57672C2908AE5BFADFFFFDCFFEF9ED9D344D4
          D129D1BE276440007A3E00A2591F752801550D004F1208300000D28A79833427
          81231E861B1E99222BA12531A52A38A4323FB35058B86468C37D7EC58B86CD96
          91D09C95D7A298EEBDB5EABCBBF0C6CDFFF1FFFFF2FDFFF2EDFFFDE3FFDFAAC8
          A244FFD63DBE8C00814700976519745A005B44003A0F00441004DC96798E422B
          8A31278D2927A0343AAE444BB7555BB96468C58285BC878AD8AFB4DBB9BADDBB
          BBF5D4CBFAD6C6FDD9C7FFEEDFFFF7F3FFEDF9FFF4FFFFF6FAFFF6F2FFDED6C7
          8959EAAE32FFCB3A9B69005B37007265006358006445122E0500E09D88A15C48
          7E35219C503ABD715ABD765BC2876DDBAC96D7B5A8DDC4C0EBD4DCF3DEE7FADF
          E8FFE6E7FFF3E9FFFFE8FFFFDFFFEFC9FFFAEDFFFCF8FFF6ECFFFAECFFEADEC6
          8063884605E5AF4AF0CE457759004C27006946078D75332D1D00D79A90AF7367
          A26754B37A61C18A6BD09F7FE4BC9FEBCDB4FFF2E1FFF7EBFFFCF3FFFCF1FFF6
          E2FFECCFFFE1BCFFDEA9F5D68BDBC478DCD09AF4E9C3FFFADFFFF7E4FFD9CDD7
          9A8C92523A8E5518E6BC41E1B9317B48008C5D139E8235372300DDA9B0B98789
          BA8B83D0A396D5A99CE7BEB5FFE1DFFFF1EEFFF3ECFFF4DEFFF1C4FDE4A4EED0
          7DDDB457CD9A39BF8F26BF9B29B3931CB78F1ED5A94EFFD7A6FFF9E3FADFD5E4
          C4BFB17C796E2D11AA6319FFC353F1BA33FBCB4DA87826431400E0B9BBC7A1A1
          C29C9AD3AEAAEAC5C1FFE1DDFFF5F1FFF8EBFFEBCFFFE3B3F9D48AE3BB5BCB9D
          2EBA830AB27300AF7100AA7800AD7A00AA6800B06A00DB9F63FFFFDFFFF6E6DE
          D0CAC6A2A2A4675D913813B75715C8740EC07715642100460600DBC2AED7BCAE
          CBACA9D8B8B9FFE3E0FFFBEDFFEDC9FFD99FF6CB7CE7B456CD922EB9770EAE64
          00AB5D00B26000B96700B16500BC6D06BD6300B25901BE7335FFE1B8FFFEE3D8
          D4C1C5B8A8C69A8DB4554CA628248C020A720000550000400000E8D4BBD0BBA6
          D4BCB0FFE5DCFFFEEDFFDFBDE1BC80E4B662E3AC44CD8B1AB36700AD5B00B762
          00C26C02C87508CC7A0DBD6800BD6500C56402C0640BA75A11D6A46AFFF5D0F7
          F3DAD0C9B5CAA597C36762BE3C47B523438F0A2B721A2A380000F9DFD3D1B8A8
          EDD7BEFFFFE3FAE1AFC3A362BF9445D49B40C8801BC06D00B96000C16700C975
          00CA7D08C5800BC6840DC68005C07300C36C00CE7C0DA867059C7227F0E0B2FF
          FFEDF7E3D1E8BDAAD9856CB84F34A53A1E7F210A59140B360000EFD6D4E3C9BD
          FFFBDBFFFAC4BE9E53A77D24CC9534C6831CBE6D04C77002D47B08E28B13E290
          13D68B0BCF8B0AD2910CDF970DD88D03CE7E00E5991BCA8A14976707E9CB90FF
          F7D7FFFCECF2CEBEFBBB9CD284569B48108A3C0D5C1E0E380000E6CFD7FFE9E3
          FFFEDDDFB378B27923D69529D8901AD88B11D68810E0911CE59823E4971DE496
          14EC9C13F4A312F9A712FEA814F7A615F1A71FF1A925E39915CB8815C9913FFF
          F8C7FFF9E8F5E4DBE8C5ABCB966BAE632B8F3D1362191540000AF0DFE3FFEBE1
          FFF1CBC9954FC8841FD6880DE99710E49106E59611DE9311D58F13D99213EAA0
          18FFB01FFFB81DFFB618FFB41AFFAF1CEFAB24EFAC27F0A51BE39719DB9835FF
          F1B1FFFAE5EEE6DFDEC9B3C49A75AE6833904017651A1842000CFAEAE3FFF6E0
          FED9A7B88332D18B1AD48300E79200EB9500E18F00DB8F00DA9208E29D12F5AE
          1EFFBF27FFC624FFC320FFBF22FEB825EBAD29E9AC2CF3AC26EAA526D69A30FF
          DF96FFFEE1F2E9DFE6CEBCCDA184B36F4291461F6423153F0605F1E7D6FFFEDF
          E4C489C09038D7951EE4980AE99600FFAB0CEC9E05EEA612F1AF21F0B224F2B3
          22F8BA20FFC523FFCD29FFC92EFFC434EDB839EAB438F5B531F0B131D49E2CF9
          D581FFFFDCF4EBDDEAD0C2D4A891BA7750944F27612B123D0F00E8E6CEFFFFDB
          E4CD8FCBA34AE5AC38F2AE25FAB11AFFCB33FFCD3AFFD244FFD34CFFCC44F1C0
          34EABC28F5C529FFCF33FFD43DFFD54BF6CB52F1C34DFAC140F4BB3AD3A62DF8
          D97CFFFFD7F7EBD9EBCEC5D9AA9CBF7F5D95572E60340F391600EEF2D9FCFBD5
          FBEDB2CDB05FEDC156E9B337FFC43FFFD34DFFD95BFFDD61FFE36CFFE76FFFE3
          64F7D952EFCF40EBC939FCD84EFFDD5DFDD864F8D15DFBCA4AF0BF3DD3AA30FB
          DF80FFFFD5F7E9D3ECCBC2DBAB9FC38666995F355D3A0E331B00E9F3DCEDF2D2
          FFFFD2DDCC89E9CC77E9C363F4CC66F8D06AF1CD6FF1D277FAE086FFF293FFF8
          91FFEE7DF0DE63E8D254F4D961FDE06DFCE071FCDA68FBD150EBC13ED0AC36FF
          E58AFFFFD5F9E4CFECC6BADCAB9BC58B689866385C3E0D2F1C00DFE5CCE7EACA
          FFFFDEFBF0B7E6D390FDE59DF0D78FEFD690E7D392E6D596E9DD9DF3E9A3F9EE
          9CF5EB8DF6E97FF9EA7CF2DB77FAE17FFEE57DFFE471FCD959ECC747D2AF41FF
          EA97FFFFD8FCE1CDEDC4B5DDAC96C58F66986A3A5B400E2C1B00E3E1C3D8D3B2
          FBF3CBFFFFD8FFF8C4F5E7B3F0E2B2F7EBC1ECE3BEE3DDBAF6F1CAFDF8C7E3DC
          9DDFD587F5E88CFCEB8EFCE698F7E090FFF895FCE472F5D858E1BF47CFAE4DFF
          FFBBFFF9D6FAD9C6F4CAB3E3B494BD8C5C956A375F4418261400EADBBADACDA7
          F5E6BFFFFFD3FFFFD8FFFFDFFFFFDDFFFADFFCF7E2F1EED9FDF9E0FAF4CFDBD3
          9ED8CB87F2E190FDEA99FFF7BAFFF8B7FFF39BFBE77CF1D962DEC154EBCD7AFF
          FFCAFFEFD2FBD8C4F1C7AADBAF86B48853896430563C17281400E9D0A6D1BA8D
          DEC799EEDAABFCE9BCFFFFD6FFFFE0FFFDE2FFFEEAFFF8E5FFFFE8FFF6D6E5D5
          A6E1CC8FF9E096FFE9A3FFF7C9FFFFD1FDEC9DF6E584E6D168DAC163FFF0AEFF
          FFD8FFE7CEFDDBC4EEC9A3D2AA7AA9834D7B5A29452D0F240F00E2C89AC6AC7E
          D0B687DEC795E6D2A2F6E6B8FCF0C8FEF4D2FDF2D7FFF3DBFFFFE5FFFFDFFBE7
          BEF0D9A7F9E0A2F9E0A8F6E3BEFFF4CAF3E3A1EDDC8BD8C771DBC97CFFFFCAFF
          FFDCF2DBC1F2D5BADEBE93BA996794734163471E341D071A0900C1AB829A845A
          A69060C3AE7AD1BD86D9C890DECD9AE7D9A9F0E1BAF8E8C4FFF6D7FFFFDFFFF6
          D3FEECC3F9E4B7F0DFB4ECE1C1EAE0BEEFE1ADEADB9DE1D294F4E7AFFFFED6FB
          F2D1ECDFBFE5D3AEC8B0829E8351775C304E37172919081A0D05ACA181756945
          75683C968955B1A368C4B577D0C183E0D095E0CF9CE8D7ACF5E5C0FFF3D3FFFB
          DDFFFADEFFF5D9FCF4D7FBF7DBE8E3C4F6EAC2F5E5BAFAECC2FFFFDFF9F7D8E1
          E2C2DFDCB6CCC397A998677D6638533D1937230A1F11050F0500959A85606349
          5B5B37706E3E888247A29956B6AA64C8B875D5C58ADDCF9BE4D8B0ECE4C6F5F2
          DDF9F9EBF7FBF0FCFFF2FFFFEBF5F3D5FFF6D8FFF3D8FFF6E0FFFFE7E4EBD0D1
          DCBBC5CC9FADAE7C998E5C7C6A415A482B4A3A293A3127231D16B5C2B495A08C
          9EA584ABAE80B0AF73C1BA75CDC278D7C981DACA88E1D49CE2D8B0E1DDC0E8E8
          D8E5ECE5E4EFEDECF9F1F7FFE8FFFFE2FFFEE6FFFBE8FCF0E4E5E5D5D4DEC7CE
          DFBAC7D3A3B5BA83B5AE7DB2A37C9D8E749A8D7D8F887F706D65}
        Caption = 'ConnectAll'
        OnClick = ConnectAll1Click
      end
      object DisconnectAll1: TMenuItem
        Bitmap.Data = {
          360C0000424D360C000000000000360000002800000020000000200000000100
          180000000000000C0000232E0000232E000000000000000000015B7298152A61
          00045D00007200008200008800008301078602008203008703008D00008F0000
          9200028900006B00005300006600006A00003000002000094725216D1E065E49
          30807064A03E3D75091055000046000054150B5E1D014D1E00436376A9203273
          031072010D8900089B000AA4000BA30A11A80E11A91310AC120AB11108B21615
          B91D25BE172AB30F22A9181CB104079100066B0001530000462226797269BFCA
          C0FFAFAAF92C30831A258706137B0000611E1E78160A5200002A6873BD29338B
          0D178C0A16A40110BA000FC9000CCD0010D4000BCB030ECA040DC8010AC50510
          CC101CD81222E01221DC121BD6222AE2161ED61620C41123A0000B6B01166769
          7CD38594FF0F1CA61E30CB1C30CB000087000F78000F5000012C696ED12C33A2
          111BA50C19BB0012CD0011D9000EDA0013DC0010D30015D30118D20316D10919
          D70E1DDD0F1DE10C1CDA000EC40916CC1619DF1519D00B19A70A1F92000D7300
          0061081FAA192FCE1D34DE081FC90004A0000D8B001D680000316A6DE73135BC
          171DC20E1BD50015DD0018DF001BD20023CD0026C6002AC90E2ED51A33DD293B
          E63543E93848E13749D63146CA374ACB4F58DE494DD42223A90D109A2028BB27
          36CC0009990019A600099A000CA70B17BD020DA400077200004D6672EE313DC5
          1B27CB1424DB0620DF0525E2012CD70535D0123FD01C45D02F4ADA4154E55761
          EF686CF37277F17580E8798EE37D92DD98A2EFCDCCFFE2DDFF958FFF4142D00E
          15B21425C200008500008000008F050BA00A119E00007500006D627FEB314EC1
          233EC4213CD21D38DC2540E82A46EA334FEA4E66F45F72F37680F68B8CFA9B94
          FDA99BFFB7A4FFBAB3FEB9C9EEBACEE0E3E7FFF1ECFFEEE6FFF3EDFFCFD3FF3F
          44C81311C80200C20D07B8000082000058141A7D11108E000074648CF2375EC8
          2E52C43655D03954DA4A60E85567F06473F27A87F59199F6ABB0FBBFBEFEC9BE
          FCCFBEFEDCC1FFDECDFFDBE4FFE4F2FFF9FAFFFBF4FBFFFAFFEEEEFFD2DDFF7E
          88F42320D42C1EF21B09D2180CB204076F00005103077D00007A6C92FF395ECC
          4566D34663CC6379DF7485E68794EAA8B2F8AEBAEABEC9E7D1DDE9E1E9F0ECED
          FBF4ECFFFAE7FFF1E3FFD9DCFFE0E8FFE2E1FFF3F1FFEDEDF9EBF2FFD8EBFF74
          8AE23B47E31B19E12C1CF62515DE0C0B9D00006E00117100045B6588FD6283F1
          4B67CC7189E38596E5A0AEF09FA9DFC4CBF6E3EBFFE7EFFFE9F3FFE8F1FFE3E5
          FFCFCCFDB4ACED9991E87071E14E4FBD6F69BBC3BCF5EDEBFFE4EFFFB2CCF18E
          ABF0485DDE262FDD271EF12012E60D0ABA08129C052186000A5C7E98FF6F88F6
          849AF993A5F2ADBBF6BCC6F5CAD2FAEDF2FFE5E7FFDADBFFBFBEFF8F8FF95957
          CE2B2CA61315910B0D911919AB110DA22414A23D2AA1837DCAEAF1FFCEE7FF9F
          BEF56580E23E51DC262BDE1C1ADE0E0ACD181ECB091EA200006C96ACFF8096F5
          A8BEFFA2B3EBBCC9F5DBE4FFEDEEFFD7D5FFA7A3FF7975F3423FD01E1FB70F14
          AD0711A5000D9B0008970004A30100A30B00A40E008F453C9DD2D7FFDFEFFFAF
          C8F48BA4EE6074E33540D8272BE1110FD71C1CDA0310A800007599AEFFB1C9FF
          8AA3CBBBD2ECD2E1FFE0E8FFC9C1FF7264EC5041E9342BDF1315C10002A00000
          8200007300037A000C8D00019A00009A02009D130396241D7E9697D4E9EEFFCB
          D6FCAEBCF7818EEA4F58DE3B41E81D19DC1B16D50707A7000085B1CBFA99B3DB
          B5CFE7CBE1FAE3EFFFB3B6FF3D33AF4233D4281ED60603BD00009B0000930010
          960018960012930009920000980404A402009E00008B0000655651A0E6E3FFE4
          E5FFBEC6F5949FE9626DE6434DE72326DC1716CA090AA0000087AFD1DEBAD8E9
          BAD1EBE1F0FFBCBFFF2420892E27AD201EB40409A200059900088F000B8F0006
          900000970700A91007B50308A30007960007950B159F100C931B1183ABA0E8E9
          E6FFCFD8F9AAB9F17687F64454E72A38DE1723C10D1997000473BDDFD9B7D4DB
          DFF5FFC6D1FF35349C150E972A23C01313B300089F000794000C950416A30D14
          B10F0AB91300C71706CC080CB9000FAC000DA40006A00C0BAF000085807AD1E6
          E6FFE9F2FFCAD9FA96A7FE4F62E13749E21E31C812239B000469C3DEDBCBE5EC
          E0F5FF616FB70B0A8F1B13BE1008C70A05C6090BBD070EB9060DBA070EC10C11
          CC0E0FD50905DA0400D60804D21413D90A0ECB060AC70B0ED40000A71A2587DA
          E5FFECF5FEDCE5EFB1BFEF7889E64052E52035D409209E000371CCDFE2D9EBFC
          CFDDFF343B980D0C9E0D08BF180FDB0000C80706C80A0CC80D0ECA090ACA0404
          CE0405D90D0CEB1814F60C02E2170DE9130DE00C0BDD0D10E70007BF121D96B6
          C0FFEEF2FFE4E7EFBCC5EA8391E34557E42137D60720A600037BD9E2ECEBEFFF
          A7A4F917128D1413A50201AB0C0BCC0000C30100C90000C10105B8090AC0120C
          D51B10E91E11F72313FB180AEB1D11ED1911E8110CE40E0EEA0B0BD31010AA8D
          8AF1EEE9FFE3E1FEBFC5FA8795EE4A60E8253DD50A21AC000486DFDCF6F4ECFF
          8171DC20109D221CB70806B30505C31310DB0D09D70A07CF0D0BC21512C61F12
          DA2310E9270CF6270DFA2E1CF9281CF0261AF0160EE7130EEB1914E5150CC171
          66ECEDE3FFE2DEFFC0C5FF8C9BF74F6BE82947D40D27AF00078BE1D0FFF6E4FF
          8871E52C18AD3123CF170EC91B17DB302BF82B25F6352BF93D34F63C2DEC2D19
          DE2308DA2D07F33915FF412CFD382DF5392CFA281FF22119F2251DF31D0BD469
          56F3ECDFFFDFDAFFBCC4FF8DA1F85477E52D53CF112EAF000C8EE4D3FFF2E0FF
          B8A6FF3928AF3C2AD52314D3372DF13930F53F35F94B40FF5E4EFF6552FF5942
          FC4428ED3D17F33C1AF44837F3493DF34D3FFF3E32FE3027F92C22F11D0AD36D
          5AF7EBDFFFDAD9FFB6C2FF8AA5F55781E2315FCB1535AC00108CE0DBFFE1DDFF
          E2E0FF6461C44C40D64333E54D3FF8493DF14E44EB574AEC6956FF7E69FF826B
          FF7056FF5A3CF94B33EB5348EA5A52F26154FF5243FF3D33FB2C22E62011C681
          74FEE9E3FFD3D9FFADC2F686A9ED5889DF3568C9163DA7001784D3DEF9C9D6F6
          E6F5FF9EA7EB6562D57067F46659F17062F66A5EE06E63DF7B6BEE8775FE8471
          FF7864FD705EFD7265FD6962EB716BF87365FF5F50FF463BFB2F27DF2A22BC9B
          97FFE8E9FFCDD9FDA7C1EF80A9E8558AE13569CD1841A4001A7EC5E7E7C1E3E9
          CDE9FFCFE5FFB2BEFE9195E88882E78D82E89A92E57E77C2A39CE7C3BAFF7C70
          E86A5FE37B76F77573EF7B79F07C74F67767FF6F5BFF5A4BFF2821CA22239DD2
          D9FFE4EDFFC6D8F79DBEEB7DA9E9558AEB3669D71B43A9002082B3E2E0A9D5DC
          B8DCF4D4F0FFD9F0FFD0DEFFCACEFFC8C5FFC2BDF0DAD5FFEDEBFFE9E7FF645D
          BE5B56C96A6AE07F7FF39A97FF9F96FF8E7BFF6E5AFF5342F73933CE656DCBC2
          D1FFD6E3FFBED2F598BBED72A1EB4A7CEC2E5FD9163DA9001C7EABDAEF95C0DB
          96B9E5B3D1FFCBE5FFDAEFFFE4F1FFE8F0FFE8EAFFF5F4FFEEECFFE3E1FF7F7C
          CB7874DD706CE97A75F6B5AFFFB5AAFFA58EFF7F67FF4938E03630BDAAB7FFE1
          F5FFCDDCFFBACEFD97BAFA6C99F44273F32C5AE31940B4001E86A6D0FA8AB2E2
          82A4E092AFEC9FBCEFB0CBF0C8DEF7D8E9FCD9E2FDDDDFFFEAEAFFE2E1FFACAC
          EC7775CE736BE78A81FF8A83EC978BF5947EFF7D66F64A3DCF4D4CC4BAC9FFD6
          ECFFC2D2FCB0C4FB89ABF75986ED3266E92454DC153BB10018839BB9FA82A0E1
          7897DC82A0E787A4EE91AEEBA2C2E6B1CEE9C0D3F4C7D3FBE1E5FFECEDFFD2D4
          FF9492D88075E39689FD988FE9A198EF8977E26F5ED16D67D8B1B6FFD8EBFFCB
          E1FFC2D2FFA9BEFC7B9DF64B7AE6275FDC1E54D1123AAA00177E97B0F0738ECE
          617FC06788CD6D8FDB7598E182AADE8CB2DCA3C2E9ADC6EEB6C3F1E1E7FFE9EE
          FFE3E2FFBAB0FCB1A5F7B7B3F5ADA6E98D80D4837AD09DA0EBDBE9FFCBDFFFC2
          D8FCB6C8F799AFF16B8FED4172E02160D01856C21140A2001F7DA8C1E9839ECA
          6A8ABB698EC66894D36B9ADE76A5E980ADEA84AFDA9CC4E1AECBE0CEE2F4DDE4
          FFF3F4FFEBE9FFE8E8FFD3D5F7C8C9F5CFC8FFDCD9FFE6F3FFDDF2FFBAD1F1BB
          D0F6A4B7E487A0DE6288E64378E0296ECB2268BC2156A7133E8FBDD5F1A3BFDE
          95B8E096C0EF8BBBF582B8F988B9FF8FC2FF9ED1FCA2D2EABBE0E8BAD4DAD6DF
          F3D9DCEBF3F4F0F3F7F2F0F7FFEAECFFEEEBFFDCDEFFDAEBFEC3DEECC1D6F5B5
          CAF0ADC0EB96B0EC7AA0FE659CFF4F99EB4A94DC4F86D14976C0}
        Caption = 'DisconnectAll'
        OnClick = DisconnectAll1Click
      end
      object StopALl1: TMenuItem
        Caption = 'Stop ALL'
        OnClick = StopALl1Click
      end
      object AllTOwn1: TMenuItem
        Caption = 'All Town'
        OnClick = AllTOwn1Click
      end
      object AllGo1: TMenuItem
        Caption = 'All Go'
        object Coordinate1: TMenuItem
          Caption = 'Coordinate'
          OnClick = Coordinate1Click
        end
        object Potion1: TMenuItem
          Caption = 'Potion'
          OnClick = Potion1Click
        end
        object Pitman1: TMenuItem
          Caption = 'Pitman'
          OnClick = Pitman1Click
        end
      end
      object AllAtack1: TMenuItem
        Caption = 'All Atack'
        object Start3: TMenuItem
          Caption = 'Start'
          OnClick = Start3Click
        end
        object Stop3: TMenuItem
          Caption = 'Stop'
          OnClick = Stop3Click
        end
      end
    end
    object Exit1: TMenuItem
      Caption = 'Exit'
      OnClick = Exit1Click
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 872
    Top = 240
    object Connect9: TMenuItem
      Caption = 'Connect'
      OnClick = ConClick
    end
    object Disconnect1: TMenuItem
      Caption = 'Disconnect'
      OnClick = DisconClick
    end
    object Move9: TMenuItem
      Caption = 'Move'
      object own1: TMenuItem
        Caption = 'Town'
        OnClick = TownClick
      end
      object Coordinate9: TMenuItem
        Caption = 'Coordinate'
        OnClick = CoordinateClick
      end
      object GoToRepair1: TMenuItem
        Caption = 'Go To Repair / Sell'
        OnClick = GoToRepair1Click
      end
      object GoPitman1: TMenuItem
        Caption = 'Go Pitman'
        OnClick = GoPitman1Click
      end
      object GoPotion1: TMenuItem
        Caption = 'Go Potion'
        OnClick = GoPotion1Click
      end
    end
    object Party2: TMenuItem
      Caption = 'Party'
      object Add2: TMenuItem
        Caption = 'Create'
        OnClick = CreatePtClick
      end
      object Add3: TMenuItem
        Caption = 'Add'
        OnClick = AddPtClick
      end
      object PARTYtP1: TMenuItem
        Caption = 'PartyTp'
        OnClick = PartyYp1Click
      end
      object Quit2: TMenuItem
        Caption = 'Quit'
        OnClick = QuitPtClick
      end
    end
    object Mine1: TMenuItem
      Caption = 'Mining'
      object Start1: TMenuItem
        Caption = 'Start'
        OnClick = Start1Click
      end
      object Stop1: TMenuItem
        Caption = 'Stop'
        OnClick = Stop1Click
      end
    end
    object Atack1: TMenuItem
      Caption = 'Attack'
      object Start2: TMenuItem
        Caption = 'Start'
        OnClick = Start2Click
      end
      object Stop2: TMenuItem
        Caption = 'Stop'
        OnClick = Stop2Click
      end
    end
    object SocketReset1: TMenuItem
      Caption = 'Socket Reset'
      OnClick = SocketReset1Click
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '31.210.68.132'
    Port = 15777
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 936
    Top = 240
  end
  object ImageList1: TImageList
    Height = 32
    Width = 32
    Left = 432
    Top = 720
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 2500
    OnTimer = Timer2Timer
    Left = 912
    Top = 440
  end
  object Timer3: TTimer
    Enabled = False
    OnTimer = Timer3Timer
    Left = 944
    Top = 632
  end
  object Timer1: TTimer
    Interval = 15000
    OnTimer = Timer1Timer
    Left = 880
    Top = 600
  end
  object ClientSocket2: TClientSocket
    Active = False
    Address = '173.208.240.130'
    ClientType = ctNonBlocking
    Port = 15778
    OnConnect = ClientSocket2Connect
    OnRead = ClientSocket2Read
    OnError = ClientSocket2Error
    Left = 864
    Top = 96
  end
  object Timer4: TTimer
    Enabled = False
    Interval = 10000
    OnTimer = Timer4Timer
    Left = 928
    Top = 176
  end
  object ClientSocket3: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Host = '127.0.0.1'
    Port = 18000
    OnConnect = ClientSocket3Connect
    OnRead = ClientSocket3Read
    OnError = ClientSocket3Error
    Left = 864
    Top = 136
  end
  object Timer5: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer5Timer
    Left = 880
    Top = 640
  end
  object Timer6: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer6Timer
    Left = 880
    Top = 680
  end
  object Timer7: TTimer
    Enabled = False
    Interval = 1300
    OnTimer = Timer7Timer
    Left = 872
    Top = 544
  end
  object ClientSocket4: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnRead = ClientSocket4Read
    Left = 888
    Top = 288
  end
  object Timer8: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer8Timer
    Left = 976
    Top = 360
  end
  object clock: TTimer
    OnTimer = clockTimer
    Left = 976
    Top = 496
  end
end