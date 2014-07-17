
void myprint( char *msg, int len );

int choose( int a, int b )
{
    if ( a >= b ) 
	{
        myprint( "this is 1st one\n", 16 );
    }
	else 
	{
        myprint( "this is 2nd one\n", 16 );
    }
    return 0;
}


