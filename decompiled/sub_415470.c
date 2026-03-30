int __usercall sub_415470@<eax>(int a1@<eax>)
{
  float v2; // [esp+8h] [ebp-4h]

  v2 = *(float *)(dword_4D7EE8 + 216) / 365.0;
  return (int)v2 - (int)((*(float *)(dword_4D7EE8 + 216) - *(float *)(a1 + 440)) / 365.0);
}
