void __usercall sub_412BF0(int a1@<eax>)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  _DWORD *v5; // edi
  _DWORD **v6; // eax
  _DWORD *v7; // ebx
  float *v8; // ebp
  int v9; // eax
  _DWORD *v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  dword_4D82A8 = 1;
  v2 = sub_4139D0();
  v3 = v2;
  v11 = v2;
  if ( v2 )
  {
    *(_DWORD *)(a1 + 260) = *(_DWORD *)(v2 + 184);
    if ( (_BYTE)word_4D8C9A )
    {
      if ( v2 != *(_DWORD *)(dword_4D7EE8 + 240) )
      {
        v4 = sub_413CF0(v2);
        v5 = (_DWORD *)v4;
        if ( v4 )
        {
          if ( sub_412020(v4) )
          {
            sub_4157C0((int)v5);
            v6 = (_DWORD **)v5[42];
            v7 = *v6;
            if ( *v6 != v6 )
            {
              do
              {
                v10 = (_DWORD *)*v7;
                v8 = (float *)sub_413CF0(v7[2]);
                if ( v8[111] < 0.69999999 )
                {
                  if ( sub_413D70(v7[2]) && v5[43] == 1 )
                    ++dword_4D632C;
                  else
                    (*(void (__thiscall **)(float *))(*(_DWORD *)v8 + 44))(v8);
                }
                v7 = v10;
              }
              while ( v10 != (_DWORD *)v5[42] );
              v3 = v11;
            }
          }
          else
          {
            (*(void (__thiscall **)(_DWORD *))(*v5 + 44))(v5);
          }
        }
      }
    }
    if ( byte_4D8CA0 && v3 != *(_DWORD *)(dword_4D7EE8 + 240) )
    {
      v9 = sub_413CF0(v3);
      if ( v9 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 44))(v9);
    }
  }
  else
  {
    *(_DWORD *)(a1 + 260) = 0;
  }
}
