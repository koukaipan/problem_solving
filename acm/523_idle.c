/* @JUDGE_ID:4461XX 523 C "Warshall" */
/* A */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 200

struct Map{
	int dis ;
	int k ;
} ;

struct Map map[MAX][MAX] ;
int city[MAX] , n ;

void Input( void )
{
	char tmp[100000] , *p ;
	int i , j ;
	
	gets( tmp ) ;
	for( i=0,p=strtok( tmp , " " ) ; p ; ++i,p=strtok( NULL , " " ) ){
		map[0][i].dis = atoi( p ) ;
		map[0][i].k = -1 ;
		if( map[0][i].dis==-1 ) map[0][i].dis = 0 ;
	}
	n = i ;

	for( i=1 ; i<n ; ++i )
		for( j=0 ; j<n ; ++j ){
			scanf( "%d" , &map[i][j].dis ) ;
			map[i][j].k = -1 ;
			if( map[i][j].dis==-1 ) map[i][j].dis = 0 ;
		}
	
	for( i=0 ; i<n ; ++i ) scanf( "%d" , &city[i] ) ;
	scanf( "\n" ) ;
}
void Warshall( void )
{
	int i , j , k ;

	for( k=0 ; k<n ; ++k )
		for( i=0 ; i<n ; ++i )
			for( j=0 ; j<n ; ++j )
				if( i!=j&&map[i][k].dis&&map[k][j].dis )
					if( !map[i][j].dis ||
					    map[i][k].dis+map[k][j].dis+city[k]<map[i][j].dis ){
						map[i][j].dis = map[i][k].dis+map[k][j].dis+city[k] ;
						map[i][j].k = k ;
					}
}
void Find_K( int from , int to )
{
	if( map[from][to].k==-1 ) return ;

	Find_K( from , map[from][to].k ) ;
	printf( "-->%d" , map[from][to].k+1 ) ;
	Find_K( map[from][to].k , to ) ;
}
void Output( int from , int to )
{
	printf( "From %d to %d :\n" , from+1 , to+1 ) ;
	printf( "Path: %d" , from+1 ) ;
	Find_K( from , to ) ;
	if( from!=to ) printf( "-->%d" , to+1 ) ;
	printf( "\nTotal cost : %d\n\n" , map[from][to].dis ) ;
}
void Input__( void )
{
	char tmp[100000] ;
	int from , to ;
	
	while( gets( tmp ) ){
		if( !strlen( tmp ) ) break ;

		sscanf( tmp , "%d %d" , &from , &to ) ;
		Output( from-1 , to-1 ) ;
	}
}
int main( void )
{
	int run_case ;
	
	scanf( "%d\n\n" , &run_case ) ;
	for( ; run_case ; --run_case ){
		Input() ;
		Warshall() ;
		Input__() ;
	}

	return 0 ;
}

 