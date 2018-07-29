object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'POKER KAYIT SERVER'
  ClientHeight = 488
  ClientWidth = 406
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 512
    Top = 500
    Width = 225
    Height = 49
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    Visible = False
  end
  object CheckBox1: TCheckBox
    Left = 512
    Top = 555
    Width = 97
    Height = 17
    Caption = 'Otomatik Kapat'
    TabOrder = 1
  end
  object Button2: TButton
    Left = 624
    Top = 555
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 406
    Height = 488
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 3
    object TabSheet1: TTabSheet
      Caption = 'GAME PLAY'
      object Label3: TLabel
        Left = 0
        Top = 447
        Width = 398
        Height = 13
        Align = alBottom
        Caption = 'PASIF'
        ExplicitWidth = 29
      end
      object DBGrid1: TDBGrid
        Left = 24
        Top = 192
        Width = 345
        Height = 120
        DataSource = DataSource1
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'KEY URET'
      ImageIndex = 1
      object Label1: TLabel
        Left = 17
        Top = 3
        Width = 48
        Height = 13
        Caption = 'BAY'#304#304' ADI'
      end
      object Label2: TLabel
        Left = 17
        Top = 25
        Width = 33
        Height = 13
        Caption = 'ADET :'
      end
      object Edit1: TEdit
        Left = 80
        Top = 0
        Width = 89
        Height = 21
        TabOrder = 0
        Text = 'BYID'
      end
      object RadioGroup1: TRadioGroup
        Left = 19
        Top = 88
        Width = 318
        Height = 81
        BiDiMode = bdLeftToRight
        Caption = 'GUN SE'#199
        Columns = 3
        ItemIndex = 0
        Items.Strings = (
          '1'
          '5'
          '10'
          '20'
          '30'
          '60'
          '120'
          '200'
          '255')
        ParentBiDiMode = False
        TabOrder = 1
      end
      object Memo2: TMemo
        Left = 19
        Top = 303
        Width = 318
        Height = 91
        TabOrder = 2
      end
      object Button1: TButton
        Left = 48
        Top = 416
        Width = 75
        Height = 25
        Caption = 'Kaydet '
        TabOrder = 3
        OnClick = Button1Click
      end
      object Button3: TButton
        Left = 192
        Top = 416
        Width = 75
        Height = 25
        Caption = 'Sil'
        TabOrder = 4
        OnClick = Button3Click
      end
      object URET: TButton
        Left = 31
        Top = 44
        Width = 66
        Height = 25
        Caption = 'URET'
        TabOrder = 5
        OnClick = URETClick
      end
      object DBGrid2: TDBGrid
        Left = 17
        Top = 192
        Width = 320
        Height = 105
        DataSource = DataSource2
        TabOrder = 6
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
      end
      object Edit2: TEdit
        Left = 80
        Top = 21
        Width = 33
        Height = 21
        TabOrder = 7
        Text = '1'
      end
      object Button4: TButton
        Left = 192
        Top = 1
        Width = 75
        Height = 25
        Caption = 'BAYI KEY SIL'
        TabOrder = 8
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 320
        Top = 416
        Width = 75
        Height = 25
        Caption = 'Button5'
        TabOrder = 9
        OnClick = Button5Click
      end
    end
  end
  object BootServer: TServerSocket
    Active = True
    Port = 15777
    ServerType = stNonBlocking
    OnClientRead = BootServerClientRead
    Left = 312
    Top = 152
  end
  object CharTable: TTable
    AfterPost = CharTableAfterPost
    OnCalcFields = CharTableCalcFields
    DatabaseName = 'PokerServerGiris'
    TableName = 'ServerGiris.DB'
    Left = 288
    Top = 232
    object CharTableBAYIID: TStringField
      FieldName = 'BAYIID'
    end
    object CharTableID: TStringField
      FieldName = 'ID'
      Size = 60
    end
    object CharTableSURE: TIntegerField
      FieldName = 'SURE'
    end
    object CharTableBAGLI: TIntegerField
      FieldName = 'BAGLI'
    end
    object CharTableKEY: TStringField
      FieldName = 'KEY'
      Size = 16
    end
    object CharTableZAMAN: TIntegerField
      FieldName = 'ZAMAN'
    end
    object CharTableSOCKETNO: TIntegerField
      FieldName = 'SOCKETNO'
    end
    object CharTableKAYITZAMAN: TDateField
      FieldName = 'KAYITZAMAN'
    end
    object CharTableKALANGUN: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'KALANGUN'
      Calculated = True
    end
    object CharTableIDKON: TStringField
      FieldName = 'IDKON'
      Size = 32
    end
  end
  object DataSource1: TDataSource
    DataSet = CharTable
    Left = 320
    Top = 192
  end
  object KeyIsle: TTable
    AfterPost = KeyIsleAfterPost
    DatabaseName = 'PokerServerGiris'
    TableName = 'KEYBILGI.DB'
    Left = 288
    Top = 192
    object KeyIsleBAYIID: TStringField
      FieldName = 'BAYIID'
    end
    object KeyIsleSURE: TIntegerField
      FieldName = 'SURE'
    end
    object KeyIsleKEY: TStringField
      FieldName = 'KEY'
      Size = 16
    end
    object KeyIsleKAYITZAMAN: TDateField
      FieldName = 'KAYITZAMAN'
    end
    object KeyIsleSATILDI: TIntegerField
      FieldName = 'SATILDI'
    end
    object KeyIsleSATILDIZAMAN: TDateField
      FieldName = 'SATILDIZAMAN'
    end
  end
  object DataSource2: TDataSource
    DataSet = KeyIsle
    Left = 320
    Top = 232
  end
  object BootServerKayit: TServerSocket
    Active = True
    Port = 15778
    ServerType = stNonBlocking
    OnClientRead = BootServerKayitClientRead
    Left = 312
    Top = 120
  end
  object ApplicationEvents1: TApplicationEvents
    OnException = ApplicationEvents1Exception
    Left = 304
    Top = 16
  end
end
