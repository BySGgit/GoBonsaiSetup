char __userpurge sub_42F490@<al>(int a1@<eax>, int a2, unsigned int a3, int a4, int a5)
{
  _BYTE *EngineInstance; // ebx
  char v7; // bl
  int v8; // ecx
  int i; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  bool v13; // zf
  char result; // al
  int v15; // ecx
  int v16; // eax
  HWND v17; // eax
  _DWORD *v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // eax
  _DWORD *v22; // edx
  SHORT KeyState; // ax
  int v24; // ebx
  int v25; // esi
  int v26; // eax
  int v27; // [esp+20h] [ebp-4h]

  if ( !*(_BYTE *)(a1 + 20) )
    return 0;
  EngineInstance = GetEngineInstance();
  if ( byte_4CA649 )
    EnterCriticalSection(&CriticalSection);
  v7 = EngineInstance[798];
  if ( byte_4CA649 )
    LeaveCriticalSection(&CriticalSection);
  if ( v7 && (a3 == 513 || a3 == 515 || a3 == 256) )
  {
    v8 = *(_DWORD *)(a1 + 572);
    for ( i = 0; i < *(_DWORD *)(v8 + 52); *(_BYTE *)(v10 + 1) = 1 )
      v10 = *(_DWORD *)(*(_DWORD *)(v8 + 48) + 4 * i++);
  }
  if ( *(_BYTE *)(a1 + 21) )
  {
    if ( a3 == 513 || a3 == 515 )
    {
      v15 = *(_DWORD *)(a1 + 536);
      if ( (__int16)a5 >= v15 && (__int16)a5 < v15 + *(_DWORD *)(a1 + 544) )
      {
        v16 = *(_DWORD *)(a1 + 540);
        if ( SHIWORD(a5) >= v16 && SHIWORD(a5) < v16 + *(_DWORD *)(a1 + 552) )
        {
          *(_BYTE *)(a1 + 23) = 1;
          v17 = (HWND)sub_41B5D0();
          SetCapture(v17);
          return 1;
        }
      }
    }
    else if ( a3 == 514 )
    {
      if ( *(_BYTE *)(a1 + 23) )
      {
        v11 = *(_DWORD *)(a1 + 536);
        if ( (__int16)a5 >= v11 && (__int16)a5 < v11 + *(_DWORD *)(a1 + 544) )
        {
          v12 = *(_DWORD *)(a1 + 540);
          if ( SHIWORD(a5) >= v12 && SHIWORD(a5) < v12 + *(_DWORD *)(a1 + 552) )
          {
            ReleaseCapture();
            v13 = *(_BYTE *)(a1 + 22) == 0;
            *(_BYTE *)(a1 + 23) = 0;
            *(_BYTE *)(a1 + 22) = v13;
            return 1;
          }
        }
      }
    }
  }
  if ( *(_BYTE *)(a1 + 22) )
    return 0;
  v18 = (_DWORD *)dword_4D7F28;
  if ( dword_4D7F28 && *(_DWORD *)(dword_4D7F28 + 24) == a1 )
  {
    if ( (*(unsigned __int8 (**)(void))(*(_DWORD *)dword_4D7F28 + 60))()
      && (*(unsigned __int8 (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)dword_4D7F28 + 16))(
           dword_4D7F28,
           a3,
           a4,
           a5) )
    {
      return 1;
    }
    v18 = (_DWORD *)dword_4D7F28;
  }
  if ( a3 > 0x101 )
  {
    if ( a3 > 0x20D )
    {
      if ( a3 == 533 && a5 != a2 )
        *(_BYTE *)(a1 + 23) = 0;
      return 0;
    }
    if ( a3 >= 0x200 )
    {
      if ( !*(_BYTE *)(a1 + 2) )
        return 0;
      v24 = (__int16)a5 - *(_DWORD *)(a1 + 536);
      v25 = SHIWORD(a5) - *(_DWORD *)(a1 + 540);
      if ( *(_BYTE *)(a1 + 21) )
        v25 -= *(_DWORD *)(a1 + 552);
      if ( !v18
        || v18[6] != a1
        || !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*v18 + 60))(v18)
        || !(*(unsigned __int8 (__thiscall **)(int, unsigned int, int, int, int, int))(*(_DWORD *)dword_4D7F28 + 24))(
              dword_4D7F28,
              a3,
              v24,
              v25,
              a4,
              a5) )
      {
        v26 = sub_42F960(a1, v24, v25);
        v27 = v26;
        if ( v26 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v26 + 60))(v26) )
        {
          if ( (*(unsigned __int8 (__thiscall **)(int, unsigned int, int, int, int, int))(*(_DWORD *)v27 + 24))(
                 v27,
                 a3,
                 v24,
                 v25,
                 a4,
                 a5) )
          {
            return 1;
          }
        }
        else if ( a3 == 513 )
        {
          if ( dword_4D7F28 && *(_DWORD *)(dword_4D7F28 + 24) == a1 )
          {
            (*(void (**)(void))(*(_DWORD *)dword_4D7F28 + 36))();
            dword_4D7F28 = 0;
            return 0;
          }
          return 0;
        }
        if ( a3 == 512 )
        {
          sub_42F9D0(a1, v24, v25);
          return 0;
        }
        return 0;
      }
      return 1;
    }
    if ( a3 < 0x104 || a3 > 0x105 )
      return 0;
  }
  else if ( a3 < 0x100 )
  {
    if ( a3 == 3 || a3 == 5 )
    {
      sub_42F9D0(a1, -1, -1);
      return 0;
    }
    if ( a3 == 28 && v18 && v18[6] == a1 && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v18 + 60))(v18) )
    {
      v19 = *(_DWORD *)dword_4D7F28;
      if ( a4 )
        (*(void (**)(void))(v19 + 32))();
      else
        (*(void (**)(void))(v19 + 36))();
      return 0;
    }
    return 0;
  }
  if ( v18 && v18[6] == a1 )
  {
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*v18 + 60))(v18)
      || !(*(unsigned __int8 (__thiscall **)(int, unsigned int, int, int))(*(_DWORD *)dword_4D7F28 + 20))(
            dword_4D7F28,
            a3,
            a4,
            a5) )
    {
      v18 = (_DWORD *)dword_4D7F28;
      goto LABEL_56;
    }
    return 1;
  }
LABEL_56:
  if ( a3 != 256 )
    return 0;
  if ( v18 && ((v20 = v18[12], v20 == 6) || v20 == 7) || (v21 = 0, *(int *)(a1 + 612) <= 0) )
  {
LABEL_64:
    if ( !*(_BYTE *)(a1 + 1) )
      return 0;
    switch ( a4 )
    {
      case 9:
        KeyState = GetKeyState(16);
        result = sub_431620(a1, (KeyState & 0x8000) == 0);
        break;
      case 37:
      case 38:
        if ( !v18 )
          return 0;
        result = sub_431620(a1, 0);
        break;
      case 39:
      case 40:
        if ( !v18 )
          return 0;
        result = sub_431620(a1, 1);
        break;
      default:
        return 0;
    }
  }
  else
  {
    v22 = *(_DWORD **)(a1 + 608);
    while ( *(_DWORD *)(*v22 + 52) != a4 )
    {
      ++v21;
      ++v22;
      if ( v21 >= *(_DWORD *)(a1 + 612) )
        goto LABEL_64;
    }
    (*(void (__thiscall **)(_DWORD))(*(_DWORD *)*v22 + 48))(*v22);
    return 1;
  }
  return result;
}
