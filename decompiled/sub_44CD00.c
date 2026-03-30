__int64 __thiscall sub_44CD00(const void ***this, char *a2, __int64 a3)
{
  int v3; // edi
  __int64 v4; // rax
  int v5; // ebx
  unsigned int v6; // esi
  __int16 v7; // cx
  __int64 v10; // [esp+10h] [ebp-8h]

  v3 = HIDWORD(a3);
  v10 = 0;
  if ( a3 > 0 )
  {
    do
    {
      v4 = sub_44D7F0((int)this);
      v5 = HIDWORD(v4);
      v6 = v4;
      if ( v4 <= 0 )
      {
        v7 = ((int (__thiscall *)(const void ***))(*this)[7])(this);
        if ( v7 == -1 )
          return v10;
        ++v10;
        *(_WORD *)a2 = v7;
        a2 += 2;
        v3 = (__PAIR64__(v3, a3) - 1) >> 32;
        a3 = __PAIR64__(v3, (int)a3 - 1);
      }
      else
      {
        if ( __SPAIR64__(v3, a3) < v4 )
        {
          v6 = a3;
          v5 = v3;
        }
        memcpy_0(a2, **(this + 8), 2 * v6);
        a2 += 2 * v6;
        v10 += __PAIR64__(v5, v6);
        a3 -= __PAIR64__(v5, v6);
        **(this + 12) = (char *)**(this + 12) - v6;
        **(this + 8) = (char *)**(this + 8) + 2 * v6;
        v3 = HIDWORD(a3);
      }
    }
    while ( v3 > 0 || v3 >= 0 && (_DWORD)a3 );
  }
  return v10;
}
