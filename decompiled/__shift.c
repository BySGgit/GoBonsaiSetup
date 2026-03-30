const char *__usercall _shift@<eax>(const char *result@<eax>, int a2@<edi>)
{
  const char *v2; // esi
  size_t v3; // eax

  v2 = result;
  if ( a2 )
  {
    v3 = strlen(result);
    return (const char *)memcpy((void *)&v2[a2], v2, v3 + 1);
  }
  return result;
}
