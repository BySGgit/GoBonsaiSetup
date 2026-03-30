double __cdecl sqrt(double X)
{
  int v1; // ecx

  _fload_withFB(v1);
  return start_3(LODWORD(X), HIDWORD(X));
}
