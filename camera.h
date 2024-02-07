Decrypt Ansi

char*v2; // rdi
  int v4; // ebx
  unsigned int v5; // er9
  unsigned int v6; // er8
  __int64 result; // rax
  unsigned int v8; // er9
  int v9; // ecx

  v2 = buffer;
  v4 = length;
  v5 = sub_14473C460(); //0x130D7A4
  v6 = v5 ^ 0x9C677CC5;
  result = 1041204193 * v5;
  v8 = v5 % 0x21;
  v9 = 0;
  if ( v4 )
  {
    do
    {
      result = v9 + v8;
      ++v9;
      v6 += result;
      *v2++ ^= v6;
    }
    while ( v9 < v4 );
  }
