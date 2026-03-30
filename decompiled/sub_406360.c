int __cdecl sub_406360(float a1)
{
  _DWORD v2[12]; // [esp+0h] [ebp-30h]

  v2[0] = L"January";
  v2[1] = L"Febuary";
  v2[2] = L"March";
  v2[3] = L"April";
  v2[4] = L"May";
  v2[5] = L"June";
  v2[6] = L"July";
  v2[7] = L"August";
  v2[8] = L"September";
  v2[9] = L"October";
  v2[10] = L"November";
  v2[11] = L"December";
  return v2[-(int)((a1 - (double)(int)a1) * -12.0)];
}
