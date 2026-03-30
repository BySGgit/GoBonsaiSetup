_DWORD *__thiscall sub_40D8C0(int this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // ecx
  _DWORD **v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  unsigned int v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = *(_DWORD **)(this + 204);
  v3 = (_DWORD *)*v2;
  if ( (_DWORD *)*v2 != v2 )
  {
    do
    {
      v9 = v3[2];
      sub_451210(&v10, &v9);
      if ( v10 != dword_4D8C10 )
      {
        v4 = *(_DWORD *)(v10 + 12);
        if ( v4 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
      }
      v3 = (_DWORD *)*v3;
    }
    while ( v3 != *(_DWORD **)(this + 204) );
  }
  v5 = *(_DWORD ***)(this + 204);
  v6 = *v5;
  *v5 = v5;
  *(_DWORD *)(*(_DWORD *)(this + 204) + 4) = *(_DWORD *)(this + 204);
  *(_DWORD *)(this + 208) = 0;
  if ( v6 != *(_DWORD **)(this + 204) )
  {
    do
    {
      v7 = (_DWORD *)*v6;
      operator delete(v6);
      v6 = v7;
    }
    while ( v7 != *(_DWORD **)(this + 204) );
  }
  *(_BYTE *)(this + 188) = 1;
  return sub_401A70(this);
}
