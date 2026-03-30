PVOID _initp_eh_hooks()
{
  PVOID result; // eax

  result = EncodePointer(terminate);
  dword_4D72B8 = result;
  return result;
}
