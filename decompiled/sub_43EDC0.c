int __stdcall sub_43EDC0(int a1, int Args)
{
  int v2; // esi
  int v3; // eax
  int *v4; // edx
  int v5; // eax
  wchar_t Format[54]; // [esp+Ch] [ebp-FCh] BYREF
  wchar_t Buffer[70]; // [esp+78h] [ebp-90h] BYREF

  qmemcpy(Format, L"Reverting to previous display settings in %d seconds", 0x6Au);
  sub_419310(Buffer, Format, Args);
  v2 = *(_DWORD *)(a1 + 1380);
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = *(int **)(a1 + 1376);
    while ( *(_DWORD *)(*v4 + 44) != 45 || *(_DWORD *)(*v4 + 48) != 1 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_6;
    }
    v5 = *v4;
  }
  return sub_4328A0(v5, (int)Buffer);
}
