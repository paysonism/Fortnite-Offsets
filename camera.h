char *v2; // rdi
  int v4; // ecx
  unsigned int v5; // eax
  __int64 v6; // rdx

  v2 = buffer;
  v4 = 9;
  v5 = Length;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      LOWORD(v5) = v4 + ~*v2;
      v4 += 7947;
      *v2++ = v5;
      --v6;
    }
    while ( v6 );
