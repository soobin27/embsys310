// returns 1 for little endian, 0 for big endian

int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}
