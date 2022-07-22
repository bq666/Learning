/* s_i_r.c -- plik z funkcjami rand1() i srand1()    */
/* uzywa przenosnego algorytmu ANSI C */
static unsigned long int nast = 1;  /* ziarno (ang. seed)  */
int rand1(void)
{
/* magiczna formula generujaca liczby pseudolosowe */
    nast = nast * 1103515245 + 12345;
    return (unsigned int) (nast/65536) % 32768;
}
void srand1(unsigned int ziarno)
{
    nast = ziarno;
}

