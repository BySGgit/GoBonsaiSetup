void __thiscall sub_43F930(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+44h] [ebp-30h] BYREF
  int v6; // [esp+48h] [ebp-2Ch] BYREF
  int v7; // [esp+4Ch] [ebp-28h] BYREF
  float v8[4]; // [esp+50h] [ebp-24h] BYREF
  _BYTE v9[16]; // [esp+60h] [ebp-14h] BYREF

  if ( *(_DWORD *)(this + 4) )
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(this + 4) + 44))(*(_DWORD *)(this + 4));
  if ( *(_DWORD *)(this + 12) )
  {
    v2 = *(_DWORD *)(this + 12);
    v7 = 0;
    v6 = 0;
    v5 = 0;
    (*(void (__stdcall **)(int, int *))(*(_DWORD *)v2 + 48))(v2, &v5);
    if ( v5 )
    {
      (*(void (__stdcall **)(int, int *, _BYTE *, int *))(*(_DWORD *)v5 + 228))(v5, &v6, v9, &v7);
      v3 = *(_DWORD *)(this + 44);
      if ( v3 )
      {
        v8[0] = 0.0;
        v8[1] = 0.0;
        v8[2] = 0.0;
        v8[3] = 0.0;
        (*(void (__stdcall **)(int, int, float *, int))(*(_DWORD *)v5 + 100))(v5, v3, v8, -1);
      }
    }
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(this + 12) + 28))(*(_DWORD *)(this + 12));
    v4 = v5;
    if ( v5 )
    {
      if ( !v6 )
      {
LABEL_12:
        if ( v4 )
          (*(void (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
        return;
      }
      (*(void (__stdcall **)(int, int, _BYTE *, int))(*(_DWORD *)v5 + 100))(v5, v6, v9, v7);
      v4 = v5;
    }
    if ( v6 )
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)v6 + 8))(v6);
      v4 = v5;
      v6 = 0;
    }
    goto LABEL_12;
  }
}
