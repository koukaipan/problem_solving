#include <stdio.h>
/*abcdasfsadfkljsdafklsafdds*/
struct ch_t
{
	char ascii;
	int count;
}ch[256];

void f_init()
{
	int i;
	for(i=0; i<256; i++)
	{
		ch[i].ascii = 0;
		ch[i].count = 0;
	}
}

//struct ch_t ;

void f_sort(int mount)
{
	int i, j;
	struct ch_t buf;

	for(i=0; i<mount; i++)    
    {
        for(j=i+1; j<mount; j++)
        {
            if( ch[j].ascii < ch[i].ascii )
            {
                buf = ch[i];
                ch[i] = ch[j];
                ch[j] = buf;
            }
        }
    }


	for(i=0; i<mount; i++)    
    {
        for(j=i+1; j<mount; j++)
        {
            if( ch[j].count <= ch[i].count )
            {
                buf = ch[i];
                ch[i] = ch[j];
                ch[j] = buf;
            }
        }
    }
}


int main()
{
	char str[1000];
	int i, j, mount;
	bool pe_flag = 0;


	while(gets(str))
	{
		mount = 0;
		f_init();				//initialize the struct

		for(i=0; str[i]; i++)	//begin to check every char
		{
			for(j=0; ch[j].ascii; j++)		//check if there is the same char exist
				if(ch[j].ascii == str[i])
				{
					ch[j].count++;
					break;
				}
			if(!ch[j].ascii)
			{
				ch[j].ascii = str[i];
				ch[j].count = 1;
				mount++;
			}
		}
		//sort
		f_sort(mount);
		//print
		if(!pe_flag)
			pe_flag = true;
		else
			printf("\n");
		for(i=0; i<mount; i++)
			printf("%d %d\n", ch[i].ascii, ch[i].count);
		
	}

	return 0;
}


