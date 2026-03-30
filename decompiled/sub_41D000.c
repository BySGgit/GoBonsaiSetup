LRESULT __stdcall sub_41D000(HWND a1, UINT Msg, WPARAM a3, LPARAM a4)
{
  char v4; // bl
  int EngineInstance; // esi
  int v6; // esi
  void (__stdcall *v7)(WPARAM, LONG, _DWORD, int); // ebx
  int v8; // esi
  int v9; // esi
  int v10; // eax
  LONG left; // edi
  char v12; // bl
  _BYTE *v13; // esi
  char v14; // al
  char v15; // cl
  char v16; // dl
  int v17; // esi
  void (__stdcall *v18)(LONG, _DWORD, int, int, int, int, LONG, LONG, int); // esi
  int v19; // ebx
  int v20; // ebx
  int v21; // esi
  int (__stdcall *v22)(HWND, UINT, WPARAM, LPARAM, char *, int); // ebx
  int v23; // esi
  int v24; // esi
  UINT v25; // edi
  LRESULT result; // eax
  HWND v27; // ebx
  WPARAM v28; // esi
  int v29; // eax
  int v30; // eax
  int v31; // esi
  int v32; // eax
  void (__stdcall *v33)(int, LONG, LONG, _DWORD, int); // ebx
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // ebx
  int v39; // eax
  void (__stdcall *v40)(int, LONG, LONG, _DWORD, int); // esi
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int *v46; // esi
  int v47; // ebx
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  HWND v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  LPARAM v64; // eax
  int v65; // ecx
  int v66; // esi
  int v67; // eax
  int v68; // eax
  int v69; // eax
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // eax
  char v74; // al
  int v75; // eax
  int v76; // eax
  int v77; // eax
  int v78; // eax
  int v79; // eax
  int v80; // eax
  HMENU Menu; // eax
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // eax
  WPARAM v86; // eax
  WPARAM v87; // eax
  int v88; // esi
  int v89; // eax
  int v90; // eax
  int v91; // esi
  char v92; // bl
  int v93; // esi
  int v94; // esi
  int v95; // eax
  char v96; // [esp+40h] [ebp-84h]
  int v97; // [esp+84h] [ebp-40h] BYREF
  WPARAM wParam; // [esp+88h] [ebp-3Ch]
  float v99; // [esp+8Ch] [ebp-38h]
  LPARAM lParam; // [esp+90h] [ebp-34h]
  LONG top; // [esp+94h] [ebp-30h]
  HWND hWnd; // [esp+98h] [ebp-2Ch]
  int v103; // [esp+9Ch] [ebp-28h]
  int v104; // [esp+A0h] [ebp-24h]
  int v105; // [esp+A4h] [ebp-20h]
  int v106; // [esp+A8h] [ebp-1Ch]
  struct tagRECT Point; // [esp+ACh] [ebp-18h] BYREF

  hWnd = a1;
  wParam = a3;
  lParam = a4;
  if ( a3 == 61696 && (a4 < 0 || (a4 & 0xFFFF0000) == 0) )
    return 0;
  if ( Msg == 256 || Msg == 260 )
  {
    v4 = 1;
  }
  else
  {
    if ( Msg != 257 && Msg != 261 )
      goto LABEL_22;
    v4 = 0;
  }
  LOBYTE(top) = v4;
  LOBYTE(v99) = (a4 & 0x20000000) != 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
  {
    EnterCriticalSection(&CriticalSection);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
  }
  *(_BYTE *)((unsigned __int8)wParam + EngineInstance + 1008) = v4;
  v6 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = *(void (__stdcall **)(WPARAM, LONG, _DWORD, int))(v6 + 876);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v7 )
  {
    v8 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v9 = *(_DWORD *)(v8 + 948);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    v7(wParam, top, LODWORD(v99), v9);
  }
LABEL_22:
  if ( Msg == 513
    || Msg == 514
    || Msg == 515
    || Msg == 519
    || Msg == 520
    || Msg == 521
    || Msg == 516
    || Msg == 517
    || Msg == 518
    || Msg == 523
    || Msg == 524
    || Msg == 525
    || Msg == 522
    || (v10 = GetEngineInstance(), (unsigned __int8)sub_41A720(v10)) && Msg == 512 )
  {
    left = (__int16)lParam;
    top = SHIWORD(lParam);
    if ( Msg == 522 )
    {
      Point.top = SHIWORD(lParam);
      Point.left = (__int16)lParam;
      ScreenToClient(hWnd, (LPPOINT)&Point);
      left = Point.left;
      top = Point.top;
    }
    v103 = 0;
    if ( Msg == 522 )
      v103 = SHIWORD(wParam);
    LOBYTE(v99) = (wParam & 2) != 0;
    v12 = wParam & 1;
    LOBYTE(Point.left) = wParam & 1;
    LOBYTE(v104) = (wParam & 0x10) != 0;
    LOBYTE(v106) = (wParam & 0x20) != 0;
    LOBYTE(v105) = (wParam & 0x40) != 0;
    v13 = (_BYTE *)GetEngineInstance();
    if ( byte_4CA649 )
    {
      EnterCriticalSection(&CriticalSection);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
    }
    v14 = LOBYTE(v99);
    v15 = v106;
    v13[1521] = v104;
    v16 = v105;
    v13[1520] = v12;
    v13[1522] = v14;
    v13[1523] = v15;
    v13[1524] = v16;
    v17 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v18 = *(void (__stdcall **)(LONG, _DWORD, int, int, int, int, LONG, LONG, int))(v17 + 880);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v18 )
    {
      v19 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v20 = *(_DWORD *)(v19 + 952);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      v18(Point.left, LODWORD(v99), v104, v106, v105, v103, left, top, v20);
    }
  }
  v21 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v22 = *(int (__stdcall **)(HWND, UINT, WPARAM, LPARAM, char *, int))(v21 + 884);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !v22 )
  {
    v25 = Msg;
    goto LABEL_66;
  }
  HIBYTE(v97) = 0;
  v23 = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v24 = *(_DWORD *)(v23 + 956);
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  v25 = Msg;
  result = v22(hWnd, Msg, wParam, lParam, (char *)&v97 + 3, v24);
  if ( !HIBYTE(v97) )
  {
LABEL_66:
    v27 = hWnd;
    v28 = wParam;
    if ( v25 <= 0x104 )
    {
      if ( v25 == 260 )
      {
        if ( wParam == 13 )
        {
          v85 = GetEngineInstance();
          if ( (unsigned __int8)sub_41A160(v85) )
          {
            if ( (unsigned __int8)sub_41BAB0() && (lParam & 0x20000000) != 0 )
            {
              sub_4250D0(1, 1);
              sub_425B80();
              sub_4250D0(0, 0);
              return 0;
            }
          }
        }
      }
      else
      {
        switch ( v25 )
        {
          case 2u:
            PostQuitMessage(0);
            goto LABEL_182;
          case 5u:
            if ( wParam == 1 )
            {
              sub_4250D0(1, 1);
              v54 = GetEngineInstance();
              sub_419C50(v54, 1);
              v55 = GetEngineInstance();
              sub_419CD0(v55, 0);
              goto LABEL_182;
            }
            v56 = (HWND)sub_41B5D0();
            GetClientRect(v56, &Point);
            if ( !Point.top && !Point.bottom )
              goto LABEL_182;
            if ( v28 == 2 )
            {
              v57 = GetEngineInstance();
              if ( (unsigned __int8)sub_419C90(v57) )
                sub_4250D0(0, 0);
              v58 = GetEngineInstance();
              sub_419C50(v58, 0);
              v96 = 1;
              goto LABEL_102;
            }
            if ( v28 )
              goto LABEL_182;
            v59 = GetEngineInstance();
            if ( (unsigned __int8)sub_419D10(v59) )
            {
              v96 = 0;
LABEL_102:
              v60 = GetEngineInstance();
              sub_419CD0(v60, v96);
              sub_4267B0();
              sub_4268E0();
              goto LABEL_182;
            }
            v61 = GetEngineInstance();
            if ( (unsigned __int8)sub_419C90(v61) )
            {
              sub_4250D0(0, 0);
              v62 = GetEngineInstance();
              sub_419C50(v62, 0);
              sub_4267B0();
              sub_4268E0();
            }
            else
            {
              v63 = GetEngineInstance();
              if ( !(unsigned __int8)sub_41A7E0(v63) )
              {
                sub_4267B0();
                sub_4268E0();
              }
            }
            break;
          case 0xFu:
            if ( (unsigned __int8)sub_41B900() )
            {
              v29 = GetEngineInstance();
              if ( (unsigned __int8)sub_41A5A0(v29) )
              {
                v30 = GetEngineInstance();
                if ( (unsigned __int8)sub_41A620(v30) )
                {
                  *(double *)&Point.left = sub_41B820();
                  v99 = sub_41B870();
                  if ( (unsigned __int8)sub_41B490() )
                  {
                    v31 = sub_41B510();
                    if ( v31 )
                    {
                      v32 = GetEngineInstance();
                      v33 = (void (__stdcall *)(int, LONG, LONG, _DWORD, int))sub_41AEE0(v32);
                      if ( v33 )
                      {
                        v34 = GetEngineInstance();
                        v35 = sub_41B160(v34);
                        v33(v31, Point.left, Point.top, LODWORD(v99), v35);
                      }
                      v36 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v31 + 68))(
                              v31,
                              0,
                              0,
                              0,
                              0);
                      if ( v36 == -2005530520 || v36 == -2005530585 )
                      {
                        v37 = GetEngineInstance();
                        sub_41A6E0(v37, 1);
                      }
                    }
                  }
                  else
                  {
                    v38 = sub_41B550();
                    if ( v38 )
                    {
                      v39 = GetEngineInstance();
                      v40 = (void (__stdcall *)(int, LONG, LONG, _DWORD, int))sub_41AFE0(v39);
                      if ( v40 )
                      {
                        v41 = GetEngineInstance();
                        if ( !(unsigned __int8)sub_4197D0(v41) )
                        {
                          v42 = GetEngineInstance();
                          v43 = sub_41B260(v42);
                          v40(v38, Point.left, Point.top, LODWORD(v99), v43);
                        }
                      }
                      v44 = GetEngineInstance();
                      if ( !(unsigned __int8)sub_4197D0(v44) )
                      {
                        v45 = GetEngineInstance();
                        sub_419610(v45);
                      }
                      v46 = (int *)sub_41B590();
                      v47 = *v46;
                      v48 = GetEngineInstance();
                      v49 = sub_419610(v48);
                      v50 = (*(int (__stdcall **)(int *, _DWORD, _DWORD))(v47 + 32))(v46, 0, *(_DWORD *)(v49 + 84));
                      if ( v50 == 142213121 )
                      {
                        v51 = GetEngineInstance();
                        sub_419790(v51, 1);
                      }
                      else if ( v50 >= 0 )
                      {
                        v52 = GetEngineInstance();
                        if ( (unsigned __int8)sub_4197D0(v52) )
                        {
                          v53 = GetEngineInstance();
                          sub_419790(v53, 0);
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LABEL_182;
          case 0x10u:
            Menu = GetMenu(hWnd);
            if ( Menu )
              DestroyMenu(Menu);
            DestroyWindow(v27);
            UnregisterClassW(L"Direct3DWindowClass", 0);
            v82 = GetEngineInstance();
            sub_419850(v82, 0);
            v83 = GetEngineInstance();
            sub_419890(v83, 0);
            v84 = GetEngineInstance();
            sub_4198D0(v84, 0);
            return 0;
          case 0x1Cu:
            if ( wParam == 1 )
            {
              if ( !(unsigned __int8)sub_41B980() )
              {
                v69 = GetEngineInstance();
                sub_41A660(v69, 1);
                sub_438A80(1);
                v70 = GetEngineInstance();
                if ( (unsigned __int8)sub_419D90(v70) )
                {
                  v71 = GetEngineInstance();
                  sub_419610(v71);
                  if ( (unsigned __int8)sub_41B470() )
                    sub_4250D0(0, 0);
                  v72 = GetEngineInstance();
                  sub_419D50(v72, 0);
                  if ( (unsigned __int8)sub_41BAF0() )
                    sub_425B80();
                }
                if ( (unsigned __int8)sub_41B9C0() )
                {
                  v73 = GetEngineInstance();
                  v74 = sub_419FD0(v73);
                }
                else
                {
                  v75 = GetEngineInstance();
                  v74 = sub_419F90(v75);
                }
                sub_424DB0(v74);
              }
            }
            else if ( !wParam && (unsigned __int8)sub_41B980() )
            {
              v76 = GetEngineInstance();
              sub_41A660(v76, 0);
              sub_438A80(0);
              if ( !(unsigned __int8)sub_41B9C0() )
              {
                ClipCursor(0);
                v77 = GetEngineInstance();
                sub_419610(v77);
                if ( (unsigned __int8)sub_41B470() )
                  sub_4250D0(1, 1);
                v78 = GetEngineInstance();
                sub_419D50(v78, 1);
              }
              sub_424DB0(1);
            }
            goto LABEL_182;
          case 0x20u:
            if ( !(unsigned __int8)sub_41B980() || (unsigned __int8)sub_41B9C0() )
              goto LABEL_182;
            if ( (unsigned __int8)sub_41B490() )
            {
              v66 = sub_41B510();
              if ( v66 )
              {
                v67 = GetEngineInstance();
                if ( (unsigned __int8)sub_41A260(v67) )
                  (*(void (__stdcall **)(int, int))(*(_DWORD *)v66 + 48))(v66, 1);
              }
            }
            else
            {
              v68 = GetEngineInstance();
              if ( !(unsigned __int8)sub_41A260(v68) )
                SetCursor(0);
            }
            return 1;
          case 0x24u:
            v64 = lParam;
            v65 = dword_4D7F00;
            *(_DWORD *)(lParam + 24) = dword_4D7EFC;
            *(_DWORD *)(v64 + 28) = v65;
            goto LABEL_182;
          case 0x84u:
            if ( !(unsigned __int8)sub_41B9C0() )
              return 1;
            goto LABEL_182;
          case 0x100u:
            if ( wParam != 19 )
            {
              if ( wParam == 27 )
              {
                v79 = GetEngineInstance();
                if ( (unsigned __int8)sub_41A120(v79) )
                  SendMessageW(v27, 0x10u, 0, 0);
              }
              goto LABEL_182;
            }
            v80 = GetEngineInstance();
            if ( !(unsigned __int8)sub_41A1A0(v80) )
              goto LABEL_182;
            if ( !(unsigned __int8)sub_41B940() )
            {
              sub_4250D0(1, 0);
              goto LABEL_182;
            }
            goto LABEL_174;
          default:
            goto LABEL_182;
        }
      }
      goto LABEL_182;
    }
    if ( v25 > 0x212 )
    {
      switch ( v25 )
      {
        case 0x218u:
          if ( wParam )
          {
            if ( wParam != 7 )
              break;
            sub_4375B0();
            sub_437640();
            v95 = GetEngineInstance();
            sub_419E50(v95, 0.0);
          }
          return 1;
        case 0x231u:
          sub_4250D0(1, 1);
          v90 = GetEngineInstance();
          sub_41A7A0(v90, 1);
          break;
        case 0x232u:
          sub_4250D0(0, 0);
          sub_4267B0();
          sub_4268E0();
          v89 = GetEngineInstance();
          sub_41A7A0(v89, 0);
          break;
      }
    }
    else
    {
      if ( v25 == 530 )
      {
LABEL_174:
        sub_4250D0(0, 0);
        goto LABEL_182;
      }
      if ( v25 > 0x200 )
      {
        if ( v25 == 529 )
          sub_4250D0(1, 1);
      }
      else
      {
        switch ( v25 )
        {
          case 0x200u:
            if ( (unsigned __int8)sub_41B980() )
            {
              if ( !(unsigned __int8)sub_41B9C0() )
              {
                if ( (unsigned __int8)sub_41B490() )
                {
                  v88 = sub_41B510();
                  if ( v88 )
                  {
                    GetCursorPos((LPPOINT)&Point);
                    (*(void (__stdcall **)(int, LONG, LONG, _DWORD))(*(_DWORD *)v88 + 44))(
                      v88,
                      Point.left,
                      Point.top,
                      0);
                  }
                }
              }
            }
            break;
          case 0x112u:
            v86 = wParam & 0xFFF0;
            if ( v86 > 0xF030 )
            {
              if ( v86 != 61696 )
                break;
            }
            else if ( v86 != 61488 )
            {
              v87 = v86 - 61440;
              if ( v87 )
              {
                if ( v87 != 16 )
                  break;
              }
            }
            if ( !(unsigned __int8)sub_41B9C0() )
              return 0;
            break;
          case 0x120u:
            return 0x10000;
        }
      }
    }
LABEL_182:
    v91 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v92 = *(_BYTE *)(v91 + 707);
    if ( byte_4CA649 )
      LeaveCriticalSection(&CriticalSection);
    if ( v92 )
    {
      v93 = GetEngineInstance();
      if ( byte_4CA649 )
        EnterCriticalSection(&CriticalSection);
      v94 = *(_DWORD *)(v93 + 576);
      if ( byte_4CA649 )
        LeaveCriticalSection(&CriticalSection);
      if ( v94 || v25 != 260 && v25 != 261 || wParam != 121 )
        return DefWindowProcW(hWnd, v25, wParam, lParam);
    }
    return 0;
  }
  return result;
}
