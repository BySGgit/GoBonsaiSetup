int __stdcall sub_452090(int a1, int a2, int a3)
{
  int result; // eax
  void *v4; // eax
  void *v5; // eax
  int v6; // edx

  result = sub_42E330();
  if ( result >= 0 )
  {
    result = sub_439810();
    if ( result >= 0 )
    {
      if ( !dword_4D82C0
        || (result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D82C0 + 68))(dword_4D82C0), result >= 0) )
      {
        if ( !dword_4D82C8
          || (result = (*(int (__stdcall **)(int))(*(_DWORD *)dword_4D82C8 + 280))(dword_4D82C8), result >= 0) )
        {
          result = D3DXCreateSprite(a1, &dword_4D82C4);
          if ( result >= 0 )
          {
            v4 = operator new(0x30u);
            if ( v4 )
              v5 = (void *)sub_43F520((int)v4);
            else
              v5 = 0;
            dword_4D82BC = v5;
            dword_4D5BE0 = *(_DWORD *)(a2 + 24) - 170;
            dword_4D5BE4 = 0;
            dword_4D5BE8 = 170;
            dword_4D5BEC = 170;
            v6 = *(_DWORD *)(a2 + 28);
            dword_4CA628 = *(_DWORD *)(a2 + 24);
            dword_4CA62C = v6;
            flt_4D82CC = (double)dword_4CA628 / (double)v6;
            sub_405710();
            sub_412480();
            if ( dword_4D7EEC )
              *(float *)(dword_4D7EEC + 200) = flt_4D82CC;
            return 0;
          }
        }
      }
    }
  }
  return result;
}
