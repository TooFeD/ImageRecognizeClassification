object Form3: TForm3
  Left = 0
  Top = 0
  Align = alCustom
  Caption = #1043#1086#1083#1086#1074#1085#1072
  ClientHeight = 340
  ClientWidth = 348
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
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 348
    Height = 340
    Align = alLeft
    OnMouseUp = Image1MouseUp
    ExplicitHeight = 315
  end
  object Image2: TImage
    Left = 13
    Top = 0
    Width = 335
    Height = 340
    Align = alRight
    Visible = False
    OnMouseUp = Image2MouseUp
    ExplicitLeft = 442
    ExplicitHeight = 444
  end
  object Label1: TLabel
    Left = 400
    Top = 120
    Width = 31
    Height = 13
    Caption = 'Label1'
    Visible = False
  end
  object Label2: TLabel
    Left = 408
    Top = 139
    Width = 31
    Height = 13
    Caption = 'Label2'
    Visible = False
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 8
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 80
    Top = 8
    object N1: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1110#1111
      object N2: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080' '#1092#1072#1081#1083
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1042#1080#1076#1110#1083#1080#1090#1080' '#1082#1086#1085#1090#1091#1088#1080
        OnClick = N3Click
      end
      object test1: TMenuItem
        Caption = #1055#1077#1088#1077#1090#1074#1086#1088#1080#1090#1080' '#1074' '#1095#1086#1088#1085#1086'-'#1073#1110#1083#1077
        OnClick = test1Click
      end
      object N5: TMenuItem
        Caption = #1058#1086#1095#1082#1080' '#1087#1077#1088#1077#1090#1080#1085#1091' '#1079' '#1089#1110#1090#1082#1086#1102
        Visible = False
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1054#1073#1074#1077#1089#1090#1080' '#1082#1086#1085#1090#1091#1088
        Visible = False
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1057#1087#1110#1074#1087#1072#1076#1110#1085#1085#1103' '#1079' '#1077#1090#1072#1083#1086#1085#1086#1084
        Visible = False
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1053#1072#1082#1083#1072#1089#1090#1080' '#1077#1090#1072#1083#1086#1085
        Visible = False
        OnClick = N8Click
      end
    end
    object N4: TMenuItem
      Caption = #1042#1082#1083'/'#1042#1080#1082#1083' '#1089#1110#1090#1082#1091
      Visible = False
      OnClick = N4Click
    end
    object test2: TMenuItem
      Caption = #1057#1087#1088#1086#1089#1090#1080#1090#1080
      Visible = False
      OnClick = test2Click
    end
    object test21: TMenuItem
      Caption = #1057#1087#1110#1074#1074#1110#1076#1085#1086#1096#1077#1085#1085#1103' '#1087#1083#1086#1097
      Visible = False
    end
  end
end
