void __usercall sub_417F40(int a1@<edi>)
{
  int v1; // eax
  unsigned int v2; // eax
  int v3; // eax
  float v4; // [esp+Ch] [ebp-4h]

  v4 = *(float *)(dword_4D7EE8 + 216) / 365.0;
  v1 = (int)v4 - (int)((*(float *)(dword_4D7EE8 + 216) - *(float *)(a1 + 440)) / 365.0);
  if ( v1 >= 1 )
  {
    if ( v1 > 3 )
    {
      if ( *(float *)(a1 + 444) > 0.2000000029802322 )
        sub_4188E0(a1);
    }
    else
    {
      v2 = *(_DWORD *)(a1 + 172);
      if ( v2 <= 1 && (v2 != 1 || (v3 = sub_416300(*(_DWORD *)(**(_DWORD **)(a1 + 168) + 8))) != 0 && sub_415470(v3)) )
        sub_417FF0(a1);
    }
  }
}
