void __stdcall `eh vector constructor iterator'(
        char *a1,
        unsigned int a2,
        int a3,
        void (__thiscall *a4)(void *),
        void (__thiscall *a5)(void *))
{
  int i; // [esp+14h] [ebp-1Ch]

  for ( i = 0; i < a3; ++i )
  {
    a4(a1);
    a1 += a2;
  }
}
