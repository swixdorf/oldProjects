object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 553
  ClientWidth = 1051
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object conv: TButton
    Left = 328
    Top = 280
    Width = 66
    Height = 25
    Caption = 'conv'
    TabOrder = 0
    OnClick = convClick
  end
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 314
    Height = 545
    ItemHeight = 13
    Items.Strings = (
      
        '___:004C36D0 sub_4C36D0      proc near               ; CODE XREF' +
        ': sub_4C4BF0+1DC'#25'p'
      
        '___:004C36D0                                         ; sub_4C539' +
        '0+BB'#25'p ...'
      '___:004C36D0'
      '___:004C36D0 var_148         = byte ptr -148h'
      '___:004C36D0 var_12C         = byte ptr -12Ch'
      '___:004C36D0 var_128         = dword ptr -128h'
      '___:004C36D0 var_118         = dword ptr -118h'
      '___:004C36D0 var_114         = dword ptr -114h'
      '___:004C36D0 var_110         = byte ptr -110h'
      '___:004C36D0 var_10          = dword ptr -10h'
      '___:004C36D0 var_C           = dword ptr -0Ch'
      '___:004C36D0 var_4           = dword ptr -4'
      '___:004C36D0 arg_0           = byte ptr  4'
      '___:004C36D0 arg_4           = dword ptr  8'
      '___:004C36D0'
      '___:004C36D0                 push    0FFFFFFFFh'
      '___:004C36D2                 push    offset loc_A58E72'
      '___:004C36D7                 mov     eax, large fs:0'
      '___:004C36DD                 push    eax'
      '___:004C36DE                 sub     esp, 13Ch'
      '___:004C36E4                 mov     eax, dword_BE1814'
      '___:004C36E9                 xor     eax, esp'
      '___:004C36EB                 mov     [esp+148h+var_10], eax'
      '___:004C36F2                 push    ebx'
      '___:004C36F3                 push    ebp'
      '___:004C36F4                 push    esi'
      '___:004C36F5                 push    edi'
      '___:004C36F6                 mov     eax, dword_BE1814'
      '___:004C36FB                 xor     eax, esp'
      '___:004C36FD                 push    eax'
      '___:004C36FE                 lea     eax, [esp+15Ch+var_C]'
      '___:004C3705                 mov     large fs:0, eax'
      '___:004C370B                 mov     esi, [esp+15Ch+arg_4]'
      '___:004C3712                 mov     ebp, ecx'
      '___:004C3714                 mov     ecx, dword_D79CBC'
      '___:004C371A                 call    sub_4F0EE0'
      '___:004C371F                 test    al, al'
      '___:004C3721                 jnz     loc_4C3B0E'
      '___:004C3727                 mov     eax, dword_D79CBC'
      '___:004C372C                 xor     edi, edi'
      '___:004C372E                 cmp     [eax+768h], edi'
      '___:004C3734                 jnz     loc_4C3B0E'
      '___:004C373A                 mov     bl, [esp+15Ch+arg_0]'
      '___:004C3741                 cmp     bl, [eax+0E99h]'
      '___:004C3747                 jz      loc_4C3B0E'
      '___:004C374D                 mov     ecx, dword_D79D74'
      '___:004C3753                 cmp     [ecx+48Ch], edi'
      '___:004C3759                 jz      short loc_4C3773'
      '___:004C375B                 mov     ecx, [ecx+48Ch]'
      '___:004C3761                 call    sub_669700'
      '___:004C3766                 test    al, al'
      '___:004C3768                 jnz     loc_4C3B0E'
      '___:004C376E                 mov     eax, dword_D79CBC'
      '___:004C3773'
      
        '___:004C3773 loc_4C3773:                             ; CODE XREF' +
        ': sub_4C36D0+89'#24'j'
      '___:004C3773                 test    bl, bl'
      '___:004C3775                 jz      short loc_4C37DE'
      '___:004C3777                 mov     [eax+0ED8h], edi'
      '___:004C377D                 mov     ecx, dword_D79D50'
      '___:004C3783                 call    sub_53EB40'
      '___:004C3788                 mov     ecx, dword_D79CBC'
      '___:004C378E                 cmp     byte ptr [ecx+0EA8h], 0'
      '___:004C3795                 jnz     loc_4C3B0E'
      '___:004C379B                 cmp     esi, edi'
      '___:004C379D                 jz      loc_4C3B0E'
      '___:004C37A3                 push    edi'
      '___:004C37A4                 push    esi'
      '___:004C37A5                 call    sub_50CDA0'
      '___:004C37AA                 mov     ecx, dword_D79CBC'
      '___:004C37B0                 cmp     [ecx+0F10h], edi'
      '___:004C37B6                 jz      short loc_4C37CB'
      '___:004C37B8                 mov     ecx, [ecx+0F10h]'
      '___:004C37BE                 push    edi'
      '___:004C37BF                 push    esi'
      '___:004C37C0                 call    sub_50CDA0'
      '___:004C37C5                 mov     ecx, dword_D79CBC'
      '___:004C37CB'
      
        '___:004C37CB loc_4C37CB:                             ; CODE XREF' +
        ': sub_4C36D0+E6'#24'j'
      '___:004C37CB                 push    esi'
      '___:004C37CC                 call    sub_4F10C0'
      '___:004C37D1                 test    al, al'
      '___:004C37D3                 jz      loc_4C3B0E'
      '___:004C37D9                 mov     eax, dword_D79CBC'
      '___:004C37DE'
      
        '___:004C37DE loc_4C37DE:                             ; CODE XREF' +
        ': sub_4C36D0+A5'#24'j'
      '___:004C37DE                 cmp     byte ptr [ebp+68Dh], 0'
      '___:004C37E5                 jnz     loc_4C3AB4'
      '___:004C37EB                 test    bl, bl'
      '___:004C37ED                 mov     [eax+0E99h], bl'
      '___:004C37F3                 jz      loc_4C389B'
      '___:004C37F9                 mov     eax, dword_D79DB4'
      '___:004C37FE                 push    edi             ; int'
      '___:004C37FF                 push    eax             ; hCursor'
      '___:004C3800                 call    sub_919E40'
      '___:004C3805                 add     esp, 8'
      '___:004C3808                 mov     [esp+15Ch+var_114], 0Fh'
      '___:004C3810                 mov     [esp+15Ch+var_118], edi'
      
        '___:004C3814                 mov     byte ptr [esp+15Ch+var_128]' +
        ', 0'
      '___:004C3819                 mov     ebx, 1'
      '___:004C381E                 mov     [esp+15Ch+var_4], ebx'
      '___:004C3825                 lea     edx, [esp+15Ch+var_12C]'
      '___:004C3829                 push    edx'
      '___:004C382A                 push    0BBAh'
      '___:004C382F                 call    sub_8A33C0'
      '___:004C3834                 mov     ecx, [ebp+4FCh]'
      '___:004C383A                 add     esp, 8'
      '___:004C383D                 cmp     ecx, edi'
      '___:004C383F                 jz      loc_4C397D'
      '___:004C3845                 call    sub_7C07E0'
      '___:004C384A                 test    al, al'
      '___:004C384C                 jz      loc_4C397D'
      '___:004C3852                 mov     eax, [esi+678h]'
      '___:004C3858                 mov     ecx, dword_D79CB8'
      '___:004C385E                 push    ebx'
      '___:004C385F                 push    eax'
      '___:004C3860                 call    sub_49FF00'
      '___:004C3865                 cmp     eax, edi'
      '___:004C3867                 jz      loc_4C392D'
      '___:004C386D                 cmp     byte ptr [eax+0AB4h], 0'
      '___:004C3874                 jnz     loc_4C392D'
      '___:004C387A                 mov     ecx, [ebp+4FCh]'
      '___:004C3880                 cmp     ecx, edi'
      '___:004C3882                 jz      loc_4C39EC'
      '___:004C3888                 push    edi'
      '___:004C3889                 lea     eax, [esp+160h+var_12C]'
      '___:004C388D                 push    eax'
      '___:004C388E                 push    esi'
      '___:004C388F                 push    2'
      '___:004C3891                 call    sub_7C1CD0'
      '___:004C3896                 jmp     loc_4C39EC'
      
        '___:004C389B ; -------------------------------------------------' +
        '--------------------------'
      '___:004C389B'
      
        '___:004C389B loc_4C389B:                             ; CODE XREF' +
        ': sub_4C36D0+123'#24'j'
      '___:004C389B                 mov     ecx, dword_D79CBC'
      '___:004C38A1                 cmp     dword ptr [ecx+6A0h], 2'
      '___:004C38A8                 mov     eax, dword_D79DA8'
      '___:004C38AD                 jz      short loc_4C38B4'
      '___:004C38AF                 mov     eax, dword_D79DA4'
      '___:004C38B4'
      
        '___:004C38B4 loc_4C38B4:                             ; CODE XREF' +
        ': sub_4C36D0+1DD'#24'j'
      '___:004C38B4                 push    edi             ; int'
      '___:004C38B5                 push    eax             ; hCursor'
      '___:004C38B6                 call    sub_919E40'
      '___:004C38BB                 add     esp, 8'
      '___:004C38BE                 mov     [esp+15Ch+var_114], 0Fh'
      '___:004C38C6                 mov     [esp+15Ch+var_118], edi'
      
        '___:004C38CA                 mov     byte ptr [esp+15Ch+var_128]' +
        ', 0'
      '___:004C38CF                 mov     [esp+15Ch+var_4], 4'
      '___:004C38DA                 lea     ecx, [esp+15Ch+var_12C]'
      '___:004C38DE                 push    ecx'
      '___:004C38DF                 push    0BBBh'
      '___:004C38E4                 call    sub_8A33C0'
      '___:004C38E9                 mov     ecx, dword_D79CBC'
      '___:004C38EF                 mov     edx, [ecx]'
      '___:004C38F1                 mov     eax, [edx+18h]'
      '___:004C38F4                 add     esp, 8'
      '___:004C38F7                 or      edi, 0FFFFFFFFh'
      '___:004C38FA                 push    edi'
      '___:004C38FB                 push    edi'
      '___:004C38FC                 push    0'
      '___:004C38FE                 push    esi'
      '___:004C38FF                 push    1'
      '___:004C3901                 push    0'
      '___:004C3903                 call    eax'
      '___:004C3905                 mov     ecx, dword_D79CBC'
      '___:004C390B                 call    sub_4F2420'
      '___:004C3910                 push    0FF00FFFFh'
      '___:004C3915                 lea     ecx, [esp+160h+var_12C]'
      '___:004C3919                 push    ecx'
      '___:004C391A                 mov     ecx, ebp'
      '___:004C391C                 call    sub_493E10'
      '___:004C3921                 mov     [esp+15Ch+var_4], edi'
      '___:004C3928                 jmp     loc_4C3B05'
      
        '___:004C392D ; -------------------------------------------------' +
        '--------------------------'
      '___:004C392D'
      
        '___:004C392D loc_4C392D:                             ; CODE XREF' +
        ': sub_4C36D0+197'#24'j'
      
        '___:004C392D                                         ; sub_4C36D' +
        '0+1A4'#24'j'
      '___:004C392D                 mov     ecx, 10h'
      '___:004C3932                 cmp     [esi+694h], ecx'
      '___:004C3938                 jb      short loc_4C3942'
      '___:004C393A                 mov     eax, [esi+680h]'
      '___:004C3940                 jmp     short loc_4C3948'
      
        '___:004C3942 ; -------------------------------------------------' +
        '--------------------------'
      '___:004C3942'
      
        '___:004C3942 loc_4C3942:                             ; CODE XREF' +
        ': sub_4C36D0+268'#24'j'
      '___:004C3942                 lea     eax, [esi+680h]'
      '___:004C3948'
      
        '___:004C3948 loc_4C3948:                             ; CODE XREF' +
        ': sub_4C36D0+270'#24'j'
      '___:004C3948                 cmp     [esp+15Ch+var_114], ecx'
      '___:004C394C                 mov     ecx, [esp+15Ch+var_128]'
      '___:004C3950                 jnb     short loc_4C3956'
      '___:004C3952                 lea     ecx, [esp+15Ch+var_128]'
      '___:004C3956'
      
        '___:004C3956 loc_4C3956:                             ; CODE XREF' +
        ': sub_4C36D0+280'#24'j'
      '___:004C3956                 push    eax'
      '___:004C3957                 push    ecx'
      '___:004C3958                 lea     ecx, [esp+164h+var_110]'
      '___:004C395C                 push    ecx'
      '___:004C395D                 call    sub_A293DE'
      '___:004C3962                 add     esp, 0Ch'
      '___:004C3965                 lea     edx, [esp+15Ch+var_110]'
      '___:004C3969                 push    edx'
      '___:004C396A                 lea     ecx, [esp+160h+var_148]'
      '___:004C396E                 call    sub_401FB0'
      
        '___:004C3973                 mov     byte ptr [esp+15Ch+var_4], ' +
        '2'
      '___:004C397B                 jmp     short loc_4C39CB'
      
        '___:004C397D ; -------------------------------------------------' +
        '--------------------------'
      '___:004C397D'
      
        '___:004C397D loc_4C397D:                             ; CODE XREF' +
        ': sub_4C36D0+16F'#24'j'
      
        '___:004C397D                                         ; sub_4C36D' +
        '0+17C'#24'j'
      '___:004C397D                 mov     ecx, 10h'
      '___:004C3982                 cmp     [esi+694h], ecx'
      '___:004C3988                 jb      short loc_4C3992'
      '___:004C398A                 mov     eax, [esi+680h]'
      '___:004C3990                 jmp     short loc_4C3998'
      
        '___:004C3992 ; -------------------------------------------------' +
        '--------------------------'
      '___:004C3992'
      
        '___:004C3992 loc_4C3992:                             ; CODE XREF' +
        ': sub_4C36D0+2B8'#24'j'
      '___:004C3992                 lea     eax, [esi+680h]'
      '___:004C3998'
      
        '___:004C3998 loc_4C3998:                             ; CODE XREF' +
        ': sub_4C36D0+2C0'#24'j'
      '___:004C3998                 cmp     [esp+15Ch+var_114], ecx'
      '___:004C399C                 mov     ecx, [esp+15Ch+var_128]'
      '___:004C39A0                 jnb     short loc_4C39A6'
      '___:004C39A2                 lea     ecx, [esp+15Ch+var_128]'
      '___:004C39A6'
      
        '___:004C39A6 loc_4C39A6:                             ; CODE XREF' +
        ': sub_4C36D0+2D0'#24'j'
      '___:004C39A6                 push    eax'
      '___:004C39A7                 push    ecx'
      '___:004C39A8                 lea     ecx, [esp+164h+var_110]'
      '___:004C39AC                 push    ecx'
      '___:004C39AD                 call    sub_A293DE'
      '___:004C39B2                 add     esp, 0Ch'
      '___:004C39B5                 lea     edx, [esp+15Ch+var_110]'
      '___:004C39B9                 push    edx'
      '___:004C39BA                 lea     ecx, [esp+160h+var_148]'
      '___:004C39BE                 call    sub_401FB0'
      
        '___:004C39C3                 mov     byte ptr [esp+15Ch+var_4], ' +
        '3'
      '___:004C39CB'
      
        '___:004C39CB loc_4C39CB:                             ; CODE XREF' +
        ': sub_4C36D0+2AB'#24'j'
      '___:004C39CB                 push    0FF00FFFFh'
      '___:004C39D0                 lea     eax, [esp+160h+var_148]'
      '___:004C39D4                 push    eax'
      '___:004C39D5                 mov     ecx, ebp'
      '___:004C39D7                 call    sub_493E10'
      
        '___:004C39DC                 mov     byte ptr [esp+15Ch+var_4], ' +
        'bl'
      '___:004C39E3                 lea     ecx, [esp+15Ch+var_148]'
      '___:004C39E7                 call    sub_401AA0'
      '___:004C39EC'
      
        '___:004C39EC loc_4C39EC:                             ; CODE XREF' +
        ': sub_4C36D0+1B2'#24'j'
      
        '___:004C39EC                                         ; sub_4C36D' +
        '0+1C6'#24'j'
      '___:004C39EC                 mov     ecx, ebp'
      '___:004C39EE                 call    sub_4AB4E0'
      '___:004C39F3                 mov     ecx, dword_D79CBC'
      '___:004C39F9                 push    ebx'
      '___:004C39FA                 call    sub_50C2F0'
      '___:004C39FF                 mov     ecx, dword_D79CBC'
      '___:004C3A05                 push    ebx'
      '___:004C3A06                 push    esi'
      '___:004C3A07                 call    sub_4F2130'
      '___:004C3A0C                 or      edi, 0FFFFFFFFh'
      '___:004C3A0F                 test    al, al'
      '___:004C3A11                 jz      short loc_4C3A28'
      '___:004C3A13                 mov     ecx, dword_D79CBC'
      '___:004C3A19                 mov     edx, [ecx]'
      '___:004C3A1B                 mov     eax, [edx+18h]'
      '___:004C3A1E                 push    edi'
      '___:004C3A1F                 push    edi'
      '___:004C3A20                 push    0'
      '___:004C3A22                 push    esi'
      '___:004C3A23                 push    ebx'
      '___:004C3A24                 push    0'
      '___:004C3A26                 call    eax'
      '___:004C3A28'
      
        '___:004C3A28 loc_4C3A28:                             ; CODE XREF' +
        ': sub_4C36D0+341'#24'j'
      '___:004C3A28                 mov     [esp+15Ch+var_4], edi'
      '___:004C3A2F                 lea     ecx, [esp+15Ch+var_12C]'
      '___:004C3A33                 call    sub_401AA0'
      '___:004C3A38                 mov     ecx, dword_D79CBC'
      '___:004C3A3E                 push    ebx'
      '___:004C3A3F                 push    esi'
      '___:004C3A40                 call    sub_4F2130'
      '___:004C3A45                 test    al, al'
      '___:004C3A47                 jnz     loc_4C3B0E'
      '___:004C3A4D                 mov     eax, dword_D79CBC'
      '___:004C3A52                 cmp     byte ptr [eax+720h], 0'
      '___:004C3A59                 jz      short loc_4C3A68'
      '___:004C3A5B                 cmp     byte ptr [eax+721h], 0'
      '___:004C3A62                 jnz     loc_4C3B0E'
      '___:004C3A68'
      
        '___:004C3A68 loc_4C3A68:                             ; CODE XREF' +
        ': sub_4C36D0+389'#24'j'
      '___:004C3A68                 mov     [esp+15Ch+var_114], 0Fh'
      '___:004C3A70                 mov     [esp+15Ch+var_118], 0'
      
        '___:004C3A78                 mov     byte ptr [esp+15Ch+var_128]' +
        ', 0'
      '___:004C3A7D                 mov     [esp+15Ch+var_4], 5'
      '___:004C3A88                 lea     edx, [esp+15Ch+var_12C]'
      '___:004C3A8C                 push    edx'
      '___:004C3A8D                 push    0BB9h'
      '___:004C3A92                 call    sub_8A33C0'
      '___:004C3A97                 add     esp, 8'
      '___:004C3A9A                 push    0FFFFFF00h'
      '___:004C3A9F                 lea     eax, [esp+160h+var_12C]'
      '___:004C3AA3                 push    eax'
      '___:004C3AA4                 mov     ecx, ebp'
      '___:004C3AA6                 call    sub_493E10'
      '___:004C3AAB                 mov     [esp+15Ch+var_4], edi'
      '___:004C3AB2                 jmp     short loc_4C3B05'
      
        '___:004C3AB4 ; -------------------------------------------------' +
        '--------------------------'
      '___:004C3AB4'
      
        '___:004C3AB4 loc_4C3AB4:                             ; CODE XREF' +
        ': sub_4C36D0+115'#24'j'
      '___:004C3AB4                 mov     byte ptr [eax+0E99h], 0'
      '___:004C3ABB                 mov     [esp+15Ch+var_114], 0Fh'
      '___:004C3AC3                 mov     [esp+15Ch+var_118], edi'
      
        '___:004C3AC7                 mov     byte ptr [esp+15Ch+var_128]' +
        ', 0'
      '___:004C3ACC                 mov     [esp+15Ch+var_4], edi'
      '___:004C3AD3                 lea     ecx, [esp+15Ch+var_12C]'
      '___:004C3AD7                 push    ecx'
      '___:004C3AD8                 push    1D2Ch'
      '___:004C3ADD                 call    sub_8A33C0'
      '___:004C3AE2                 mov     ecx, dword_D79D74'
      '___:004C3AE8                 add     esp, 8'
      '___:004C3AEB                 push    0FFFF3B3Bh'
      '___:004C3AF0                 lea     edx, [esp+160h+var_12C]'
      '___:004C3AF4                 push    edx'
      '___:004C3AF5                 call    sub_493E10'
      
        '___:004C3AFA                 mov     [esp+15Ch+var_4], 0FFFFFFFF' +
        'h'
      '___:004C3B05'
      
        '___:004C3B05 loc_4C3B05:                             ; CODE XREF' +
        ': sub_4C36D0+258'#24'j'
      
        '___:004C3B05                                         ; sub_4C36D' +
        '0+3E2'#24'j'
      '___:004C3B05                 lea     ecx, [esp+15Ch+var_12C]'
      '___:004C3B09                 call    sub_401AA0'
      '___:004C3B0E'
      
        '___:004C3B0E loc_4C3B0E:                             ; CODE XREF' +
        ': sub_4C36D0+51'#24'j'
      
        '___:004C3B0E                                         ; sub_4C36D' +
        '0+64'#24'j ...'
      '___:004C3B0E                 mov     ecx, [esp+15Ch+var_C]'
      '___:004C3B15                 mov     large fs:0, ecx'
      '___:004C3B1C                 pop     ecx'
      '___:004C3B1D                 pop     edi'
      '___:004C3B1E                 pop     esi'
      '___:004C3B1F                 pop     ebp'
      '___:004C3B20                 pop     ebx'
      '___:004C3B21                 mov     ecx, [esp+148h+var_10]'
      '___:004C3B28                 xor     ecx, esp'
      '___:004C3B2A                 call    sub_A289C3'
      '___:004C3B2F                 add     esp, 148h'
      '___:004C3B35                 retn    8'
      '___:004C3B35 sub_4C36D0      endp')
    TabOrder = 1
  end
  object ListBox2: TListBox
    Left = 519
    Top = 8
    Width = 474
    Height = 545
    ItemHeight = 13
    TabOrder = 2
  end
  object Memo1: TMemo
    Left = 328
    Top = 8
    Width = 185
    Height = 266
    Lines.Strings = (
      'Memo1')
    TabOrder = 3
  end
  object Button1: TButton
    Left = 328
    Top = 336
    Width = 75
    Height = 25
    Caption = 'testpatch'
    TabOrder = 4
  end
end
