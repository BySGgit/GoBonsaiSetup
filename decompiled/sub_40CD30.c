void sub_40CD30()
{
  _DWORD *v0; // eax
  _DWORD *v1; // esi
  int v2; // eax
  int v3; // [esp+28h] [ebp-10h] BYREF
  int v4; // [esp+2Ch] [ebp-Ch] BYREF
  unsigned int v5; // [esp+30h] [ebp-8h] BYREF
  int v6; // [esp+34h] [ebp-4h] BYREF

  if ( dword_4D7EE8
    && (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, int))(*(_DWORD *)dword_4D7E90 + 44))(
         dword_4D7E90,
         0,
         0,
         &v3,
         0x2000) >= 0 )
  {
    if ( (*(int (__stdcall **)(int, _DWORD, _DWORD, int *, int))(*(_DWORD *)dword_4D7EA8 + 44))(
           dword_4D7EA8,
           0,
           0,
           &v4,
           0x2000) >= 0 )
    {
      dword_4D7E98 = 0;
      dword_4D7EB0 = 0;
      dword_4D7EC0 = v3;
      dword_4D7EC4 = v4;
      sub_40CC70(*(_DWORD *)(dword_4D7EE8 + 240));
      v0 = *(_DWORD **)(dword_4D7EE8 + 204);
      v1 = (_DWORD *)*v0;
      if ( (_DWORD *)*v0 != v0 )
      {
        do
        {
          v5 = v1[2];
          sub_451210(&v6, &v5);
          if ( v6 != dword_4D8C10 )
          {
            v2 = *(_DWORD *)(v6 + 12);
            if ( v2 )
              sub_40CC70(v2);
          }
          v1 = (_DWORD *)*v1;
        }
        while ( v1 != *(_DWORD **)(dword_4D7EE8 + 204) );
      }
      if ( (unsigned int)dword_4D7E98 <= 2 )
        dword_4D7E98 = 0;
      else
        dword_4D7E98 -= 2;
      if ( (unsigned int)dword_4D7EB0 <= 2 )
        dword_4D7EB0 = 0;
      else
        dword_4D7EB0 -= 2;
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7E90 + 48))(dword_4D7E90);
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7EA8 + 48))(dword_4D7EA8);
    }
    else
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)dword_4D7E90 + 48))(dword_4D7E90);
    }
  }
}
