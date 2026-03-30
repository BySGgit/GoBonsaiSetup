__int16 __usercall sub_44A1D0@<ax>(int *a1@<esi>)
{
  int v1; // ecx
  __int16 **v2; // eax
  __int16 result; // ax

  if ( !*((_BYTE *)a1 + 4) )
  {
    v1 = *a1;
    if ( *a1 )
    {
      v2 = *(__int16 ***)(v1 + 32);
      if ( *v2 && **(int **)(v1 + 48) > 0 )
        result = **v2;
      else
        result = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 24))(v1);
      if ( result != -1 )
      {
        *((_WORD *)a1 + 3) = result;
        *((_BYTE *)a1 + 4) = 1;
        return result;
      }
    }
    *a1 = 0;
    *((_BYTE *)a1 + 4) = 1;
  }
  return *((_WORD *)a1 + 3);
}
