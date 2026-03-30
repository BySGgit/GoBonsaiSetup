int sub_4022B0()
{
  int result; // eax
  bool v1; // cl

  result = dword_4D7EEC;
  v1 = *(_BYTE *)(dword_4D7EEC + 420) == 0;
  *(_BYTE *)(dword_4D7EEC + 420) = v1;
  if ( v1 )
  {
    *(_DWORD *)(result + 404) = dword_4D82D4;
    *(_DWORD *)(result + 408) = dword_4D82D8;
    *(_DWORD *)(result + 412) = dword_4D82DC;
    *(_BYTE *)(result + 388) = 0;
  }
  else
  {
    *(float *)(result + 416) = 0.78539819;
    *(float *)(result + 212) = 0.0;
    *(float *)(result + 352) = 0.0;
  }
  return result;
}
