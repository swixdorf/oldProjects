object dlgBl: TdlgBl
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Bl'
  ClientHeight = 269
  ClientWidth = 255
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object pnBlAdd: TBevel
    Left = 8
    Top = 8
    Width = 241
    Height = 225
    Shape = bsFrame
  end
  object btnOk: TButton
    Left = 88
    Top = 239
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = btnOkClick
  end
  object lstBladd: TListBox
    Left = 16
    Top = 16
    Width = 129
    Height = 153
    ItemHeight = 13
    TabOrder = 1
  end
  object txtname: TEdit
    Left = 16
    Top = 175
    Width = 129
    Height = 21
    TabOrder = 2
  end
  object btnadd: TButton
    Left = 16
    Top = 202
    Width = 57
    Height = 23
    Caption = 'isim ekle'
    TabOrder = 3
    OnClick = btnaddClick
  end
  object btnclear: TButton
    Left = 88
    Top = 202
    Width = 57
    Height = 23
    Caption = 'temizle'
    TabOrder = 4
    OnClick = btnclearClick
  end
  object btnaddselected: TButton
    Left = 151
    Top = 16
    Width = 82
    Height = 23
    Caption = '<- Se'#231'ili ekle'
    TabOrder = 5
    OnClick = btnaddselectedClick
  end
  object chbltown: TCheckBox
    Left = 151
    Top = 117
    Width = 82
    Height = 17
    Caption = 'Town At'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = chbltownClick
  end
  object chbldc: TCheckBox
    Left = 151
    Top = 132
    Width = 66
    Height = 17
    Caption = 'DC Ol'
    TabOrder = 7
    OnClick = chbldcClick
  end
  object chpmcontrol: TCheckBox
    Left = 151
    Top = 94
    Width = 82
    Height = 17
    Caption = 'PM Kontrol'
    TabOrder = 8
    OnClick = chpmcontrolClick
  end
end
