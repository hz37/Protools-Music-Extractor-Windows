object SettingsForm: TSettingsForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Settings'
  ClientHeight = 152
  ClientWidth = 426
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object IgnoreAfterExtensionCheckBox: TCheckBox
    Left = 9
    Top = 8
    Width = 409
    Height = 17
    Caption = 'Ignore string data after extension (aif, cda, m4a, mp3, wav)'
    TabOrder = 0
  end
  object IgnoreAfterNewCheckBox: TCheckBox
    Left = 8
    Top = 31
    Width = 409
    Height = 17
    Caption = 'Ignore string data after .new'
    TabOrder = 1
  end
  object IgnoreFadeCheckBox: TCheckBox
    Left = 8
    Top = 54
    Width = 409
    Height = 17
    Caption = 'Ignore regions that begin with "Fade"'
    TabOrder = 2
  end
  object SuppressFramesCheckBox: TCheckBox
    Left = 8
    Top = 77
    Width = 209
    Height = 17
    Caption = 'Suppress frames in output'
    TabOrder = 3
  end
  object CombineSimilarCheckBox: TCheckBox
    Left = 8
    Top = 100
    Width = 209
    Height = 17
    Caption = 'Combine similar regions'
    TabOrder = 4
  end
  object IgnoreShorterThanCheckBox: TCheckBox
    Left = 8
    Top = 123
    Width = 209
    Height = 17
    Caption = 'Ignore regions shorter than 1 second'
    TabOrder = 5
  end
  object IgnoreShorterThanUpDown: TUpDown
    Left = 223
    Top = 123
    Width = 33
    Height = 17
    Min = 1
    Max = 59
    Orientation = udHorizontal
    Position = 1
    TabOrder = 6
    OnClick = IgnoreShorterThanUpDownClick
  end
  object BitBtn1: TBitBtn
    Left = 342
    Top = 119
    Width = 75
    Height = 25
    TabOrder = 7
    OnClick = BitBtn1Click
    Kind = bkOK
  end
end
