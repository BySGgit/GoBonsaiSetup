float *sub_451D70()
{
  DWORD Time; // eax
  float *result; // eax
  float *v2; // esi

  Time = timeGetTime();
  srand(Time);
  dword_4D5614 = (int)&dword_4D8C38;
  sub_42F420(&unk_4D53D8);
  sub_431990(&unk_4D53D8);
  dword_4D5904 = (int)&dword_4D8C38;
  sub_42F420(&word_4D56C8);
  sub_431990(&word_4D56C8);
  dword_4D53D0 = (int)&unk_4D53D8;
  sub_438B90();
  dword_4D5C04 = (int)&dword_4D8C38;
  sub_42E4C0();
  sub_42F420(&unk_4D59C8);
  sub_431990(&unk_4D59C8);
  dword_4D5C08 = (int)sub_452700;
  dword_4D5C0C = 0;
  sub_403C50();
  result = (float *)operator new(0x120u);
  v2 = result;
  if ( result )
  {
    *(_DWORD *)result = &BonsaiController::`vftable';
    result = (float *)sub_401830(result + 8);
    v2[64] = NAN;
    v2[66] = 0.0;
    v2[67] = 0.0;
    v2[65] = 0.0;
    dword_4D82D0 = v2;
  }
  else
  {
    dword_4D82D0 = 0;
  }
  return result;
}
