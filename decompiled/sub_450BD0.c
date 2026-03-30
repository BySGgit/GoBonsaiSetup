_DWORD *__thiscall sub_450BD0(char *this)
{
  int v2; // eax
  _BYTE *v3; // esi
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  _DWORD *result; // eax
  _DWORD *v8; // esi
  int v9; // edi
  _BYTE v10[68]; // [esp+10h] [ebp-48h] BYREF

  (*(void (__thiscall **)(char *))(*(_DWORD *)this + 32))(this);
  v2 = *((_DWORD *)this + 45);
  if ( v2 )
  {
    D3DXMatrixMultiply(v10, this + 40, v2 + 104);
    v3 = v10;
  }
  else
  {
    v3 = this + 40;
  }
  v4 = *((_DWORD *)this + 6);
  v5 = *((_DWORD *)this + 7);
  *((float *)this + 5) = *((float *)this + 9);
  *((_DWORD *)this + 2) = v4;
  qmemcpy(this + 104, v3, 0x40u);
  v6 = *((_DWORD *)this + 8);
  *((_DWORD *)this + 3) = v5;
  result = (_DWORD *)*((_DWORD *)this + 42);
  *((_DWORD *)this + 4) = v6;
  v8 = (_DWORD *)*result;
  if ( (_DWORD *)*result != result )
  {
    do
    {
      v9 = v8[2];
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 16))(v9);
      result = (_DWORD *)sub_450A80(v9 + 8, (int)(this + 8));
      v8 = (_DWORD *)*v8;
    }
    while ( v8 != *((_DWORD **)this + 42) );
  }
  return result;
}
