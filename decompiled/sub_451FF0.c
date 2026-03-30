int __fastcall sub_451FF0(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // edx

  result = sub_42E270(a1, a2, a3);
  if ( result >= 0 )
  {
    if ( a3 )
    {
      dword_4D5618 = (int)sub_43AB90;
      dword_4D561C = (int)&dword_4D53C8;
      dword_4D5908 = (int)sub_43AB90;
      dword_4D590C = (int)&dword_4D53C8;
      result = D3DXCreateFontW(a3, 22, 0, 700, 1, 0, 1, 0, 0, 0, L"Times New Roman", &dword_4D82C0);
      if ( result >= 0 )
      {
        v6 = *(_DWORD *)(a4 + 28);
        dword_4CA628 = *(_DWORD *)(a4 + 24);
        dword_4CA62C = v6;
        result = 0;
        flt_4D82CC = (double)dword_4CA628 / (double)v6;
      }
    }
    else
    {
      return -2147024809;
    }
  }
  return result;
}
