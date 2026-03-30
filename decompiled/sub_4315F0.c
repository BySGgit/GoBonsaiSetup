BOOL sub_4315F0()
{
  if ( dword_4D7F28 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_4D7F28 + 36))(dword_4D7F28);
    dword_4D7F28 = 0;
  }
  return ReleaseCapture();
}
