object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1050#1083#1072#1089#1080#1092#1110#1082#1072#1090#1086#1088
  ClientHeight = 340
  ClientWidth = 260
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
  object Image2: TImage
    Left = 0
    Top = 0
    Width = 260
    Height = 340
    Align = alClient
    OnMouseUp = Image2MouseUp
    ExplicitWidth = 105
    ExplicitHeight = 105
  end
  object MainMenu1: TMainMenu
    Left = 120
    Top = 32
    object N1: TMenuItem
      Caption = #1054#1087#1077#1088#1072#1094#1110#1111
      object N3: TMenuItem
        Caption = #1058#1086#1095#1082#1080' '#1087#1077#1088#1077#1090#1080#1085#1091' '#1079' '#1089#1110#1090#1082#1086#1102
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1054#1073#1074#1077#1089#1090#1080' '#1082#1086#1085#1090#1091#1088
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1057#1087#1110#1074#1089#1090#1072#1074#1083#1077#1085#1085#1103' '#1082#1086#1085#1090#1091#1088#1091' '#1079' '#1077#1090#1072#1083#1086#1085#1085#1080#1084
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1055#1086#1088#1110#1074#1085#1103#1085#1085#1103' '#1082#1086#1085#1090#1091#1088#1091' '#1079' '#1077#1090#1072#1083#1086#1085#1085#1080#1084
        OnClick = N6Click
      end
      object N7: TMenuItem
        Caption = #1057#1087#1088#1086#1089#1090#1080#1090#1080' '#1082#1086#1085#1090#1091#1088
        OnClick = N7Click
      end
      object N8: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1079#1086#1073#1088#1072#1078#1077#1085#1085#1103
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1042#1080#1084#1110#1088#1103#1090#1080' '#1087#1083#1086#1097#1091
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1047#1074#1110#1074#1085#1103#1090#1080' '#1087#1083#1086#1097#1091' '#1079' '#1077#1090#1072#1083#1086#1085#1086#1084
        OnClick = N10Click
      end
    end
    object N2: TMenuItem
      Caption = #1042#1074#1110#1084#1082'/'#1042#1080#1084#1082' '#1089#1110#1090#1082#1091
      OnClick = N2Click
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 32
    Top = 32
  end
  object SavePictureDialog1: TSavePictureDialog
    DefaultExt = 'bmp'
    Left = 192
    Top = 40
  end
end
