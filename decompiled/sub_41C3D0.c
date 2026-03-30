int __cdecl sub_41C3D0(LPCWSTR lpCmdLine)
{
  int result; // eax
  char *v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  _DWORD *EngineInstance; // edi
  bool v8; // zf
  int v9; // eax
  int v10; // esi
  _DWORD *v11; // edi
  int v12; // eax
  _BYTE *v13; // esi
  int v14; // esi
  _DWORD *v15; // edi
  _BYTE *v16; // esi
  _BYTE *v17; // esi
  void *v18; // eax
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  void *v23; // eax
  void *v24; // eax
  void *v25; // eax
  void *v26; // eax
  void *v27; // eax
  void *v28; // eax
  void *v29; // eax
  void *v30; // eax
  void *v31; // eax
  void *v32; // eax
  void *v33; // eax
  wchar_t *v34; // eax
  int v35; // edx
  int v36; // esi
  wchar_t v37; // cx
  wchar_t *i; // eax
  int v39; // [esp+0h] [ebp-230h]
  int v40; // [esp+0h] [ebp-230h]
  int v41; // [esp+0h] [ebp-230h]
  int v42; // [esp+0h] [ebp-230h]
  int v43; // [esp+0h] [ebp-230h]
  int v44; // [esp+0h] [ebp-230h]
  int v45; // [esp+0h] [ebp-230h]
  int v46; // [esp+14h] [ebp-21Ch] BYREF
  int pNumArgs; // [esp+18h] [ebp-218h] BYREF
  int v48; // [esp+1Ch] [ebp-214h]
  LPWSTR *v49; // [esp+20h] [ebp-210h]
  wchar_t String[260]; // [esp+24h] [ebp-20Ch] BYREF

  v49 = CommandLineToArgvW(lpCmdLine, &pNumArgs);
  result = 1;
  v48 = 1;
  if ( pNumArgs > 1 )
  {
    while ( 1 )
    {
      v2 = (char *)v49[result];
      v3 = *(unsigned __int16 *)v2;
      if ( v3 != 47 && v3 != 45 )
        goto LABEL_88;
      v4 = (int)(v2 + 2);
      v46 = v4;
      if ( (int)wcslen((const unsigned __int16 *)v4) >= 8 && !_wcsnicmp((const wchar_t *)v4, L"forceapi", 8u) )
      {
        v5 = *(unsigned __int16 *)(v4 + 16);
        if ( !(_WORD)v5 || v5 == 58 )
        {
          v46 = v4 + 16;
          if ( sub_41CB90(String, &v46) )
          {
            v6 = _wtoi(String);
            EngineInstance = GetEngineInstance();
            if ( byte_4CA649 )
              EnterCriticalSection(&CriticalSection);
            v8 = byte_4CA649 == 0;
            EngineInstance[201] = v6;
            if ( v8 )
              goto LABEL_97;
            goto LABEL_47;
          }
          v4 = v46;
        }
      }
      if ( (int)wcslen((const unsigned __int16 *)v4) >= 7 && !_wcsnicmp((const wchar_t *)v4, L"adapter", 7u) )
      {
        v9 = *(unsigned __int16 *)(v4 + 14);
        if ( !(_WORD)v9 || v9 == 58 )
        {
          v46 = v4 + 14;
          if ( sub_41CB90(String, &v46) )
          {
            v10 = _wtoi(String);
            v11 = GetEngineInstance();
            if ( byte_4CA649 )
              EnterCriticalSection(&CriticalSection);
            v8 = byte_4CA649 == 0;
            v11[202] = v10;
            if ( v8 )
              goto LABEL_97;
            goto LABEL_47;
          }
          v4 = v46;
        }
      }
      if ( (int)wcslen((const unsigned __int16 *)v4) >= 8 && !_wcsnicmp((const wchar_t *)v4, L"windowed", 8u) )
      {
        v12 = *(unsigned __int16 *)(v4 + 16);
        if ( !(_WORD)v12 || v12 == 58 )
        {
          v13 = GetEngineInstance();
          if ( byte_4CA649 )
            EnterCriticalSection(&CriticalSection);
          v8 = byte_4CA649 == 0;
          v13[812] = 1;
          if ( v8 )
            goto LABEL_97;
          goto LABEL_47;
        }
      }
      if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"output") && sub_41CB90(String, &v46) )
      {
        v14 = _wtoi(String);
        v15 = GetEngineInstance();
        if ( byte_4CA649 )
          EnterCriticalSection(&CriticalSection);
        v8 = byte_4CA649 == 0;
        v15[204] = v14;
        if ( v8 )
          goto LABEL_97;
        goto LABEL_47;
      }
      if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"fullscreen") )
        break;
      if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forcehal") )
      {
        v17 = GetEngineInstance();
        if ( byte_4CA649 )
          EnterCriticalSection(&CriticalSection);
        v8 = byte_4CA649 == 0;
        v17[840] = 1;
        if ( v8 )
          goto LABEL_97;
LABEL_47:
        LeaveCriticalSection(&CriticalSection);
        goto LABEL_97;
      }
      if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forceref") )
      {
        v18 = GetEngineInstance();
        sub_41AAA0((int)v18);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forcepurehwvp") )
      {
        v19 = GetEngineInstance();
        sub_41AAE0((int)v19);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forcehwvp") )
      {
        v20 = GetEngineInstance();
        sub_41AB20((int)v20);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forceswvp") )
      {
        v21 = GetEngineInstance();
        sub_41ABA0((int)v21);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"forcevsync") && sub_41CB90(String, &v46) )
      {
        v39 = _wtoi(String);
        v22 = GetEngineInstance();
        sub_41AD20((int)v22, v39);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"width") && sub_41CB90(String, &v46) )
      {
        v40 = _wtoi(String);
        v23 = GetEngineInstance();
        sub_41A9A0((int)v23, v40);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"height") && sub_41CB90(String, &v46) )
      {
        v41 = _wtoi(String);
        v24 = GetEngineInstance();
        sub_41AA20((int)v24, v41);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"startx") && sub_41CB90(String, &v46) )
      {
        v42 = _wtoi(String);
        v25 = GetEngineInstance();
        sub_41A8A0((int)v25, v42);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"starty") && sub_41CB90(String, &v46) )
      {
        v43 = _wtoi(String);
        v26 = GetEngineInstance();
        sub_41A920((int)v26, v43);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"constantframetime") )
      {
        if ( sub_41CB90(String, &v46) )
          *(float *)&v46 = wcstod(String, 0);
        else
          *(float *)&v46 = 0.033300001;
        v27 = GetEngineInstance();
        sub_41AC20((int)v27);
        v44 = v46;
        v28 = GetEngineInstance();
        sub_41AC60((int)v28, *(float *)&v44);
        sub_428070(*(float *)&v46);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"quitafterframe") && sub_41CB90(String, &v46) )
      {
        v45 = _wtoi(String);
        v29 = GetEngineInstance();
        sub_41ACA0((int)v29, v45);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"noerrormsgboxes") )
      {
        v30 = GetEngineInstance();
        sub_41A1E0((int)v30, 0);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"nostats") )
      {
        v31 = GetEngineInstance();
        sub_41A220((int)v31);
      }
      else if ( sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"relaunchmce") )
      {
        v32 = GetEngineInstance();
        sub_41ADA0((int)v32);
      }
      else
      {
        if ( !sub_41CB10((const wchar_t **)&v46, (wchar_t *)L"automation") )
        {
          v2 = (char *)v46;
LABEL_88:
          v34 = String;
          v35 = 256;
          v36 = v2 - (char *)String;
          while ( v35 != -2147483390 )
          {
            v37 = *(wchar_t *)((char *)v34 + v36);
            if ( !v37 )
              break;
            *v34++ = v37;
            if ( !--v35 )
            {
              --v34;
              break;
            }
          }
          *v34 = 0;
          for ( i = String; *i; ++i )
          {
            if ( *i <= 0x20u )
              break;
          }
          *i = 0;
          nullsub_1(0);
          goto LABEL_97;
        }
        v33 = GetEngineInstance();
        sub_41A760((int)v33);
      }
LABEL_97:
      result = v48 + 1;
      v48 = result;
      if ( result >= pNumArgs )
        return result;
    }
    v16 = GetEngineInstance();
    if ( byte_4CA649 )
      EnterCriticalSection(&CriticalSection);
    v8 = byte_4CA649 == 0;
    v16[820] = 1;
    if ( v8 )
      goto LABEL_97;
    goto LABEL_47;
  }
  return result;
}
