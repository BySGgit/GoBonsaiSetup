int __cdecl sub_41E880(_DWORD *a1, int a2, ID3D10Device *a3, char a4, int a5)
{
  _DWORD *EngineInstance; // edi
  _DWORD *v6; // ebp
  int v7; // eax
  _DWORD *v9; // ebx
  void *v10; // eax
  unsigned __int8 (__stdcall *v11)(_DWORD *, int); // esi
  void *v12; // eax
  int v13; // eax
  int *v14; // eax
  void *v15; // eax
  void *v16; // eax
  void *v17; // eax
  int v18; // ecx
  int v20; // eax
  void *v21; // eax
  int v22; // eax
  void *v23; // eax
  void *v24; // eax
  HWND v25; // eax
  int v26; // esi
  HWND v27; // eax
  int v28; // esi
  void *v29; // eax
  void *v30; // eax
  HWND v31; // eax
  void *v32; // eax
  WINDOWPLACEMENT *v33; // esi
  HWND v34; // eax
  HWND v35; // eax
  void *v36; // eax
  HWND v37; // eax
  void *v38; // eax
  int v39; // eax
  void *v40; // eax
  int v41; // eax
  void *v42; // eax
  HWND v43; // eax
  HWND v44; // eax
  int v45; // esi
  HWND v46; // eax
  void *v47; // eax
  HWND v48; // eax
  HWND v49; // eax
  HWND v50; // eax
  int v51; // eax
  void *v52; // eax
  void *v53; // eax
  int v54; // eax
  void *v55; // eax
  int v56; // eax
  void *v57; // eax
  int v58; // eax
  int v59; // esi
  void *v60; // eax
  void *v61; // eax
  char v62; // al
  void *v63; // eax
  int v64; // eax
  int v65; // esi
  void *v66; // eax
  void *v67; // eax
  void *v68; // eax
  void *v69; // eax
  HWND v70; // eax
  void *v71; // eax
  HWND v72; // eax
  HWND v73; // eax
  HWND v74; // eax
  HWND v75; // eax
  HWND v76; // eax
  int v77; // esi
  int v78; // edi
  HWND v79; // eax
  void *v80; // eax
  void *v81; // eax
  DWORD v82; // eax
  HWND v83; // eax
  int *v84; // ebp
  int v85; // eax
  int v86; // eax
  HWND v87; // eax
  HMONITOR v88; // edi
  HWND v89; // eax
  HMONITOR v90; // esi
  HWND v91; // eax
  HWND v92; // eax
  HWND v93; // eax
  HWND v94; // eax
  HWND v95; // eax
  HWND v96; // eax
  HMONITOR v97; // eax
  HWND v98; // eax
  HMONITOR v99; // eax
  int v100; // edi
  int v101; // ebx
  LONG v102; // esi
  LONG v103; // ebp
  HWND v104; // eax
  void *v105; // eax
  HWND v106; // eax
  LONG WindowLongW; // eax
  LONG left; // edx
  LONG top; // ebp
  int v110; // ecx
  int v111; // esi
  int v112; // edi
  int v113; // eax
  HWND v114; // eax
  int v115; // eax
  void *v116; // eax
  HWND v117; // eax
  LONG v118; // eax
  HWND v119; // eax
  HWND v120; // eax
  int v121; // edi
  int v122; // esi
  int v123; // esi
  void *v124; // eax
  HWND v125; // eax
  HWND v126; // eax
  void *v127; // eax
  void *v128; // eax
  HWND v129; // [esp-18h] [ebp-188h]
  int v130; // [esp-14h] [ebp-184h]
  int v131; // [esp-Ch] [ebp-17Ch]
  int v132; // [esp-Ch] [ebp-17Ch]
  int v133; // [esp-8h] [ebp-178h]
  int v134; // [esp-4h] [ebp-174h]
  int v135; // [esp-4h] [ebp-174h]
  LONG v136; // [esp-4h] [ebp-174h]
  HMENU v137; // [esp-4h] [ebp-174h]
  char v138; // [esp-4h] [ebp-174h]
  unsigned int v139; // [esp-4h] [ebp-174h]
  int v140; // [esp-4h] [ebp-174h]
  int v141; // [esp-4h] [ebp-174h]
  HMENU Menu; // [esp-4h] [ebp-174h]
  int v143; // [esp-4h] [ebp-174h]
  int v144; // [esp-4h] [ebp-174h]
  int v145; // [esp-4h] [ebp-174h]
  int v146; // [esp-4h] [ebp-174h]
  HMONITOR v147; // [esp-4h] [ebp-174h]
  const WINDOWPLACEMENT *v148; // [esp-4h] [ebp-174h]
  BOOL v149; // [esp-4h] [ebp-174h]
  BOOL v150; // [esp-4h] [ebp-174h]
  BOOL v151; // [esp-4h] [ebp-174h]
  char v152; // [esp+12h] [ebp-15Eh]
  char v153; // [esp+13h] [ebp-15Dh]
  _DWORD *v154; // [esp+1Ch] [ebp-154h]
  void *v155; // [esp+20h] [ebp-150h]
  _DWORD v156[24]; // [esp+28h] [ebp-148h] BYREF
  _BYTE v157[96]; // [esp+88h] [ebp-E8h] BYREF
  struct tagRECT Rect; // [esp+E8h] [ebp-88h] BYREF
  struct tagMONITORINFO v159; // [esp+F8h] [ebp-78h] BYREF
  WINDOWPLACEMENT wndpl; // [esp+120h] [ebp-50h] BYREF
  struct tagRECT v161; // [esp+14Ch] [ebp-24h] BYREF
  struct tagRECT v162; // [esp+15Ch] [ebp-14h] BYREF

  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v6 = (_DWORD *)EngineInstance[2];
  v155 = v6;
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( !a1 )
    return 1;
  if ( *a1 )
    v7 = sub_41F640();
  else
    v7 = sub_41F750();
  if ( v7 < 0 )
    return -2147219199;
  v9 = operator new(0x60u);
  v154 = v9;
  if ( !v9 )
    return -2147024882;
  qmemcpy(v9, a1, 0x60u);
  v10 = GetEngineInstance();
  v11 = (unsigned __int8 (__stdcall *)(_DWORD *, int))sub_41ADE0((int)v10);
  if ( v11 && !a2 && !a3 )
  {
    v12 = GetEngineInstance();
    v13 = sub_41B020((int)v12);
    if ( !v11(v9, v13) )
    {
      if ( !v6 )
        sub_4256B0(-2147219198);
      operator delete(v9);
      return -2147467260;
    }
    v14 = (int *)GetEngineInstance();
    if ( !sub_419590(v14) )
    {
      v15 = GetEngineInstance();
      if ( !sub_419650((int)v15) )
      {
        operator delete(v9);
        return 1;
      }
    }
  }
  v16 = GetEngineInstance();
  sub_4195D0((int)v16, (int)v9);
  sub_4250D0(1, 1);
  if ( sub_41B490() )
  {
    v17 = GetEngineInstance();
    sub_419DD0((int)v17, 1);
  }
  if ( !a2 && !a3 && !v6 )
    sub_41F7F0(v9);
  v152 = 0;
  if ( *v9 )
    v18 = v9[4];
  else
    v18 = v9[5];
  if ( !v18 && !(*v9 ? v9[5] : v9[6]) )
    v152 = 1;
  if ( sub_41B490() )
  {
    if ( sub_41B4E0(v9) )
    {
      if ( v6 && !sub_41B4E0(v6) )
      {
        if ( *v6 )
          v20 = v6[4];
        else
          v20 = v6[5];
        v134 = v20;
        v21 = GetEngineInstance();
        sub_419A10((int)v21, v134);
        if ( *v6 )
          v22 = v6[5];
        else
          v22 = v6[6];
        v135 = v22;
        v23 = GetEngineInstance();
        sub_419A50((int)v23, v135);
        v24 = GetEngineInstance();
        v136 = sub_419B90((int)v24);
        v25 = (HWND)sub_41B6C0();
        SetWindowLongW(v25, -16, v136);
      }
      v26 = sub_41B680();
      if ( v26 != sub_41B6C0() )
      {
        v27 = (HWND)sub_41B680();
        ShowWindow(v27, 0);
      }
      v28 = sub_41B680();
      if ( v28 == sub_41B6C0() )
      {
        v29 = GetEngineInstance();
        if ( sub_4199D0((int)v29) )
        {
          v30 = GetEngineInstance();
          v137 = (HMENU)sub_4199D0((int)v30);
          v31 = (HWND)sub_41B6C0();
          SetMenu(v31, v137);
        }
      }
    }
    else
    {
      if ( !v6 || sub_41B4E0(v6) )
      {
        v32 = GetEngineInstance();
        v33 = (WINDOWPLACEMENT *)sub_419B10((int)v32);
        memset(v33, 0, sizeof(WINDOWPLACEMENT));
        v33->length = 44;
        v34 = (HWND)sub_41B6C0();
        GetWindowPlacement(v34, v33);
        v35 = (HWND)sub_41B6C0();
        v138 = (GetWindowLongW(v35, -20) & 8) != 0;
        v36 = GetEngineInstance();
        sub_419BD0((int)v36, v138);
        v37 = (HWND)sub_41B6C0();
        v139 = GetWindowLongW(v37, -16) & 0xDEFFFFFF;
        v38 = GetEngineInstance();
        sub_419B50((int)v38, v139);
        if ( v6 )
        {
          if ( *v6 )
            v39 = v6[4];
          else
            v39 = v6[5];
          v140 = v39;
          v40 = GetEngineInstance();
          sub_419A90((int)v40, v140);
          if ( *v6 )
            v41 = v6[5];
          else
            v41 = v6[6];
          v141 = v41;
          v42 = GetEngineInstance();
          sub_419AD0((int)v42, v141);
        }
      }
      v43 = (HWND)sub_41B680();
      ShowWindow(v43, 0);
      v44 = (HWND)sub_41B680();
      SetWindowLongW(v44, -16, -2146959360);
      v45 = sub_41B680();
      if ( v45 == sub_41B6C0() )
      {
        v46 = (HWND)sub_41B680();
        Menu = GetMenu(v46);
        v47 = GetEngineInstance();
        sub_419990((int)v47, (int)Menu);
        v48 = (HWND)sub_41B680();
        SetMenu(v48, 0);
      }
      memset(&wndpl, 0, sizeof(wndpl));
      wndpl.length = 44;
      v49 = (HWND)sub_41B680();
      GetWindowPlacement(v49, &wndpl);
      if ( (wndpl.flags & 2) != 0 )
      {
        wndpl.flags &= ~2u;
        wndpl.showCmd = 9;
        v50 = (HWND)sub_41B680();
        SetWindowPlacement(v50, &wndpl);
      }
    }
  }
  else if ( sub_41B4E0(v9) )
  {
    if ( v6 && !sub_41B4E0(v6) )
    {
      if ( *v6 )
        v51 = v6[4];
      else
        v51 = v6[5];
      v143 = v51;
      v52 = GetEngineInstance();
      sub_419A10((int)v52, v143);
      if ( *v6 )
        v144 = v6[5];
      else
        v144 = v6[6];
      v53 = GetEngineInstance();
      sub_419A50((int)v53, v144);
    }
  }
  else if ( v6 && sub_41B4E0(v6) )
  {
    if ( *v6 )
      v54 = v6[4];
    else
      v54 = v6[5];
    v145 = v54;
    v55 = GetEngineInstance();
    sub_419A90((int)v55, v145);
    if ( *v6 )
      v56 = v6[5];
    else
      v56 = v6[6];
    v146 = v56;
    v57 = GetEngineInstance();
    sub_419AD0((int)v57, v146);
  }
  if ( a4 || !sub_41F5A0(v9, v6, a2, (int)a3) )
  {
    if ( v6 )
      sub_426B70(0);
    if ( *v9 )
      v64 = sub_421960(a3);
    else
      v64 = sub_41FF90(a2);
    v65 = v64;
    if ( v64 < 0 )
    {
      if ( v6 )
        operator delete(v6);
      sub_426B70(1);
      sub_4256B0(v65);
      sub_4250D0(0, 0);
      v66 = GetEngineInstance();
      sub_419DD0((int)v66, 0);
      return v65;
    }
LABEL_97:
    if ( sub_41B4E0(v9) )
    {
      v61 = GetEngineInstance();
      v62 = sub_419FD0((int)v61);
    }
    else
    {
      v67 = GetEngineInstance();
      v62 = sub_419F90((int)v67);
    }
    sub_424DB0(v62);
    v147 = sub_426C00(v9);
    v68 = GetEngineInstance();
    sub_419910((int)v68, (int)v147);
    sub_427400();
    if ( v6 && !sub_41B4E0(v6) && sub_41B4E0(v9) )
    {
      v69 = GetEngineInstance();
      v148 = (const WINDOWPLACEMENT *)sub_419B10((int)v69);
      v70 = (HWND)sub_41B6C0();
      SetWindowPlacement(v70, v148);
      v71 = GetEngineInstance();
      v129 = (HWND)((sub_419C10((int)v71) != 0) - 2);
      v72 = (HWND)sub_41B6C0();
      SetWindowPos(v72, v129, 0, 0, 0, 0, 0xBu);
    }
    v153 = 0;
    if ( sub_41B4E0(v9) && !v152 )
    {
      v73 = (HWND)sub_41B6C0();
      if ( IsIconic(v73) )
      {
        memset(&wndpl, 0, sizeof(wndpl));
        wndpl.length = 44;
        v74 = (HWND)sub_41B6C0();
        GetWindowPlacement(v74, &wndpl);
        if ( (wndpl.flags & 2) != 0 && wndpl.showCmd == 2 )
        {
          v75 = (HWND)sub_41B6C0();
          ShowWindow(v75, 9);
          v76 = (HWND)sub_41B6C0();
          GetClientRect(v76, &Rect);
          v77 = Rect.right - Rect.left;
          v78 = Rect.bottom - Rect.top;
          v79 = (HWND)sub_41B6C0();
          ShowWindow(v79, 6);
        }
        else
        {
          memset(&Rect, 0, sizeof(Rect));
          v80 = GetEngineInstance();
          v149 = sub_4199D0((int)v80) != 0;
          v81 = GetEngineInstance();
          v82 = sub_419B90((int)v81);
          AdjustWindowRect(&Rect, v82, v149);
          v77 = Rect.left + wndpl.rcNormalPosition.right - wndpl.rcNormalPosition.left - Rect.right;
          v78 = Rect.top + wndpl.rcNormalPosition.bottom - wndpl.rcNormalPosition.top - Rect.bottom;
        }
      }
      else
      {
        v83 = (HWND)sub_41B6C0();
        GetClientRect(v83, &Rect);
        v77 = Rect.right - Rect.left;
        v78 = Rect.bottom - Rect.top;
      }
      v84 = v9;
      if ( *v9 )
        v85 = v9[4];
      else
        v85 = v9[5];
      if ( v77 != v85 || (*v9 ? (v86 = v9[5]) : (v86 = v9[6]), v78 != v86) )
        v153 = 1;
      if ( (_BYTE)a5 )
      {
        v87 = (HWND)sub_41B6C0();
        if ( !IsIconic(v87) )
        {
          v159.cbSize = 40;
          v88 = sub_426C00(v9);
          sub_438210(&v159, v88);
          v89 = (HWND)sub_41B5D0();
          v90 = sub_438340(v89, 1u);
          v91 = (HWND)sub_41B6C0();
          GetWindowRect(v91, &Rect);
          if ( Rect.left < v159.rcWork.left
            || Rect.right > v159.rcWork.right
            || Rect.top < v159.rcWork.top
            || Rect.bottom > v159.rcWork.bottom )
          {
            if ( v90 != v88 || (v92 = (HWND)sub_41B6C0(), !IsZoomed(v92)) )
            {
LABEL_148:
              v93 = (HWND)sub_41B6C0();
              if ( IsIconic(v93) )
              {
                v94 = (HWND)sub_41B6C0();
                ShowWindow(v94, 9);
              }
              v95 = (HWND)sub_41B6C0();
              if ( IsZoomed(v95) )
              {
                v96 = (HWND)sub_41B6C0();
                ShowWindow(v96, 9);
              }
              if ( (_BYTE)a5 )
              {
                v159.cbSize = 40;
                v97 = sub_426C00(v84);
                sub_438210(&v159, v97);
                wndpl.length = 40;
                v98 = (HWND)sub_41B5D0();
                v99 = sub_438340(v98, 1u);
                sub_438210((struct tagMONITORINFO *)&wndpl, v99);
                v100 = v159.rcWork.right - v159.rcWork.left;
                v101 = v159.rcWork.bottom - v159.rcWork.top;
                if ( *v84 )
                  v102 = v84[4];
                else
                  v102 = v84[5];
                if ( *v84 )
                  v103 = v84[5];
                else
                  v103 = v84[6];
                v104 = (HWND)sub_41B6C0();
                GetWindowRect(v104, &v162);
                Rect.left = 0;
                Rect.right = v102;
                Rect.top = 0;
                Rect.bottom = v103;
                v105 = GetEngineInstance();
                v150 = sub_4199D0((int)v105) != 0;
                v106 = (HWND)sub_41B6C0();
                WindowLongW = GetWindowLongW(v106, -16);
                AdjustWindowRect(&Rect, WindowLongW, v150);
                left = Rect.left;
                top = Rect.top;
                v110 = Rect.right - Rect.left;
                v111 = Rect.bottom - Rect.top;
                if ( Rect.right - Rect.left > v100 )
                  v110 = v100;
                if ( v111 > v101 )
                  v111 = v101;
                if ( Rect.left < v159.rcWork.left
                  || Rect.top < v159.rcWork.top
                  || Rect.right > v159.rcWork.right
                  || Rect.bottom > v159.rcWork.bottom )
                {
                  v112 = (v100 - v110) / 2;
                  v113 = (v101 - v111) / 2;
                  left = v112 + v159.rcWork.left;
                  top = v113 + v159.rcWork.top;
                  Rect.left = v112 + v159.rcWork.left;
                  Rect.top = v113 + v159.rcWork.top;
                  Rect.right = v159.rcWork.left + v110 + v112;
                  Rect.bottom = v159.rcWork.top + v111 + v113;
                }
                v131 = v110;
                v130 = left;
                v114 = (HWND)sub_41B6C0();
                SetWindowPos(v114, 0, v130, top, v131, v111, 4u);
              }
              else
              {
                v115 = *v84;
                memset(&Rect, 0, sizeof(Rect));
                if ( v115 )
                  Rect.right = v84[4];
                else
                  Rect.right = v84[5];
                if ( v115 )
                  Rect.bottom = v84[5];
                else
                  Rect.bottom = v84[6];
                v116 = GetEngineInstance();
                v151 = sub_4199D0((int)v116) != 0;
                v117 = (HWND)sub_41B6C0();
                v118 = GetWindowLongW(v117, -16);
                AdjustWindowRect(&Rect, v118, v151);
                v133 = Rect.bottom - Rect.top;
                v132 = Rect.right - Rect.left;
                v119 = (HWND)sub_41B6C0();
                SetWindowPos(v119, 0, 0, 0, v132, v133, 6u);
              }
              v120 = (HWND)sub_41B6C0();
              GetClientRect(v120, &v161);
              if ( *v154 )
                v121 = v154[4];
              else
                v121 = v154[5];
              if ( v161.right - v161.left != v121
                || (*v154 ? (v122 = v154[5]) : (v122 = v154[6]), v161.bottom - v161.top != v122) )
              {
                qmemcpy(v156, sub_427EC0(v157), sizeof(v156));
                if ( v156[0] )
                {
                  v156[4] = 0;
                  v156[5] = 0;
                }
                else
                {
                  v156[5] = 0;
                  v156[6] = 0;
                }
                v123 = sub_41E880(v156, 0, 0, 0, a5);
                if ( v123 < 0 )
                {
                  if ( v155 )
                    operator delete(v155);
                  sub_426B70(1);
                  sub_4250D0(0, 0);
                  v124 = GetEngineInstance();
                  sub_419DD0((int)v124, 0);
                  return v123;
                }
              }
              goto LABEL_191;
            }
          }
        }
      }
      if ( v153 )
      {
        v84 = v9;
        goto LABEL_148;
      }
    }
LABEL_191:
    v125 = (HWND)sub_41B5D0();
    if ( !IsWindowVisible(v125) )
    {
      v126 = (HWND)sub_41B5D0();
      ShowWindow(v126, 5);
    }
    if ( sub_41B9C0() )
      SetThreadExecutionState(0x80000000);
    else
      SetThreadExecutionState(0x80000002);
    if ( v155 )
      operator delete(v155);
    v127 = GetEngineInstance();
    sub_419DD0((int)v127, 0);
    sub_4250D0(0, 0);
    v128 = GetEngineInstance();
    sub_41A4A0((int)v128, 1);
    return 0;
  }
  if ( !v6 || *v6 )
    v58 = sub_4224F0();
  else
    v58 = sub_4204F0();
  v59 = v58;
  if ( v58 >= 0 )
    goto LABEL_97;
  if ( v58 == -2005530520 )
  {
    v60 = GetEngineInstance();
    sub_41A6E0((int)v60, 1);
    goto LABEL_97;
  }
  if ( v58 != -2147219192 && v58 != -2147219197 )
  {
    v63 = GetEngineInstance();
    sub_4195D0((int)v63, (int)v6);
    if ( (int)sub_41E880(v9, a2, a3, 1, a5) < 0 )
    {
      sub_428190(0);
      return -2147219195;
    }
    sub_4250D0(0, 0);
    return 0;
  }
  if ( v6 )
    operator delete(v6);
  sub_4256B0(v59);
  sub_428190(0);
  return v59;
}
